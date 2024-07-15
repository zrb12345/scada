#include "mainwindow.h"
#include <beckhoffmanager.h>
#include <mylogger.h>
#include <QAbstractItemDelegate>
#include <QButtonGroup>
#include <QCheckBox>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QTcpSocket>
#include <QThreadPool>
#include <csignal>
#include "configmanager.h"
#include "tcpmanager.h"
#include "ui_mainwindow.h"
#include "qdom.h"
#include <QModbusTcpClient>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QModbusServer>
#include "xochange.h"
#include "qiec104slave.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
#ifdef linux
    signal(SIGPIPE, SIG_IGN);
#endif

    ui->setupUi(this);
    MyLogger::getInstance();
    readConfigs();
    //执行modbus协议部分第一步 连接指定ip和端口的从站
    QThreadPool::globalInstance()->setMaxThreadCount(1000);
    ConfigManager &configInstance = ConfigManager::get_instance();
    std::string host = configInstance.m_publishIp.toStdString();
    localAddress = Xochange::getLocalAdrdress(3);
    if (!host.empty()) {
        QMap<int, config::publishNode> modbusPublishs =  configInstance.m_publishConfigs.value("modbus");
        tcpSocket = new QTcpSocket(this);
        tcpSocket->connectToHost(localAddress, configInstance.m_nodeConfig.control_port);
        for (QMap<int, config::publishNode>::iterator it = modbusPublishs.begin(); it != modbusPublishs.end(); it++)
        {
            modbus_mapping_t *mapping = modbus_mapping_new(60000, 60000, 60000, 60000);
            MODBUSmappings.insert(it.key(), mapping);
            //abcd  是getByteFromFloat获取到的；通过modbus_set_float_badc方法转化为 badc
            // ba 一个寄存器 dc一个寄存器 存放到 1 和 2 中
            RDSModbusSlaveThread   *m_rdsModbusSlaveThread = new RDSModbusSlaveThread(it.key(), mapping);
            m_rdsModbusSlaveThread->start();
        }
        QMap<int, config::publishNode> IEC104Publishs =  configInstance.m_publishConfigs.value("IEC104");
        for (QMap<int, config::publishNode>::iterator it2 = IEC104Publishs.begin(); it2 != IEC104Publishs.end(); it2++)
        {
            modbus_mapping_t *mapping = modbus_mapping_new(60000, 60000, 130000, 130000);
            MODBUSmappings.insert(it2.key(), mapping);
            config::publishNode values = it2.value();
            QMap<QString, QList<int> >typeAddress;
            QList<int> charList;
            QList<int>  inputCharList;
            QList<int>  floatList;
            QList<int>  inputFloatList;

            QMap<QString, QString> siyaoType;
            QMap<QString, QMap<QString, dataConfig>> publishDatas = values.publishDatas;
            siyaoType.insert("yx", values.yx_type);
            siyaoType.insert("yk", values.yk_type);
            siyaoType.insert("yc", values.yc_type);
            siyaoType.insert("yd", values.yd_type);
            for (QMap<QString, QMap<QString, dataConfig>>::iterator it = publishDatas.begin(); it != publishDatas.end(); it++)
            {
                QMap<QString, dataConfig> dataConfigs =  it.value();
                for (auto item : dataConfigs)
                {
                    if (item.IEC104Type == "yx")
                    {
                        inputCharList.append(item.id);
                    }
                    else if (item.IEC104Type == "yk")
                    {
                        charList.append(item.id);
                    }
                    else if (item.IEC104Type == "yc")
                    {
                        int id =  item.id;
                        id = id * 2 + 1;
                        inputFloatList.append(id);
                    }
                    else if (item.IEC104Type == "yd")
                    {
                        int id =  item.id;
                        id = id * 2 + 1;
                        floatList.append(id);
                    } else {
                        qDebug() << "type error is not in yx yk yc yd";
                    }
                }
            }

            charList =   Xochange:: sort(charList);
            inputCharList =   Xochange:: sort(inputCharList);
            floatList =   Xochange:: sort(floatList);
            inputFloatList =   Xochange:: sort(inputFloatList);
            typeAddress.insert("char", charList);
            typeAddress.insert("inputChar", inputCharList);
            typeAddress.insert("float", floatList);
            typeAddress.insert("inputFloat", inputFloatList);

            QIec104   *iec104 = new QIec104(it2.key(), it2.value().publishDatas, this, mapping, typeAddress);
            // iec104s.insert(it2.key(), iec104);

        }
        recieveUDPMsg();
    } else {
        LOG_ERROR("modbus publish not begin ,no host ");
    }
}





