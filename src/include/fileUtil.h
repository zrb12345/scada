#ifndef FILEUTIL_H
#define FILEUTIL_H

// 1. 引入头文件
#include <mylogger.h>
#include <zipwriterreader.h>
#include <QDateTime>
#include <QDir>
#include <QFile>
/*判断文件夹存在 方法1*/
static bool isDirExist(QString fullPath) {
  QDir dir(fullPath);

  if (dir.exists()) {
    return true;
  }
  return false;
}

//  创建多级文件夹
static bool createMultipleFolders(const QString path) {
  QDir dir(path);

  if (!dir.exists(path)) {
    bool res = dir.mkpath(path);
    return res;
  }
  return true;
}

// 创建文件
static QString createFile(const QString path, const QString suffix) {
  QString createTime = QDateTime::currentDateTime().toString(
      "yyyy-MM-dd HH-mm-ss");  // 文件名不能用“:”命名
  QString fileName = path + "\\" + createTime + suffix;
  QFile file(fileName);

  if (file.exists()) {
    return fileName;
  } else {
    // 如果没有此文件，就创建
    file.open(QFile::WriteOnly | QFile::Text | QIODevice::Append);
  }

  return fileName;
}
static bool zipFileListUnderDir(const QString& dirPath) {
  ZipWriterReader& zipWriter = ZipWriterReader::get_instance();
  QStringList fileList;
  QDir dir(dirPath);
  if (!dir.exists())
    return false;
  dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
  dir.setSorting(QDir::Name);
  auto mDirNames = dir.entryList();
  QDateTime now = QDateTime::currentDateTime();
  quint16 year = now.date().year();   //年
  quint8 month = now.date().month();  //月
  quint8 day = now.date().day();      //日
  quint8 hour = now.time().hour();    //时
  if (hour == 0) {
    QDateTime last_day = now.addDays(-1);
    LOG_DEBUG(QString("此时为零点前一天时间为%1").arg(last_day.toString("yyyy/MM/dd A HH:mm:ss")));
    year = last_day.date().year();
    month = last_day.date().month();
    day = last_day.date().day();
  }
  for (int i = 0; i < mDirNames.size(); ++i) {
    QString csvFileDirPath = dirPath + "/" + QString::number(year) + "/" +
                             QString::number(month) + "/" +
                             QString::number(day);
    QDir dirCSV(csvFileDirPath);
    if (!dirCSV.exists()) {
      LOG_ERROR(QString("error: %1不存在").arg(dirCSV.path()));
      return false;
    }
    dirCSV.setFilter(QDir::Files);
    dirCSV.setSorting(QDir::Name);
    dirCSV.setNameFilters(QString("*.csv;*.CSV").split(";"));
    auto mNamesCSV = dirCSV.entryList();
    for (int i = 0; i < mNamesCSV.size(); ++i) {
      auto name = mNamesCSV[i].split(".");
      if (name[name.size() - 2].toInt() != hour) {
        QString filename = csvFileDirPath + "/" + mNamesCSV[i];
        QString zipfile = csvFileDirPath + "/" + mNamesCSV[i] + ".zip";
        //压缩
        zipWriter.zipWriter(zipfile, QFileInfo(filename));

        QFile::remove(csvFileDirPath + "/" + mNamesCSV[i]);
      }
    }
  }
  return true;
}
#endif  // FILEUTIL_H
