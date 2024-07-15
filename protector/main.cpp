#include <protector.h>
#include <QCoreApplication>
#include <QProcess>
#include <QDir>
int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);
  QDir::setCurrent(a.applicationDirPath());
  Protector protector;

  return a.exec();
}
