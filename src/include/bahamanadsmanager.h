#ifndef BAHAMANADSMANAGER_H
#define BAHAMANADSMANAGER_H
#include <StructAndEnum.h>

#include <map>
#include "m1com/m1com.h"
#ifdef linux
    typedef unsigned char BYTE;
    typedef BYTE *PBYTE;
#endif
using namespace config;
struct BhmAdsVariables {
    int varcount;
    QList<M1C_H_VARIABLE> variablesHands;
    QList<config::dataValue> varValues;
    QList<VARIABLE_BUFFER> buffers;
};



class BahamanAdsManager {
public:
    BahamanAdsManager();
    ~BahamanAdsManager();

    QList<config::dataValue> ReadVariables(
        BhmAdsVariables &bhmAdsVariables,
        QPair<QString, QList<dataValue>> lastTimeData,BhmAdsVariables &bhmAlarmVariables);
    void WriteVariables(QMap<QString, QPair<int, config::dataConfig>> &datas,
                        plcConfig &controllerInfo,
                        QStringList var_name,
                        QStringList value);

    BhmAdsVariables initVariables(
        QMap<QString, QPair<int, config::dataConfig>> datas,
        plcConfig &controllerInfo);
    int m_adsErrorCode = 0;
    int m_firstAlarm_index = 0;
    double m_firstAlarm_status = 0;
    int m_controllerStatus_index = 0;
    //    QList<TDataPar>m_dataPar;

    plcConfig m_controllerInfobhm;
    M1C_H_TARGET m_targetHandle = nullptr;
    QMap<QString, M1C_H_VARIABLE> m_variableNameMap;
    //在读取之后和之前的数据比较,如果发生了改变就设置为false
    bool m_isEqual = true;
    double m_controller_status = 3;
    QMap<QString, double> m_errorNodes;
    QMap<QString, config::dataValue> m_AlarmNodes;
    QMap<QString, QPair<int,config::dataConfig>> m_alarmsMap;
    //  BhmAdsVariables m_bhmAdsVariables;
    BhmAdsVariables empty(QMap<QString, QPair<int, config::dataConfig>> datas);

    int getControllerStatus(QString var_name, double value);

    int getControllerErrorStatus(QMap<QString, double> errorNodes);
    int IsErrorNode(QString var_name);

    double getAlarmId(BhmAdsVariables &bhmAlarmVariables);
    BhmAdsVariables initAlarmVariables(plcConfig &controllerInfo);
private:
    template <typename T>
    T byte2T(PBYTE buffer);
};

#endif  // BAHAMANADSMANAGER_H
