#ifndef ZIPWRITERREADER_H
#define ZIPWRITERREADER_H
#include <singleton.h>
#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>
#include "QtGui/private/qzipreader_p.h"
#include "QtGui/private/qzipwriter_p.h"
class ZipWriterReader : public Singleton<ZipWriterReader> {
public:
    ZipWriterReader(token) {};

    ZipWriterReader(const ZipWriterReader &) = delete;
    ZipWriterReader &operator=(const ZipWriterReader &) = delete;
    bool zipReader(QString zipPath = "test.zip", QString zipDir = "");
    void zipWriter(QString zipPath = "test.zip",
                   QFileInfo fileInfo = QFileInfo());
    //    QByteArray GzipCompress(QByteArray postBody);
    //  QByteArray GZipUnCompress(QByteArray src);
    //  bool zipCompress(QString filename, QString file);

    //  int zlibCompress(char* dest, int& destLen, char* source, int sourceLen);

    //  int zlibUncompress(char* dest, int& destLen, char* source, int sourceLen);
};

#endif  // ZIPWRITERREADER_H
