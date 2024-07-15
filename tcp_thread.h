#ifndef TCP_THREAD_H
#define TCP_THREAD_H

#include <QThread>
#include <QtNetwork/QTcpSocket>
#include "qiec104slave.h"

class Tcp_Thread:public QThread{
    Q_OBJECT

public:
    explicit Tcp_Thread(QIec104 *iec104,QObject *parent = nullptr);
    ~Tcp_Thread();

protected:
    void run() override;
    int readTCP(char *buf, int size);
    QTcpSocket *tcpSocket;
    QIec104 *iec104;

    bool m_shouldRun = false;
    QWaitCondition m_condition;
    QMutex mutex;

signals:
    void parseMsg(struct APDU *papdu, int sz, bool isSend,   QMap<QString, QList<int>>  modbussAddress);
};

#endif // TCP_THREAD_H
