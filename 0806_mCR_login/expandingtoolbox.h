#ifndef EXPANDINGTOOLBOX_H
#define EXPANDINGTOOLBOX_H
#include <QWidget>
#include <QVBoxLayout>
#include "toolitem.h"



class ExpandingToolBox : public QWidget
{
public:
    ExpandingToolBox();
    void addItem(ToolItem *item);
private:
    QVBoxLayout *layout;
};

#endif // EXPANDINGTOOLBOX_H
