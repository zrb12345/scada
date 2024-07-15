// #include "analysis_modbus.h"

// analysis_modbus::analysis_modbus()
// {
//     readseting = new QSettings("dataini/Data.ini", QSettings::IniFormat);
//     m_thread = new QThread(this);
//     this->moveToThread(m_thread);
//     readseting->moveToThread(m_thread);
//     m_thread->start();

// }
// analysis_modbus::~analysis_modbus()
// {
//     if (m_thread->isRunning())
//     {
//         m_thread->quit();
//         m_thread->wait();
//         while (true == m_thread->isRunning());
//     }
//     readseting->deleteLater();
//     m_thread->deleteLater();
// }
// //接收报文并处理状态
// void analysis_modbus::recvModbusMsg(QByteArray msg, quint8 addr)
// {
//     qDebug() << "数据解析线程:" << QThread::currentThreadId();
//     if (msg.isEmpty() == false)
//     {
//         recvModbusmsgArray = msg;
//         mb_addr = addr;
//         MB_satae state = parse_Modbus_Msg(recvModbusmsgArray);
//         parse_Modbus_MB_satae(state);
//     }
// }
// //读取状态
// MB_satae analysis_modbus::parse_Modbus_Msg(QByteArray ba)
// {
//     //打印报文和长度
//     // qDebug() << ba.toHex().toUpper()  << ba.length() ;
//     //解析报文头

//     //判断帧长度
//     if (ba.length() > 259 || ba.length() < 12)
//     {
//         errorMsg = "报文长度过长或过短不正确 Lenghtrerror";
//         return MB_SLAVE_STATE_PACKET_OTHER;
//         qDebug() << "this is Lenghtrerror";
//     }
//     //读取报文数据段字节计数
//     quint8 rdsize = (quint8)ba.at(5);
//     //读取报文数据段长度
//     QByteArray drsize = ba.mid(6, ba.size());

//     //拷贝协议标识符
//     mb_protocol = ((quint8)ba[2]) * 256 + (quint8)ba[3];

