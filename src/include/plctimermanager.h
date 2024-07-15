#ifndef PLCTIMERMANAGER_H
#define PLCTIMERMANAGER_H

#include <StructAndEnum.h>
#include <mainwindow.h>
#include <udpclient.h>
#include <QObject>
using namespace config;
class PlcTimerManager : public QObject {
    Q_OBJECT
public:
    explicit PlcTimerManager(QString name,
                             int controller_port, QString template_name,
                             QObject *parent = nullptr);
    ~PlcTimerManager();
public slots:

    virtual void readVariables();
    virtual void onCreateTimer();
    virtual void onCreateShowDataTimer();
    virtual void stopTimer();     // 暂停采集数据
    virtual void restartTimer();  // 重新开启采集数据
    virtual void reConnect();     // 重连接plc
    virtual void showData();
    virtual void startShowDataTimer();  // 开启数据展示定时器
    virtual void stopShowDataTimer();  // 关闭数据展示定时器
    virtual void openFile();           //新建CSV文件或者打开CSV文件
    virtual void startWriteTimer();    //开启写CSV的定时器
    virtual void writeVariables(QStringList var_name, QStringList value);
    virtual void stopAllTimers();

    virtual void flushFile();  //刷新缓存区并写入磁盘
    virtual void stopUpdateRestartSlotForUpdateFactor(QString varName, double factorvalue, int preErrorCode);
signals:

    void stopTimerSignals();
    void stopUpdateRestartSignalForUpdateFactor(QString varName, double factorvalue, int preErrorCode);
    void startTimerSignals();
    void stopShowDataTimerSignals();
    void startShowDataTimerSignals();
    void stopAllTimerSignals();
    void writeDataToPlc(QStringList var_name, QStringList value);

public:
    void runShowDataThread();
    void writeDataToCSV();
    void openFileFirst();
    void initSignals();
    QPair<QString, QList<dataValue>> m_mapofreadDataValues;
    QPair<QString, bool> m_mapofValueChanges;
    QPair<QDateTime, bool> m_firstReadTimeOfNoChanges;
    // QDateTime *m_firstReadTimeOfNoChanges;
public:
    QTimer *m_timer = nullptr;
    QTimer *m_reconnectTimer = nullptr;
    QTimer *m_showDataTimer = nullptr;
    QTimer *m_writeTimer = nullptr;
    bool m_isStop = true;
    bool m_isShowData = false;
    bool m_isShowDataStop = false;
    MainWindow *m_window = nullptr;
    QString m_name = "";    //node name
    //new add
    QString m_templateName = ""; //node -> template_name

    QString m_timeFormat = "";
    QFile m_file;
    QMap<QString, QPair<int, config::dataConfig>> m_dataConfigs;
    QList<config::pcConfig> m_pcConfigs;
    UDPClient *m_udpClient = nullptr;
    int m_controller_port = 0;
    int m_plcErrorCode = 0;
    int m_pre_plcErrorCode = 0;
    QFutureWatcher<void> *m_watcher;
    int m_firstAlarm_index = 0;
    int m_controllerStatus_index = 0;
    QDateTime m_error_time;
    bool m_firstDisconnect = true;

    //  int m_time = 0;
};

#endif  // PLCTIMERMANAGER_H
