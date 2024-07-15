#include "udp_thread.h"
#include <QUdpSocket>
#include "configmanager.h"
#include "xochange.h"

Udp_Thread::Udp_Thread(MainWindow *mainwindow,QObject *parent) : QThread{parent} {
    this->mainwindow = mainwindow;
}

Udp_Thread::~Udp_Thread() {}

void Udp_Thread::run()
{
    QUdpSocket *udpSocket = new QUdpSocket();

    int localPort = ConfigManager::get_instance().m_nodeConfig.pc_configs[0].port;
    QHostAddress localAddress;

    qDebug() << "localPort " << QString::number(localPort);

    if (!udpSocket->bind(localAddress, localPort)) {
        qDebug() << "Failed to bind UDP socket Ip : " << localAddress.toString() << " port " << localPort;
    } else {
        qDebug() << "success to bind UDP socket Ip : " << localAddress.toString() << " port " << localPort;
    }

    ConfigManager &configInstance = ConfigManager::get_instance();

    while (1) {
        //有数据等待读取则为true
        while (udpSocket->hasPendingDatagrams())
        {
            QByteArray udpData;
            udpData.resize(udpSocket->pendingDatagramSize());
            udpSocket->readDatagram(udpData.data(), udpData.size());
            // qDebug() << "received msg " << udpData.toHex().toUpper();
            if (udpData.length() < 17)
            {
                return;
            }
            //qDebug() << QString("udp size:%1,udp data:%2").arg(udpData.size()).arg(udpData.toHex(' ').toUpper());
            QList<config::dataConfig> datas;
            QString nodeName;
            QString templateName;
            int ip1 = (uchar)udpData[0];
            int ip2 = (uchar)udpData[1];
            int ip3 = (uchar)udpData[2];
            int ip4 = (uchar)udpData[3];
            QString ip;
            ip.append(QString::number(ip4, 10));
            ip.append('.');
            ip.append(QString::number(ip3, 10));
            ip.append('.');
            ip.append(QString::number(ip2, 10));
            ip.append('.');
            ip.append(QString::number(ip1, 10));
            if (configInstance.m_nodeConfig.beckhoff_configs.contains(ip))
            {
                auto modbus_config = configInstance.m_nodeConfig.beckhoff_configs.value(ip);
                nodeName = modbus_config.name;
                templateName = modbus_config.template_name;
                datas = configInstance.m_dataConfigsSorted.value(templateName);
            }
            else if (configInstance.m_nodeConfig.modbus_configs.contains(ip))
            {
                auto modbus_config = configInstance.m_nodeConfig.modbus_configs.value(ip);
                nodeName = modbus_config.name;
                templateName = modbus_config.template_name;
                datas = configInstance.m_dataConfigsSorted.value(templateName);
            } else if (configInstance.m_nodeConfig.plc_configs.contains(ip))
            {
                auto config = configInstance.m_nodeConfig.plc_configs.value(ip);
                nodeName = config.name;
                templateName = config.template_name;
                datas = configInstance.m_dataConfigsSorted.value(templateName);
            }
            // LOG_ERROR("datasize " + QString::number(datas.size()));
            if (udpData != "" && datas.size() != 0) {
                // 4 ip  6 time 2 补位 从[12]开始才是int 字节总长度
                int len1 = (uchar)udpData[12];
                int len2 = (uchar)udpData[13];
                int len3 = (uchar)udpData[14];
                int len4 = (uchar)udpData[15];
                int lenofbyte = len4 << 24 | len3 << 16 | len2 << 8 | len1;
                int startAddr = 16;
                if (startAddr == udpData.length() - 1)
                {
                    return;
                }

                // QMap<const QString, size_t> type_map = {
                //     {"bool", 1},  {"char", 1},   {"ushort", 2},   {"uint16", 2}, {"int16", 2},
                //     {"short", 2}, {"uint", 4},   {"int", 4},      {"dint", 4},   {"udint", 4},
                //     {"float", 4}, {"double", 8}, {"STRING", 255},
                // };
                QMap<const QString, size_t> type_map = {
                    {"bool", 1},  {"char", 1},  {"ushort", 2}, {"uint16", 2},
                    {"int16", 2}, {"short", 2}, {"uint", 4},   {"int", 4},
                    {"dint", 4},  {"udint", 4}, {"float", 4},  {"double", 8}
                };
                QMap<QString, config::dataValue> resolveMap;
                int totalAddr = 0;
                for (int i = 0; i < datas.length(); i++) {
                    auto &modbus_config = datas[i];
                    config::dataValue item;
                    item.var_name = modbus_config.var_name;
                    item.chinese_name = modbus_config.chinese_name;
                    item.Type = modbus_config.Type;
                    item.alarm_id = modbus_config.alarm_id;
                    item.alarm_level = modbus_config.alarm_level;
                    item.factor = modbus_config.factor;
                    item.RWmodle = modbus_config.RWmodle;
                    auto type_size = type_map[modbus_config.Type];

                    if (type_size == 1) { //char
                        //风机状态点的值为1 就设1 其他的就是0
                        //qDebug() << "StartAddr " << startAddr << "item.var_name " << item.var_name;
                        int byte1char = (uchar) udpData[startAddr];
                        item.value2 = byte1char;
                    }
                    else if (type_size == 2) {
                        int byte1int = (uchar)udpData[startAddr];
                        int byte2int = (uchar)udpData[startAddr + 1];
                        item.value2 = byte2int << 8 | byte1int;
                    }
                    else if (type_size == 4) { //float
                        uchar char11 = (uchar)udpData[startAddr];
                        uchar char22 = (uchar)udpData[startAddr + 1];
                        uchar char33 = (uchar)udpData[startAddr + 2];
                        uchar char44 = (uchar)udpData[startAddr + 3];
                        item.value2 = Xochange::ByteToFloat(char44, char33, char22, char11);
                        if (item.var_name == "S_ControllerState")
                        {
                            if (item.value2 != 1) {
                                item.value2 = 0;
                            }
                        }
                    }
                    else if (type_size == 8) {//double类型的数据暂时不发布 都设置为0
                        item.value2 = 0;
                    }
                    LOG_INFO("i:"+QString::number(i)+" var_name:"+item.var_name+" "+item.Type+" "+QString::number(item.value2)+" START Addr:"+QString::number(startAddr));
                    resolveMap.insert(item.var_name, item);
                    startAddr += type_size;
                    totalAddr += type_size;
                    //if(startAddr >= 315)
                    //    qDebug() << "START Addr:" << startAddr;
                }
                if(totalAddr != lenofbyte)
                {    LOG_ERROR("length of byte is error total size:"+QString::number(totalAddr)+" lenofbyte:"+QString::number(lenofbyte));}
                else if(mainwindow->iec104->allowMutation)
                {
                    QMap<QString, QMap<int, config::publishNode>> publishs = configInstance.m_publishConfigs;
                    QMap<int, config::publishNode> modbus_publishs = publishs.value("modbus");
                    QMap<int, config::publishNode> IEC104_publishs = publishs.value("IEC104");
                    publishModbusReslovedDatas(resolveMap, modbus_publishs, nodeName);
                    publishIEC104ReslovedDatas(resolveMap, IEC104_publishs, nodeName);
                }
            }
        }
        // msleep(1);
    }

    // connect(udpSocket, &QUdpSocket::readyRead, [ = ]()
    //         {
    //         });
}

