#include "rdsmodbusslave.h"

#include <QDebug>
#include <QEventLoop>
#include <QSocketNotifier>
#include <QUdpSocket>
#include "configmanager.h"
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QThreadPool>
#include <QtConcurrent>
#include "xochange.h"
using namespace config;
#ifdef _WIN32
    typedef int socklen_t;
#endif

RDSModbusSlaveThread::RDSModbusSlaveThread(int  port, modbus_mapping_t *mapping,  QObject *parent)
    : QThread(parent) {
    m_port = port;
    QMap<QString, QMap<int, config::publishNode>> publishs = ConfigManager::get_instance().m_publishConfigs;
    QMap<int, config::publishNode> modbus_publishs = publishs.value("modbus");
    config::publishNode node = modbus_publishs.value(m_port);
    modbusPortPublishdatas =  node.publishDatas;
    MODBUSmapping = mapping;
    connect(this, &RDSModbusSlaveThread::writeModbusDataSignal, this, &RDSModbusSlaveThread::writeModbusDataSlot);
}

RDSModbusSlaveThread::~RDSModbusSlaveThread() {
    // for (QMap< int, portCtxs * > :: iterator it =  slaves.begin(); it != slaves.end(); it++)
    // {
    //     modbus_close(it.value()->ctx);
    //     modbus_free(it.value()->ctx);
    // }
}

void RDSModbusSlaveThread:: publishDatas()
{

}

void RDSModbusSlaveThread:: writeModbusDataSlot(QByteArray msg, QString ip)
{
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost(ip, ConfigManager::get_instance().m_nodeConfig.control_port);
    tcpSocket->waitForConnected(500);
    tcpSocket->write(msg);
    qDebug() << " wirte to master " << msg;
}


// bool RDSModbusSlaveThread::setDoubleYXCoil(int port, int coilStartaddress,
//         uint8_t status) {
//     iec104_mapping *mapping =  IEC104mappings.value(port);
//     if (coilStartaddress > (m_numBits)) {
//         return false;
//     }
//     int startBits = mapping->double_yx_start_bits;
//     int mapping_address = coilStartaddress - startBits;
//     if (mapping_address < 0 || mapping_address >= mapping->double_yx_bits) {
//     } else {
//         mapping->tab_double_yx_bits[mapping_address] = status ? ON : OFF;
//     }
//     return true;
// }
// bool RDSModbusSlaveThread::setSingleYXCoil(int port, int coilStartaddress,
//         uint8_t status) {
//     iec104_mapping *mapping =  IEC104mappings.value(port);
//     // qDebug() << " setSingleYXCoil " << "value = " << status;

//     if (coilStartaddress > (m_numBits)) {
//         return false;
//     }
//     int startBits = mapping->single_yx_start_bits;
//     int mapping_address = coilStartaddress - startBits;
//     if (mapping_address < 0 || mapping_address >= mapping->single_yx_bits) {
//     } else {
//         // qDebug() << " setSingleYXCoil " << "beforevalue = " <<  mapping->tab_single_yx_bits[mapping_address] ;
//         mapping->tab_single_yx_bits[mapping_address] = status ? ON : OFF;
//     }
//     return true;
// }


// bool RDSModbusSlaveThread::setYCBYTES(int port, int registerStartaddress, float Value, QString sort)
// {
//     if (registerStartaddress > (m_yc_bytes - 2)) {
//         return false;
//     }
//     slavemutex.lock();
//     iec104_mapping *mapping = IEC104mappings.value(port);
//     qDebug() << " ycBYTES ?????" << registerStartaddress << "???" << Value << "sort " << sort << "port " << port;
//     qDebug() << " ycBYTES " << "beforevalue = " <<  mapping->tab_yc_bytes[registerStartaddress] ;
//     switch (sort[0].toLatin1()) {
//         case 'a':
//             modbus_set_float_abcd(Value, &mapping->tab_yc_bytes[registerStartaddress]);
//             break;
//         case 'd':
//             modbus_set_float_dcba(Value, &mapping->tab_yc_bytes[registerStartaddress]);
//             break;
//         case 'b':
//             modbus_set_float_badc(Value, &mapping->tab_yc_bytes[registerStartaddress]);
//             break;
//         case 'c':
//             modbus_set_float_cdab(Value, &mapping->tab_yc_bytes[registerStartaddress]);
//             break;
//     }
//     slavemutex.unlock();
//     return true;
// }

void RDSModbusSlaveThread::run() {
    std::thread loop([this]() {
        while (true) {
            recieveMessages();
        }
    });
    loop.detach();
    return;
}

