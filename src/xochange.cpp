#include "xochange.h"
#include <math.h>
#include <iostream>
Xochange::Xochange() {}
Xochange::~Xochange() {}
float Xochange::ByteToFloat(unsigned char m0, unsigned char m1, unsigned char m2, unsigned char m3)
{
    // 求符号位
    float sig = 1.0;
    if (m0 >= 128.0) {
        sig = -1.0;
    }
    //求阶码
    float jie = 0.0;
    if (m0 >= 128.0)
    {
        jie = m0 - 128.0;
    }
    else
    {
        jie = m0;
    }
    jie = jie * 2.0;
    if (m1 >= 128.0) {
        jie += 1.0;
    }
    jie -= 127.0;
    //求尾码
    float tail = 0.0;
    if (m1 >= 128.0) {
        m1 -= 128.0;
    }
    tail =  m3 + (m2 + m1 * 256.0) * 256.0;
    tail  = (tail) / 8388608; //   8388608 = 2^23
    float f = sig * pow(2.0, jie) * (1 + tail);
    return f;
}
QHostAddress Xochange::getLocalAdrdress(int ipnumber) {
    QHostAddress localAddress;
    int indexip = 0;
    foreach (QHostAddress ptr, QNetworkInterface::allAddresses())
    {
        if (ptr.protocol() == QAbstractSocket::IPv4Protocol) {
            if (!ptr.isLoopback()) {
                localAddress = ptr;
                indexip ++;
                if (indexip ==  ipnumber)
                {
                    break;
                }
            }
        }
    }
    return localAddress;
}
QList<int>Xochange::sort(QList<int> list)
{
    int i = 0;
    for (i = 0; i < list.size() - 1; i++)
    {
        int j = 0;
        for (j = 0; j < list.size() - 1 - i; j++)
        {
            if (list[j] >  list[j + 1])
            {
                int emp =  list[j];
                list[j] =  list[j + 1];
                list[j + 1] = emp;
            }
        }
    }
    return list;
}
QByteArray Xochange::getByteFromFloat(float fvalue) {
    // QByteArray res;
    // uint8_t *bytes = reinterpret_cast<uint8_t *>(&fvalue);

    // for (size_t i = 0; i < sizeof(fvalue); ++i) {
    //     res.append(bytes[i]);
    // }
    // QByteArray res2 = QByteArray::fromRawData(reinterpret_cast<float *>(fvalue), 4);
    // return res;
    QByteArray byte;
    byte.push_back(QByteArray::fromRawData(
                       reinterpret_cast<const char *>(&fvalue), 4));
    return byte;

}
