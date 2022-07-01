#ifndef TOOLITEM_H
#define TOOLITEM_H
#include <QVBoxLayout>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>

class ToolItem : public QWidget
{
public:
    ToolItem(QWidget *title, QWidget *item);
//    ToolItem(QWidget *title, QStringList *itemList);



protected:
    void mousePressEvent(QMouseEvent *event);

private:
    QWidget *item;
    QScrollArea *scrollInsideItem;
//    QStringList *itemList;
};

#endif // TOOLITEM_H
