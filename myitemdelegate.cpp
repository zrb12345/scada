#include "myitemdelegate.h";
MyItemDelegate::MyItemDelegate(QObject *parent) : QStyledItemDelegate()
{
    // 添加事件过滤器
    installEventFilter(this);
    // MainWindow *main2 = new MainWindow();
    // connect(this, &MyItemDelegate::valuechanged, main2, &MainWindow::updateFactor);
}
bool MyItemDelegate::eventFilter(QObject *editor, QEvent *event)
{
    // 监听键盘事件

    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        // 按下回车键
        if (keyEvent->key() == Qt::Key_Return)
        {
            qDebug() << "Ate key press" ;
            QAbstractSpinBox *item = (QAbstractSpinBox *)editor;
            qDebug() << item->text() << "嗨嗨嗨";
            emit valuechanged(item->text());
            return true;
        }
    }
    return QStyledItemDelegate::eventFilter(editor, event);
}