// void RDSModbusSlaveThread::run() {
//     int server_socket = -1;
//     modbus_t *ctx ;
//     ctx = modbus_new_tcp(NULL, m_port);
//     modbus_set_debug(ctx, FALSE);
//     if (MODBUSmapping == NULL)
//     {
//         modbus_free(ctx);
//     } else {
//         qDebug() << " port " << m_port << " is running";
//     }
//     //开始监听端口
//     server_socket = modbus_tcp_listen(ctx, 1);
//     if (server_socket == -1)
//     {
//         modbus_free(ctx);
//     }
//     //开始接收数据
//     modbus_tcp_accept(ctx, &server_socket);
//     while (1)
//     {   uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
//         int rc;
//         rc = modbus_receive(ctx, query);
//         if (rc >= 0)
//         {
//             int intt = 0;
//             modbus_reply(ctx, query, rc, MODBUSmapping, &intt);
//             uint16_t address = (query[8] << 8) + query[9];
//             int function = query[7];
//             handleWriteRes(function, address, intt);
//         } else {
//             modbus_close(ctx);
//             modbus_tcp_accept(ctx, &server_socket);
//         }
//     }
//     modbus_mapping_free(MODBUSmapping);
//     modbus_close(ctx);
//     modbus_free(ctx);
// }
void RDSModbusSlaveThread::recieveMessages() {
    modbus_t *ctx ;
    ctx = modbus_new_tcp(NULL, m_port);
    m_modbusSocket = modbus_tcp_listen(ctx, 1);
    uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
    int master_socket = 0;
    int rc = 0;
    fd_set refset;
    fd_set rdset;
    /* Maximum file descriptor number */
    int fdmax;
    /* Clear the reference set of socket */
    FD_ZERO(&refset);
    /* Add the server socket
     * m_modbusSocket 是和指定ip和port的从站的连接 作为从站的数据来源,后面的Socket是新的连接 */
    FD_SET(m_modbusSocket, &refset);
    qDebug() << " init m_modbusSocket" << QString::number(m_modbusSocket);
    /* Keep track of the max file descriptor */
    fdmax = m_modbusSocket;
    while (true) {
        rdset = refset;
        if (select(fdmax + 1, &rdset, NULL, NULL, NULL) == -1) {
            qDebug() << "Server select() failure ";
            break;
        }
        /* Run through the existing connections looking for data to be
         * read */
        for (master_socket = 0; master_socket <= fdmax; master_socket++) {
            if (!FD_ISSET(master_socket, &rdset)) {//当描述符fd在描述符集fdset中返回非零值，否则，返回零
                continue;
            }
            QDateTime time =  QDateTime::currentDateTime();
            time.toString(Qt::ISODateWithMs);
            // qDebug() << " master_socket " << QString::number(master_socket) << " time " << time;
            if (master_socket == m_modbusSocket) {
                /* A client is asking a new connection */
                socklen_t addrlen;
                struct sockaddr_in clientaddr;
                int newfd;
                /* Handle new connections */
                addrlen = sizeof(clientaddr);
                memset(&clientaddr, 0, sizeof(clientaddr));
                //accept函数用于提取套接字 上挂起连接队列中的第一个连接。 然后，它会创建并返回新套接字的句柄。 新创建的套接字是将处理实际连接的套接字;
                // 它具有 与套接字相同的属性，包括向 WSAAsyncSelect 或 WSAEventSelect 函数注册的异步事件。
                //如果队列中没有挂起的连接，并且套接字标记为阻塞，则 accept 函数可以阻止调用方，直到存在连接。 如果套接字标记为非阻止，并且队列中没有挂起的连接，
                // 则接受 将返回如下所述的错误。 成功完成 accept 返回新的套接字句柄后，接受的套接字不能用于接受更多连接。 原始套接字保持打开状态，并侦听新的连接请求。
                newfd = accept(m_modbusSocket, (struct sockaddr *)&clientaddr, &addrlen);
                if (newfd == -1) {
                    perror("Server accept() error");
                } else {
                    FD_SET(newfd, &refset);

                    if (newfd > fdmax) {
                        /* Keep track of the maximum */
                        fdmax = newfd;
                    }
                    qDebug() << " New connection from " << inet_ntoa(clientaddr.sin_addr) << ":" << QString::number(clientaddr.sin_port) << " on socket "  << QString::number(newfd)
                             << " m_modbusSocket " << QString::number(m_modbusSocket) << " fdmax " << QString::number(fdmax);
                }
            } else {//已经存在的请求数据的连接 又不是作为数据源的和主站的连接 执行相应的读取或写入操作
                modbus_set_socket(ctx, master_socket);
                rc = modbus_receive(ctx, query);
                if (rc > 0) {
                    uint16_t address;
                    if (ctx == NULL) {
                        errno = EINVAL;
                    }
                    int  function = query[7];
                    address = (query[8] << 8) + query[9];
                    double resvalue ;
                    modbus_reply(ctx, query, rc, MODBUSmapping,  &resvalue);
                    handleWriteRes(function,  address, resvalue);
                    if (rc == -1) {
                        /* This example server in ended on connection closing or
                         * any errors. */
                        printf("Connection closed on socket %d\n", master_socket);
#ifdef _WIN32
                        closesocket(master_socket);
#else
                        close(master_socket);
#endif
                        /* Remove from reference set */
                        FD_CLR(master_socket, &refset);

                        if (master_socket == fdmax) {
                            fdmax--;
                        }
                    }
                }
            }
        }
    }
}