void Udp_Thread::publishModbusReslovedDatas(QMap<QString, config::dataValue> resolveMap, QMap<int, config::publishNode> modbus_publishs, QString nodeName)
{
    for (config::dataValue readData : resolveMap)
    {
        for (auto &publishTemplate : modbus_publishs)
        {
            int port = publishTemplate.port;
            QString float_sort = publishTemplate.float_sort;
            QMap<QString, QMap<QString, dataConfig>> dataConfigsOfPlcs = publishTemplate.publishDatas;
            if (dataConfigsOfPlcs.contains(nodeName))
            {
                QMap<QString, config::dataConfig> dataConfigsOfPlc = dataConfigsOfPlcs.value(nodeName);
                if (dataConfigsOfPlc.contains(readData.var_name))
                {
                    config::dataConfig publishConfig = dataConfigsOfPlc.value(readData.var_name);
                    int modAddress = publishConfig.modAddress;
                    float value = readData.value2;//不管是什么类型 统一发布成float类型
                    if (publishConfig.Type != "char")
                    {
                        if (publishConfig.RWmodle == "W")
                        {
                            //LOG_INFO("IEC104 not char W,varName " + readData.var_name + " setHoldingRegisterValue modbus addres " + QString::number(modAddress) + " value" + QString::number(value));
                            // qDebug() << "set holdingRegister port" << QString::number(port) << " address" << QString::number(modAddress) << " value" << QString::number(value);
                            this->setHoldingRegisterValue(port, modAddress, value, float_sort);
                        }
                        else
                        {
                            //LOG_INFO("IEC104 not char R,varName " + readData.var_name + " setInputRegisterValue modbus addres " + QString::number(modAddress) + " value" + QString::number(value));
                            this->setInputRegisterValue(port, modAddress, value, float_sort);
                        }
                    } else {
                        if (publishConfig.RWmodle == "W")
                        {
                            uint8_t valueCoil = (uint8_t)readData.value2;
                            this->setCoil(port, modAddress, valueCoil);
                            // LOG_INFO("IEC104 char W,varName " + readData.var_name + " setCoil modbus addres " + QString::number(modAddress) + " value" + QString::number(value));
                        }
                        else
                        {
                            uint8_t valueCoil = (uint8_t)readData.value2;
                            // qDebug()<<"insert "<<valueCoil<<" to addr"<<modAddress;
                            setInputCoil(port, modAddress, valueCoil);
                            //LOG_INFO("IEC104 char R,varName " + readData.var_name + " setInputCoil modbus addres " + QString::number(modAddress) + " value" + QString::number(value));
                        }
                    }
                }
            }
        }
    }
}

