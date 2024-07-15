
#include <csvmanager.h>
#include <fileUtil.h>

#include <QCoreApplication>
#include <QDateTime>
#include <QDir>
// 读取CSV文件
bool CsvManager::readCsv(QString filePath, QList<QStringList>& data) {
  QFile file(filePath);

  if (!file.open(QIODevice::ReadOnly))
    return false;

  QTextCodec* codec = QTextCodec::codecForName("UTF-8");  // 使用UTF-8编码
  QByteArray content = file.readAll();
  QString text = codec->toUnicode(content);
  QStringList lines = text.split('\n');

  for (int i = 0; i < lines.size(); i++) {
    if (!lines.at(i).isEmpty()) {
      QStringList row = lines.at(i).split(',');
      data.append(row);
    }
  }

  file.close();
  return true;
}
bool CsvManager::openFile(QFile& file,
                          QString name,
                          bool isFirst,
                          QString dirPath) {
  QDateTime now = QDateTime::currentDateTime();
  quint16 year = now.date().year();     //年
  quint8 month = now.date().month();    //月
  quint8 day = now.date().day();        //日
  quint8 hour = now.time().hour();      //时
  quint8 minute = now.time().minute();  //分
  quint8 second = now.time().second();  //秒
  //  QString path = QCoreApplication::applicationDirPath();
  int ret = 0;
  // 文件夹路径

  // 文件路径
  QString filePath = dirPath + "/" + QString::number(year) + "/" +
                     QString::number(month) + "/" + QString::number(day);

  if (!isDirExist(filePath)) {
    ret = createMultipleFolders(filePath);
    if (!ret)
      return ret;
  }
  QString createTime = QDateTime::currentDateTime().toString(
      "yyyy-MM-dd HH-mm-ss");  // 文件名不能用“:”命名
  QString fileName = name + "." + QString::number(year) + "." +
                     QString::number(month) + "." + QString::number(day) + "." +
                     QString::number(hour) + ".csv";
  filePath = filePath + "/" + fileName;
  QFileInfo fileinfo(filePath);
  if (!fileinfo.exists()) {
    if (file.isOpen())
      file.close();
    file.setFileName(filePath);
    ret = file.open(QIODevice::WriteOnly | QFile::Text | QIODevice::Append);
  } else if (isFirst && !file.isOpen()) {
    file.setFileName(filePath);
    ret = file.open(QIODevice::WriteOnly | QFile::Text | QIODevice::Append);
  }
  return ret;
}
bool CsvManager::writeCSVfromPlc(
    QFile& file,
    std::pair<QString, QList<config::dataValue>> mapofreadDataValues,
    QString name) {
  auto fileSize = file.size();
  //  LOG_DEBUG("filesize:" << fileSize );
  QList<QStringList> csvBeginThreeDatasRows;
  QStringList plcNamerow;

  QStringList chineseNamerow;

  QStringList typerow;

  if (fileSize == 0) {
    plcNamerow.push_back(QStringLiteral("时间"));
    chineseNamerow.push_back(QStringLiteral("中文名称"));
    typerow.push_back(QStringLiteral("数据类型"));
  }

  QStringList dataVlueslist;
  QString time = mapofreadDataValues.first;
  dataVlueslist.push_back(time);
  for (auto value : mapofreadDataValues.second)
  // plcName
  {
    if (fileSize == 0) {
      plcNamerow.push_back((value.var_name));
      chineseNamerow.push_back((value.chinese_name));

      // type
      typerow.push_back((value.Type));
    }

    dataVlueslist.push_back(QString::number(value.value2));
  }
  if (fileSize == 0) {
    csvBeginThreeDatasRows.push_back(plcNamerow);
    csvBeginThreeDatasRows.push_back(chineseNamerow);
    csvBeginThreeDatasRows.push_back(typerow);
  }
  csvBeginThreeDatasRows.push_back(dataVlueslist);

  int ret = writeCsvLines(file, csvBeginThreeDatasRows);
  if (!ret) {
    LOG_ERROR(QString("write csv error"));
    return false;
  }
  return true;
}
// 写入CSV文件
bool CsvManager::writeCsvLines(QFile& file, QList<QStringList>& data) {
  //    QFile file(filePath);

  //    if (!file.open(QIODevice::Append | QIODevice::Text)) return false;

  QTextCodec* codec = QTextCodec::codecForName("GBK");  // 使用UTF-8编码

  for (int i = 0; i < data.size(); i++) {
    QStringList row = data.at(i);
    QString line = row.join(",");
    line += "\n";
    QByteArray encodedLine = codec->fromUnicode(line);
    file.write(encodedLine);
  }
  data.clear();
  return true;
}
// 写入CSV文件 一行一行 一行代表一次读取
bool CsvManager::writeCsvLine(QFile& file, QStringList data) {
  QTextCodec* codec = QTextCodec::codecForName("UTF-8");  // 使用UTF-8编码
  QString line = data.join(",");
  line += "\n";
  QByteArray encodedLine = codec->fromUnicode(line);
  file.write(encodedLine);

  //  file.close();
  return true;
}

CsvManager::CsvManager() {}

CsvManager::~CsvManager() {}