// bool RDSModbusSlaveThread::modbus_set_slave_id(int id) {
//     int rc = modbus_set_slave(ctx, id);
//     if (rc == -1) {
//         // fprintf(stderr, "Invalid slave id\n");
//         qDebug() << " Invalid slave id ";
//         modbus_free(ctx);
//         return false;
//     }
//     return true;
// }
/* Allocates 3 arrays to store singleYX bits,doubleYX bits , YC registers
   The pointers are stored in IEC104_mapping structure.
   The IEC104_mapping_new_start_address() function shall return the new allocated
   structure if successful. Otherwise it shall return NULL and set errno to
   ENOMEM. */
// IEC104_mapping *RDSModbusSlaveThread::IEC104_mapping_new_start_address(
//     unsigned int start_single_yx_bits, unsigned int single_yx_bits,
//     unsigned int start_double_yx_bits, unsigned int double_yx_bits,
//     unsigned int start_yc_registers, unsigned int yc_registers)
// {
//     IEC104_mapping *iec104_mappingRes;

//     iec104_mappingRes = (IEC104_mapping *)malloc(sizeof(IEC104_mapping));
//     if (iec104_mappingRes == NULL) {
//         return NULL;
//     }

//     /* 0X */
//     iec104_mappingRes->single_yx_bits = single_yx_bits;
//     iec104_mappingRes->single_yx_start_bits = start_single_yx_bits;
//     if (single_yx_bits == 0) {
//         iec104_mappingRes->tab_single_yx_bits = NULL;
//     } else {
//         /* Negative number raises a POSIX error */
//         iec104_mappingRes->tab_single_yx_bits =
//             (uint8_t *) malloc(single_yx_bits * sizeof(uint8_t));
//         if (iec104_mappingRes->tab_single_yx_bits == NULL) {
//             free(iec104_mappingRes);
//             return NULL;
//         }
//         memset(iec104_mappingRes->tab_single_yx_bits, 0, single_yx_bits * sizeof(uint8_t));
//     }

//     /* 1X */
//     iec104_mappingRes->double_yx_bits = double_yx_bits;
//     iec104_mappingRes->double_yx_start_bits = start_double_yx_bits;
//     if (double_yx_bits == 0) {
//         iec104_mappingRes->tab_double_yx_bits = NULL;
//     } else {
//         iec104_mappingRes->tab_double_yx_bits =
//             (uint8_t *) malloc(double_yx_bits * sizeof(uint8_t));
//         if (iec104_mappingRes->tab_double_yx_bits == NULL) {
//             free(iec104_mappingRes->tab_single_yx_bits);
//             free(iec104_mappingRes);
//             return NULL;
//         }
//         memset(iec104_mappingRes->tab_double_yx_bits, 0, double_yx_bits * sizeof(uint8_t));
//     }

//     /* 2X */
//     iec104_mappingRes->yc_bytes = yc_registers;
//     iec104_mappingRes->yc_start_bytes = start_yc_registers;
//     if (yc_registers == 0) {
//         iec104_mappingRes->tab_yc_bytes = NULL;
//     } else {
//         iec104_mappingRes->tab_yc_bytes =
//             (uint16_t *) malloc(yc_registers * sizeof(uint16_t));
//         if (iec104_mappingRes->tab_yc_bytes == NULL) {
//             free(iec104_mappingRes->tab_double_yx_bits);
//             free(iec104_mappingRes->tab_single_yx_bits);
//             free(iec104_mappingRes);
//             return NULL;
//         }
//         memset(iec104_mappingRes->tab_yc_bytes, 0, yc_registers * sizeof(uint16_t));
//     }
//     return iec104_mappingRes;
// }

// IEC104_mapping *RDSModbusSlaveThread::IEC104_mapping_new(int single_yx_bits, int double_yx_bits,
//         int yc_registers)
// {
//     return IEC104_mapping_new_start_address(
//                0, single_yx_bits, 0, double_yx_bits, 0, yc_registers);
// }

void RDSModbusSlaveThread:: handleWriteRes(int function,  uint16_t address, double resvalue) {
    QString varName = "";
    QString plcName = "";
    QString ip = "";
    if (function == 6 || function == 5 || function == 15 || function == 16)
    {
        for (auto datapub = modbusPortPublishdatas.begin(); datapub != modbusPortPublishdatas.end(); datapub++)
        {
            QMap<QString, dataConfig>temp = datapub.value();
            for (auto tempitem = temp.begin(); tempitem != temp.end(); tempitem++)
            {
                dataConfig item2 = tempitem.value();
                if (item2.modAddress == address)
                {
                    varName = item2.var_name;
                    plcName = item2.nodeName;
                    ip = item2.nodeIp;
                };
            }
        }
        if (varName != "")
        {
            QString sendData = plcName + " " + varName + " " + QString::number(resvalue);
            qDebug() << " send master " << sendData;
            const QByteArray send_data = sendData.toUtf8();
            emit this->writeModbusDataSignal(send_data, ip);
        }
    }
}