void Udp_Thread::publishIEC104ReslovedDatas(QMap<QString, config::dataValue> resolveMap, QMap<int, config::publishNode> iec104_publishs, QString nodeName)
{
    for (auto &publishTemplate : iec104_publishs)
    {
        QMap<QString, QMap<QString, dataConfig>> dataConfigsOfPlcs = publishTemplate.publishDatas;
        if (dataConfigsOfPlcs.contains(nodeName))
        {
            QMap<QString, config::dataConfig> dataConfigsOfPlc = dataConfigsOfPlcs.value(nodeName);
            QList<QPair<int, float>> changeData_YC;
            QList<QPair<int, float>> changeData_YX;
            for (config::dataValue readData : resolveMap)
            {
                // int port = publishTemplate.port;
                // QString float_sort = publishTemplate.float_sort;
                if (dataConfigsOfPlc.contains(readData.var_name))
                {
                    config::dataConfig publishConfig = dataConfigsOfPlc.value(readData.var_name);
                    int modAddress = publishConfig.id;
                    float value = readData.value2;//不管是什么类型 统一发布成float类型
                    if (publishConfig.Type != "char")
                    {
                        // modAddress = modAddress * 2 + 1;

                        // if (publishConfig.RWmodle == "W")
                        // {
                        // LOG_ERROR("varName " + readData.var_name + " setHoldingRegisterValue modbus addres " + QString::number(modAddress) + " value" + QString::number(value));
                        //qDebug() << "W 104 insert port" << port << " modAddress " << modAddress << " value " << value;
                        //this->setHoldingRegisterValue(port, modAddress, value, "badc");
                        // }
                        // else
                        // {
                        //qDebug() << "R 104 insert port" << port << " modAddress " << modAddress << " value " << value;
                        //this->setInputRegisterValue(port, modAddress, value, "badc");
                        // }

                        if(ConfigManager::get_instance().m_ycAddrValue.contains(modAddress))
                        {
                            if (ConfigManager::get_instance().m_ycAddrValue[modAddress] == value)
                            {
                                //LOG_DEBUG(QString("the yc data no change!address:%1,value:%2").arg(address).arg(value));
                            }
                            else
                            {
                                changeData_YC.append({modAddress,value});
                                // 数据不相等
                                ConfigManager::get_instance().m_ycAddrValue[modAddress] = value;
                                // iec104->sendYC(address, value);
                                LOG_INFO(QString("update yc Data to send!address:%1,value:%2").arg(modAddress).arg(value));
                            }
                            // compareYCData(modAddress,value);
                        }
                        else
                        {
                            // 数据不存在，插入新数据
                            ConfigManager::get_instance().m_ycAddrValue.insert(modAddress,value);
                        }
                        LOG_INFO(QString("save yc address:%1,fValue:%2").arg(modAddress).arg(value));
                    }
                    else
                    {
                        // uint8_t valueCoil = (uint8_t)readData.value2;
                        // if (publishConfig.RWmodle == "W")
                        // {
                        //uint8_t valueCoil = (uint8_t)readData.value2;
                        //this->setCoil(port, modAddress, valueCoil);
                        // }
                        // else
                        // {
                        //this->setInputCoil(port, modAddress, valueCoil);
                        // }

                        if(ConfigManager::get_instance().m_yxAddrValue.contains(modAddress))
                        {
                            if (ConfigManager::get_instance().m_yxAddrValue[modAddress] == value)
                            {
                                //LOG_DEBUG(QString("the yx data no change!address:%1,value:%2").arg(address).arg(value));
                            }
                            else
                            {
                                changeData_YX.append({modAddress,value});
                                // 数据不相等
                                ConfigManager::get_instance().m_yxAddrValue[modAddress] = value;
                                // iec104->sendYC(address, value);
                                LOG_INFO(QString("update yx Data to send!address:%1,value:%2").arg(modAddress).arg(value));
                            }
                            // compareYCData(modAddress,value);
                        }
                        else
                        {
                            // 数据不存在，插入新数据
                            ConfigManager::get_instance().m_yxAddrValue.insert(modAddress,value);
                        }
                        LOG_INFO(QString("save yx address:%1,fValue:%2").arg(modAddress).arg(value));
                    }
                }
            }
            // while (mainwindow->iec104->m_shouldRun) {
            //     mainwindow->iec104->m_condition.wait(&mutex);
            //     // 线程在这里被阻塞，直到被唤醒或者m_shouldRun为false
            // }
            emit sendYC1(changeData_YC);
            emit sendYX1(changeData_YX);
        }
    }
}

