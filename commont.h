#ifndef COMMONT_H
#define COMMONT_H

/*********系统头文件**************/
#include<QBitArray>
#include<QRegExp>
#include <QTcpSocket>
#include <QHostInfo>
#include<QDebug>
/*********用户头文件**************/

/*********宏定义**************/

/*********函数声明**************/
bool HexStringToByte(QString &str, QByteArray &ba);
void ByteToHexString(QString &str, QByteArray &ba);
QString Get_LocalIp();
void byteReverse(QString &coils);
quint16 BondTwoUint8ToUint16(quint8 preNum, quint8 afterNum);
QString HexByteArrayToBinString(QByteArray DataArray);
#endif // COMMONT_H
