#include "toolitem.h"
#include "euhistory.h"

ToolItem::ToolItem(QWidget *title, QWidget *item) : item(item)
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(title);
    layout->addWidget(item);
    // Setting style for items to be added to custom "toolbox"
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
}
