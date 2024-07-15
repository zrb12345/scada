#include "iec_slave_base.h"
#include <QDialog>
using namespace std;
#include <QString>
#include <QDebug>
#include "configmanager.h"
#include"xochange.h"
#ifndef OFF
    #define OFF 0
#endif

#ifndef ON
    #define ON 1
#endif
iec_base::iec_base() {
    // this->slavePort = port;  // set iec104 tcp port to 2404
    strncpy(this->slaveIP, "", 20);
    this->masterAddr = 0;  // originator address
    this->slaveAddr = 0;   // common address os ASDU
    this->vs = 0;
    this->vr = 0;
    this->isClockSYnc = false;
    this->ifCheckSeq = true;
    this->allowSend = true;
    this->numMsgUnack = 0;
    this->numMsgReceived = 0;
    initServerBase();
}


uint32_t iec_base::getSlavePort() {
    return this->slavePort;
}

void iec_base::setSlavePort(uint32_t port) {
    this->slavePort = port;
}

char *iec_base::getSlaveIP() {
    return this->slaveIP;
}

void iec_base::setSlaveIP(const char *ip) {
    strncpy(this->slaveIP, ip, 20);
}

uint16_t iec_base::getSlaveAddr() {
    return this->slaveAddr;
}

void iec_base::setSlaveAddr(uint16_t addr) {
    this->slaveAddr = addr;
}

void iec_base::initServerBase() {

    this->umapType2String[1] = "M_SP_NA_1";
    this->umapType2String[2] = "M_SP_TA_1";
    this->umapType2String[3] = "M_DP_NA_1";
    this->umapType2String[5] = "M_ST_NA_1";
    this->umapType2String[6] = "M_ST_TA_1";
    this->umapType2String[7] = "M_BO_NA_1";
    this->umapType2String[8] = "M_BO_TA_1";
    this->umapType2String[9] = "M_ME_NA_1";
    this->umapType2String[11] = "M_ME_NB_1";
    this->umapType2String[12] = "";
    this->umapType2String[13] = "M_ME_NC_1";
    this->umapType2String[14] = "";
    this->umapType2String[15] = "M_IT_NA_1";
    this->umapType2String[16] = "";
    this->umapType2String[17] = "";
    this->umapType2String[18] = "";
    this->umapType2String[19] = "";
    this->umapType2String[20] = "M_PS_NA_1";
    this->umapType2String[30] = "M_SP_TB_1";
    this->umapType2String[31] = "M_DP_TB_1";
    this->umapType2String[32] = "M_ST_TB_1";
    this->umapType2String[33] = "M_BO_TB_1";
    this->umapType2String[34] = "M_ME_TD_1";
    this->umapType2String[35] = "M_ME_TE_1";
    this->umapType2String[36] = "M_ME_TF_1";
    this->umapType2String[37] = "M_IT_TB_1";
    this->umapType2String[38] = "M_EP_TD_1";
    this->umapType2String[39] = "M_EP_TE_1";
    this->umapType2String[40] = "M_EP_TF_1";
    this->umapType2String[45] = "C_SC_NA_1:single command";  //
    this->umapType2String[46] = "C_DC_NA_1:double command";
    this->umapType2String[47] = "C_RC_NA_1:regulating step command";
    this->umapType2String[48] = "C_SE_NA_1:set-point normalised command";
    this->umapType2String[49] = "C_SE_NB_1:set-point scaled command";
    this->umapType2String[50] = "C_SE_NC_1:set-point short floating point command";
    this->umapType2String[51] = "C_BO_NA_1:Bitstring of 32 bit command";
    this->umapType2String[58] = "C_SC_TA_1:single command with time tag";
    this->umapType2String[59] = "C_DC_TA_1:double command with time tag";
    this->umapType2String[60] = "C_RC_TA_1:regulating step command with time tag";
    this->umapType2String[61] = "C_SE_TA_1:set-point normalised command with time tag";
    this->umapType2String[62] = "C_SE_TB_1:set-point scaled command with time tag";
    this->umapType2String[63] = "C_SE_TC_1:set-point short floating point command with time tag";
    this->umapType2String[64] = "C_BO_TA_1:Bitstring of 32 bit command with time tag";
    this->umapType2String[70] = "M_EI_NA_1:end of initialization";
    this->umapType2String[100] = "C_IC_NA_1:general interrogation";
    this->umapType2String[101] = "C_CI_NA_1:counter interrogation";
    this->umapType2String[102] = "C_RD_NA_1:read command";
    this->umapType2String[103] = "C_CS_NA_1:clock synchronization command";
    this->umapType2String[105] = "C_RP_NA_1:reset process command";
    this->umapType2String[107] = "C_TS_TA_1:test command with time tag CP56Time2a";
    this->umapType2String[110] = "P_ME_NA_1:Parameter of measured values, normalized value";
    this->umapType2String[111] = "P_ME_NB_1:Parameter of measured values, scaled value";
    this->umapType2String[112] = "P_ME_NC_1:Parameter of measured values, short floating point number";
    this->umapType2String[113] = "P_AC_NA_1:Parameter activation";


}

/**
 * @brief iec_base::packetReadyTCP - tcp packets are ready to be read from the
 * connection with slave station. modbus_mapping_t *Mapping,
 */
void iec_base::messageReadyRead(QMap<QString, QList<int>> typeAddress) {

    static bool brokenMsg = false;
    static apdu wapdu;
    uint8_t *p;
    p = (uint8_t *)&wapdu;
    uint32_t bytesNum /* result of readTCP */, len /* apdu length */;
    char buf[1000];

    while (true) {
        if (!brokenMsg) {
            // 找到START
            do {
                bytesNum = readTCP((char *)p, 1);//
                if (bytesNum == 0) {
                    return;  // 该函数被调用说明这里不应该被执行到
                }
            } while (p[0] != START);
            // 找到len
            bytesNum = readTCP((char *)p + 1, 1);
            if (bytesNum == 0) {
                return;
            }
        }

        len = p[1];
        if (len < 4) {  // 小于4说明是错误的帧，重新寻找
            brokenMsg = false;
            qDebug() << " len < 4";
            // //log.pushMsg("ERROR: invalid frame");
            continue;
        }
        // 读取除了68和length剩下的部分
        //   waitForReadyRead(len, 10000);  等待len字节的数据被准备好
        // qDebug() << "waitForReadyRead 30000 over";
        bytesNum = readTCP((char *)p + 2, len);
        if (bytesNum == 0) {
            //log.pushMsg("ERROR: broken msg");
            brokenMsg = true;
            return;
        } else if (bytesNum < len) {
            uint32_t rest = len - bytesNum;
            sprintf(buf, "--> should reread %d(%d in total)", rest, len);
            //log.pushMsg(buf);

            // 第二次读
            // waitForReadyRead(rest, 300);
            bytesNum = readTCP((char *)p + 2 + bytesNum, rest);
            sprintf(buf, "--> reread %d bytes in fact", bytesNum);
            if (bytesNum < rest) {
                //log.pushMsg("--> broken msg");
                brokenMsg = true;
                return;
            }
        }

        brokenMsg = false;
        showMessage((const char *)p, len + 2, false);
        qDebug() << "parseMsg is begin " << m_port;
        parseMsg(&wapdu, wapdu.length + 2, true, typeAddress);// Mapping,
        break;
    }
}

