/*********系统头文件**************/

/*********用户头文件**************/
#include"commont.h"

/*********宏定义**************/
//获取本地IP
QString Get_LocalIp()
{
    QString hostName = QHostInfo::localHostName();          //本地主机名
    QHostInfo hostInfo = QHostInfo::fromName(hostName); //本机IP地址
    QList<QHostAddress> addList = hostInfo.addresses();    //IP地址列表
    for (int i = 0; i < addList.count(); i++)
    {
        QHostAddress aHost = addList.at(i); //每一项是一个QHostAddress
        if (QAbstractSocket::IPv4Protocol == aHost.protocol())
        {
            return aHost.toString(); //显示出Ip地址
        }
    }
    return QString("");
}
//字节数组转16进制字符串
void ByteToHexString(QString &str, QByteArray &ba)
{
    QString strs = ba.toHex().toUpper();//直接转换中间没有空格
    // qDebug() << "ba.toHex()" << ba.toHex() ;
    for (int i = 0; i < strs.length(); i += 2)
    {
        QString str_1 = strs.mid(i, 2);
        str += str_1;
        str += " ";
    }
    /*
    for (int i = 0; i < ba.length(); i++)
    {
        unsigned char n =static_cast<unsigned char>((ba.at(i)));
        QString nhex = QByteArray::number(n, 16).toUpper();
        str.append(nhex);
        str.append(' ');//字节间加空格
    }
    */
}
//16进制字符串转字节数组
//str：输入字符串，ba：输出字节数组
bool HexStringToByte(QString &str, QByteArray &ba)
{
    QString pattern("[a-fA-F0-9]+");//正则:数字0-9字母a-f、A-F匹配大于等于一次
    QRegExp rx(pattern);
    str = str.replace(' ', "");//删除所有空格
    if (rx.exactMatch(str))//匹配
    {
        bool ok;
        int length = str.length();
        if ((length % 2) == 0) //双数
        {
            for (int i = 0; i < length; i += 2)
            {
                QString str_hex = str.mid(i, 2);//每两个字符对应一个hex字符串
                ba.append(static_cast<char>(str_hex.toInt(&ok, 16)));//hex字符串转整数值
            }
        }
        else//单数
        {
            for (int i = 0; i < length - 1; i += 2)
            {
                QString str_hex = str.mid(i, 2);//每两个字符对应一个hex字符串
                ba.append(static_cast<char>(str_hex.toInt(&ok, 16)));//hex字符串转整数值
            }
            //最后一个单独处理
            ba.append(static_cast<char>(str.mid(length - 1, 1).toInt(&ok, 16))); //hex字符串转整数值
        }
        return true;
    }
    else
    {
        return false;
    }
}
//字节反转函数
void byteReverse(QString &coils)
{
    // 定义临时字符变量
    QChar temp;

    for (int i = 0; i < 4; i++)
    {
        temp = coils[i];        // 将第i个元素存入临时字符变量
        coils[i] = coils[8 - i - 1]; // 将第i个字符元素和第n-i-1个元素对调
        coils[8 - i - 1] = temp; // 将临时字符变量的值赋给第n-i-1个元素
    }
}
//连接两个quint8数据为一个quint16数据
quint16 BondTwoUint8ToUint16(quint8 preNum, quint8 afterNum)
{
    quint16 bondNum = (preNum << 8) | afterNum;
    return bondNum;
}
//将16进制字节数组转化为 2进制字符串
QString HexByteArrayToBinString(QByteArray DataArray)
{
    //2进制字符串的长度
    quint16 DataArrayLength;
    DataArrayLength = DataArray.size();

    QString res;
    for (int i = 0; i < DataArrayLength; i++)
    {
        //先转化为2进制字符串
        QString str = QString::number((quint8)DataArray.at(i), 2);
        //再转化为2进制整形，由二进制整形转化为8位2进制字符串前面自动补0，从而保证8位
        str = QString("%1").arg((quint8)str.toInt(NULL, 2), 8, 2, QChar('0'));
        //8bit字节倒转
        byteReverse(str);
        res += str;
    }
    return res;
}
