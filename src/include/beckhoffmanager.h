#ifndef BECKHOFFMANAGER_H
#define BECKHOFFMANAGER_H

#include <adsmanager.h>
#include <mainwindow.h>
#include <plctimermanager.h>
#include <QObject>
#include <QRunnable>
using namespace config;
class BeckhoffManager : public PlcTimerManager {
  Q_OBJECT

 public:
  explicit BeckhoffManager(QString name,
                           int controller_port,
                           QString template_name,
                           PlcTimerManager* parent = nullptr);
  //  BeckhoffManager();
  ~BeckhoffManager();

 public slots:

  void readVariables();
  void onCreateTimer();
  void onCreateShowDataTimer();
  //  void stopTimer();     // 暂停采集数据
  //  void restartTimer();  // 重新开启采集数据
  void reConnect();  // 重连接plc
  void showData();
  //  void startShowDataTimer();  // 开启数据展示定时器
  //  void stopShowDataTimer();   // 关闭数据展示定时器
  //  void startWriteTimer();
  void writeVariables(QStringList var_name, QStringList value);

 signals:

  //  void stopTimerSignals();
  //  void startTimerSignals();
  //  void stopShowDataTimerSignals();
  //  void startShowDataTimerSignals();

 public:
  void run(QMap<QString, QPair<int, config::dataConfig>> datas,
           config::beckhoffConfig controllerInfo,
           MainWindow* window,
           QFutureWatcher<void>* watcher);
  bool setReadType(QString type);
  //  void runShowDataThread();

 private:
  void initVariables();
  //  templateDataConfig template_datas;
  beckhoffConfig m_controllerInfo;
  AdsVariables m_adsVariables;
  AdsVariables m_AlarmVariables;
  AdsManager* m_ads = nullptr;
  int m_readType =
      0;  //倍福读取方式，默认为单点读取，0：单点读取； 1： 数组读取
};

#endif  // BECKHOFFMANAGER_H
