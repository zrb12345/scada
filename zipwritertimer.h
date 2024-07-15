#ifndef ZIPWRITERTIMER_H
#define ZIPWRITERTIMER_H

#include <QObject>
#include <QTimer>
class ZIPWriterTimer : public QObject {
  Q_OBJECT
 public:
  explicit ZIPWriterTimer(QObject* parent = nullptr);
  ~ZIPWriterTimer();
  void run(QString dirPath);

 private:
  QTimer* m_writeZipTimer;
  QString m_dirPath;
  void zipfiles();
 signals:
};

#endif  // ZIPWRITERTIMER_H
