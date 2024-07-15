
#QT       += mime
QT += core gui widgets concurrent gui-private network xml serialbus
#QT += mime
greaterThan(QT_MAJOR_VERSION,5):QT+=core5compat
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += precompile_header
#DEFINES += QSLOG_IS_SHARED_LIBRARY_IMPORT
CONFIG += exceptions
#DEFINES += UNICODE _UNICODE
#Ԥ����ͷ�ļ�·��
#PRECOMPILED_HEADER = $$PWD/stdafx.h
INCLUDEPATH += src/include \
              src/include/ads \
              src/include/m1com \
              src/include/msys/inc \
              src/include/modbus
#LIBS += $$PWD/src/lib/m1com64.lib
#LIBS += $$PWD/src/lib/lib/m1com64.dll
SOURCES += \
    StructAndEnum.cpp \
    # analysis_modbus.cpp \
    commont.cpp \
    iec_slave_base.cpp \
    myitemdelegate.cpp \
    mylogger.cpp \
    qiec104slave.cpp \
    rdsmodbusslave.cpp \
    src/csvmanager.cpp \
    src/include/modbus/modbus-data.c \
    src/include/modbus/modbus-rtu.c \
    src/include/modbus/modbus-tcp.c \
    src/include/modbus/modbus.c \
    src/singleton.cpp \
    src/configmanager.cpp \
    main.cpp \
    mainwindow.cpp \
    src/xmlmanager.cpp \
    src/xmlmanagerOLD.cpp \
    src/xochange.cpp \
    tcpmanager.cpp \
    zipwriterreader.cpp \
    zipwritertimer.cpp
HEADERS += \
        # analysis_modbus.h \
        commont.h \
        iec_slave_base.h \
        iec_slave_def.h \
        myitemdelegate.h \
        mylogger.h \
        qiec104slave.h \
        rdsmodbusslave.h \
        src/include/csvmanager.h \
        src/include/fileUtil.h \
        src/include/modbus/config.h \
        src/include/modbus/modbus-private.h \
        src/include/modbus/modbus-rtu-private.h \
        src/include/modbus/modbus-rtu.h \
        src/include/modbus/modbus-tcp-private.h \
        src/include/modbus/modbus-tcp.h \
        src/include/modbus/modbus-version.h \
        src/include/modbus/modbus.h \
        src/include/singleton.h \
        src/include/configmanager.h \
        src/include/StructAndEnum.h \
        src/include/xmlmanager.h \
        src/include/mainwindow.h \
        # src/include/plctimermanager.h \
        src/include/xochange.h \
        stdafx.h \
        tcpmanager.h \
        zipwriterreader.h \
        zipwritertimer.h
FORMS += \
    mainwindow.ui \
    route.ui
#CONFIG += lrelease
#CONFIG += embed_translations
DEFINES += PLATFORM_TYPE
MOC_DIR = ./temp
OBJECTS_DIR = ./temp
#PRE_TARGETDEPS += $$PWD/src/lib/m1com64.lib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#DISTFILES += \
#    node.toml
#QMAKE_LFLAGS_RELEASE += /MAP
#QMAKE_CFLAGS_RELEASE += /Zi
#QMAKE_LFLAGS_RELEASE += /debug /opt:ref
#QMAKE_LFLAGS += /MANIFESTUAC:\"level=\'requireAdministrator\' uiAccess=\'false\'\"
#Windows
win32{
    message("Windows 32 bit [win32]")
}

#LIBS += -L'D:/Program Files (x86)/Visual Leak Detector/lib/Win64/' -lvld
# Linux
linux-g++*{
    message("Linux Generic [linux-g++]")
    INCLUDEPATH += /usr/lib/x86_64-linux-gnu

    CONFIG(debug, debug|release): {
        DEFINES += DEBUG
    }
}
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/src/lib -llog4cplus
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/src/lib -llog4cplusD
else:unix:!macx: LIBS += -L$$PWD/src/lib -llog4cplus

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/src/lib -lm1com64
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/src/lib -lm1com64
else:unix: LIBS += -L$$PWD/src/lib -lm1com

INCLUDEPATH += $$PWD/src/include
DEPENDPATH += $$PWD/src/include

message($$LIBS)






