#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <StructAndEnum.h>
#include <singleton.h>
#include <QMap>
#include <QString>
#include <map>
#include <string>
using namespace config;

class ConfigManager : public Singleton<ConfigManager> {
public:
    ConfigManager(token) {};
    ~ConfigManager() {
        QMap<QString, QMap<QString, QPair<int, config::dataConfig>>>().swap(
            m_dataConfigs);
    };
    ConfigManager(const ConfigManager &) = delete;
    ConfigManager &operator=(const ConfigManager &) = delete;

public:
    //读取采集点数据配置信息
    void readDataConfig(QString &path);
    //读取发布点表配置信息
    void readPublishConfig(QString &path);
    //根据顺序对采集点配置信息排序，用list存储，然后用template_name做key存在qmap中
    void readDataConfigSorted(QString &path);
    //读取节点数据配置信息
    void readNodeConfig(QString &path);

    config::nodeConfig m_nodeConfig;
    QMap<QString, QMap<QString, QPair<int, config::dataConfig>>> m_dataConfigs;
    QMap<QString, QMap<int, config::publishNode>>m_publishConfigs;
    //只有节点顺序排序的dataconfig 便于modbus处理数据
    QMap<QString, QList<config::dataConfig>> m_dataConfigsSorted;
    //  QMap<QString, dataConfig> m_dataMapConfigs;
    QString m_publishIp;
    QString m_masterIp;

private:
    //从xml文件读取节点相关信息
    void readNodeConfigfromXML(QString &path);
};

#endif  // CONFIGMANAGER_H