void iec_base::send(const struct apdu &wapdu) {
    this->sendTCP(reinterpret_cast<const char *>(&wapdu), wapdu.length + 2);
}

void iec_base::onTcpConnect() {
    this->vr = 0;
    this->vs = 0;
    this->isConnected = true;
    // this->log.pushMsg("connect success!");
}

void iec_base::onTcpDisconnect() {
    this->isConnected = false;
    // this->log.pushMsg("disconnect success!");
}

/**
 * @brief iec_base::onTimeoutPerSecond - when the timer is up and modify the
 * timeout.
 */
void iec_base::onTimeoutPerSecond() {
    if (isConnected) {
        if (t1Timeout > 0) {
            --t1Timeout;
            if (t1Timeout == 0) {  // 超时，重新连接
                // TODO:
                // 超时，主动关闭
                //            sendStartDtAct();   // t1Timeout < 0表示不需要处理
            }
        }

        if (t2Timeout > 0) {
            --t2Timeout;
            if (t2Timeout == 0) {
                sendMonitorMessage();
                t2Timeout = -1;
            }
        }

        if (t3Timeout > 0) {
            --t3Timeout;
            if (t3Timeout == 0) {
                sendTestfrAct();
            }
        }
    }
    // TODO:
}

void iec_base::sendStartDtCon() {
    struct apdu a;

    // log.pushMsg("INFO: U(STARTDTCON)");
    a.start = START;
    a.length = 4;
    a.NS = uint16_t(STARTDTCON);
    a.NR = 0;
    send(a);
}

void iec_base::sendStopDtAct() {
    struct apdu a;
    a.start = START;
    a.length = 4;
    a.NS = uint16_t(STOPDTACT);
    a.NR = 0;
    send(a);
    // log.pushMsg("INFO: U(STOPDTACT)");
}

void iec_base::sendStopDtCon() {
    struct apdu a;
    a.start = START;
    a.length = 4;
    a.NS = uint16_t(STOPDTCON);
    a.NR = 0;
    send(a);
    // this->log.pushMsg("INFO: U(STOPDTCON)");
}

void iec_base::sendTestfrAct() {
    struct apdu a;
    a.start = START;
    a.length = 4;
    a.NS = uint16_t(TESTFRACT);
    a.NR = 0;
    send(a);
    // this->log.pushMsg("INFO: U(TESTFRACT)");
}

void iec_base::sendTestfrCon() {
    struct apdu a;
    a.start = START;
    a.length = 4;
    a.NS = uint16_t(TESTFRCON);
    a.NR = 0;
    send(a);
    // this->log.pushMsg("INFO: U(TESTFRCON)");
}

void iec_base::generalInterrogationCon() {
    struct apdu a;
    a.start = START;
    a.length = 0x0E;
    a.NS = vs << 1;
    a.NR = vr << 1;
    a.head.type = INTERROGATION;
    a.head.num = 1;
    a.head.sq = 0;
    a.head.cot = ACTCONFIRM;  // 7: 激活确认
    //    a.head.t = 0;
    //    a.head.pn = 0;
    a.head.oa = masterAddr;
    a.head.ca = slaveAddr;
    a.nsq100.ioa16 = 0x00;
    a.nsq100.ioa8 = 0x00;
    a.nsq100.obj.qoi = 0x14;

    if (allowSend) {
        send(a);
        ++vs;
        ++numMsgUnack;
    }
}
void iec_base::singleYkCon() {
    struct apdu a;
    a.start = START;
    a.length = 0x0E;
    a.NS = vs << 1;
    a.NR = vr << 1;
    a.head.type = M_SP_NA_1;
    a.head.num = 1;
    a.head.sq = 0;
    a.head.cot = ACTCONFIRM;  // 7: 激活确认
    //    a.head.t = 0;
    //    a.head.pn = 0;
    a.head.oa = masterAddr;
    a.head.ca = slaveAddr;
    // a.nsq100.ioa16 = 0x00;
    // a.nsq100.ioa8 = 0x00;
    // a.nsq100.obj.qoi = 0x14;

    if (allowSend) {
        send(a);
        ++vs;
        ++numMsgUnack;
    }
}


void iec_base::generalInterrogationEnd() {
    struct apdu a;

    a.start = START;
    a.length = 0x0E;
    a.NS = vs << 1;
    a.NR = vr << 1;
    a.head.type = INTERROGATION;
    a.head.num = 1;
    a.head.sq = 0;
    a.head.cot = ACTTERM;  // cause: 10(激活终止)
    //    a.head.t = 0;
    //    a.head.pn = 0;
    //    a.head.oa = ...
    a.head.ca = masterAddr;
    a.nsq100.ioa16 = 0x00;
    a.nsq100.ioa8 = 0x00;
    a.nsq100.obj.qoi = 0x14;  // 召唤品质描述词

    if (allowSend) {
        send(a);
        ++vs;
        ++numMsgUnack;
    }
}

/**
 * @brief iec_base::sendYC - 模拟并发送遥测数据
 * @param type  - 类型标识
 * @param sq    - 是否连续值
 */
