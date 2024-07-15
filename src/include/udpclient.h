#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QDebug>
#include <QHostAddress>
#include <QObject>
#include <QTimer>
#include <QUdpSocket>
#include <QVariant>
#include "StructAndEnum.h"
#include "singleton.h"
class UDPClient : public QObject {
    Q_OBJECT
public:
    //    UDPClient();
    //    void InitSocket();//初始化UDP套接字
    //  void InitTimer();//初始化定时器
    explicit UDPClient(int port, QObject *parent = nullptr);
    ~UDPClient();

    // type 0单播    1广播   2组播 ip 接受方ip地址 port 接受方端口
    void SendData(QPair<QString, QList<config::dataValue>> data,
                  QString plccontroller_ip,
                  QString pc_ip,
                  int port);
    //发送数据
    void udpSendModbusData(QByteArray allByte,
                           QString plccontroller_ip,
                           QString pc_ip,
                           int port) ;
    QByteArray handleData(QPair<QString, QList<config::dataValue>> data,
                          QString ip);

    template <typename T>
    QByteArray value2byte(double value, int byte_size);

    template <typename T>
    QByteArray value2byte2(double value, int byte_size);

private:
    QUdpSocket *mUdpSocket;      // UDP套接字对象
    QHostAddress mGroupAddress;  //组播地址
    QTimer *mTimer;              //定时器对象
    int mType;  //记录UDP消息传送模式 0:单播 1:广播 2:组播（多播）
};

#endif  // UDPCLIENT_H
