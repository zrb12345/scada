#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include <StructAndEnum.h>
#include <singleton.h>
#include <QFile>
#include <map>
#include <string>

class XmlManager : public Singleton<XmlManager> {
public:
    XmlManager(token) {};
    ~XmlManager() {};
    XmlManager(const XmlManager &) = delete;
    XmlManager &operator=(const XmlManager &) = delete;

public://第一个QString template_name 第二个QString data.xml里面节点的 var_name
    QMap<QString, QMap<QString, QPair<int, config::dataConfig>>> loadDataXmlFile(QFile &file);
    QMap<QString, QMap<int, config::publishNode>>loadPublishXmlFile(QFile &file, QString *publishIp, QString *masterIp, config::nodeConfig m_nodeConfig);
    QMap <QString, QList<config::dataConfig>>loadDataXmlFileForModbusSorted(QFile &file) ;
    config::nodeConfig loadNodeXmlFile(QFile &file);
};

#endif  // XMLMANAGER_H
