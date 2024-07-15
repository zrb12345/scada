#include "include/configmanager.h"

#include <xmlmanager.h>
#include <QDebug>
#include <QFileInfo>
#include <QMimeDatabase>
#include <QMimeType>
#include <iostream>

void ConfigManager::readNodeConfigfromXML(QString &path) {
    QFile file;  // 需要打开的文件

    file.setFileName(path);
    auto &xml = XmlManager::get_instance();
    m_nodeConfig = xml.loadNodeXmlFile(file);
}

void ConfigManager::readDataConfig(QString &path) {
    QFile file;  // 需要打开的文件
    file.setFileName(path);
    XmlManager &xml = XmlManager::get_instance();
    m_dataConfigs = xml.loadDataXmlFile(file);
    // LOG_DEBUG("success";
}
//发布点表的配置额外再搞一个publish.xml
void ConfigManager::readPublishConfig(QString &path) {
    QFile file;  // 需要打开的文件
    file.setFileName(path);
    XmlManager &xml = XmlManager::get_instance();
    QString publishIp = "";
    QString masterIp = "";
    m_publishConfigs = xml.loadPublishXmlFile(file, &publishIp, &masterIp, m_nodeConfig);
    m_publishIp = publishIp;
    m_masterIp = masterIp;
// LOG_DEBUG("success";
}
void ConfigManager::readDataConfigSorted(QString &path) {
    QFile file;  // 需要打开的文件
    file.setFileName(path);
    XmlManager &xml = XmlManager::get_instance();
    m_dataConfigsSorted = xml.loadDataXmlFileForModbusSorted(file);
    // LOG_DEBUG("success";
}
// 读取配置文件 nodeconfig
void ConfigManager::readNodeConfig(QString &path) {
    QMimeDatabase db;
    QMimeType mime = db.mimeTypeForFile(QFileInfo(path));
    if ((mime.name() == "application/xml") || (mime.name() == "text/xml")) {
        readNodeConfigfromXML(path);
    }
    // LOG_DEBUG("success";
}
