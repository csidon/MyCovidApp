#include "customlistwidget.h"

CustomListWidget::CustomListWidget(QListWidget*) : layout(new QVBoxLayout)
{
    setLayout(layout);
}

void CustomListWidget::addLabelItem(QLabel *uppLeft, QLabel *uppRight, QLabel *botLeft, QLabel *botRight)
{
    // Grouping the labels and putting them into layouts
    QHBoxLayout *topLabel = new QHBoxLayout;
    topLabel->addWidget(uppLeft);
    topLabel->addWidget(uppRight);
    QHBoxLayout *bottomLabel = new QHBoxLayout;
    bottomLabel->addWidget(botLeft);
    bottomLabel->addWidget(botRight);

    // Combining the layouts
    layout->addLayout(topLabel);
    layout->addLayout(bottomLabel);
    layout->addStretch();

    // Wrap it all with a QVBoxLayout -- Not working?
    QVBoxLayout *wrapper = new QVBoxLayout;
    wrapper->addLayout(layout);
}
