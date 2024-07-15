#include "mainwindow.h"
#include <fileUtil.h>
#include <mylogger.h>
#include <QApplication>
#include <QLocale>
#include <QMessageBox>
#include <QTextCodec>
#include <QTranslator>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
