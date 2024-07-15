#include "xmlmanager.h"
#include <QDebug>
#include <QFile>
#include <QString>
#include <QXmlStreamReader>
QMap<QString, QMap<QString, QPair<int, config::dataConfig>>>
XmlManager::loadDataXmlFile(QFile &file) {
    QString nodename;  // 节点的名字
    QMap<QString, QMap<QString, QPair<int, config::dataConfig>>> template_datas;

    // 查找xml文件的路径
    if (!file.exists()) {
        LOG_DEBUG("xml文件不存在");
    } else {
        LOG_DEBUG("xml文件存在");
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))  // 打开文件
    {
        LOG_DEBUG("打开文件失败!");
    } else {
        QXmlStreamReader xmlreader(&file);  // 读取xml文件的迭代器
        LOG_DEBUG("xml文件存在,且打开文件成功!");

        while (!xmlreader.atEnd() ||
                !xmlreader.hasError())  // 当文件没有结束且没有出错执行下面的代码
        {
            xmlreader.readNextStartElement();  // 找到非根节点下的第一个子节点
            nodename = xmlreader.name().toString();  // 第一个子节点Data

            if ((nodename == "node") &&
                    xmlreader.isStartElement())  // 如果是第一个子节点的开始执行下列代码
            {
                QString template_name =
                    xmlreader.attributes().value("template").toString();
                nodename = xmlreader.name().toString();
                QMap<QString, QPair<int, config::dataConfig>> datas;
                int index = 0;
                while (!(nodename == "node" &&
                         xmlreader.isEndElement()))  // 如果子节点中的内容没有结束
                {
                    xmlreader.readNextStartElement();
                    nodename = xmlreader.name().toString();
                    if (!xmlreader.isStartElement()) {
                        //            LOG_DEBUG("false >>>>> " << nodename
                        //                     << xmlreader.isStartElement();
                    } else {
                        config::dataConfig data;
                        data.Type = xmlreader.attributes().value("type").toString();
                        // data.modAddress =
                        // xmlreader.attributes().value("modAddress").toInt();
                        data.RWmodle = xmlreader.attributes().value("RWmodle").toString();
                        data.Module = xmlreader.attributes().value("module").toString();
                        data.var_name = xmlreader.attributes().value("var_name").toString();
                        data.plc_name = xmlreader.attributes().value("plc_name").toString();
                        data.chinese_name =
                            xmlreader.attributes().value("chinese_name").toString();
                        data.factor =
                            xmlreader.attributes().value("factor").toDouble()
                            ? xmlreader.attributes().value("factor").toDouble()
                            : 1;
                        data.alarm_id = xmlreader.attributes().value("alarm_id").toString();
                        data.alarm_level =
                            xmlreader.attributes().value("alarm_level").toInt();
                        if (datas.contains(data.var_name)) {
                            qDebug() << "var_name重复了。" << data.var_name;
                            LOG_DEBUG(QString("var_name:%1重复了。").arg(data.var_name));
                        }
                        datas.insert(data.var_name, qMakePair(index++, data));
                    }
                }
                template_datas.insert(template_name, datas);
                QMap<QString, QPair<int, config::dataConfig>>().swap(datas);
            }
        }
    }
    file.close();
    return template_datas;
}
// QMap<QString, QMap<QString, QMap<QString, config::dataConfig>>>
QMap<QString, QMap<int, config::publishNode>> XmlManager::loadPublishXmlFile(QFile &file, QString *publishIp, QString *masterIp,  config::nodeConfig m_nodeConfig) {
    QString nodename;  // 节点的名字
    QString templateName;//modbus还是104
    QMap<int, config::publishNode> modbus_publish_datas;
    QMap<int, config::publishNode> IEC104_publish_datas;
    QMap<QString, QMap<int, config::publishNode>>res;

    // 查找xml文件的路径
    if (!file.exists()) {
        LOG_DEBUG("xml文件不存在");
    } else {
        LOG_DEBUG("xml文件存在");
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))  // 打开文件
    {
        LOG_DEBUG("打开文件失败!");
    } else {
        QXmlStreamReader xmlreader(&file);  // 读取xml文件的迭代器
        LOG_DEBUG("xml文件存在,且打开文件成功!");

        while (!xmlreader.atEnd() ||
                !xmlreader.hasError())  // 当文件没有结束且没有出错执行下面的代码
        {
            xmlreader.readNextStartElement();  // 找到非根节点下的第一个子节点
            nodename = xmlreader.name().toString();  // 第一个子节点Data
            templateName = xmlreader.attributes().value("template").toString();
            if ((nodename == "WINFARM_SCADA_SYSCFG") && xmlreader.isStartElement())
            {
                *publishIp = xmlreader.attributes().value("slaveIP").toString();
                *masterIp = xmlreader.attributes().value("controlIP").toString();
            }
            if ((nodename == "node") &&
                    xmlreader.isStartElement())  // 如果是第一个子节点的开始执行下列代码
            {
                int port =  xmlreader.attributes().value("port").toInt();
                nodename = xmlreader.name().toString();
                config::publishNode publishNode;
                QMap<QString, QMap<QString, config::dataConfig>> publishDatas;
                publishNode.float_sort = xmlreader.attributes().value("float_sort").toString();
                publishNode.short_sort = xmlreader.attributes().value("short_sort").toString();
                publishNode.yx_type = xmlreader.attributes().value("yx_type").toString();
                publishNode.yk_type = xmlreader.attributes().value("yk_type").toString();
                publishNode.yc_type = xmlreader.attributes().value("yc_type").toString();
                publishNode.yd_type = xmlreader.attributes().value("yd_type").toString();
                publishNode.port = xmlreader.attributes().value("port").toInt();
                while (!(nodename == "node" && xmlreader.isEndElement()))  // 如果子节点中的内容没有结束
                {
                    xmlreader.readNextStartElement();
                    nodename = xmlreader.name().toString();
                    if (!xmlreader.isStartElement()) {
                    } else {
                        config::dataConfig data; //modbusAddress
                        data.nodeName = xmlreader.attributes().value("nodeName").toString();
                        data.modAddress = xmlreader.attributes().value("modbusAddress").toInt();
                        data.id = xmlreader.attributes().value("id").toInt();
                        // LOG_ERROR("modAddress" + QString::number(data.modAddress));
                        // qDebug() << "id " << data.id;
                        data.Type = xmlreader.attributes().value("type").toString();
                        data.RWmodle = xmlreader.attributes().value("RWmodle").toString();
                        data.var_name = xmlreader.attributes().value("var_name").toString();
                        data.plc_name = xmlreader.attributes().value("plc_name").toString();
                        LOG_ERROR("varName" + data.var_name + " type "  + data.Type);
                        if (data.Type == "char")
                        {
                            if (data.RWmodle == "R")
                            {
                                data.IEC104Type = "yx";//遥信 char R
                            } else {
                                data.IEC104Type = "yk";//遥控 char W
                            }
                        } else {
                            if (data.RWmodle == "R")
                            {
                                data.IEC104Type = "yc";//遥测 float R
                            } else {
                                data.IEC104Type = "yd";//遥调 float W
                            }
                        }
                        for (QMap<QString, config::controllerConfig<config::beckhoffConfig>>::iterator it5 = m_nodeConfig.beckhoff_configs.begin();
                                it5 != m_nodeConfig.beckhoff_configs.end(); it5++)
                        {

                            config::controllerConfig<config::beckhoffConfig> itemtrue = it5.value();
                            if (itemtrue.name == data.nodeName)
                            {
                                data.nodeIp = it5.key();
                            }
                        }
                        for (QMap<QString, config::controllerConfig<config::plcConfig>>::iterator it6 = m_nodeConfig.plc_configs.begin();
                                it6 != m_nodeConfig.plc_configs.end(); it6++)
                        {

                            config::controllerConfig<config::plcConfig> itemtrue = it6.value();
                            if (itemtrue.name == data.nodeName)
                            {
                                data.nodeIp = it6.key();
                            }
                        }
                        for (QMap<QString, config::controllerConfig<config::modbusConfig>>::iterator it7 = m_nodeConfig.modbus_configs.begin();
                                it7 != m_nodeConfig.modbus_configs.end(); it7++)
                        {

                            config::controllerConfig<config::modbusConfig> itemtrue = it7.value();
                            if (itemtrue.name == data.nodeName)
                            {
                                data.nodeIp = it7.key();
                            }
                        }
                        if (!publishDatas.contains(data.nodeName))
                        {
                            QMap<QString, config::dataConfig> dataMapOfOneNode;
                            dataMapOfOneNode.insert(data.var_name, data);
                            publishDatas.insert(data.nodeName, dataMapOfOneNode);
                        } else {
                            QMap<QString, config::dataConfig> dataMapOfOneNode = publishDatas.value(data.nodeName);
                            dataMapOfOneNode.insert(data.var_name, data);
                            publishDatas.insert(data.nodeName, dataMapOfOneNode);
                        }
                    }
                }
                publishNode.publishDatas = publishDatas;
                if (templateName == "modbus") {
                    modbus_publish_datas.insert(port, publishNode);
                }
                if (templateName == "IEC104")
                {
                    IEC104_publish_datas.insert(port, publishNode);
                }
                QMap<QString, QMap<QString, config::dataConfig>>().swap(publishDatas);
            }
        }
    }
    file.close();
    res.insert("modbus", modbus_publish_datas);
    res.insert("IEC104", IEC104_publish_datas);
    return res;
}