MainWindow::~MainWindow() {
    for (QMap<int, modbus_mapping_t *>::iterator it = MODBUSmappings.begin(); it != MODBUSmappings.end(); it++) {
        modbus_mapping_t *mapping = it.value();
        modbus_mapping_free(mapping);
    }
    if (m_futureWatchers.size()) {
        int i = 0;
        for (auto &watcher : m_futureWatchers) {
            if (watcher) {
                QString logstr;
                QTextStream(&logstr) << "waitForFinished " << i << "is finishing";
                LOG_INFO(logstr);
                while (!watcher->isRunning()) {
                    logstr = "";
                    QTextStream(&logstr) << "watcher is not running;";
                }
                emit watcher->canceled();
                logstr = "";
                QTextStream(&logstr) << i << " has emit cancel signal";
                LOG_INFO(logstr);
                watcher->waitForFinished();
                logstr = "";
                QTextStream(&logstr) << "waitForFinished " << i++ << "has finished";
                LOG_INFO(logstr);
                delete watcher;
                watcher = nullptr;
            }
        }
        QList<QFutureWatcher<void>*>().swap(m_futureWatchers);
    }

    if (m_buttons.size()) {
        for (auto &button : m_buttons) {
            button->deleteLater();
        }
        QList<QPushButton *>().swap(m_buttons);
    }
    if (m_plcTimerManagers.size()) {
        for (auto iter = m_plcTimerManagers.begin();
                iter != m_plcTimerManagers.end(); iter++) {
            //
            delete iter.value();
            iter.value() = nullptr;

            //删除迭代器元素先加加再删，否则迭代器失效程序崩溃！！！(必须iter++
            //不可以++ iter)
        }
        QMap<QString, PlcTimerManager *>().swap(m_plcTimerManagers);
    }
    if (m_ModBusManagers.size())
    {
        for (auto modbus = m_ModBusManagers.begin(); modbus != m_ModBusManagers.end(); modbus++)
        {
            delete modbus.value();
            modbus.value() = nullptr;
        }
        QMap<QString, ModbusManager *>().swap(m_ModBusManagers);

    }
    if (m_zipWriterTimer) {
        m_zipWriterTimer->deleteLater();
        m_zipWriterTimer = nullptr;
    }
    delete ui;
    LOG_INFO("Program ending");
}
void MainWindow::showDialog(int port, int id, short value)
{
    // QDialog *dialog = new QDialog(this);
    QString ports = QString::number(port);
    QString ids = QString::number(id);
    QString values = QString::number(value);
    QString title = "从站遥控返校";
    QString str = "是否执行 遥控返校 归一化值设置 公共地址: ";
    str.append(ports);
    str.append("\n点号: ");
    str.append(ids);
    str.append("值: ");
    str.append(values);
    int ret1 = QMessageBox::information(this, title, str, QMessageBox::Yes, QMessageBox::No);
    if (ret1 == QMessageBox::Yes) {
        id = id * 2 + 1;
        setInputRegisterValue(port, id, value, "bdca");
        qDebug() << "确认返校了 " << port << " id " << id << " value " << value;
    }
    else
    {
        qDebug() << "取消返校了 ";
    }
}

bool MainWindow::readConfigs() {
    ConfigManager &config = ConfigManager::get_instance();

    QString config_dir = QCoreApplication::applicationDirPath() + "/config/";
    QString log;
    QTextStream(&log) << "xml配置文件所在目录:" << config_dir;
    LOG_INFO(log);
    QString node_path = config_dir + "node.xml";
    QString data_path = config_dir + "data.xml";
    QString publish_path = config_dir + "publish.xml";

    config.readNodeConfig(node_path);
    config.readDataConfig(data_path);
    config.readPublishConfig(publish_path);
    config.readDataConfigSorted(data_path);

    m_controllerport = config.m_nodeConfig.control_port;
    m_historyPath = config.m_nodeConfig.path;
    m_pcs = config.m_nodeConfig.pc_configs;
    return true;
}

