#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QRunnable>

class Task : public QObject, public QRunnable {
  Q_OBJECT
 public:
  explicit Task(QObject* parent = nullptr);
  void receNum(int num);
 signals:
  void working(int num);
  void finish(QString elapsedTime);

 protected:
  void run() override;

 private:
  int iRecvNum;
};
#endif  // MYTHREAD_H