QMap<QString, QList<config::dataConfig>>
XmlManager::loadDataXmlFileForModbusSorted(QFile &file) {
    QString nodename;  // 节点的名字
    QMap<QString, QList<config::dataConfig>> template_datas;
    // 查找xml文件的路径
    if (!file.exists()) {
        LOG_DEBUG("xml文件不存在");
    } else {
        LOG_DEBUG("xml文件存在");
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))  // 打开文件
    {
        LOG_DEBUG("打开文件失败!");
    } else {
        QXmlStreamReader xmlreader(&file);  // 读取xml文件的迭代器
        LOG_DEBUG("xml文件存在,且打开文件成功!");

        while (!xmlreader.atEnd() ||
                !xmlreader.hasError())  // 当文件没有结束且没有出错执行下面的代码
        {
            xmlreader.readNextStartElement();  // 找到非根节点下的第一个子节点
            nodename = xmlreader.name().toString();  // 第一个子节点Data

            if ((nodename == "node") &&
                    xmlreader.isStartElement())  // 如果是第一个子节点的开始执行下列代码
            {
                QString template_name =
                    xmlreader.attributes().value("template").toString();
                nodename = xmlreader.name().toString();
                QList<config::dataConfig> datas;
                int index = 0;
                while (!(nodename == "node" &&
                         xmlreader.isEndElement()))  // 如果子节点中的内容没有结束
                {
                    xmlreader.readNextStartElement();
                    nodename = xmlreader.name().toString();
                    if (!xmlreader.isStartElement()) {
                    } else {
                        config::dataConfig data;
                        data.Type = xmlreader.attributes().value("type").toString();
                        data.modAddress =
                            xmlreader.attributes().value("modbussAddress").toInt();
                        // qDebug() << " " <<
                        // xmlreader.attributes().value("var_name").toString() << " 的Type:
                        // " << xmlreader.attributes().value("type").toString();
                        data.RWmodle = xmlreader.attributes().value("RWmodle").toString();
                        data.Module = xmlreader.attributes().value("module").toString();
                        data.var_name = xmlreader.attributes().value("var_name").toString();
                        data.plc_name = xmlreader.attributes().value("plc_name").toString();
                        data.chinese_name =
                            xmlreader.attributes().value("chinese_name").toString();
                        data.factor =
                            xmlreader.attributes().value("factor").toDouble()
                            ? xmlreader.attributes().value("factor").toDouble()
                            : 1;
                        data.alarm_id = xmlreader.attributes().value("alarm_id").toString();
                        data.alarm_level =
                            xmlreader.attributes().value("alarm_level").toInt();
                        //            qDebug() << data.var_name << "index: " << index <<
                        // if (datas.contains(data.var_name)) {
                        // LOG_DEBUG(QString("var_name:%1重复了。").arg(data.var_name));
                        // }
                        datas.insert(index++, data);
                        // datas.push_back(data);
                        //            qDebug() << nodename <<
                        // xmlreader.isStartElement();
                    }
                }
                template_datas.insert(template_name, datas);
                datas.clear();
            }
        }
    }
    file.close();
    return template_datas;
}
config::nodeConfig XmlManager::loadNodeXmlFile(QFile &file) {
    QString nodename;  // 节点的名字
    config::nodeConfig node_config;
    QList<config::pcConfig> pc_configs;
    QMap<QString, config::controllerConfig<config::beckhoffConfig>> beckhoff_configs;
    QMap<QString, config::controllerConfig<config::plcConfig>> plc_configs;
    QMap<QString, config::controllerConfig<config::modbusConfig>> modbus_configs;
    if (!file.exists()) {
        // LOG_DEBUG("xml文件不存在";
    } else {
        // LOG_DEBUG("xml文件存在";
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))  // 打开文件
    {
        // LOG_DEBUG("打开文件失败!";
    } else {
        QXmlStreamReader xmlreader(&file);  // 读取xml文件的迭代器
        // LOG_DEBUG("xml文件存在,且打开文件成功!";

        while (!xmlreader.atEnd() ||
                !xmlreader.hasError())  // 当文件没有结束且没有出错执行下面的代码
        {
            xmlreader.readNextStartElement();  // 找到非根节点下的第一个子节点
            nodename = xmlreader.name().toString();  // 第一个子节点Data
            if ((nodename == "WINFARM_SCADA_SYSCFG") && xmlreader.isStartElement()) {
                int controlport = xmlreader.attributes().value("controlport").toInt();
                QString path = xmlreader.attributes().value("path").toString();
                node_config.control_port = controlport;
                node_config.path = path;
            }
            if ((nodename == "node") &&
                    xmlreader.isStartElement())  // 如果是第一个子节点的开始执行下列代码
            {
                config::controllerConfig<config::beckhoffConfig> beckhoff_data;
                config::controllerConfig<config::plcConfig> plc_data;
                // modbus 数据源 modbusConfig
                config::controllerConfig<config::modbusConfig> modbus_data;
                config::pcConfig pc_data;
                QString type = xmlreader.attributes().value("type").toString();
                nodename = xmlreader.name().toString();

                if (type == "pc") {
                    pc_data.name = xmlreader.attributes().value("name").toString();
                    pc_data.code = xmlreader.attributes().value("code").toInt();
                    pc_data.ip = xmlreader.attributes().value("ip").toString();
                    pc_data.port =
                        xmlreader.attributes().value("port").toString().toInt();
                    pc_configs.push_back(pc_data);
                } else if (type == "controller") {
                    QString plc_name = xmlreader.attributes().value("plc").toString();
                    QString name = xmlreader.attributes().value("name").toString();
                    QString ip = xmlreader.attributes().value("ip").toString();
                    QString template_name =
                        xmlreader.attributes().value("template").toString();
                    QString ztemplate =
                        xmlreader.attributes().value("zftemplate").toString();
                    int time = xmlreader.attributes().value("time").toInt();
                    int writeTime = xmlreader.attributes().value("writetime").toInt();
                    if (plc_name == "beckhoff") {  //
                        QString readType =
                            xmlreader.attributes().value("readType").toString();
                        QString netid = xmlreader.attributes().value("netid").toString();
                        QString username =
                            xmlreader.attributes().value("username").toString();
                        QString password =
                            xmlreader.attributes().value("password").toString();
                        int port = xmlreader.attributes().value("port").toInt();
                        beckhoff_data.plc_config.readType =
                            readType != "" ? readType : "simple";
                        beckhoff_data.name = name;
                        beckhoff_data.plc = plc_name;
                        beckhoff_data.template_name = template_name;
                        beckhoff_data.ztemplate_name = ztemplate;
                        beckhoff_data.plc_config.time = time ? time : 1000;
                        beckhoff_data.plc_config.writetime = writeTime ? writeTime : 60000;
                        beckhoff_data.plc_config.ip = ip;
                        beckhoff_data.plc_config.netid = netid;
                        beckhoff_data.plc_config.port = port;
                        beckhoff_data.plc_config.username =
                            username != "" ? username : "Administrator";
                        beckhoff_data.plc_config.password = password != "" ? password : "1";
                        beckhoff_configs.insert(ip, beckhoff_data);
                    } else if (plc_name == "Bachmann") {
                        QString username =
                            xmlreader.attributes().value("username").toString();
                        QString password =
                            xmlreader.attributes().value("password").toString();
                        plc_data.name = name;
                        plc_data.plc = plc_name;
                        plc_data.plc_config.ip = ip;
                        plc_data.template_name = template_name;
                        plc_data.ztemplate_name = ztemplate;
                        plc_data.plc_config.time = time ? time : 1000;
                        plc_data.plc_config.writetime = writeTime ? writeTime : 60000;
                        plc_data.plc_config.username =
                            username != "" ? username : "Administrator";
                        plc_data.plc_config.password = password != "" ? password : "1";
                        plc_configs.insert(ip, plc_data);
                    } else if (plc_name == "modbus") {
                        int port = xmlreader.attributes().value("port").toInt();
                        modbus_data.name = name;
                        modbus_data.plc = plc_name;
                        modbus_data.plc_config.ip = ip;
                        modbus_data.plc_config.port = port;
                        //寄存器的读取长度和起始地址还有float类型的节点数
                        modbus_data.plc_config.readnumRegister =
                            xmlreader.attributes().value("readnumRegister").toInt();
                        modbus_data.plc_config.startaddrRegister =
                            xmlreader.attributes().value("startaddrRegister").toInt();
                        modbus_data.plc_config.readnumFloatRegister =
                            xmlreader.attributes().value("readnumFloatRegister").toInt();
                        //只读寄存器的读取长度和起始地址
                        modbus_data.plc_config.readnumInputRegister =
                            xmlreader.attributes().value("readnumInputRegister").toInt();
                        modbus_data.plc_config.startaddrInputRegister =
                            xmlreader.attributes().value("startaddrInputRegister").toInt();
                        modbus_data.plc_config.readnumFloatInputRegister =
                            xmlreader.attributes().value("readnumFloatInputRegister").toInt();
                        //线圈的读取长度和起始地址
                        modbus_data.plc_config.readnumCoil =
                            xmlreader.attributes().value("readnumCoil").toInt();
                        modbus_data.plc_config.startaddrCoil =
                            xmlreader.attributes().value("startaddrCoil").toInt();
                        //只读线圈的读取长度和起始地址
                        modbus_data.plc_config.readnumInputCoil =
                            xmlreader.attributes().value("readnumInputCoil").toInt();
                        modbus_data.plc_config.startaddrInputCoil =
                            xmlreader.attributes().value("startaddrInputCoil").toInt();
                        modbus_data.template_name = template_name;
                        modbus_data.ztemplate_name = ztemplate;
                        modbus_data.plc_config.time = time ? time : 1000;
                        modbus_data.plc_config.writetime = writeTime ? writeTime : 60000;
                        modbus_data.port = port;
                        modbus_data.plc_config.slaveaddr =
                            xmlreader.attributes().value("slaveaddr").toInt();
                        // modbus_data.plc_config.portCoil = portCoil;
                        // modbus_data.plc_config.portRegister = portRegister;
                        modbus_configs.insert(ip, modbus_data);
                    }
                }
            }
            node_config.beckhoff_configs = beckhoff_configs;
            node_config.pc_configs = pc_configs;
            node_config.modbus_configs = modbus_configs;
            node_config.plc_configs = plc_configs;
        }
    }
    file.close();
    return node_config;
}
