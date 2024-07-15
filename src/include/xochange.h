#ifndef XOCHANGE_H
#define XOCHANGE_H
#include <QObject>
#include <QList>
#include <iostream>
#include <math.h>
#include <QHostAddress>
#include <QNetworkInterface>
class Xochange: public QObject {
    Q_OBJECT
public:
    Xochange();
    ~Xochange();
    static float ByteToFloat(unsigned char m0,
                             unsigned char m1,
                             unsigned char m2,
                             unsigned char m3);
    static QHostAddress getLocalAdrdress(int indeip);
    static QList<int>    sort(QList<int> list);
    static QByteArray getByteFromFloat(float fvalue);
};


#endif // XOCHANGE_H