//     //判断协议标识符
//     if (mb_protocol != 0)
//     {
//         errorMsg = "协议标识符不正确 mb_protocolerror";
//         return MB_SLAVE_STATE_PACKET_OTHER;
//     }
//     //应用数据单元ADU长度判断
//     quint16 ADULength;
//     ADULength = ((quint8)ba[4] << 8) | (quint8)ba[5];
//     if (ADULength != (ba.size() - 6))
//     {
//         errorMsg = "字节长度错误，请求报文中字节长度与实际应用数据单元长度不一致! Lenghtrerror";
//         return MB_SLAVE_STATE_PACKET_OTHER;
//     }
//     //判断从机地址
//     // if (ba[6] != mb_addr)
//     // {
//     //     errorMsg = "不是给本机的 Addrerror";
//     //     qDebug() << "this is Addrerror";
//     //     return MB_SLAVE_STATE_PACKET_OTHER;
//     // }
//     //解析数据单元
//     //判断功能码
//     switch (ba[7])
//     {
//         case READER_COIL_CODE:
//             mb_code = READER_COIL_CODE;
//             qDebug() << "this is 01 function";
//             //起始地址
//             mb_startaddr = ((quint8)ba[8]) * 256 + (quint8)ba[9];
//             //数据量
//             mb_num = ((quint8)ba[10]) * 256 + (quint8)ba[11];
//             if (mb_num > 2000 || mb_num == 0)
//             {
//                 qDebug() << "this is dataNumerror";
//                 errorMsg = "03异常数据数量错误 dataNumerror";
//                 return MB_SLAVE_STATE_DATA_ERROR;
//             } else if ((mb_startaddr + mb_num - 1) > 65535)
//             {
//                 qDebug() << "this is dataAddrerror";
//                 errorMsg = "02异常数据地址错误 dataAddrerror";
//                 return MB_SLAVE_STATE_DATAADDR_ERROR;
//             }
//             else if (ba.length() > 12 || (rdsize != drsize.size()))
//             {
//                 errorMsg = "读取报文长度或字节数与数据段不正确 Lenghtrerror";
//                 qDebug() << "this is Lenghtrerror";
//                 return MB_SLAVE_STATE_PACKET_SIZELENTH;
//             }
//             else
//             {
//                 return MB_SLAVE_STATE_PACKET_PROCESS;
//             }
//             break;
//         case Read_REGISTER:
//             mb_code = Read_REGISTER;
//             qDebug() << "this is 03 function";
//             //起始地址
//             mb_startaddr = ((quint8)ba[8]) * 256 + (quint8)ba[9];
//             //数据量
//             mb_num = ((quint8)ba[10]) * 256 + (quint8)ba[11];
//             if (mb_num > 125 || mb_num == 0)
//             {
//                 qDebug() << "this is dataNumerror";
//                 errorMsg = "03异常数据数量错误 dataNumerror";
//                 return MB_SLAVE_STATE_DATA_ERROR;
//             } else if ((mb_startaddr + mb_num - 1) > 65535)
//             {
//                 qDebug() << "this is dataAddrerror";
//                 errorMsg = "02异常数据地址错误 dataAddrerror";
//                 return MB_SLAVE_STATE_DATAADDR_ERROR;
//             }
//             else if (ba.length() > 12 || (rdsize != drsize.size()))
//             {
//                 errorMsg = "读取报文长度或字节数与数据段不正确 Lenghtrerror";
//                 qDebug() << "this is Lenghtrerror";
//                 return MB_SLAVE_STATE_PACKET_SIZELENTH;
//             }
//             else
//             {
//                 return MB_SLAVE_STATE_PACKET_PROCESS;
//             }
//             break;
//         case WRITE_COIL:
//             mb_code = WRITE_COIL;
//             //写数据字节数
//             csize = (quint8)ba.at(12);
//             //数据段字节数
//             csizes = ba.mid(13, ba.size());
//             //数量
//             wnum = BondTwoUint8ToUint16((quint8)ba.at(10), (quint8)ba.at(11));
//             //起始地址
//             mb_startaddr = ((quint8)ba[8]) * 256 + (quint8)ba[9];
//             //数据量
//             mb_num = ((quint8)ba[10]) * 256 + (quint8)ba[11];
//             qDebug() << "this is 0f function";
//             if (mb_num > 1968 || mb_num == 0)
//             {
//                 qDebug() << "this is dataNumerror";
//                 errorMsg = "03异常数据数量错误 dataNumerror";
//                 return MB_SLAVE_STATE_DATA_ERROR;
//             } else if ((mb_startaddr + mb_num - 1) > 65535)
//             {
//                 qDebug() << "this is dataAddrerror";
//                 errorMsg = "02异常数据地址错误 dataAddrerror";
//                 return MB_SLAVE_STATE_DATAADDR_ERROR;
//             }
//             else if (csize != csizes.size() || ((wnum + 7) / 8) != csize)
//             {
//                 errorMsg = "写入字节与数据段长度或数量与字节数不正确 Lenghtrerror";
//                 qDebug() << "this is Lenghtrerror";
//                 return MB_SLAVE_STATE_PACKET_SIZELENTH;
//             }
//             else
//             {
//                 return MB_SLAVE_STATE_PACKET_PROCESS;
//             }
//             break;
//         case WRITE_REGISTER:
//             mb_code = WRITE_REGISTER;
//             qDebug() << "this is 10 function";
//             //写
//             csize = (quint8)ba.at(12);
//             csizes = ba.mid(13, ba.size());
//             wnum = BondTwoUint8ToUint16((quint8)ba.at(10), (quint8)ba.at(11));
//             //起始地址
//             mb_startaddr = ((quint8)ba[8]) * 256 + (quint8)ba[9];
//             //数据量
//             mb_num = ((quint8)ba[10]) * 256 + (quint8)ba[11];
//             if (mb_num > 123 || mb_num == 0)
//             {
//                 qDebug() << "this is dataNumerror";
//                 errorMsg = "03异常数据数量错误dataNumerror";
//                 return MB_SLAVE_STATE_DATA_ERROR;
//             } else if ((mb_startaddr + mb_num - 1) > 65535)
//             {
//                 qDebug() << "this is dataAddrerror";
//                 errorMsg = "02异常数据地址错误 dataAddrerror";
//                 return MB_SLAVE_STATE_DATAADDR_ERROR;
//             }
//             else if (csize != csizes.size() || (wnum * 2 != csize))
//             {
//                 errorMsg = "写入字节与数据段长度或数量与字节数不正确 Lenghtrerror";
//                 qDebug() << "this is Lenghtrerror";
//                 return MB_SLAVE_STATE_PACKET_SIZELENTH;
//             }
//             else
//             {
//                 return MB_SLAVE_STATE_PACKET_PROCESS;
//             }
//             break;
//         default:
//             errorMsg = "功能码不支持 functionerror";
//             mb_code = ba[7];
//             return MB_SLAVE_STATE_FUNCTION_ERROR;
//             break;
//     }
// }
// //状态处理
// void analysis_modbus::parse_Modbus_MB_satae(MB_satae satae)
// {
//     switch (satae)
//     {
//         case MB_SLAVE_STATE_PACKET_PROCESS:
//             switch (mb_code)
//             {
//                 case 1:
//                     func_01();
//                     break;
//                 case 3:
//                     func_03();
//                     break;
//                 case 15:
//                     func_0f();
//                     break;
//                 case 16:
//                     func_10();
//                     break;
//             }
//             break;
//         //异常处理
//         case MB_SLAVE_STATE_DATAADDR_ERROR:
//             parse_Modbus_Exception_Handling02();
//             emit toUishowMsg(errorMsg);
//             break;
//         case MB_SLAVE_STATE_DATA_ERROR:
//             parse_Modbus_Exception_Handling03();
//             emit toUishowMsg(errorMsg);
//             break;
//         case MB_SLAVE_STATE_FUNCTION_ERROR:
//             parse_Modbus_Exception_Handling01();
//             emit toUishowMsg(errorMsg);
//             break;
//         case MB_SLAVE_STATE_PACKET_SIZELENTH:
//             emit toUishowMsg(errorMsg);
//             break;
//         case MB_SLAVE_STATE_PACKET_OTHER:
//             emit toUishowMsg(errorMsg);
//             break;
//     }
// }
// //正常帧处理
// void analysis_modbus::func_01()
// {
//     QByteArray ba;
//     quint16 num = ((quint8)recvModbusmsgArray[10]) * 256 + (quint8)recvModbusmsgArray[11];
//     quint16 startaddr = ((quint8)recvModbusmsgArray[8]) * 256 + (quint8)recvModbusmsgArray[9];
//     GetData0X01(ba, startaddr, num);
//     //报文头组装
//     //事务及协议
//     recvModbusmsgArray[0] = recvModbusmsgArray[0];
//     recvModbusmsgArray[1] = recvModbusmsgArray[1];
//     recvModbusmsgArray[2] = recvModbusmsgArray[2];
//     recvModbusmsgArray[3] = recvModbusmsgArray[3];
//     //字节长度
//     recvModbusmsgArray[4] = (3 + ba.size()) >> 8;
//     recvModbusmsgArray[5] = (3 + ba.size()) & 0xFF;
//     //单元标识符
//     recvModbusmsgArray[6] = recvModbusmsgArray[6];
//     //功能码
//     recvModbusmsgArray[7] = recvModbusmsgArray[7];
//     //字节计数
//     recvModbusmsgArray[8] = (quint8)ba.size();
//     //状态值
//     for (int i = 9, j = 0; j < ba.size(); j++)
//     {
//         recvModbusmsgArray[i++] = (quint8)ba.at(j);
//     }
//     //显示读出的数据
//     ReadCoilPackMsgToShow(startaddr, num, ba);
//     emit toUishowMsgPack(sendModbusmsgArray);
//     emit analysis_over(sendModbusmsgArray);
//     sendModbusmsgArray.clear();
// }
// void analysis_modbus::func_03()
// {
//     quint16 num = ((quint8)recvModbusmsgArray[10]) * 256 + (quint8)recvModbusmsgArray[11];
//     quint16 startaddr = ((quint8)recvModbusmsgArray[8]) * 256 + (quint8)recvModbusmsgArray[9];
//     //报文头组装
//     //事务及协议
//     sendModbusmsgArray[0] = recvModbusmsgArray[0];
//     sendModbusmsgArray[1] = recvModbusmsgArray[1];
//     sendModbusmsgArray[2] = recvModbusmsgArray[2];
//     sendModbusmsgArray[3] = recvModbusmsgArray[3];
//     //字节长度
//     sendModbusmsgArray[4] = (3 + num * 2) >> 8;
//     sendModbusmsgArray[5] = (3 + num * 2) & 0xFF;
//     //单元标识符
//     sendModbusmsgArray[6] = recvModbusmsgArray[6];
//     //功能码
//     sendModbusmsgArray[7] = recvModbusmsgArray[7];
//     //字节计数
//     sendModbusmsgArray[8] = (quint8)num * 2;
//     //状态值
//     for (quint16 i = 9, z = 0, j = startaddr; z < num; z++, j++)
//     {
//         //读出寄存器数据
//         QString registerData = readseting->value("Section" + QString::number(j + 1) + "/regi").toString();
//         sendModbusmsgArray[i++] = ((quint16)registerData.toInt()) >> 8;
//         sendModbusmsgArray[i++] = ((quint16)registerData.toInt()) & 0xFF;
//         msg.push_back((quint16)registerData.toInt());
//     }
//     ReadRegsPackMsgToShow(startaddr, num, msg);
//     emit toUishowMsgPack(sendModbusmsgArray);
//     emit analysis_over(sendModbusmsgArray);
//     sendModbusmsgArray.clear();
// }
// void analysis_modbus::func_0f()
// {
//     QByteArray ba;
//     quint16 num = recvModbusmsgArray[12];
//     quint16 datanum = ((quint8)recvModbusmsgArray[10]) * 256 + (quint8)recvModbusmsgArray[11];
//     quint16 startaddr = ((quint8)recvModbusmsgArray[8]) * 256 + (quint8)recvModbusmsgArray[9];
//     quint16 sizenum = ((quint8)recvModbusmsgArray[4]) * 256 + (quint8)recvModbusmsgArray[5];
//     //读取数据
//     for (int i = 0; i < num; i++)
//     {
//         ba[i] = recvModbusmsgArray[13 + i];
//     }
//     //转化为二进制字符串
//     HexByteArrayToBinString(ba);
//     //更新表格
//     emit wirtTablec(datanum, startaddr, HexByteArrayToBinString(ba));
//     //写入文件
//     WriteData0X0F(startaddr, HexByteArrayToBinString(ba));
//     //读出写入数据
//     WirteCoilPackMsgToShow(startaddr, datanum, ba);
//     //回应报文
//     ba = recvModbusmsgArray.mid(0, 12);
//     ba[4] = (sizenum - num - 1) >> 8;
//     ba[5] = (sizenum - num - 1) & 0xFF;
//     emit toUishowMsgPack(ba);
//     emit analysis_over(ba);
//     bac.clear();
// }
// void analysis_modbus::func_10()
// {
//     QByteArray ba;
//     quint16 num = recvModbusmsgArray[12];
//     quint16 startaddr = ((quint8)recvModbusmsgArray[8]) * 256 + (quint8)recvModbusmsgArray[9];
//     quint16 sizenum = ((quint8)recvModbusmsgArray[4]) * 256 + (quint8)recvModbusmsgArray[5];
//     //读取数据
//     for (int j = 13, z = 0, k = startaddr; z < num / 2; k++, z++)
//     {
//         quint16 coildata = ((quint8)recvModbusmsgArray[j++]) * 256 + (quint8)recvModbusmsgArray[j++];
//         bar.push_back(coildata);
//         //写入文件
//         QString s = "Section" + QString::number(k + 1) + "/regi";
//         readseting->setValue(s, coildata);
//     }
//     //更新表格
//     emit wirtTabler(num / 2, startaddr, bar);
//     WirteRegsPackMsgToShow(startaddr, num / 2, bar);
//     //回应报文
//     ba = recvModbusmsgArray.mid(0, 12);
//     ba[4] = (sizenum - num - 1) >> 8;
//     ba[5] = (sizenum - num - 1) & 0xFF;
//     emit toUishowMsgPack(ba);
//     emit analysis_over(ba);
//     sendModbusmsgArray.clear();
//     bar.clear();
// }
// //异常处理
// void analysis_modbus::parse_Modbus_Exception_Handling01()
// {
//     QByteArray ba;
//     //回应报文
//     ba = recvModbusmsgArray.mid(0, 8);
//     ba[4] = (3) >> 8;
//     ba[5] = (3) & 0xFF;
//     ba[7] = (mb_code + 0x80);
//     ba[8] = 0x01;
//     emit toUishowMsgPack(ba);
//     emit analysis_over(ba);
// }
// void analysis_modbus::parse_Modbus_Exception_Handling02()
// {
//     QByteArray ba;
//     //回应报文
//     ba = recvModbusmsgArray.mid(0, 8);
//     ba[4] = (3) >> 8;
//     ba[5] = (3) & 0xFF;
//     ba[7] = (mb_code + 0x80);
//     ba[8] = 0x02;
//     emit toUishowMsgPack(ba);
//     emit analysis_over(ba);
// }
// void analysis_modbus::parse_Modbus_Exception_Handling03()
// {
//     QByteArray ba;
//     //回应报文
//     ba = recvModbusmsgArray.mid(0, 8);
//     ba[4] = (3) >> 8;
//     ba[5] = (3) & 0xFF;
//     ba[7] = (mb_code + 0x80);
//     ba[8] = 0x03;
//     emit toUishowMsgPack(ba);
//     emit analysis_over(ba);
// }
// //从文件中读出线圈状态为字节
// void analysis_modbus::GetData0X01(QByteArray &coilsDataArr, quint16 BeginAddress, quint16 Number)
// {
//     //声明读取的数据字符串
//     QString getDataString;
//     quint8 responseMessageByteNum;
//     //求响应报文字节数
//     responseMessageByteNum = (quint8)((Number + 7) / 8);