void iec_base::sendYC(uint8_t type, bool sq,  QMap<QString, QList<int>>  typeAddress) {
    stringstream ss;
    int len;
    int num;
    int startAddr = 0;
    int part = 0;
    bool iscomplete;
    QList<int> floatList = typeAddress.value("inputFloat");
    floatList.size() % m_parMax == 0 ? iscomplete = true : iscomplete = false;
    iscomplete ? part = floatList.size() / m_parMax  : part = floatList.size() / m_parMax + 1;
    for (int i = 0; i < part; ++i) {
        struct apdu *papdu;
        num = m_parMax;
        if (!iscomplete && i == part - 1 && part > 1 || floatList.size() < m_parMax)
        {
            num = floatList.size() % m_parMax;
        };
        switch (type) {
            case M_ME_NC_1: {  // 13: 测量值, 浮点数
                if (sq) {
                    len = sizeof((*papdu).start) + sizeof((*papdu).length) +
                          sizeof((*papdu).NR) + sizeof((*papdu).NS) +
                          sizeof((*papdu).head) + 3 /* 信息对象地址 */ +
                          num * sizeof(struct iec_type13);
                    papdu = (struct apdu *)new uint8_t[len];
                    papdu->length = len - 2;

                    for (int index = 0; index < num; ++index) {
                        int address = floatList.at(startAddr + index);
                        uint16_t intvalue1 = mapping->tab_input_registers[ address ] ;
                        uint16_t intvalue3 = mapping->tab_input_registers[ address + 1 ] ;
                        QByteArray array;
                        QDataStream stream(&array, QIODevice::WriteOnly);
                        stream << intvalue1;
                        stream << intvalue3;
                        float fValue = Xochange::ByteToFloat(array[2], array[3], array[0], array[1]);
                        //qDebug() << "遥测 part " << part << "index " << index << " addr " << address << " value " << fValue;
                        papdu->sq13.ioa16 = (floatList.at(startAddr) - 1) / 2;
                        papdu->sq13.ioa8 = 0x00;
                        papdu->sq13.obj[index].frac = fValue;
                        papdu->sq13.obj[index].ov = 0;
                        papdu->sq13.obj[index].res = 0;
                        papdu->sq13.obj[index].bl = 0;
                        papdu->sq13.obj[index].sb = 0;
                        papdu->sq13.obj[index].nt = 0;
                        papdu->sq13.obj[index].iv = 0;
                    }
                } else {
                    int len1 = sizeof((*papdu).start);
                    int len2 = sizeof((*papdu).length) ;
                    int len3 = sizeof((*papdu).NR);
                    int len4 = sizeof((*papdu).NS) ;
                    int len5 = sizeof((*papdu).head) ;
                    int len6 = num * (3 /* 信息对象地址 */ + sizeof(struct iec_type13));
                    len = len1 + len2 + len3 + len4 + len5 + len6;
                    papdu = (struct apdu *)new uint8_t[len];
                    papdu->length = len - 2 ;
                    for (int i = 0; i < num; i++)
                    {
                        papdu->nsq13[i].ioa16 = i + 1;
                        papdu->nsq13[i].ioa8 = i;
                        uint16_t intvalue1 =   mapping->tab_registers[2 * i + 4] ;
                        uint16_t intvalue3 =   mapping->tab_registers[2 * i + 5] ;
                        QByteArray array;
                        QDataStream stream(&array, QIODevice::WriteOnly);
                        stream << intvalue1;
                        stream << intvalue3;
                        float fValue = Xochange::ByteToFloat(array[1], array[0], array[3], array[2]);
                        papdu->nsq13[i].obj.frac = fValue;
                        papdu->nsq13[i].obj.ov = 0;
                        papdu->nsq13[i].obj.res = 0;
                        papdu->nsq13[i].obj.bl = 0;
                        papdu->nsq13[i].obj.sb = 0;
                        papdu->nsq13[i].obj.nt = 0;
                        papdu->nsq13[i].obj.iv = 0;
                    }
                }
                papdu->start = START;
                papdu->NS = vs << 1;
                papdu->NR = vr << 1;
                papdu->head.type = type;
                papdu->head.num = num;
                papdu->head.sq = sq ? 1 : 0;
                papdu->head.cot = INTROGEN;  // 传输原因：响应站召唤
                papdu->head.oa = slaveAddr;
                papdu->head.ca = masterAddr;  // ASDU公共地址
            }
            break;
            default:
                ss.str("");
                ss << "ERROR: type " << uint32_t(type) << " is not implemented!";
                return;
                break;
        }

        if (allowSend) {
            send(*papdu);
            ++vs;
            ++numMsgUnack;
        }
        startAddr += m_parMax;
        delete[] papdu;
    }

}
// /**
//  * @brief iec_base::sendYD - 模拟并发送遥调数据
//  * @param type  - 类型标识
//  * @param sq    - 是否连续值
//  */
void iec_base::sendYD(uint8_t type, bool sq,  QMap<QString, QList<int>>  typeAddress) {
    stringstream ss;

    // uint16_t intvalue1 = mapping->tab_registers[ 33249 ] ;
    // uint16_t intvalue3 = mapping->tab_registers[ 33250 ] ;
    // QByteArray array;
    // QDataStream stream(&array, QIODevice::WriteOnly);
    // stream << intvalue1;
    // stream << intvalue3;
    // float fValue = Xochange::ByteToFloat(array[2], array[3], array[0], array[1]);
    // qDebug() << "遥调 part 2404"   << " addr " << "16624" << " value " << fValue;
    int len;
    int num;
    int startAddr = 0;
    int part = 0;
    bool iscomplete;
    QList<int> floatList = typeAddress.value("float");
    floatList.size() % m_parMax == 0 ? iscomplete = true : iscomplete = false;
    iscomplete ? part = floatList.size() / m_parMax  : part = floatList.size() / m_parMax + 1;
    for (int i = 0; i < part; ++i) {
        struct apdu *papdu;
        num = m_parMax;
        if (!iscomplete && i == part - 1 && part > 1 || floatList.size() < m_parMax)
        {
            num = floatList.size() % m_parMax;
        };
        switch (type) {
            case M_ME_NC_1: {  // 13: 测量值, 浮点数
                if (sq) {
                    len = sizeof((*papdu).start) + sizeof((*papdu).length) +
                          sizeof((*papdu).NR) + sizeof((*papdu).NS) +
                          sizeof((*papdu).head) + 3 /* 信息对象地址 */ +
                          num * sizeof(struct iec_type13);
                    papdu = (struct apdu *)new uint8_t[len];
                    papdu->length = len - 2;

                    for (int index = 0; index < num; ++index) {
                        int address = floatList.at(startAddr + index);
                        uint16_t intvalue1 = mapping->tab_registers[ address ] ;
                        uint16_t intvalue3 = mapping->tab_registers[ address + 1 ] ;
                        QByteArray array;
                        QDataStream stream(&array, QIODevice::WriteOnly);
                        stream << intvalue1;
                        stream << intvalue3;
                        float fValue = Xochange::ByteToFloat(array[2], array[3], array[0], array[1]);
                        qDebug() << "遥调 part " << part << "index " << index << " addr " << address << " value " << fValue;
                        papdu->sq13.ioa16 = (floatList.at(startAddr) - 1) / 2;
                        papdu->sq13.ioa8 = 0x00;
                        papdu->sq13.obj[index].frac = fValue;
                        papdu->sq13.obj[index].ov = 0;
                        papdu->sq13.obj[index].res = 0;
                        papdu->sq13.obj[index].bl = 0;
                        papdu->sq13.obj[index].sb = 0;
                        papdu->sq13.obj[index].nt = 0;
                        papdu->sq13.obj[index].iv = 0;
                    }
                } else {
                    int len1 = sizeof((*papdu).start);
                    int len2 = sizeof((*papdu).length) ;
                    int len3 = sizeof((*papdu).NR);
                    int len4 = sizeof((*papdu).NS) ;
                    int len5 = sizeof((*papdu).head) ;
                    int len6 = num * (3 /* 信息对象地址 */ + sizeof(struct iec_type13));
                    len = len1 + len2 + len3 + len4 + len5 + len6;
                    papdu = (struct apdu *)new uint8_t[len];
                    papdu->length = len - 2 ;
                    for (int i = 0; i < num; i++)
                    {
                        papdu->nsq13[i].ioa16 = i + 1;
                        papdu->nsq13[i].ioa8 = i;
                        uint16_t intvalue1 =   mapping->tab_registers[2 * i + 4] ;
                        uint16_t intvalue3 =   mapping->tab_registers[2 * i + 5] ;
                        QByteArray array;
                        QDataStream stream(&array, QIODevice::WriteOnly);
                        stream << intvalue1;
                        stream << intvalue3;
                        float fValue = Xochange::ByteToFloat(array[1], array[0], array[3], array[2]);
                        papdu->nsq13[i].obj.frac = fValue;
                        papdu->nsq13[i].obj.ov = 0;
                        papdu->nsq13[i].obj.res = 0;
                        papdu->nsq13[i].obj.bl = 0;
                        papdu->nsq13[i].obj.sb = 0;
                        papdu->nsq13[i].obj.nt = 0;
                        papdu->nsq13[i].obj.iv = 0;
                    }
                }
                papdu->start = START;
                papdu->NS = vs << 1;
                papdu->NR = vr << 1;
                papdu->head.type = type;
                papdu->head.num = num;
                papdu->head.sq = sq ? 1 : 0;
                papdu->head.cot = INTROGEN;  // 传输原因：响应站召唤
                papdu->head.oa = slaveAddr;
                papdu->head.ca = masterAddr;  // ASDU公共地址
            }
            break;
            default:
                ss.str("");
                ss << "ERROR: type " << uint32_t(type) << " is not implemented!";
                return;
                break;
        }

        if (allowSend) {
            send(*papdu);
            ++vs;
            ++numMsgUnack;
        }
        startAddr += m_parMax;
        delete[] papdu;
    }

}

