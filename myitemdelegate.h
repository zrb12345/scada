#ifndef MYITEMDELEGATE_H
#define MYITEMDELEGATE_H
#include<QStyledItemDelegate>

#include<QEvent>
#include<QKeyEvent>
#include<QTableWidget>
#include <QObject>
class MyItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    MyItemDelegate(QObject *parent = nullptr);
    bool eventFilter(QObject *editor, QEvent *event);
signals:
    void valuechanged(QString value);
};
#endif // MYITEMDELEGATE_H
