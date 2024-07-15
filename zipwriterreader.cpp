#include "zipwriterreader.h"

#include <QDir>

// bool ZipWriterReader::zipCompress(QString filename, QString file) {
//  qDebug() << QFileInfo(filename).absolutePath() );
//  int ret = JlCompress::compressFile(filename, file);
//  LOG_DEBUG("compress ddddd " << ret );
//  return ret;
//}

// int ZipWriterReader::zlibCompress(char* dest,
//                                  int& destLen,
//                                  char* source,
//                                  int sourceLen) {
//  unsigned char* dest1 = reinterpret_cast<unsigned char*>(dest);
//  unsigned long destLen1 = static_cast<unsigned long>(destLen);
//  unsigned char* source1 = reinterpret_cast<unsigned char*>(source);
//  unsigned long sourceLen1 = static_cast<unsigned long>(sourceLen);

//  return (compress(dest1, &destLen1, source1, sourceLen1));
//}

// int ZipWriterReader::zlibUncompress(char* dest,
//                                    int& destLen,
//                                    char* source,
//                                    int sourceLen) {
//  unsigned char* dest1 = reinterpret_cast<unsigned char*>(dest);
//  unsigned long destLen1 = static_cast<unsigned long>(destLen);
//  unsigned char* source1 = reinterpret_cast<unsigned char*>(source);
//  unsigned long sourceLen1 = static_cast<unsigned long>(sourceLen);

//  return (uncompress(dest1, &destLen1, source1, sourceLen1));
//}

bool ZipWriterReader::zipReader(QString zipPath, QString zipDir) {
  QDir tempDir;
  if (!tempDir.exists(zipDir))
    tempDir.mkpath(zipDir);
  QZipReader reader(zipPath);
  return reader.extractAll(zipDir);
}

void ZipWriterReader::zipWriter(QString zipPath, QFileInfo fileInfo) {
  QZipWriter* writer = new QZipWriter(zipPath);

  QFile file(fileInfo.filePath());
  if (!file.exists())
    return;
  file.open(QIODevice::ReadOnly);
  writer->addFile(fileInfo.fileName(), file.readAll());
  file.close();

  writer->close();
  if (writer) {
    delete writer;
    writer = nullptr;
  }
}
// QByteArray ZipWriterReader::GzipCompress(QByteArray postBody) {
//  QByteArray outBuf;
//  z_stream c_stream;
//  int err = 0;
//  int windowBits = 15;
//  int GZIP_ENCODING = 16;
//  if (!postBody.isEmpty()) {
//    c_stream.zalloc = (alloc_func)0;
//    c_stream.zfree = (free_func)0;
//    c_stream.opaque = (voidpf)0;
//    c_stream.next_in = (Bytef*)postBody.data();
//    c_stream.avail_in = postBody.size();
//    if (deflateInit2(&c_stream, Z_DEFAULT_COMPRESSION, Z_DEFLATED,
//                     MAX_WBITS + GZIP_ENCODING, 8, Z_DEFAULT_STRATEGY) !=
//                     Z_OK)
//      return QByteArray();
//    for (;;) {
//      char destBuf[4096] = {0};
//      c_stream.next_out = (Bytef*)destBuf;
//      c_stream.avail_out = 4096;
//      int err = deflate(&c_stream, Z_FINISH);
//      outBuf.append(destBuf, 4096 - c_stream.avail_out);
//      if (err == Z_STREAM_END || err != Z_OK) {
//        break;
//      }
//    }
//    auto total = c_stream.total_out;
//    deflateEnd(&c_stream);
//    total = c_stream.total_out;
//  }
//  return outBuf;
//}

// QByteArray ZipWriterReader::GZipUnCompress(QByteArray src) {
//  QByteArray outBuffer;
//  z_stream strm;
//  strm.zalloc = NULL;
//  strm.zfree = NULL;
//  strm.opaque = NULL;

//  strm.avail_in = src.size();
//  strm.next_in = (Bytef*)src.data();

//  int err = -1, ret = -1;
//  err = inflateInit2(&strm, MAX_WBITS + 16);
//  if (err == Z_OK) {
//    while (true) {
//      char buffer[4096] = {0};
//      strm.avail_out = 4096;
//      strm.next_out = (Bytef*)buffer;
//      int code = inflate(&strm, Z_FINISH);
//      outBuffer.append(buffer, 4096 - strm.avail_out);
//      // qDebug()<<"ddd"<<code<<Z_OK;
//      if (Z_STREAM_END == code) {
//        break;
//      }
//    }
//  }
//  inflateEnd(&strm);
//  return outBuffer;
//}
