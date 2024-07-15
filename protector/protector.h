#ifndef PROTECTOR_H
#define PROTECTOR_H
#include <QObject>
#include <QProcess>
class Protector : public QObject {
  Q_OBJECT
 public:
  explicit Protector(QObject* parent = nullptr);
  ~Protector();
  QProcess* m_pProcess;
  void setEnvironment();

 public slots:
  void getProState(QProcess::ProcessState state);
  void restart(int exitCode, QProcess::ExitStatus status);
};

#endif  // PROTECTOR_H
