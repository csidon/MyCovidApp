#ifndef EXPANDINGTOOLBOX_H
#define EXPANDINGTOOLBOX_H
#include <QWidget>
#include <QVBoxLayout>
#include "toolitem.h"
#include <QPushButton>


// This is a custom widget created to emulate
// QToolBox, but with expanding capabilities
// Used in conjunction with ToolItem and CustomListWidget
// Refer to documentation on layout priorities
class ExpandingToolBox : public QWidget
{
public:
    ExpandingToolBox();
    void addItem(ToolItem *item);
private:
    QVBoxLayout *layout;
};

#endif // EXPANDINGTOOLBOX_H
