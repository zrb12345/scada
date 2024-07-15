#pragma once
#ifndef CSVMANAGER_H
#define CSVMANAGER_H
#include <StructAndEnum.h>
#include <singleton.h>
#include <QFile>
#include <QTextCodec>
class CsvManager {
 public:
  CsvManager();
  ~CsvManager();
  // 读取CSV文件
  static bool readCsv(QString filePath, QList<QStringList>& data);

  // 写入CSV文件
  static bool writeCsvLines(QFile& file, QList<QStringList>& data);
  // 写入CSV文件 一行一行 一行代表一次读取
  static bool writeCsvLine(QFile& file, QStringList data);
  //根据plc的value写入csv
  static bool writeCSVfromPlc(
      QFile& file,
      std::pair<QString, QList<config::dataValue>> mapofreadDataValues,
      QString name);
  static bool openFile(QFile& file,
                       QString name,
                       bool isFirst,
                       QString dirPath);
};
#endif  // CSVMANAGER_H
