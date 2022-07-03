#include "toolitem.h"
#include "euhistory.h"
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
//ToolItem::ToolItem(QWidget *title, QStringList *itemList) : item(itemList)
{
//    QFrame *titleWrapper = new QFrame;
//    titleWrapper->setContentsMargins(0,0,0,0);
//    titleWrapper->addWidget();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(title);
    layout->addWidget(item);

//    item->setGeometry(0,0,320,800);
    item->setStyleSheet("border-style: none;"
                        "border-width: 1px;");
    item->setMinimumHeight(350);



    title->setStyleSheet("background-color: #FFCC00;"
                         "padding: 6px;"
                         "margin: 0px;"
                         "border-top-right-radius: 10px;"
                         "border-top-left-radius: 3px;"
                         "border-bottom-right-radius: 0px;"
                         "border-bottom-left-radius: 0px;"
                         "border-width: 1px;");
    title->setMinimumHeight(0);
    setLayout(layout);

    item->setVisible(false);
}

void ToolItem::mousePressEvent(QMouseEvent *event)
{
    item->setVisible(!item->isVisible());
//    item->setMinimumHeight(350);

}
