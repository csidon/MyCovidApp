#ifndef TOOLITEM_H
#define TOOLITEM_H
#include <QVBoxLayout>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>

class ToolItem : public QWidget
{
public:
    ToolItem(QWidget *title, QWidget *item);
//    ToolItem(QWidget *title, QStringList *itemList);


protected:
    void mousePressEvent(QMouseEvent *event);

private:
    QWidget *item;
//    QStringList *itemList;
};

#endif // TOOLITEM_H
