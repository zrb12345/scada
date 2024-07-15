#include "zipwritertimer.h"

#include <configmanager.h>
#include <fileUtil.h>
#include <QCoreApplication>
#include <QDir>
#include <QEventLoop>
ZIPWriterTimer::ZIPWriterTimer(QObject* parent) : QObject{parent} {}

ZIPWriterTimer::~ZIPWriterTimer() {
  LOG_DEBUG("stop zip writer timer");
  m_writeZipTimer->stop();
  m_writeZipTimer->deleteLater();
}

void ZIPWriterTimer::run(QString dirPath) {
  QEventLoop loop;

  m_writeZipTimer = new QTimer();

  //  int writeInterval = 60 * 1000 * 60;
  int writeInterval = 60 * 1000 * 10;
  m_writeZipTimer->setTimerType(Qt::PreciseTimer);
  connect(m_writeZipTimer, &QTimer::timeout, this, &ZIPWriterTimer::zipfiles);
  connect(m_writeZipTimer, &QTimer::destroyed, &loop, &QEventLoop::quit);
  m_writeZipTimer->start(writeInterval);
  m_dirPath = dirPath;
  QString log;
  QTextStream(&log)<<"zip timer start : " << m_writeZipTimer->isActive()
                  << "history dir:" << dirPath;
  LOG_INFO(log);
  loop.exec();
}

void ZIPWriterTimer::zipfiles() {
  int ret = 0;
  // 文件夹路径
  QDateTime now = QDateTime::currentDateTime();
  auto minute = now.time().minute();
  if (minute <= 10) {
    QString dirPath = m_dirPath;
    QDir dir(dirPath);
    dirPath = dir.fromNativeSeparators(dirPath);
    //  LOG_DEBUG("zipfiles:" << dirPath );
    zipFileListUnderDir(dirPath);
  }
}