//     //从数据表中读取需要数量的线圈数据,形成二进制形式字符串
//     for (quint16 i = BeginAddress; i < (BeginAddress + Number); i++)
//     {
//         //读出线圈数据
//         QString buffer = readseting->value("Section" + QString::number(i + 1) + "/coil").toString();
//         if (buffer == "1")
//         {
//             getDataString += "1";
//         }
//         else
//         {
//             getDataString += "0";
//         }
//     }
//     //二进制字符串补0
//     for (int i = 1; i <= (8 * responseMessageByteNum - Number); i++)
//     {
//         getDataString += "0";
//     }
//     //coilsDataArr.resize(responseMessageByteNum);
//     //将二进制字符串按字节填入响应报文数组
//     for (int i = 0; i < responseMessageByteNum; i++)
//     {
//         //对8位1字节进行反转处理
//         QString buffer = getDataString.mid((8 * i), 8);
//         //字节反转
//         byteReverse(buffer);
//         //存入响应报文数组
//         coilsDataArr[i] = buffer.toInt(NULL, 2);
//     }
// }
// //报文线圈数据读出提示
// void analysis_modbus::ReadCoilPackMsgToShow(quint16 startaddr, quint16 num, QByteArray msg)
// {
//     quint8 size = msg.size();
//     QString msgs;
//     for (quint8 i = 0; i < size; i++)
//     {
//         //先转化为2进制字符串
//         QString str = QString::number((quint8)msg.at(i), 2);
//         //再转化为2进制整形，由二进制整形转化为8位2进制字符串前面自动补0，从而保证8位
//         str = QString("%1").arg((quint8)str.toInt(NULL, 2), 8, 2, QChar('0'));
//         //8bit字节倒转
//         byteReverse(str);
//         //添加到数据中
//         msgs += str;
//     }
//     //去除填充的0位，读出请求报文请求的线圈数
//     msgs = msgs.left(num);
//     emit toUishowMsg("*****************成功读出线圈的数据***************\n");
//     emit toUishowMsg(QString("起始地址:%1").arg(startaddr) + "             " + QString("数量:%1\r\n").arg(num));
//     emit toUishowMsg(msgs + "\n");
//     emit toUishowMsg("***********************************************\n");
//     msgs.clear();
// }
// //报文寄存器数据读出提示
// void analysis_modbus::ReadRegsPackMsgToShow(quint16 startaddr, quint16 num, QVector<quint16> msg)
// {
//     quint8 size = msg.size();
//     QString msgs;
//     quint16 data;
//     for (quint8 i = 0; i < size; i++)
//     {
//         QString str;
//         data = msg.at(i);
//         str = QString("%1 ").arg(data);
//         msgs += str;
//     }
//     emit toUishowMsg("*****************成功读出寄存器的数据***************\n");
//     emit toUishowMsg(QString("起始地址:%1").arg(startaddr) + "             " + QString("数量:%1\r\n").arg(num));
//     emit toUishowMsg(msgs + "\n");
//     emit toUishowMsg("***********************************************\n");
//     msgs.clear();
// }
// //报文线圈数据写入提示
// void analysis_modbus::WirteCoilPackMsgToShow(quint16 startaddr, quint16 num, QByteArray msg)
// {
//     quint8 size = msg.size();
//     QString msgs;
//     for (quint8 i = 0; i < size; i++)
//     {
//         //先转化为2进制字符串
//         QString str = QString::number((quint8)msg.at(i), 2);
//         //再转化为2进制整形，由二进制整形转化为8位2进制字符串前面自动补0，从而保证8位
//         str = QString("%1").arg((quint8)str.toInt(NULL, 2), 8, 2, QChar('0'));
//         //8bit字节倒转
//         byteReverse(str);
//         //添加到数据中
//         msgs += str;
//     }
//     //去除填充的0位，读出请求报文请求的线圈数
//     msgs = msgs.left(num);
//     emit toUishowMsg("*****************成功写入线圈的数据***************\n");
//     emit toUishowMsg(QString("起始地址:%1").arg(startaddr) + "             " + QString("数量:%1\r\n").arg(num));
//     emit toUishowMsg(msgs + "\n");
//     emit toUishowMsg("***********************************************\n");
//     msgs.clear();
// }
// //报文寄存器数据写入提示
// void analysis_modbus::WirteRegsPackMsgToShow(quint16 startaddr, quint16 num, QVector<quint16> msg)
// {
//     quint8 size = msg.size();
//     QString msgs;
//     quint16 data;
//     for (quint8 i = 0; i < size; i++)
//     {
//         QString str;
//         data = (quint16)msg.at(i);
//         str = QString("%1 ").arg(data);
//         msgs += str;
//     }
//     emit toUishowMsg("*****************成功写入寄存器的数据***************\n");
//     emit toUishowMsg(QString("起始地址:%1").arg(startaddr) + "             " + QString("数量:%1\r\n").arg(num));
//     emit toUishowMsg(msgs + "\n");
//     emit toUishowMsg("***********************************************\n");
//     msgs.clear();
// }
// //0x0f功能码 写入线圈数据  单个线圈
// void analysis_modbus::WriteData0X0F(quint16 satrt, QString CoilData)
// {
//     //更新ini文件数据
//     for (int j = 0, k = satrt; j < CoilData.length(); j++, k++)
//     {
//         QString s = "Section" + QString::number(k + 1) + "/coil";
//         quint8 coildata;
//         if (CoilData.at(j) == '1')
//         {
//             coildata = 1;
//         }
//         else
//         {
//             coildata = 0;
//         }
//         readseting->setValue(s, coildata);
//     }
// }