/**
 * @brief iec_base::sendYX - 模拟并发送遥信数据
 * @param type  - 类型标识
 * @param sq    - 是否连续值
 * TODO: Add more types.
 */
void iec_base::sendYX(uint8_t type, bool sq,  QMap<QString, QList<int>>  typeAddress) {
    int len;
    int num = m_yxMax;
    int startAddr = 0;
    int part = 0;
    bool iscomplete;
    QList<int> charList = typeAddress.value("inputChar");
    charList.size() % m_yxMax == 0 ? iscomplete = true : iscomplete = false;
    iscomplete ? part = charList.size() / m_yxMax  : part = charList.size() / m_yxMax + 1;
    for (int i = 0; i < part; ++i) {
        struct apdu *papdu;
        num = m_yxMax;
        if (!iscomplete && i == part - 1 && part > 1 || charList.size() < m_yxMax)
        {
            num = charList.size() % m_yxMax;
        };
        switch (type) {
            case M_SP_NA_1: {  // 13: 测量值, 浮点数
                if (sq) {
                    len = sizeof((*papdu).start) + sizeof((*papdu).length) +
                          sizeof((*papdu).NR) + sizeof((*papdu).NS) +
                          sizeof((*papdu).head) + 3 /* 信息对象地址 */ +
                          num * sizeof(struct iec_type1);
                    papdu = (struct apdu *)new uint8_t[len];
                    papdu->length = len - 2;
                    for (int index = 0; index < num; ++index) {
                        int address = charList.at(startAddr + index);
                        // qDebug() << "遥信 part " << part << "index " << index;
                        // papdu->sq1.ioa16 = 0x0001;
                        papdu->sq1.ioa16 = charList.at(startAddr);
                        papdu->sq1.ioa8 = 0x00;
                        papdu->sq1.obj[index].spi = mapping->tab_input_bits[address];
                        papdu->sq1.obj[index].res = 0;
                        papdu->sq1.obj[index].bl = 0;
                        papdu->sq1.obj[index].sb = 0;
                        papdu->sq1.obj[index].nt = 0;
                        papdu->sq1.obj[index].iv = 0;
                    }
                } else {
                    int len1 = sizeof((*papdu).start);
                    int len2 = sizeof((*papdu).length) ;
                    int len3 = sizeof((*papdu).NR);
                    int len4 = sizeof((*papdu).NS) ;
                    int len5 = sizeof((*papdu).head) ;
                    int len6 = num * (3 /* 信息对象地址 */ + sizeof(struct iec_type1));
                    len = len1 + len2 + len3 + len4 + len5 + len6;
                    papdu = (struct apdu *)new uint8_t[len];
                    papdu->length = len - 2 ;
                    for (int i = 0; i < num; i++)
                    {
                        uint16_t ioa16value = i + 1;
                        papdu->sq1.ioa16 = ioa16value;
                        papdu->sq1.ioa8 = i;
                        papdu->sq1.obj[i].spi = i + 1;
                        papdu->sq1.obj[i].res = 0;
                        papdu->sq1.obj[i].bl = 0;
                        papdu->sq1.obj[i].sb = 0;
                        papdu->sq1.obj[i].nt = 0;
                        papdu->sq1.obj[i].iv = 0;
                    }
                }
                papdu->start = START;
                papdu->NS = vs << 1;
                papdu->NR = vr << 1;
                papdu->head.type = type;
                papdu->head.num = num;
                papdu->head.sq = sq ? 1 : 0;
                papdu->head.cot = INTROGEN;  // 传输原因：响应站召唤
                papdu->head.oa = slaveAddr;
                papdu->head.ca = masterAddr;  // ASDU公共地址
            }
            break;
            default:
                qDebug() << "ERROR: type " << uint32_t(type) << " is not implemented!";
                return;
                break;
        }

        if (allowSend) {
            send(*papdu);
            ++vs;
            ++numMsgUnack;
        }
        startAddr += m_yxMax;
        delete[] papdu;
    }

}
// /**
//  * @brief iec_base::sendYX - 模拟并发送遥控数据
//  * @param type  - 类型标识
//  * @param sq    - 是否连续值
//  * TODO: Add more types.
//  */
// void iec_base::sendYK(uint8_t type, bool sq,  QMap<QString, QList<int>>  typeAddress) {
//     int len;
//     int num = m_yxMax;
//     int startAddr = 0;
//     int part = 0;
//     bool iscomplete;
//     QList<int> charList = typeAddress.value("char");
//     charList.size() % m_yxMax == 0 ? iscomplete = true : iscomplete = false;
//     iscomplete ? part = charList.size() / m_yxMax  : part = charList.size() / m_yxMax + 1;
//     for (int i = 0; i < part; ++i) {
//         struct apdu *papdu;
//         num = m_yxMax;
//         if (!iscomplete && i == part - 1 && part > 1 || charList.size() < m_yxMax)
//         {
//             num = charList.size() % m_yxMax;
//         };
//         switch (type) {
//             case M_SP_TA_1: {  // 2: 遥控
//                 if (sq) {
//                     len = sizeof((*papdu).start) + sizeof((*papdu).length) +
//                           sizeof((*papdu).NR) + sizeof((*papdu).NS) +
//                           sizeof((*papdu).head) + 3 /* 信息对象地址 */ +
//                           num * sizeof(struct iec_type1);
//                     papdu = (struct apdu *)new uint8_t[len];
//                     papdu->length = len - 2;
//                     for (int index = 0; index < num; ++index) {
//                         int address = charList.at(startAddr + index);
//                         // qDebug() << "遥控 part " << part << "index " << index;
//                         papdu->sq2.ioa16 = 0x0001;
//                         papdu->sq2.ioa8 = 0x00;
//                         papdu->sq2.obj[index].spi = mapping->tab_bits[address];
//                         papdu->sq2.obj[index].res = 0;
//                         papdu->sq2.obj[index].bl = 0;
//                         papdu->sq2.obj[index].sb = 0;
//                         papdu->sq2.obj[index].nt = 0;
//                         papdu->sq2.obj[index].iv = 0;
//                     }
//                 } else {
//                     int len1 = sizeof((*papdu).start);
//                     int len2 = sizeof((*papdu).length) ;
//                     int len3 = sizeof((*papdu).NR);
//                     int len4 = sizeof((*papdu).NS) ;
//                     int len5 = sizeof((*papdu).head) ;
//                     int len6 = num * (3 /* 信息对象地址 */ + sizeof(struct iec_type1));
//                     len = len1 + len2 + len3 + len4 + len5 + len6;
//                     papdu = (struct apdu *)new uint8_t[len];
//                     papdu->length = len - 2 ;
//                     for (int i = 0; i < num; i++)
//                     {
//                         uint16_t ioa16value = i + 1;
//                         papdu->sq2.ioa16 = ioa16value;
//                         papdu->sq2.ioa8 = i;
//                         papdu->sq2.obj[i].spi = i + 1;
//                         papdu->sq2.obj[i].res = 0;
//                         papdu->sq2.obj[i].bl = 0;
//                         papdu->sq2.obj[i].sb = 0;
//                         papdu->sq2.obj[i].nt = 0;
//                         papdu->sq2.obj[i].iv = 0;
//                     }
//                 }
//                 papdu->start = START;
//                 papdu->NS = vs << 1;
//                 papdu->NR = vr << 1;
//                 papdu->head.type = type;
//                 papdu->head.num = num;
//                 papdu->head.sq = sq ? 1 : 0;
//                 papdu->head.cot = INTROGEN;  // 传输原因：响应站召唤
//                 papdu->head.oa = slaveAddr;
//                 papdu->head.ca = masterAddr;  // ASDU公共地址
//             }
//             break;
//             default:
//                 qDebug() << "ERROR: type " << uint32_t(type) << " is not implemented!";
//                 return;
//                 break;
//         }