bool Udp_Thread::setHoldingRegisterValue(int port, int registerStartaddress, float Value, QString sort) {
    if (registerStartaddress > (mainwindow->m_numRegisters - 2)) {
        return false;
    }
    mainwindow->slavemutex.lock();

    modbus_mapping_t *mapping = mainwindow->MODBUSmappings.value(port);
    // qDebug() << "insert port" << QString::number(port) << "address " << QString::number(registerStartaddress) << " value " << QString::number(Value);
    switch (sort[0].toLatin1()) {
    case 'a':
        modbus_set_float_abcd(Value, &mapping->tab_registers[registerStartaddress]);
        break;
    case 'b':
        modbus_set_float_badc(Value, &mapping->tab_registers[registerStartaddress]);
        break;
    case 'c':
        modbus_set_float_cdab(Value, &mapping->tab_registers[registerStartaddress]);
        break;
    case 'd':
        modbus_set_float_dcba(Value, &mapping->tab_registers[registerStartaddress]);
        break;

    }
    mainwindow->slavemutex.unlock();
    return true;
}

bool Udp_Thread::setInputRegisterValue(int port, int registerStartaddress,float Value, QString sort) {
    if (registerStartaddress > (mainwindow->m_numRegisters - 2)) {
        return false;
    }
    /*??????*/
    mainwindow->slavemutex.lock();
    modbus_mapping_t *mapping = mainwindow->MODBUSmappings.value(port);
    switch (sort[0].toLatin1()) {
    case 'a':
        modbus_set_float_abcd(Value, &mapping->tab_input_registers[registerStartaddress]);
        break;
    case 'd':
        modbus_set_float_dcba(Value, &mapping->tab_input_registers[registerStartaddress]);
        break;
    case 'b':
        modbus_set_float_badc(Value, &mapping->tab_input_registers[registerStartaddress]);
        break;
    case 'c':
        modbus_set_float_cdab(Value, &mapping->tab_input_registers[registerStartaddress]);
        break;
    }
    // modbus_set_float_abcd(Value, &mapping->tab_input_registers[registerStartaddress]);
    mainwindow->slavemutex.unlock();

    return true;
}

bool Udp_Thread::setCoil(int port, int coilStartaddress, uint8_t status)
{
    modbus_mapping_t *mapping =  mainwindow->MODBUSmappings.value(port);
    if (coilStartaddress > (mainwindow->m_numBits)) {
        return false;
    }
    int startBits = mapping->start_bits;
    int mapping_address = coilStartaddress - startBits;
    if (mapping_address < 0 || mapping_address >= mapping->nb_bits) {
    } else {

        mapping->tab_bits[mapping_address] = status ? ON : OFF;
    }
    return true;
}

bool Udp_Thread::setInputCoil(int port, int coilStartaddress,uint8_t status) {
    modbus_mapping_t *mapping =  mainwindow->MODBUSmappings.value(port);
    if (coilStartaddress > (mainwindow->m_numBits)) {
        return false;
    }
    int startBits = mapping->start_input_bits;
    int mapping_address = coilStartaddress - startBits;
    if (mapping_address < 0 || mapping_address >= mapping->nb_input_bits) {
    } else {
        mapping->tab_input_bits[mapping_address] = status ? ON : OFF;
    }
    return true;
}