void MainWindow::setRowColor(int row, QStandardItemModel *model) {
    int cols = model->columnCount();
    for (int i = 0; i < cols; i++) {
        QBrush brush(Qt::red);
        model->setData(model->index(row, i), brush, Qt::BackgroundRole);
    }
}



bool MainWindow::eventFilter(QObject *obj, QEvent *ev) {
    /*判断发生事件的是否为主窗口*/
    if (obj == this) {
        /*判断事件的类型是否为关闭事件*/
        if (ev->type() == QEvent::Close) {
            qApp->quit();  // 主窗口关闭事件,程序退出,其他窗口将被关闭
            return true;  // 返回true代表事件已被处理不需要向下传递，返回false代表事件未被处理需要向下传递由别的组件处理
        } else if (ev->type() == QEvent::Show) {
            QString log;
            QTextStream(&log) << "thread num:"
                              << QThreadPool::globalInstance()->activeThreadCount();
            LOG_INFO(log);
        }
    }
    /*不是我们关心的事件，交由QMainWindow的事件过滤器处理*/
    return QMainWindow::eventFilter(obj, ev);
}

//执行此方法可以让template_4里面的所有节点的var_name唯一
void MainWindow::updateXmlFileSameVarName() {
    qDebug() << "开始修改";
    QString config_dir = QCoreApplication::applicationDirPath() + "/config/";
    QString node_path = config_dir + "data.xml";
    QFile file(node_path);
    QDomDocument doc;
    if (!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::information(this, tr("错误"), tr("data打开失败"));
        return;
    }
    QString errorStr;  //出错的原因
    int errorLine;  //出错的行
    int errorCol;   //出错的列
    if (!doc.setContent(&file, true, &errorStr, &errorLine, &errorCol))
    {
        qDebug() << errorStr << "line: " << errorLine << "col: " << errorCol;
        QMessageBox::information(this, tr("错误"), tr("读取错误"));
        file.close();
        return;
    }
    file.close();
    QDomElement docElem = doc.documentElement();
    QDomNode firstNode = docElem.firstChild();   //返回根节点的第一个子节点
    QMap<QString, int> varNamecounts;
    int index = 0;
    int address = 0;
    while (!firstNode.isNull()) //若是节点不为空
    {
        if (firstNode.toElement().tagName() == "node" && firstNode.toElement().attribute("template") == "template_4")
        {
            QDomNode tempData = firstNode.firstChild();
            while (!tempData.isNull())
            {

                //如果节点是元素
                if (tempData.isElement())
                {
                    index += 1;

                    //将其转换为元素
                    QDomElement targetdata = tempData.toElement();
                    QString varName = targetdata.attribute("var_name");
                    address++;
                    if (address > 900) {
                        qDebug() << "type 2" << targetdata.attribute("type");
                    }
                    if (!varNamecounts.contains(varName))
                    {
                        varNamecounts.insert(varName, 1);
                    } else {
                        int count = varNamecounts.value(varName);
                        varNamecounts.insert(varName, count + 1);
                        QString temp = "_";
                        QString stringValue = QString::number(count + 1);
                        QString newName = temp.append(stringValue);
                        targetdata.setAttribute("var_name", varName.append(newName));
                    }
                }
                //下一个兄弟节点
                tempData = tempData.nextSibling();
            }
        }
        firstNode = firstNode.nextSibling();  //下一个兄弟节点
    }
    QString node_path1 = config_dir + "data.xml";
    QFile file1(node_path1);
    file1.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream out_stream(&file1);
    doc.save(out_stream, 4);
    file1.close();
    qDebug() << "修改结束";
}
void MainWindow:: recieveUDPMsg()
{
    QUdpSocket *udpSocket = new QUdpSocket();

    int localPort;
    QHostAddress localAddress;
    int indexip = 0;
    foreach (QHostAddress ptr, QNetworkInterface::allAddresses())
    {
        if (ptr.protocol() == QAbstractSocket::IPv4Protocol) {
            if (!ptr.isLoopback()) {
                localAddress = ptr;
                indexip ++;
                if (indexip == 3) {
                    break;
                }
            }
        }
    }
    for (auto pc : ConfigManager::get_instance().m_nodeConfig.pc_configs)
    {
        if (pc.ip == localAddress.toString())
        {
            localPort = pc.port;
            break;
        };
    }
    qDebug() << "localPort " << QString::number(localPort);

    if (!udpSocket->bind(localAddress, localPort)) {
        qDebug() << "Failed to bind UDP socket Ip : " << localAddress.toString() << " port " << localPort;
    } else {
        qDebug() << "success to bind UDP socket Ip : " << localAddress.toString() << " port " << localPort;
    }
    connect(udpSocket, &QUdpSocket::readyRead, [ = ]()
    {
        ConfigManager &configInstance = ConfigManager::get_instance();
        while (udpSocket->hasPendingDatagrams()) {
            QByteArray udpData;
            udpData.resize(udpSocket->pendingDatagramSize());
            udpSocket->readDatagram(udpData.data(), udpData.size());
            // qDebug() << "received msg " << udpData.toHex().toUpper();
            if (udpData.length() < 17)
            {
                return;
            }
            QList<config::dataConfig> datas;
            QString nodeName;
            QString templateName ;


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
                int lenofbayte = len4 << 24 | len3 << 16 | len2 << 8 | len1;
                int startAddr = udpData.length() - lenofbayte ;
                if (startAddr == udpData.length() - 1)
                {
                    return;
                }

                QMap<const QString, size_t> type_map = {
                    {"bool", 1},  {"char", 1},   {"ushort", 2},   {"uint16", 2}, {"int16", 2},
                    {"short", 2}, {"uint", 4},   {"int", 4},      {"dint", 4},   {"udint", 4},
                    {"float", 4}, {"double", 8}, {"STRING", 255},
                };
                QMap<QString, config::dataValue> resolveMap;
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

                    if (type_size == 1) {
                        //风机状态点的值为1 就设1 其他的就是0
                        // qDebug() << "StartAddr " << startAddr << "item.var_name " << item.var_name;
                        int byte1char = (uchar) udpData[startAddr];
                        item.value2 = byte1char;
                    }
                    if (type_size == 2) {
                        int byte1int = (uchar)udpData[startAddr];
                        int byte2int = (uchar)udpData[startAddr + 1];
                        item.value2 = byte2int << 8 | byte1int;
                    }
                    if (type_size == 4) {
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
                    if (type_size == 8) {//double类型的数据暂时不发布 都设置为0
                        item.value2 = 0;
                    }
                    resolveMap.insert(item.var_name, item);
                    startAddr += type_size;
                }
                QMap<QString, QMap<int, config::publishNode>> publishs = configInstance.m_publishConfigs;
                QMap<int, config::publishNode> modbus_publishs = publishs.value("modbus");
                QMap<int, config::publishNode> IEC104_publishs = publishs.value("IEC104");
                publishModbusReslovedDatas(resolveMap, modbus_publishs, nodeName);
                publishIEC104ReslovedDatas(resolveMap, IEC104_publishs, nodeName);
            }
        }
    });
}