//         if (allowSend) {
//             send(*papdu);
//             ++vs;
//             ++numMsgUnack;
//         }
//         startAddr += m_yxMax;
//         delete[] papdu;
//     }

// }
/**
 * @brief iec_base::sendClockSyncCon - 时钟同步确认报文
 * TODO: address and so on.
 */
void iec_base::sendClockSyncCon() {
    struct apdu wapdu;
    stringstream ss;
    time_t t = time(nullptr);
    struct tm *timeinfo = localtime(&t);
    uint32_t addr24 = 0;  // 24位信息对象地址

    wapdu.start = START;
    wapdu.length = sizeof(wapdu.NR) + sizeof(wapdu.NS) + sizeof(wapdu.head) +
                   sizeof(wapdu.nsq103);
    wapdu.NS = vs << 1;
    wapdu.NR = vr << 1;
    wapdu.head.type = C_CS_NA_1;
    wapdu.head.num = 1;           // 单信息元素
    wapdu.head.sq = 0;            // sq = 0
    wapdu.head.cot = ACTIVATION;  // 控制方向传送原因=激活
    wapdu.head.pn = 0;
    wapdu.head.t = 0;
    wapdu.head.oa = slaveAddr;
    wapdu.head.ca = masterAddr;
    wapdu.nsq103.ioa16 = (uint16_t)addr24;
    wapdu.nsq103.ioa8 = (uint8_t)(addr24 >> 16);
    //    cmd.nsq103.ioa16 = (obj->address & 0xFFFF);
    //    cmd.nsq103.ioa8 = (obj->address >> 16);
    wapdu.nsq103.obj.time.year = timeinfo->tm_year % 100;  // [0...99]
    wapdu.nsq103.obj.time.mon = timeinfo->tm_mon + 1;
    wapdu.nsq103.obj.time.dmon = timeinfo->tm_mday;
    wapdu.nsq103.obj.time.dweek = timeinfo->tm_wday;
    wapdu.nsq103.obj.time.hour = timeinfo->tm_hour;
    wapdu.nsq103.obj.time.min = timeinfo->tm_min;
    wapdu.nsq103.obj.time.mesc = timeinfo->tm_sec * 1000;
    wapdu.nsq103.obj.time.res1 = wapdu.nsq103.obj.time.res2 =
                                     wapdu.nsq103.obj.time.res3 = wapdu.nsq103.obj.time.res4 = 0;
    wapdu.nsq103.obj.time.iv = 0;
    wapdu.nsq103.obj.time.su = 0;

    if (allowSend) {
        send(wapdu);
        ++vs;
        ++numMsgUnack;
    }
    return;
    // TODO: 啥意思捏，为啥return了
    // if (log.isLogging()) {
    //     ss.str("");
    //     ss << "CLOCK SYNCHRONIZATION\n    ADDRESS" << (uint32_t)addr24
    //        << ", TYPE: " << (uint32_t)wapdu.head.type
    //        << ", COT: " << (uint32_t)wapdu.head.cot;

    //     ss << "\n    TIME.YEAR"
    //        << (uint32_t)wapdu.nsq103.obj.time.year                   // 年 2022
    //        << ", TIME.MONTH" << (uint32_t)wapdu.nsq103.obj.time.mon  // 月 5
    //        << ", TIME.DAY" << (uint32_t)wapdu.nsq103.obj.time.dmon   // 日 24
    //        << ", TIME.HOUR" << (uint32_t)wapdu.nsq103.obj.time.hour  // 时 14
    //        << ", TIME.MIN" << (uint32_t)wapdu.nsq103.obj.time.min    // 分 53
    //        << ", TIME.SRC" << (uint32_t)timeinfo->tm_sec;            // 秒 21
    //     log.pushMsg(ss.str().c_str());
    // }
}

