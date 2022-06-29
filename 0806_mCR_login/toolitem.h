#ifndef TOOLITEM_H
#define TOOLITEM_H
#include <QVBoxLayout>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>

class ToolItem : public QWidget
{
public:
//    ToolItem(const QString &title, QWidget *item);
    ToolItem(QWidget *title, QWidget *item);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    QWidget *item;
};

#endif // TOOLITEM_H
