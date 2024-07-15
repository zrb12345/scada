#ifndef UDP_THREAD_H
#define UDP_THREAD_H

#include <QThread>
#include "configmanager.h"
#include "qiec104slave.h"

class Udp_Thread:public QThread{
    Q_OBJECT

public:
    explicit Udp_Thread(MainWindow *mainwindow,QObject *parent = nullptr);
    ~Udp_Thread();

signals:
    void sendYC1(QList<QPair<int, float>> changeData_YC);
    void sendYX1(QList<QPair<int, float>> changeData_YX);

protected:
    void run() override;
    void publishModbusReslovedDatas(QMap<QString, config::dataValue> resolveMap, QMap<int, config::publishNode> modbus_publishs, QString nodeName);
    void publishIEC104ReslovedDatas(QMap<QString, config::dataValue> resolveMap, QMap<int, config::publishNode> modbus_publishs, QString nodeName);
    bool setCoil(int port, int coilStartaddress, uint8_t status);
    bool setInputCoil(int port, int coilStartaddress, uint8_t status);
    bool setInputRegisterValue(int port, int registerStartaddress,  float Value, QString sort);
    bool setHoldingRegisterValue(int port, int registerStartaddress, float Value, QString sort);

    // QMutex mutex;
    MainWindow *mainwindow = nullptr;
    // QIec104 *iec104 = nullptr;
    // QMap< int, modbus_mapping_t * >MODBUSmappings;

    // int m_numRegisters{ 60000 };
    // int m_numBits{ 60000 };
    // std::mutex slavemutex;
};

#endif // UDP_THREAD_H