/**
 * @brief iec_base::sendMonitorFrame
 */
void iec_base::sendMonitorMessage() {
    struct apdu wapdu;
    stringstream ss;
    wapdu.start = START;
    wapdu.length = 4;
    wapdu.NS = SUPERVISORY;
    wapdu.NR = vr << 1;
    send(wapdu);
    ss.str("");
    ss << "INFO: S(SUPERVISORY), the N(R) is " << wapdu.NR;
    // log.pushMsg(ss.str().c_str());
}

/**
 * @brief iec_base::parse
 * @param papdu
 * @param size  modbus_mapping_t *Mapping,
 * @param isSend - If we want to send the result to server. This parameter
 */
void iec_base::parseMsg(struct apdu *papdu, int size,  bool isSend, QMap<QString, QList<int>>  typeAddress) {
    uint16_t vrReceived;
    stringstream ss;

    if (papdu->start != START) {
        // log.pushMsg("ERROR: no start in frame");
        return;
    }

    // TODO: ca
    //    if (papdu->head.ca != masterAddr && papdu->length > 6) {
    //        log.pushMsg("ERROR: parse ASDU with unexpected origin");
    //        return;
    //    }

    if (size == 6) {  // U格式APDU长度为6（2 + 4）
        switch (papdu->NS) {
            case STARTDTACT: {
                // 子站：发送确认建立通信链路给主站
                // log.pushMsg("receive STARTDTACT");
                sendStartDtCon();
            }
            break;
            case STOPDTACT: {  // 停止数据传送命令
                // log.pushMsg("receive STOPDTACT");
                sendStopDtCon();
            }
            break;
            case STOPDTCON:  // 停止数据传送命令确认
                // TODO:
                break;
            case TESTFRACT: {
                // 链路测试命令
                // log.pushMsg("receive TESTFRACT");
                sendTestfrCon();
            }
            break;
            case SUPERVISORY: {  // S帧
                // log.pushMsg("INFO: receive SUPERVISORY");
                if (vs >= papdu->NR) {  // NOTE: 考虑到NR可能比当前vs小
                    numMsgUnack = vs - papdu->NR;
                    if (numMsgUnack < SERVERK) {
                        allowSend = true;
                    }
                } else {
                    ss.str("");
                    ss << "ERROR: wrong N(R) of SUPERVISORY message="
                       << papdu->NR << ", while current vs is " << vs;
                    // log.pushMsg(ss.str().c_str());
                    // TODO: disconnect
                    return;
                }
            }
            break;
            default:
                // log.pushMsg("ERROR: unknown control message");
                break;
        }
    } else {
        // TODO:
        // code...

        // check vr
        vrReceived = papdu->NS >> 1;
        if (vrReceived != vr) {
            ss.str("");
            ss << "ERROR: N(R) is " << uint32_t(this->vr)
               << ", but the N(S) of I message is " << uint32_t(vrReceived);
            // log.pushMsg(ss.str().c_str());
            if (ifCheckSeq) {
                ss.str("");
                ss << "WARNING: start to disconnect tcp";
                // log.pushMsg(ss.str().c_str());
                tcpDisconnect();
                return;
            }
        } else {
            ++vr;
        }
        // check vs主站收到的 papdu->NR 主站发送的, 主站收到的如果小于从站发送的就会return
        if (vs >= papdu->NR) {
            numMsgUnack = vs - papdu->NR;
            if (numMsgUnack < SERVERK) {
                allowSend = true;
            }
        }
        // else { //2024 1 27 不用校验请求和响应的次数大小是否相等先
        //     ss.str("");
        //     ss << "ERROR: parse wrong N(R) of msg "
        //        << umapType2String[papdu->head.type] << ", the N(R) is "
        //        << papdu->NR << ", while current vs is " << vs;
        //     // log.pushMsg(ss.str().c_str());
        //     // TODO: disconnect
        //     return;
        // }

        ss.str("");
        if (isSend) {
            ss << "INFO: receive ";
        }

        ss << umapType2String[papdu->head.type] << "\n";
        ss << "    CA: " << uint32_t(papdu->head.ca)
           << "; TYP: " << uint32_t(papdu->head.type)
           << "; COT: " << int(papdu->head.cot)
           << "; SQ: " << uint32_t(papdu->head.sq)
           << "; NUM: " << uint32_t(papdu->head.num);
        //     68 12 00 00 00 00 32 01 06 00 64 09 9e 44 00 98 78 f3 3f 00
        //     起始字节=68 数据单元长度(APDU)=18 I格式帧 发送序号(NS)=0 接收序号(NR)=0 TI= 50
        //     VSQ=01 SQ=0 INFONUM=1 COT= 06 T=0 PN=0 CAUSE =6 COA =2404 C_SE_NC_1
        //     设定值命令, 短浮点数       肯定认可    激活 点号=17566  值=1.902118 执行
        //     从站发送
        qDebug() << ss.str().c_str();
        // log.pushMsg(ss.str().c_str());
        uint32_t addr24;
        // single_YX value
        uint8_t statusSYX;
        uint8_t res;

        switch (papdu->head.type) {
            case M_SP_NA_1: {  // 1: single-point information
                struct iec_type1 *pobj;
                // TODO:

            }
            break;
            case M_SP_TA_1:  // 2: single-point information with time
                // tag(cp24time2a)
                break;
            case M_BO_NA_1: {  // 7: bitstring of 32 bits
                // 监视方向过程信息的应用服务数据单元
                struct iec_type7 *pobj;
                struct iec_obj *piecarr = new iec_obj[papdu->head.num];
                uint32_t addr24 = 0;  // 24位信息对象地址

                for (int i = 0; i < papdu->head.num; ++i) {
                    if (papdu->head.sq) {
                        pobj = &papdu->sq7.obj[i];
                        if (i == 0) {
                            addr24 = papdu->sq7.ioa16 +
                                     ((uint32_t)papdu->sq7.ioa8 << 16);
                        } else {
                            ++addr24;
                        }
                    } else {
                        pobj = &papdu->nsq7[i].obj;
                        addr24 = papdu->nsq7[i].ioa16 +
                                 ((uint32_t)papdu->nsq7[i].ioa8 << 16);
                    }
                    piecarr[i].address = addr24;
                    piecarr[i].type = papdu->head.type;
                    piecarr[i].ca = papdu->head.ca;
                    piecarr[i].cause = papdu->head.cot;
                    piecarr[i].pn = papdu->head.pn;
                    piecarr[i].bsi = pobj->bsi;
                    piecarr[i].value = (float)pobj->bsi;
                    piecarr[i].ov = pobj->ov;
                    piecarr[i].bl = pobj->bl;
                    piecarr[i].sb = pobj->sb;
                    piecarr[i].nt = pobj->nt;
                    piecarr[i].iv = pobj->iv;
                }
                dataIndication(piecarr, papdu->head.num);
                delete[] piecarr;
            }
            break;
            case M_BO_TA_1:  // 8: bitstring of 32 bits with time
                // tag(cp24time2a)
                break;
            case C_SC_NA_1:  // 45: single command
                struct iec_type45 *pobj;
                pobj = &papdu->nsq45.obj;
                if (papdu->head.cot == ACTIVATION) {
                    qDebug() << "传送原因：激活; ";
                    statusSYX = 1;
                } else if (papdu->head.cot == DEACTIVATION) {
                    qDebug() << "传送原因：停止激活; ";
                    statusSYX = 0;
                }
                addr24 = papdu->nsq45.ioa16 + ((uint32_t)papdu->nsq45.ioa8 << 16);
                qDebug() << " ADDRESS: " << addr24
                         << "; SCS: " << uint32_t(pobj->scs)
                         << "; QU: " << uint32_t(pobj->qu)
                         << "; S/E: " << uint32_t(pobj->se);
                for (auto item : publishDatas)
                {
                    for (auto itemData : item)
                    {
                        if (itemData.Type == "char" && itemData.id == addr24)
                        {
                            QString plcNameMSG =  itemData.nodeName + " ";
                            QString varNameMSG =  itemData.var_name + " ";
                            QString varlueMSG = QString::number(pobj->scs) + "";
                            qDebug() << " before value " << mapping->tab_bits[addr24] ;
                            mapping->tab_bits[addr24] = pobj->scs;
                            qDebug() << " after value " << mapping->tab_bits[addr24] ;
                            QString sendData = plcNameMSG + varNameMSG + varlueMSG;
                            const QByteArray send_data = sendData.toUtf8();
                            window->controlback(itemData.nodeIp, send_data);
                        }
                    }
                }
                // singleYkCon();激活不写
                break;
            case C_DC_NA_1: {  // 46: double command
                struct iec_type46 *pobj;
                pobj = &papdu->nsq46.obj;
                addr24 = papdu->nsq46.ioa16 + ((uint32_t)papdu->nsq46.ioa8 << 16);
                for (auto item : publishDatas)
                {
                    for (auto itemData : item)
                    {
                        if (itemData.Type == "char" && itemData.id == addr24)
                        {
                            QString plcNameMSG =  itemData.nodeName + " ";
                            QString varNameMSG =  itemData.var_name + " ";
                            QString varlueMSG = QString::number(pobj->dcs) + "";
                            QString sendData = plcNameMSG + varNameMSG + varlueMSG;
                            const QByteArray send_data = sendData.toUtf8();
                            window->controlback(itemData.nodeIp, send_data);
                        }
                    }
                }
            }
            break;
            case C_RC_NA_1: {  // 47: regulating step command
                struct iec_type47 *pobj;
                pobj = &papdu->nsq47.obj;
                ss.str("");
                if (papdu->head.cot == ACTIVATION) {
                    ss << "传送原因：激活; ";
                } else if (papdu->head.cot == DEACTIVATION) {
                    ss << "传送原因：停止激活; ";
                }
                // TODO: pn, t, ...
                uint32_t addr24 = papdu->nsq47.ioa16 +
                                  ((uint32_t)papdu->nsq47.ioa8 << 16);
                ss << "ADDRESS: " << addr24
                   << "; DCS: " << uint32_t(pobj->rcs)
                   << "; QU: " << uint32_t(pobj->qu)
                   << "; S/E: " << uint32_t(pobj->se);
                qDebug() << ss.str().c_str();
            }
            break;

            case C_SE_NA_1: {  // 48: set-point normalised command 设定命令,
                // 规一化值
                struct iec_type48 *pobj;
                pobj = &papdu->nsq48.obj;

                ss.str("");
                if (papdu->head.cot == ACTIVATION) {
                    ss << "传送原因：激活; ";
                } else if (papdu->head.cot == DEACTIVATION) {
                    ss << "传送原因：停止激活; ";
                }
                // TODO: pn, t, ...
                uint32_t addr24 = papdu->nsq48.ioa16 +
                                  ((uint32_t)papdu->nsq48.ioa8 << 16);
                ss << " ADDRESS: " << addr24
                   << "; NVA: " << uint32_t(pobj->nva)
                   << "; S/E: " << uint32_t(pobj->se);
                qDebug() << ss.str().c_str();
                // window->showDialog(m_port, addr24, pobj->nva);
            }
            break;
            // 50:set-point short floating point command
            case   C_SE_NC_1: {
                // 遥调设置值 float
                struct iec_type50 *pobj;
                pobj = &papdu->nsq50.obj;
                ss.str("");
                if (papdu->head.cot == ACTIVATION) {
                    ss << "传送原因：激活; ";
                } else if (papdu->head.cot == DEACTIVATION) {
                    ss << "传送原因：停止激活; ";
                }
                // TODO: pn, t, ...
                uint32_t addr24 = papdu->nsq48.ioa16 + ((uint32_t)papdu->nsq48.ioa8 << 16);
                ss << " ADDRESS: " << addr24
                   << "; NVA: " << float(pobj->mv)
                   << "; S/E: " << uint32_t(pobj->se);
                qDebug() << ss.str().c_str();
                int trueAddr = addr24 * 2 + 1;
                window->setHoldingRegisterValue(m_port,  trueAddr, pobj->mv, "bdca");
                uint16_t intvalue1 = mapping->tab_registers[ trueAddr ] ;
                uint16_t intvalue3 = mapping->tab_registers[ trueAddr + 1 ] ;
                QByteArray array;
                QDataStream stream(&array, QIODevice::WriteOnly);
                stream << intvalue1;
                stream << intvalue3;
                float fValue = Xochange::ByteToFloat(array[2], array[3], array[0], array[1]);
                qDebug() << "遥调 part 2404"   << " addr " << trueAddr << " value " << fValue;
                for (auto item : publishDatas)
                {
                    for (auto itemData : item)
                    {
                        if (itemData.Type != "char" && itemData.id == addr24)
                        {
                            QString plcNameMSG =  itemData.nodeName + " ";
                            QString varNameMSG =  itemData.var_name + " ";
                            QString varlueMSG = QString::number(fValue) + "";
                            QString sendData = plcNameMSG + varNameMSG + varlueMSG;
                            const QByteArray send_data = sendData.toUtf8();
                            window->controlback(itemData.nodeIp, send_data);
                        }
                    }
                }


            }
            break;
            // 51: bitstring of 32 bit command
            case C_BO_NA_1: {
            }
            break;

            case C_SC_TA_1: {  // 58: single command with time tag
                struct iec_type58 *pobj;
                pobj = &papdu->nsq58.obj;

                // if (log.isLogging()) {
                //     ss.str("");
                //     if (papdu->head.cot == ACTIVATION) {
                //         ss << "传送原因：激活; ";
                //     } else if (papdu->head.cot == DEACTIVATION) {
                //         ss << "传送原因：停止激活; ";
                //     }
                //     // TODO: pn, t, ...
                //     uint32_t addr24 = papdu->nsq58.ioa16 +
                //                       ((uint32_t)papdu->nsq58.ioa8 << 16);
                //     ss << "    ADDRESS: " << addr24
                //        << "; SCS: " << uint32_t(pobj->scs)
                //        << "; QU: " << uint32_t(pobj->qu)
                //        << "; S/E: " << uint32_t(pobj->se);
                //     // TODO
                //     //                ss << "\n    TIME.YEAR: " <<
                //     //                uint32_t(pobj->time.year)
                //     //                   << "; TIME.MONTH: " <<
                //     //                   uint32_t(pobj->time.mon)      // 月 5
                //     //                   << "; TIME.DAY: " <<
                //     //                   uint32_t(pobj->time.dmon)       // 日
                //     //                   24
                //     //                   << "; TIME.HOUR: " <<
                //     //                   uint32_t(pobj->time.hour)      // 时 14
                //     //                   << "; TIME.MIN: " <<
                //     //                   uint32_t(pobj->time.min)        // 分
                //     //                   53
                //     //                   << "; TIME.SRC: " << uint32_t(pobj->;
                //     //                   // 秒 21

                //     log.pushMsg(ss.str().c_str());
                // }

            }
            break;

            case M_EI_NA_1:  // 70:end of initialization(初始化结束)
                break;

            case C_IC_NA_1: {
                // 100: general interrogation
                // 从站：总召唤确认、发送遥测与遥信数据、总召唤结束
                // 总召唤确认
                generalInterrogationCon();
                // 发送遥测与遥信数据
                sendYX(1, true, typeAddress); // 遥信
                // sendYK(2, true, Mapping, typeAddress); // 遥控
                sendYC(13, true, typeAddress);   // 遥测
                sendYD(13, true, typeAddress); // 遥调
                // 总召唤结束
                generalInterrogationEnd();
            }
            break;
            case C_CS_NA_1: {  // 103: clock sync
                struct iec_obj *piecarr = new iec_obj[1];
                addr24 = 0;  // 24位信息对象地址

                /**
                     * NOTE:被控站初始化后，在时钟同步命令前上传的所有带时标报文其时标中的无效（
                     * invalid）位应
                     * 置Ⅰ(即时标无效)，其后置О（即时标有效);若被控站在站对时周期内未收到控制站发出的“时钟同步
                     * 命令”，则 invalid位也应置l;
                     */
                isClockSYnc = true;

                addr24 =
                    papdu->nsq103.ioa16 + ((uint32_t)papdu->nsq103.ioa8 << 16);
                piecarr[0].address = addr24;
                piecarr[0].type = papdu->head.type;
                piecarr[0].ca = papdu->head.ca;
                piecarr[0].cause = papdu->head.cot;
                piecarr[0].pn = papdu->head.pn;
                piecarr[0].time = papdu->nsq103.obj.time;

                dataIndication(piecarr, 1);
                delete[] piecarr;

                // send confirm message
                sendClockSyncCon();
            }
            break;
            default:
                break;
        }
    }

    // TODO: 修改策略
    if (t2Timeout < 0) {
        t2Timeout = T2;
    } else if (t2Timeout == 0) {
        t2Timeout = -1;
        sendMonitorMessage();
    } else {  // t2Timeout > 0
        --t2Timeout;
    }

    t3Timeout = T3;

    // check parameter `k` and `w`
    if (isSend) {
        ++numMsgReceived;
        if (numMsgReceived == SERVERW) {
            sendMonitorMessage();
            numMsgReceived = 0;
        }
    }
}

/**
 * @brief iec_base::showMessage - Show the message in a appropriate way.
 * @param buf       -
 * @param size      - bytes number.
 * @param isSend    - send or receive message.
 */
void iec_base::showMessage(const char *msg, int size, bool isSend) {
    char buf[200];
    char buf1[200];
    strncpy(buf1, msg, 16);

    // if (log.isLogging()) {
    //     memset(buf, 0, sizeof(buf));
    //     if (isSend) {
    //         sprintf(buf, "send    --> size: (%03d) ", size);
    //     } else {
    //         sprintf(buf, "receive <-- size: (%03d) ", size);
    //     }
    //     int cnt = 20, i;
    //     for (i = 0; i < size && i < cnt; ++i) {
    //         sprintf(buf + strlen(buf), "%02x ", (uint8_t)msg[i]);
    //     }
    //     if (size > cnt) {
    //         sprintf(buf + strlen(buf), "...");
    //     }
    //     log.pushMsg(buf);
    // }
}
