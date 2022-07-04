#ifndef TOOLITEM_H
#define TOOLITEM_H
#include <QVBoxLayout>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>
#include <QFrame>

// This custom widget allows users to add widgets within another widget
// with specific styling. When used in conjuction with the ExpandingToolBox
// class, it creates an expandable "window" with a title and a space for items (layouts)
class ToolItem : public QWidget
{
public:
    ToolItem(QWidget *title, QWidget *item);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    QWidget *item;
    QScrollArea *scrollInsideItem;
};

#endif // TOOLITEM_H
