#include "toolitem.h"
#include <QFrame>

//ToolItem::ToolItem(const QString &title, QWidget *item) : item(item)
//{
//    QVBoxLayout *layout = new QVBoxLayout;
//    layout->setContentsMargins(0, 0, 0, 0);
//    layout->addWidget(new QLabel(title));
//    layout->addWidget(item);
//    item->setStyleSheet("border-style: dashed;" "border-width: 1px;");
//    setLayout(layout);

//    item->setVisible(false);
//}

ToolItem::ToolItem(QWidget *title, QWidget *item) : item(item)
//ToolItem::ToolItem(const QString &title, QWidget *item) : item(item)
{
//    QFrame *titleWrapper = new QFrame;
//    titleWrapper->setContentsMargins(0,0,0,0);
//    titleWrapper->addWidget();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(title);
    layout->addWidget(item);
    item->setStyleSheet("margin: 0px;"
                        "border-style: dashed;"
                        "border-width: 1px;");

    title->setStyleSheet("font: bold 12px;"
                         "background-color: #FFCC00;"
                         "padding: 6px;"
                         "margin: 0px;"
                         "border-top-right-radius: 5px;"
                         "border-top-left-radius: 1px;"
                         "border-bottom-right-radius: 0px;"
                         "border-bottom-left-radius: 0px;"
                         "border-style: outset;"
                         "border-width: 1px;");
    setLayout(layout);

    item->setVisible(false);
}

void ToolItem::mousePressEvent(QMouseEvent *event)
{
    item->setVisible(!item->isVisible());
}
