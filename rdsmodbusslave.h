#ifndef RDSMODBUSSLAVE_H
#define RDSMODBUSSLAVE_H

#include <stdlib.h>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
// using namespace std;
/*如果是windows平台则要加载相应的静态库和头文件*/
// clang-format off
#ifdef _WIN32
    #define _WINSOCK_DEPRECATED_NO_WARNINGS
    #include <winsock2.h>
    #include <windows.h>
    // clang-format on

    //#include <modbus.h>
    #pragma comment(lib, "Ws2_32.lib")
    //#pragma comment(lib, "modbus.lib")
    /*linux平台*/
#else
    //#include <modbus/modbus.h>
    #include <arpa/inet.h>
    #include <error.h>
    #include <sys/select.h>
    #include <sys/socket.h>
    #include <sys/time.h>
    #include <unistd.h>
#endif

//#define  MAX_POINT  50000
#include <stdio.h>
#include <QDebug>
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QStringList>
#include <QThread>
#include <QTimer>
#include "config.h"
#include "modbus-rtu.h"
#include <QTimer>
#include <QDebug>
#include <QStringList>
#include <QSerialPortInfo>
#include <QSerialPort>
#include "StructAndEnum.h"
// #include "mainwindow.h"
#include <QTcpSocket>
// typedef struct portCtxs {
//     std::string HostIp;
//     QString masterIp;
//     modbus_t *ctx{ nullptr };
//     modbus_mapping_t *mb_mapping;
//     int master_socket = 0;
//     int rc = 0;
//     fd_set refset;
//     fd_set rdset;
//     int fdmax = 0;
//     int m_modbusSocket = 0;
//     bool initialized = false;
// } portCtxs;

class RDSModbusSlaveThread : public QThread
{
    Q_OBJECT
public:
    explicit RDSModbusSlaveThread(int  port, modbus_mapping_t *mapping, QObject *parent = nullptr);
    ~RDSModbusSlaveThread();
public:
    QTcpSocket *tcpSocket ;
    int m_modbusSocket = 0;
    void handleWriteRes(int function, uint16_t address, double resvalue);
    // bool setSingleYXCoil(int slave_id, int coilStartaddress, uint8_t status);
    // bool setDoubleYXCoil(int slave_id, int coilStartaddress, uint8_t status);
    // bool setYCBYTES(int slave_id, int bytesStartaddress, float Value, QString sort);
    // IEC104_mapping *IEC104_mapping_new_start_address(
    // unsigned int start_single_yx_bits, unsigned int single_yx_bits,
    // unsigned int start_double_yx_bits, unsigned int double_yx_bits,
    // unsigned int start_yc_registers, unsigned int yc_registers);
    // IEC104_mapping *IEC104_mapping_new(int single_yx_bits, int double_yx_bits,
    // int yc_registers);
    int m_single_yx_bits{ 60000 };
    int m_double_yx_bits{ 60000 };
    int m_yc_bytes{ 60000 };
    // QMap<int, iec104_mapping *>IEC104mappings;
    // MainWindow *m_window;
    // QMap<int, HostPort> hostPorts;
private:
    std::mutex slavemutex;
    QHostAddress localHost;
    int m_errCount{ 0 };
    bool m_initialized{ false };
    // QMap< int, portCtxs * > slaves;
    modbus_mapping_t *MODBUSmapping;
    QMap<QString,  QMap<QString, config::dataConfig> > modbusPortPublishdatas;
    /*Mapping*/
    int m_numBits{ 60000 };
    int m_numInputBits{ 60000 };
    int m_numRegisters{ 60000 };
    int m_numInputRegisters{ 60000 };
    int m_port;
public:
    void loadFromConfigFile();
    QHostAddress masterAddress;
    void recieveMessages();
protected:
    void run();
    // void recieveMessages();
public slots:
    void writeModbusDataSlot(QByteArray data, QString ip);
    //在收到了数据的情况下,每个port对应的从站需要单独一个线程去发布自己的数据
    void publishDatas();
signals:
    void writeModbusDataSignal(QByteArray data, QString ip);
};

/*annotation:
(1)https://www.jianshu.com/p/0ed380fa39eb
(2)typedef struct _modbus_mapping_t
{
    int nb_bits;                //线圈
    int start_bits;
    int nb_input_bits;          //离散输入
    int start_input_bits;
    int nb_input_registers;     //输入寄存器
    int start_input_registers;
    int nb_registers;           //保持寄存器
    int start_registers;
    uint8_t *tab_bits;
    uint8_t *tab_input_bits;
    uint16_t *tab_input_registers;
    uint16_t *tab_registers;
}modbus_mapping_t;*/

#endif  // RDSMODBUSSLAVE_H
