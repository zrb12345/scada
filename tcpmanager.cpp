//#include "tcpmanager.h"
////#include "mainwindow.h"
//TcpManager::TcpManager(MainWindow* window, QObject* parent)
//    : QObject{parent}, m_window(window) {
//  connect(this, &TcpManager::close, this, &TcpManager::closeServer);
//}

//TcpManager::~TcpManager() {
//  if (m_tcpserver) {
//    delete m_tcpserver;
//    m_tcpserver = nullptr;
//  }
//}

//bool TcpManager::startListen(unsigned short port) {
//  if (m_tcpserver->isListening()) {
//    return true;
//  } else {
//    //从界面上读取ip和端口
//    //可以使用 QHostAddress::Any 监听所有地址的对应端口
//    const QHostAddress address = QHostAddress::Any;
//    //开始监听，并判断是否成功
//    if (m_tcpserver->listen(address, port)) {
//      return true;
//    } else
//      return false;
//  }
//  //  updateState();
//}

//void TcpManager::run(unsigned short port) {
//  initServer(port);
//  //  startListen(port);
//}

//void TcpManager::initServer(unsigned short port) {
//  m_tcpserver = new QTcpServer(this);
//  //点击监听按钮，开始监听
//  bool ret = startListen(port);
//  if (!ret)
//    return;
//  //监听到新的客户端连接请求
//  QEventLoop loop;
//  connect(m_tcpserver, &QTcpServer::newConnection, this, [this] {
//    //如果有新的连接就取出
//    while (m_tcpserver->hasPendingConnections()) {
//      // nextPendingConnection返回下一个挂起的连接作为已连接的QTcpSocket对象
//      //套接字是作为服务器的子级创建的，这意味着销毁QTcpServer对象时会自动删除该套接字。
//      //最好在完成处理后显式删除该对象，以避免浪费内存。
//      //返回的QTcpSocket对象不能从另一个线程使用，如有需要可重写incomingConnection().
//      QTcpSocket* socket = m_tcpserver->nextPendingConnection();
//      m_tcpclientList.append(socket);

//      //关联相关操作的信号槽
//      //收到数据，触发readyRead
//      connect(socket, &QTcpSocket::readyRead, [this, socket] {
//        //没有可读的数据就返回
//        if (socket->bytesAvailable() <= 0)
//          return;
//        //注意收发两端文本要使用对应的编解码
//        const QString recv_text = QString::fromUtf8(socket->readAll());
//        emit m_window->receiveMessageFromTCP(recv_text);
//      });

//      // error信号在5.15换了名字
//#if QT_VERSION < QT_VERSION_CHECK(5, 15, 0)
//      //错误信息
//      connect(
//          socket,
//          static_cast<void (QAbstractSocket::*)(QAbstractSocket::SocketError)>(
//              &QAbstractSocket::error),
//          [this, socket](QAbstractSocket::SocketError) {
//            ui->textRecv->append(QString("[%1:%2] Soket Error:%3")
//                                     .arg(socket->peerAddress().toString())
//                                     .arg(socket->peerPort())
//                                     .arg(socket->errorString()));
//          });
//#else
//            //错误信息
//            connect(socket,&QAbstractSocket::errorOccurred,[this,socket](QAbstractSocket::SocketError){
//          emit m_window->receiveMessageFromTCP(QString("[%1:%2] Socket Error:%3")
//                                                   .arg(socket->peerAddress().toString())
//                                                   .arg(socket->peerPort())
//                                                   .arg(socket->errorString()));
//            });
//#endif

//      //连接断开，销毁socket对象，这是为了开关server时socket正确释放
//      connect(socket, &QTcpSocket::disconnected, [this, socket] {
//        LOG_DEBUG("断开连接" );
//        socket->deleteLater();
//        m_tcpclientList.removeOne(socket);
//      });
//    }
//  });

//  //  // server向client发送内容
//  //  connect(ui->btnSend, &QPushButton::clicked, [this] {
//  //    //判断是否开启了server
//  //    if (!m_tcpserver->isListening())
//  //      return;
//  //    //将发送区文本发送给客户端
//  //    const QByteArray send_data = ui->textSend->toPlainText().toUtf8();
//  //    //数据为空就返回
//  //    if (send_data.isEmpty())
//  //      return;
//  //    for (QTcpSocket* socket : clientList) {
//  //      socket->write(send_data);
//  //      // socket->waitForBytesWritten();
//  //    }
//  //  });

//  // server的错误信息
//  //如果发生错误，则serverError()返回错误的类型，
//  //并且可以调用errorString()以获取对所发生事件的易于理解的描述
//  connect(m_tcpserver, &QTcpServer::acceptError,
//          [this](QAbstractSocket::SocketError) {
//            emit m_window->receiveMessageFromTCP("Server Error:" +
//                                                 m_tcpserver->errorString());
//          });
//  connect(m_tcpserver, &QTcpServer::destroyed, &loop, &QEventLoop::quit);

//  loop.exec();
//}

//void TcpManager::closeServer() {
//  //停止服务
//  LOG_DEBUG("关闭服务" );
//  m_tcpserver->close();
//  for (QTcpSocket* socket : m_tcpclientList) {
//    //断开与客户端的连接
//    socket->disconnectFromHost();
//    if (socket->state() != QAbstractSocket::UnconnectedState) {
//      socket->abort();
//    }
//  }
//}
