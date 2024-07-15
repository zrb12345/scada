#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define IP "192.168.0.136"
#define PORT 502
#include <StructAndEnum.h>
#include <singleton.h>
#include <udpclient.h>
#include <zipwritertimer.h>
#include <QMainWindow>
#include <QPushButton>
#include <QStandardItemModel>
#include <QTableWidget>
#include <QtConcurrent>
#include "myitemdelegate.h"
/************modbus协议需要的文件******************/
//#include "myserver.h"
//#include "mysocket.h"
//#include "mythread.h"
#include "commont.h"
#include "analysis_modbus.h"
// #include "modbusmanager.h"
#include <QModbusClient>
#include <QModbusTcpServer>
#include "rdsmodbusslave.h"
#include "modbus.h"
// #include "qiec104slave.h"
class ModbusManager;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class BeckhoffManager;
class BachmanManager;
class PlcTimerManager;
class TcpManager;
class QIec104;
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    friend class BeckhoffManager;
    friend class BachmanManager;
    friend class QIec104;
    friend class PlcTimerManager;
    friend class TcpManager;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // QMap<int port, QIec104 *iec104 >iec104s;
    void showDialog(int port, int id, short value);
    bool readConfigs();
    void showDataVariableTable(QList<config::dataConfig> dataValues);
    void showDataValueTable(QList<config::dataValue> dataValues);
    int modbusConnectState = 1;//1 未连接，2正在连接，3已关闭 0已连接
    QModbusClient *modbusDevice  = nullptr;
    float ByteToFloat(unsigned char m0, unsigned char m1, unsigned char m2, unsigned char m3);
    void modbusSlaveTimerWork(modbus_t *ctx);
    QModbusTcpServer *modbusDeviceSlave = nullptr;
    // RDSModbusSlaveThread *m_rdsModbusSlaveThread = nullptr;
    //全局的modbus寄存器map
    modbus_mapping_t *m_mb_mapping;
    //作为从站时接收的 来自modbus主站的请求
    uint8_t m_query[MODBUS_TCP_MAX_ADU_LENGTH] = {0};
    //修改配置文件 让所有的var_name都不同
    void  updateXmlFileSameVarName();
    void  publishModbusReslovedDatas(QMap<QString, config::dataValue> resolveMap, QMap<int, config::publishNode> modbus_publishs, QString nodeName);
    void  publishIEC104ReslovedDatas(QMap<QString, config::dataValue> resolveMap, QMap<int, config::publishNode> modbus_publishs, QString nodeName);
    void  recieveUDPMsg();
    //给plc的控制指令
    void controlback(QString ip, QByteArray msg);
    bool setCoil(int port, int coilStartaddress, uint8_t status);
    bool setInputCoil(int port, int coilStartaddress, uint8_t status);
    bool setInputRegisterValue(int port, int registerStartaddress,  float Value, QString sort);
    bool setHoldingRegisterValue(int port, int registerStartaddress, float Value, QString sort);
    QTcpSocket *tcpSocket ;


signals:
    void receiveMessageFromTCP(QString data);
    //在读到信息后触发的信号
    void windowStart(QByteArray msg, quint8 m_addr);
    void stopUpdateRestartSignalForUpdateFactor(QString varName, double factorvalue, int preErrorCode);
private:
    QHostAddress localAddress;
    int m_numBits{ 60000 };
    int m_numInputBits{ 60000 };
    int m_numRegisters{ 60000 };
    int m_numInputRegisters{ 60000 };
    std::mutex slavemutex;
//    QIec104 iec;
    QMap< int, modbus_mapping_t * >MODBUSmappings;
    // QMap<int, IEC104_mapping *>IECmappings;
    // analysis_modbus *m_analysis;
    Ui::MainWindow *ui;
    QMutex m_mutex;
    QButtonGroup *m_btnGroup;
    QList<int> m_showRows;
    bool m_isFirstShowData;  // data table 搜索之前第一次是否显示
    QMap<QString, ModbusManager *> m_ModBusManagers;
    QMap<QString, PlcTimerManager *> m_plcTimerManagers;
    QList<QFutureWatcher<void>*> m_futureWatchers;
    QList<int> m_addRouteIndexs;
//    TcpManager *m_tcpManager = nullptr;
    ZIPWriterTimer *m_zipWriterTimer = nullptr;
    QList<QPushButton *> m_buttons;
    QList<config::pcConfig> m_pcs;
    QMap<QString, QDateTime> mapofsenddatas;
    QList<config::controllerConfig<config::modbusConfig>> modbus_configs;
    int m_lastSelectRow = 0;
    int m_controllerport = 0;
    bool m_tableDataHidden = false;
    bool m_threadAssigned = false;
    QString m_historyPath;
    //  QList<config::pcConfig> m_pcConfigs;
    void backTOMain();
    void openFileFirst(bool isFirst = false);
    void stopTimers(QString name);
    void setRowColor(int row, QStandardItemModel *model);
    QTcpSocket *m_tcpSocket = nullptr;
protected:
    bool eventFilter(QObject *obj, QEvent *ev);
};
#endif  // MAINWINDOW_H
