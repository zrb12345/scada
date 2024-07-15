#include "protector.h"
#include <QCoreApplication>
#include <QDir>

Protector::Protector(QObject *parent) {
  QEventLoop loop;
  m_pProcess = new QProcess(this);
  setEnvironment();
#ifdef _WIN32
  m_pProcess->start(
      "D:/SCADA开发/SCADA/SCADA.Desktop/bin/Debug/net6.0/SCADA.Desktop.exe");
#else
  //  unsetenv("LD_LIBRARY_PATH");
  QString exepath = "./scada1";
  exepath.replace("\n", "");
  m_pProcess->start(exepath);
#endif
  connect(m_pProcess, &QProcess::stateChanged, this, &Protector::getProState);
  connect(m_pProcess, &QProcess::finished, this, &Protector::restart);
  connect(m_pProcess, &QProcess::destroyed, &loop, &QEventLoop::quit);
  if (!m_pProcess->waitForStarted())
    qDebug() << "Make failed:" << m_pProcess->errorString();
  else
    qDebug() << "Child Process Started. " << m_pProcess->errorString()
             << m_pProcess->readAll();

  loop.exec();
}

Protector::~Protector() {
  delete m_pProcess;
  m_pProcess = NULL;
}

void Protector::restart(int exitCode, QProcess::ExitStatus status) {
  qDebug() << "restart...." << m_pProcess->readAll();
#ifdef _WIN32
  m_pProcess->start(
      "D:/SCADA开发/SCADA/SCADA.Desktop/bin/Debug/net6.0/SCADA.Desktop.exe");
#else
  //  unsetenv("LD_LIBRARY_PATH");
  QString exepath = "./scada1";
  exepath.replace("\n", "");
  m_pProcess->start(exepath);
#endif
  if (!m_pProcess->waitForStarted())
    qDebug() << "Make failed:" << m_pProcess->errorString();
  else
    qDebug() << "Child Process Started. " << m_pProcess->readAll();
}

void Protector::setEnvironment() {
  QString environmentPath = qgetenv("path"); // qgetenv函数获取系统环境变量
  QString exepath = QCoreApplication::applicationDirPath(); // exe路径
  exepath.append(
      "/dependency"); //在QT程序的exe目录下新建dependency文件夹，放入需要启动的程序及环境
  environmentPath += QDir::toNativeSeparators(exepath).prepend(
      ';'); // QT自动获取的路径包含斜杠“/”，系统环境变量需要反斜杠“\”，toNativeSeparators函数自动将路径变为适应系统格式的路径；可以将需要运行的exe变量加到系统环境变量的最前边或者用append添加到最后边都可以
  qputenv(
      "path",
      environmentPath.toStdString()
          .c_str()); //变换格式，然后存入系统环境变量，这样就可以临时添加系统环境变量了，QT程序退出后，环境变量也就消失了
}
void Protector::getProState(QProcess::ProcessState state) {
  switch (state) {
  case QProcess::NotRunning: // exe程序未运行
  {
    qDebug() << "exe程序未运行！";

  } break;
  case QProcess::Starting: // exe程序启动中
  {
    qDebug() << "exe程序启动中！";
  } break;
  case QProcess::Running: // exe程序运行中
  {
    qDebug() << "exe程序运行中！";
  } break;

  default: {
    qDebug() << "exe程序其他状态！";
  } break;
  }
}
