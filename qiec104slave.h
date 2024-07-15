#ifndef QIEC104SLAVE_H
#define QIEC104SLAVE_H

#include <QObject>
#include <QTimer>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QNetworkInterface>
#include "iec_slave_base.h"
#include "modbus.h"
// #include "mainwindow.h"
class QIec104 : public QObject, public iec_base {
    Q_OBJECT
public:
    explicit QIec104(int port, QMap<QString,  QMap<QString, config::dataConfig> > publishNode, MainWindow *window, modbus_mapping_t *mapping, QMap<QString, QList<int>> typeAddress, QObject *parent = 0);
    ~QIec104();
    QTcpSocket *cli;    // 连接socket（与客户端）
    QTcpServer *tcpServer;  // 监听socket
    QTimer *tm;  // tmKeepAlive定时器(1 second)
    // MainWindow *window = nullptr;
private:
    bool end;           // 是否终止
    bool allowConnect;  //
    int port;//2404作为默认端口不再生效，用传入的port替换
    QMap<QString, QList<int>> typeAddress; //每个发布类型的全部地址，用来做响应时 对全部数据的计算

public:
    void terminate();
    void enableConnect();
    void disableConnect();
    void initServer();   // init the server
    int m_single_yx_bits{ 60000 };
    int m_double_yc_bits{ 60000 };
    int m_yc_bytes{ 60000 };
private:
    int readTCP(char *buf, int size);
    void sendTCP(const char *buf, int size);
    void tcpConnect();
    void tcpDisconnect();
    int bytesAvailable();
    void waitForReadyRead(int bytes, int msecs);

    void dataIndication(struct iec_obj * /* obj */,
                        unsigned int /* numpoints */);
    void udpConnect();
    void udpDisconnect();

signals:
    void signalInitServerSuccess();
    void signalInitServerError();
    void signalTcpCpnnect();
    void signalTcpDisconnect();
    void signalDataIndication(struct iec_obj *, unsigned int);
    void signalNewConnection(); // new client connection

public slots:
    void slotTcpDisconnect();

private slots:
    void slotTcpConnect();
    void slotNewConnection();   // connect client
    void slotTcpReadyRead();  // ready to read via tcp socket
    void slotTcpError(QAbstractSocket::SocketError err);
    void slotTimeOut();  // when the alarm times out
};

#endif  // QIEC104SLAVE_H
