#include "customlistwidget.h"

CustomListWidget::CustomListWidget(QListWidget*) : layout(new QVBoxLayout)
{
    setLayout(layout);
    dispPageNum = new QLabel;
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
}

void CustomListWidget::addProfileItem(QLabel *title, QLabel *data)
{
    title->setStyleSheet("font-size: 12px;"
                         "font-weight: bold;"
                         "padding-top: 5px;"
                         "padding-bottom: 0px;");
    data->setStyleSheet("font-size: 16px;"
                         "font-weight: normal;"
                         "padding-top: 0px;");
    // Grouping the labels and putting them into layouts
    QVBoxLayout *oneLabel = new QVBoxLayout;
    oneLabel->addWidget(title);
    oneLabel->addWidget(data);
    // Combining the layouts
    layout->addLayout(oneLabel);
    layout->addStretch();
}


void CustomListWidget::addArrows(int printingPage, int totalPages)
{
    backArrow = new QPushButton;
    nextArrow = new QPushButton;
    backArrow->setIcon(QIcon(":/images/pageLeft.png"));
    nextArrow->setIcon(QIcon(":/images/pageRight.png"));

    if (printingPage == 1)
    {
        backArrow->setDisabled(true);
    }
    if (printingPage < totalPages)
    {
        nextArrow->setEnabled(true);
    }
    if (printingPage > 1)
    {
        backArrow->setEnabled(true);
    }
    if (printingPage == totalPages)
    {
        nextArrow->setDisabled(true);
    }

    QHBoxLayout *arrowContainer = new QHBoxLayout;
    arrowContainer->setAlignment(Qt::AlignRight);
    arrowContainer->addWidget(backArrow);
    arrowContainer->addWidget(nextArrow);
    layout->addLayout(arrowContainer);
}

// Displays the page number if there's more than one page, but also
// returns the current page number
void CustomListWidget::addPageNumDisplay(int page, int totalPages)
{
    QHBoxLayout *pageNumContainer = new QHBoxLayout;
    pageNumContainer->setAlignment(Qt::AlignRight);

    QString pageOfPage = QString::number(page) + " of " + QString::number(totalPages);
    dispPageNum->setText(pageOfPage);

    // Sets a page number
    pageNumContainer->addWidget(dispPageNum);
    layout->addLayout(pageNumContainer);

    // Set the current page and total pages for updating
    setPage(page);
    setTotalPages(totalPages);
}


//################################################
// Getters and setters
//-----------------------------------------------
int CustomListWidget::getPage()
{
    return currentPage;
}

void CustomListWidget::setPage(int page)
{
    this->currentPage = page;
}

int CustomListWidget::getTotalPages()
{
    return totalPages;
}

void CustomListWidget::setTotalPages(int tPages)
{
    this->totalPages = tPages;
}
