#include "tcp_thread.h"
#include "qiec104slave.h"

Tcp_Thread::Tcp_Thread(QIec104 *iec104,QObject *parent) : QThread{parent} {
    this->iec104 = iec104;
    this->tcpSocket = iec104->cli;
}

Tcp_Thread::~Tcp_Thread() {}

void Tcp_Thread::run()
{
    bool brokenMsg = false;
    struct APDU apdu;
    uint8_t *p;
    p = (uint8_t *)&apdu;
    uint32_t bytesNum, len;

    while (1)
    {
        //有数据等待读取则为true
        while (tcpSocket->bytesAvailable()>0)
        {
            if (!brokenMsg)
            {
                //每次读一个字节，直到找到START
                do {
                    bytesNum = readTCP((char *)p, 1);//
                    if (bytesNum == 0) {
                        break;//说明数据读完了也没找到START
                    }
                } while (p[0] != 0x68);

                // 找到START后，下一个字节就是len
                bytesNum = readTCP((char *)p + 1, 1);
                if (bytesNum == 0) {
                    break;//没找到len
                }

                len = p[1];
                if (len < 4) {  // 小于4说明是错误的帧，重新寻找
                    break;
                }
            }

            // 读取除了START和length剩下的部分
            bytesNum = readTCP((char *)p + 2, len);
            if (bytesNum < len) {
                len = len - bytesNum;
                brokenMsg = true;
                break;//报文未读完，继续读取
            }

            brokenMsg = false;

            // mutex.lock();
            // m_shouldRun = true;

            qDebug()<<"1111111111";
            emit parseMsg(&apdu, apdu.apci.len + 2, true, iec104->typeAddress);//分析处理报文
            // m_shouldRun = false;
            // m_condition.wakeAll();
            // mutex.unlock();
        }
    }
}

int Tcp_Thread::readTCP(char *buf, int size) {
    int ret;
    ret = (int)tcpSocket->read(buf, size);
    if (ret > 0) {
        return ret;
    }
    return 0;
}
