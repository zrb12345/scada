#ifndef MYLOGGER_H
#define MYLOGGER_H
#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) && !defined(__CYGWIN__)
//#define UNICODE
#endif
//#define UNICODE
#include <log4cplus/configurator.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/initializer.h>
#include <log4cplus/layout.h>
#include <log4cplus/log4cplus.h>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/tchar.h>
#include <QCoreApplication>
#include <QString>
#include <iostream>
#include <mutex>
#include <string>
#ifdef linux
// 记录追踪日志
#define LOG_TRACE(msg)                                            \
  {                                                               \
    LOG4CPLUS_TRACE(Logger::getInstance(LOG4CPLUS_TEXT("scada")), \
                    QString(msg).toStdString());                  \
  }
// 记录调试日志
#define LOG_DEBUG(msg)                                            \
  {                                                               \
    LOG4CPLUS_DEBUG(Logger::getInstance(LOG4CPLUS_TEXT("scada")), \
                    QString(msg).toStdString());                  \
  }
// 记录信息日志
#define LOG_INFO(msg)                                            \
  {                                                              \
    LOG4CPLUS_INFO(Logger::getInstance(LOG4CPLUS_TEXT("scada")), \
                   QString(msg).toStdString());                  \
  }
// 记录告警日志
#define LOG_WARNING(msg)                                         \
  {                                                              \
    LOG4CPLUS_WARN(Logger::getInstance(LOG4CPLUS_TEXT("scada")), \
                   QString(msg).toStdString());                  \
  }
// 记录错误日志
#define LOG_ERROR(msg)                                            \
  {                                                               \
    LOG4CPLUS_ERROR(Logger::getInstance(LOG4CPLUS_TEXT("scada")), \
                    QString(msg).toStdString());                  \
  }
// 记录致命日志
#define LOG_FATAL(msg)                                            \
  {                                                               \
    LOG4CPLUS_FATAL(Logger::getInstance(LOG4CPLUS_TEXT("scada")), \
                    QString(msg).toStdString());                  \
  }
#else
// 记录追踪日志
#define LOG_TRACE(msg) \
  { LOG4CPLUS_TRACE(MyLogger::logger, QString(msg).toStdWString()); }
// 记录调试日志
#define LOG_DEBUG(msg) \
  { LOG4CPLUS_DEBUG(MyLogger::logger, QString(msg).toStdWString()); }
// 记录信息日志
#define LOG_INFO(msg) \
  { LOG4CPLUS_INFO(MyLogger::logger, QString(msg).toStdWString()); }
// 记录告警日志
#define LOG_WARNING(msg) \
  { LOG4CPLUS_WARN(MyLogger::logger, QString(msg).toStdWString()); }
// 记录错误日志
#define LOG_ERROR(msg) \
  { LOG4CPLUS_ERROR(MyLogger::logger, QString(msg).toStdWString()); }
// 记录致命日志
#define LOG_FATAL(msg) \
  { LOG4CPLUS_FATAL(MyLogger::logger, QString(msg).toStdWString()); }
#endif
using namespace log4cplus;
// using namespace log4cplus::helpers;
//单例模式
class MyLogger {
 public:
  static MyLogger* getInstance();
  // static void deleteInstance();
  //  static Logger getLogger();
  static Logger logger;
  void shutDown();
  void closeLog();

 private:
  MyLogger();
  ~MyLogger() {
    //    shutDown();
    closeLog();
    std::cout << "Destory singleton for log4cplus!!" << std::endl;
  }
  static MyLogger* m_logger;
  static std::mutex myMutex;

 private:
  //内部类来删除对象
  class Garbo {
   public:
    Garbo() {}
    ~Garbo() {
      if (m_logger != NULL) {
        delete m_logger;
        m_logger = nullptr;
      }
    }
  };
  static Garbo _garbo;
};

#endif  // MYLOGGER_H
