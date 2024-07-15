#ifndef BACHMANMANAGER_H
#define BACHMANMANAGER_H

#include <bahamanadsmanager.h>
#include <mainwindow.h>
#include <msys/inc/res.h>
#include <plctimermanager.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QObject>
#include <QRunnable>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "m1com/m1com.h"
#define TEST_IP "10.1.50.2"
#define TEST_USER "M1"
#define TEST_PASSWD "bachmann"

VOID sleepMilli(UINT32 millisec);

UINT32 getError();
using namespace config;
class BachmanManager : public PlcTimerManager {
  Q_OBJECT

 public:
  explicit BachmanManager(QString name,
                          int controller_port,
                          QString template_name,
                          PlcTimerManager* parent = nullptr);
  ~BachmanManager();
 public slots:
  void readVariables();
  void writeVariables(QStringList var_name, QStringList value);
  void onCreateTimer();
  void onCreateShowDataTimer();
  void reConnect();  // 重连接plc
  void showData();
  // void stopUpdateRestartSlotForUpdateFactor(QString varName, double
  // factorvalue);
 public:
  void run(QMap<QString, QPair<int, config::dataConfig>> datas,
           config::plcConfig controllerInfo,
           MainWindow* window,
           QFutureWatcher<void>* watcher);
 signals:
  // void stopUpdateRestartSignalForUpdateFactor(QString varName, double
  // factorvalue);
 private:
  plcConfig m_controllerInfo;
  BhmAdsVariables m_bhmAdsVariables;
  BhmAdsVariables m_bhmAlarmVariables;
  BahamanAdsManager* m_bhmAds = nullptr;
};

#endif  // BACHMANMANAGER_H
