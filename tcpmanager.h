//#ifndef TCPMANAGER_H
//#define TCPMANAGER_H
//#include <mainwindow.h>
//#include <mylogger.h>
//#include <QObject>
//#include <QTcpServer>
//#include <QTcpSocket>
//class TcpManager : public QObject {
//  Q_OBJECT
// public:
//  explicit TcpManager(MainWindow* window, QObject* parent = nullptr);
//  ~TcpManager();
//  //初始化server操作
//  void initServer(unsigned short port);
//  // close server
//  void closeServer();
//  bool startListen(unsigned short port);
//  void run(unsigned short port);
// signals:
//  //  void sendMessage(QString data);
//  void close();

// private:
//  QTcpServer* m_tcpserver;
//  MainWindow* m_window;
//  QList<QTcpSocket*> m_tcpclientList;
//};

//#endif  // TCPMANAGER_H
