#include "mylogger.h"

#include <QFile>
MyLogger *MyLogger::m_logger = NULL;
std::mutex MyLogger::myMutex;
MyLogger::Garbo MyLogger::_garbo;

Logger MyLogger::logger = Logger::getInstance(LOG4CPLUS_TEXT("scada"));
MyLogger *MyLogger::getInstance() {
    if (NULL == m_logger) {
        std::lock_guard<std::mutex> mg(myMutex);
        if (NULL == m_logger) {
            m_logger = new MyLogger;  //在堆上建立
        }
    }
    return m_logger;
}

//Logger MyLogger::getLogger()
//{
////    logger =
//    return Logger::getInstance(LOG4CPLUS_TEXT("scada"));
//}


MyLogger::MyLogger() {
    //  QString path = QCoreApplication::applicationDirPath();
    //  std::string properties = path.toStdString() + L"./log4cplus.properties";
//  log4cplus::initialize();

    log4cplus::PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("config/log.properties"));

//  std::cout<<log4cplus::PropertyConfigurator::getProperties()<<std::endl;
    std::cout << "Create Singleton for log4cplus!" << std::endl;
}

void MyLogger::shutDown() {
    log4cplus::Logger::shutdown();
}
void MyLogger::closeLog() {
    log4cplus::deinitialize();
}
