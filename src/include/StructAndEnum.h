#ifndef STRUCTANDENUM_H
#define STRUCTANDENUM_H
#include <mylogger.h>
#include <QDateTime>
#include <QList>
#include <QMap>
#include <QString>
#include <string>
typedef unsigned long long hash_t;

constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;

constexpr inline static hash_t hash_(char const *pstr) {
    hash_t ret{basis};
    while (*pstr) {
        ret ^= *pstr;
        ret *= prime;
        pstr++;
    }
    return ret;
}

constexpr inline hash_t operator"" _hash(char const *p, size_t) {
    return hash_(p);
}
namespace config {
// 接收方pc定义
struct pcConfig {
    QString name;
    QString ip;
    bool code;
    int port;
};

//倍福plc定义
struct beckhoffConfig {
    QString ip;
    QString netid;
    int port = 0;
    QString username;
    QString password;
    int rownum;         // 该节点所在界面table的行数，便于定位
    int time;           // 时间频率，ms为单位
    int writetime = 0;  //写入频率，ms为单位
    QString deviceType;
    QString readType;
};

// 除了倍福plc的其他plc定义 巴哈曼
struct plcConfig {
    QString ip;
    QString username;  // 巴哈曼的也有用户名和密码
    QString password;
    int rownum = 0;     // 该节点所在界面table的行数，便于定位
    int time = 0;       // 时间频率，ms为单位
    int writetime = 0;  //写入频率，ms为单位
    QString deviceType;
};

// modbus
struct modbusConfig {
    QString ip;  // ip
    int port;
    // int portRegister;//寄存器的端口
    // int portCoil;//线圈的端口
    // int portInputRegister;//只读寄存器的端口
    // int portInputCoil;//只读线圈的端口
    QString name;       // modbus的name
    int rownum = 0;     // 该节点所在界面table的行数，便于定位
    int time = 0;       // 时间频率，ms为单位
    int writetime = 0;  //写入频率，ms为单位
    QString deviceType;
    int readnumRegister;         //寄存器的读取长度
    int readnumFloatRegister;    //类型为float需要两个寄存器，读取的时候多读一个字节
    int startaddrRegister;       //寄存器的读取开始地址
    int readnumCoil;             //线圈的读取长度
    int startaddrCoil;           //线圈的读取开始地址
    int readnumInputRegister;    //只读寄存器的读取长度
    int readnumFloatInputRegister;    //类型为float需要两个寄存器，读取的时候多读一个字节
    int startaddrInputRegister;  //只读寄存器的读取开始地址
    int readnumInputCoil;        //只读线圈的读取长度
    int startaddrInputCoil;      //只读线圈的读取开始地址

    //从站地址 1-247
    int slaveaddr;
};
// 采集点controller定义
template <typename T>
struct controllerConfig {
    T plc_config;
    QString name;
    QString plc;
    QString template_name;
    QString ztemplate_name;
    int port;
};

struct nodeConfig {
    QList<pcConfig> pc_configs;
    QMap<QString, controllerConfig<modbusConfig>> modbus_configs;
    QMap<QString, controllerConfig<beckhoffConfig>> beckhoff_configs;
    QMap<QString, controllerConfig<plcConfig>> plc_configs;
    int control_port;
    QString path;
};

// 采集点数据定义
struct dataConfig {
    QString Type;  // 表示数据类型
    QString RWmodle;  // 表示数据读写，R表示只读，W表示可写属于控制点
    QString Module;  // 表示数据所属部件名称，Pcs表示变频器
    QString var_name;  // 表示对外变量点名，因为plc_name名字太长不适合对外做统一处理
    QString plc_name;      // 表示plc中的原始变量点名称
    QString chinese_name;  // 表示点中文含义
    double factor = 0;  // 表示系数，因为值从PLC取出来之后，可能需要转换系数。
    int alarm_level = 0;  //报警层级
    QString alarm_id;     //报警id
    int modAddress;//对于modbus协议来说，需要寄存器、线圈的地址
    int id;//对于iec104协议来说,遥信 遥测 遥调 遥控 数据存储的地址 点号
    QString nodeName;//modbus协议发布点表需要知道站点的名称
    QString IEC104Type;//单点遥信 双点遥信 归一化值 //syx dyx yc
    QString nodeIp;//nodeName对应的IP
};
//发布集合定义，一个发布集合里面有多个plcName,一个plcName里面有多个node 代表一个从站，一个mapping
struct publishNode {
    int port;
    QString float_sort;
    QString short_sort;
    QString yx_type;
    QString yk_type;
    QString yc_type;
    QString yd_type;
    // QString templateName;
    // plcName varName
    QMap<QString,  QMap<QString, dataConfig> >publishDatas;
};
struct dataValue {
    QString Type;
    QString readTime;      // 读取时间
    QDateTime changeTime;  // 变位时间
    QString var_name;
    QString chinese_name;
    double value = 0;
    double value2 = 0;
    int alarm_level;   //报警层级
    QString alarm_id;  //报警id
    double factor = 0;
    QString RWmodle;  // 表示数据读写，R表示只读，W表示可写属于控制点
    // QByteArray
    // bytetemp;//从站解析UDP发送的modbus数据时暂存节点的字节，不立即解析成对应的数据。等到和发布点表确认后再转成对应类型的数据
};
struct writeData {
    QStringList data;
    QStringList var_names;
};
}  // namespace config
#endif  // STRUCTANDENUM_H
