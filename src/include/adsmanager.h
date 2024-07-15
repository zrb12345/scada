#ifndef ADSMANAGER_H
#define ADSMANAGER_H
//#define TEST
// clang-format off
#include <AdsLib.h>
#include <AdsDevice.h>

// clang-format on
#include <StructAndEnum.h>
#include <iostream>
#include <map>

#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) && !defined(__CYGWIN__)
#pragma comment(lib, "ws2_32.lib")
typedef struct dataPar {
  unsigned long indexGroup;   // index group in ADS server interface
  unsigned long indexOffset;  // index offset in ADS server interface
  unsigned long length;       // count of bytes to read
} TDataPar;
template <typename T>
struct dataParWrite {
  unsigned long indexGroup;   // index group in ADS server interface
  unsigned long indexOffset;  // index offset in ADS server interface
  unsigned long length;       // count of bytes to read
  T data;                     // count of bytes to read   2字节
};
#elif linux
typedef unsigned char BYTE;
typedef BYTE* PBYTE;
typedef struct dataPar {
  unsigned int indexGroup;   // index group in ADS server interface
  unsigned int indexOffset;  // index offset in ADS server interface
  unsigned int length;       // count of bytes to read
} TDataPar;
template <typename T>
struct dataParWrite {
  unsigned int indexGroup;   // index group in ADS server interface
  unsigned int indexOffset;  // index offset in ADS server interface
  unsigned int length;       // count of bytes to read
  T data;                    // count of bytes to read   2字节
};
#endif
using namespace config;

struct AdsVariables {
  QList<TDataPar> dataPars;
  QList<config::dataValue> varValues;
};

class AdsManager {
 public:
  AdsManager();
  ~AdsManager();
  AdsVariables empty(QMap<QString, QPair<int, config::dataConfig>> datas);
  static int addroute(beckhoffConfig& controllerInfo);
  void ReadVariables(beckhoffConfig& controllerInfo,
                     AdsVariables& adsVariables,
                     QPair<QString, QList<dataValue>> lastTimeData,
                     AdsVariables& alarmVariables);
  template <typename T>
  void WriteVariables(AdsDevice& device, dataParWrite<T> ataParWrites);
  template <typename T>
  int Write(const AdsDevice& device,
            const AdsHandle& handle,
            const char* const value);
  static QPair<QString, QString> CheckIP();
  AdsVariables initVariables(
      QMap<QString, QPair<int, config::dataConfig>> datas,
      beckhoffConfig controllerInfo);

  int getAlarmId(AdsVariables& alarmVariables);
  AdsVariables initAlarmVariables(beckhoffConfig& controllerInfo);
  AdsVariables initArrayVariables(
      QMap<QString, QPair<int, config::dataConfig>> datas,
      beckhoffConfig& controllerInfo);
  void initVariablesWrite(QMap<QString, QPair<int, config::dataConfig>> datas,
                          beckhoffConfig controllerInfo,
                          QStringList var_name,
                          QStringList value);
  void delLocalRoute();

  int m_adsErrorCode = 0;
  static uint16_t m_port;
  int m_addlocalRoute = 0;
  int m_firstAlarm_index = 0;
  int m_controllerStatus_index = 0;
  beckhoffConfig m_controllerInfo;
  AmsAddr m_Addr;
  AmsNetId m_netId;
  const char* m_ip = nullptr;
  double m_controller_status = 3;
  double m_firstAlarm_status = 0;
  bool m_isEqual = true;
  //  QMap<QString, config::dataConfig> m_dataConfigs;

  int getControllerErrorStatus(QMap<QString, double> errorNodes);
  int IsErrorNode(QString var_name);
  QMap<QString, double> m_errorNodes;
  QMap<QString, QPair<int, config::dataConfig>> m_alarmsMap;
  QMap<QString, QPair<int, config::dataConfig>> m_ArrayMap;
  QMap<int, config::dataValue> m_AlarmNodes;
  QMap<QString, QMap<int, config::dataConfig>> m_arrayDatas;

  void ReadArrayVariables(beckhoffConfig &controllerInfo, AdsVariables &adsVariables, QPair<QString, QList<dataValue> > lastTimeData, AdsVariables &alarmVariables);
  private:
  template <typename T>
  T byte2T(PBYTE buffer);
  void handleArrayVariables(
      QMap<QString, QPair<int, config::dataConfig>> datas);
  unsigned char* GetAdsSumBufferRes(AdsVariables adsVariables, long port);
};

#endif  // ADSMANAGER_H
