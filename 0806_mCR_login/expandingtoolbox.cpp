#include "expandingtoolbox.h"

ExpandingToolBox::ExpandingToolBox() : layout(new QVBoxLayout)
{
    setLayout(layout);
}

void ExpandingToolBox::addItem(ToolItem *item)
{
    // Remove last spacer item if present.
    int count = layout->count();
    if (count > 1)
    {
      layout->removeItem(layout->itemAt(count - 1));
    }

    // Add item and make sure it stretches the remaining space.
    layout->addWidget(item);
    layout->addStretch();
}