bool MainWindow::setHoldingRegisterValue(int port, int registerStartaddress,
        float Value, QString sort) {
    if (registerStartaddress > (m_numRegisters - 2)) {
        return false;
    }
    slavemutex.lock();

    modbus_mapping_t *mapping = MODBUSmappings.value(port);
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
    slavemutex.unlock();
    return true;
}


bool MainWindow::setInputRegisterValue(int port, int registerStartaddress,
                                       float Value, QString sort) {
    if (registerStartaddress > (m_numRegisters - 2)) {
        return false;
    }
    /*??????*/
    slavemutex.lock();
    modbus_mapping_t *mapping = MODBUSmappings.value(port);
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
    slavemutex.unlock();

    return true;
}
bool MainWindow::setCoil(int port, int coilStartaddress, uint8_t status)
{
    modbus_mapping_t *mapping =  MODBUSmappings.value(port);
    if (coilStartaddress > (m_numBits)) {
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
bool MainWindow::setInputCoil(int port, int coilStartaddress,
                              uint8_t status) {
    modbus_mapping_t *mapping =  MODBUSmappings.value(port);
    if (coilStartaddress > (m_numBits)) {
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
void MainWindow:: publishModbusReslovedDatas(QMap<QString, config::dataValue> resolveMap, QMap<int, config::publishNode> modbus_publishs, QString nodeName)
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
                            // LOG_ERROR("varName " + readData.var_name + " setHoldingRegisterValue modbus addres " + QString::number(modAddress) + " value" + QString::number(value));
                            // qDebug() << "set holdingRegister port" << QString::number(port) << " address" << QString::number(modAddress) << " value" << QString::number(value);
                            this->setHoldingRegisterValue(port, modAddress, value, float_sort);
                        }
                        else
                        {
                            // LOG_ERROR("varName " + readData.var_name + " setInputRegisterValue modbus addres " + QString::number(modAddress) + " value" + QString::number(value));
                            this->setInputRegisterValue(port, modAddress, value, float_sort);
                        }
                    } else {
                        if (publishConfig.RWmodle == "W")
                        {
                            uint8_t valueCoil = (uint8_t)readData.value2;
                            this->setCoil(port, modAddress, valueCoil);
                        }
                        else
                        {
                            uint8_t valueCoil = (uint8_t)readData.value2;
                            this->setInputCoil(port, modAddress, valueCoil);

                        }
                    }
                }
            }
        }
    }
}
void MainWindow:: publishIEC104ReslovedDatas(QMap<QString, config::dataValue> resolveMap, QMap<int, config::publishNode> iec104_publishs, QString nodeName)
{
    for (config::dataValue readData : resolveMap)
    {
        for (auto &publishTemplate : iec104_publishs)
        {
            int port = publishTemplate.port;
            // QString float_sort = publishTemplate.float_sort;
            QMap<QString, QMap<QString, dataConfig>> dataConfigsOfPlcs = publishTemplate.publishDatas;
            if (dataConfigsOfPlcs.contains(nodeName))
            {
                QMap<QString, config::dataConfig> dataConfigsOfPlc = dataConfigsOfPlcs.value(nodeName);
                if (dataConfigsOfPlc.contains(readData.var_name))
                {
                    config::dataConfig publishConfig = dataConfigsOfPlc.value(readData.var_name);
                    int modAddress = publishConfig.id;
                    float value = readData.value2;//不管是什么类型 统一发布成float类型
                    if (publishConfig.Type != "char")
                    {
                        int handledAddr = modAddress * 2 + 1;
                        if (publishConfig.RWmodle == "W")
                        {
                            // LOG_ERROR("varName " + readData.var_name + " setHoldingRegisterValue modbus addres " + QString::number(modAddress) + " value" + QString::number(value));
                            // qDebug() << " insert port" << port << " modAddress " << modAddress << " value " << value;
                            this->setHoldingRegisterValue(port, handledAddr, value, "badc");
                        }
                        else
                        {
                            // qDebug() << " insert port" << port << " handledAddr " << handledAddr << " value " << value;
                            this->setInputRegisterValue(port, handledAddr, value, "badc");
                        }
                    } else {
                        if (publishConfig.RWmodle == "W")
                        {
                            uint8_t valueCoil = (uint8_t)readData.value2;
                            this->setCoil(port, modAddress, valueCoil);
                        }
                        else
                        {
                            uint8_t valueCoil = (uint8_t)readData.value2;
                            this->setInputCoil(port, modAddress, valueCoil);

                        }
                    }
                }
            }
        }
    }
}
void MainWindow:: controlback(QString ip, QByteArray msg) {
    QTcpSocket *tcpSocketBack = new QTcpSocket(this);
    tcpSocketBack->connectToHost(ip, m_controllerport);
    int res = tcpSocketBack->write(msg);
    if (res)
    {
        qDebug() << " write success ip : " << ip << "m_controllerport" << m_controllerport << " msg " << msg;
    }
}
