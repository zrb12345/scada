
// #ifndef ANALYSIS_MODBUS_H
// #define ANALYSIS_MODBUS_H
// #include<QByteArray>
// #include<QObject>
// #include<QDebug>
// #include<QSettings>
// #include<QThread>
// #include"commont.h"
// /******************宏定义*******************/
// //数据长度
// #define MAXDATA                256
// #define ADDRESS_MAX            65535
// //MODBUS协议标识符
// #define MB_PROTOCOL            0x0000
// //读取的线圈寄存器功能码     01
// #define READER_COIL_CODE       0x01
// //读保持寄存器功能码        03
// #define Read_REGISTER          0x03
// //写线圈寄存器功能码        0f
// #define WRITE_COIL             0x0f
// //写保持寄存器功能码        10
// #define WRITE_REGISTER         0x10

// typedef enum TCP_MODBUS_STATE
// {
//     //功能码错误
//     MB_SLAVE_STATE_FUNCTION_ERROR = 1,
//     //数据值错误
//     MB_SLAVE_STATE_DATA_ERROR = 2,
//     //数据地址错误
//     MB_SLAVE_STATE_DATAADDR_ERROR = 3,
//     //功能码正确
//     MB_SLAVE_STATE_FUNCTION_TRUE = 4,
//     //正确帧
//     MB_SLAVE_STATE_PACKET_PROCESS = 5,
//     //其他
//     MB_SLAVE_STATE_PACKET_OTHER = 6,
//     //字节与数据字段不正确
//     MB_SLAVE_STATE_PACKET_SIZELENTH = 7,

// } MB_satae;

// class analysis_modbus : public QObject
// {
//     Q_OBJECT
// public:
//     explicit analysis_modbus();
//     ~analysis_modbus();
// signals:
//     //解析完成
//     void analysis_over(QByteArray ba);
//     void wirtTablec(quint16 num, quint16 satrtaddr, QString bac);
//     void wirtTabler(quint16 num, quint16 satrtaddr, QVector<quint16> bar);
//     void toUishowMsg(QString errorMsg);
//     void toUishowMsgPack(QByteArray packMsg);
// public slots:
//     //接收报文
//     void recvModbusMsg(QByteArray msg, quint8 addr);
// private:
//     //状态处理
//     void parse_Modbus_MB_satae(MB_satae);
//     //正常帧处理
//     void parse_Modbus_True_Msg(QByteArray msg);
//     //异常处理
//     void parse_Modbus_Exception_Handling03();
//     void parse_Modbus_Exception_Handling02();
//     void parse_Modbus_Exception_Handling01();
//     //报文数据读取提示
//     void ReadCoilPackMsgToShow(quint16 startaddr, quint16 num, QByteArray msg);
//     void ReadRegsPackMsgToShow(quint16 startaddr, quint16 num, QVector<quint16> msg);
//     //报文写入提示
//     void WirteCoilPackMsgToShow(quint16 startaddr, quint16 num, QByteArray msg);
//     void WirteRegsPackMsgToShow(quint16 startaddr, quint16 num, QVector<quint16> msg);
//     //封装ini线圈状态to byte
//     void GetData0X01(QByteArray &ba, quint16 BeginAddress, quint16 Number);
//     void WriteData0X0F(quint16 satrt, QString CoilData);

//     //解析报文查询状态
//     MB_satae parse_Modbus_Msg(QByteArray msg);
//     //功能码处理函数
//     void func_01();
//     void func_03();
//     void func_0f();
//     void func_10();
//     QByteArray recvModbusmsgArray;
//     QByteArray sendModbusmsgArray;
//     quint16 mb_startaddr, mb_num, mb_protocol;
//     quint16 mb_code;
//     quint8  mb_addr;
//     QString errorMsg;
//     quint8 csize;
//     quint16 wnum;
//     QByteArray csizes;
//     QThread *m_thread;
//     QSettings *readseting = nullptr;
//     bool IniQsetingFlag = true;
//     QVector<quint16> bar;
//     QVector<quint16> msg;
//     QString bac;
// };
// #endif // ANALYSIS_MODBUS_H
