#include "customlistwidget.h"
#include "handlepagemoves.h"

CustomListWidget::CustomListWidget(QListWidget*) : layout(new QVBoxLayout)
{
    setLayout(layout);
    dispPageNum = new QLabel;
//    connect(nextArrow, &QPushButton::clicked,this,&nextPage);
//    connect(nextArrow, SIGNAL(clicked()),this, SLOT(nextPage(int, int)));
//    connect(backArrow, SIGNAL(clicked()),this, SLOT(backPage(int, int)));
}

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

void CustomListWidget::addLabelItem(QLabel *uppLeft, QLabel *uppRight, QLabel *botLeft, QLabel *botRight)
{
    // Grouping the labels and putting them into layouts
    QHBoxLayout *topLabel = new QHBoxLayout;
    topLabel->addWidget(uppLeft);
    topLabel->addWidget(uppRight);
    qDebug() << "Created top Label layout ";
    QHBoxLayout *bottomLabel = new QHBoxLayout;
    bottomLabel->addWidget(botLeft);
    bottomLabel->addWidget(botRight);
    qDebug() << "Created bottom Label layout";

    // Combining the layouts
    layout->addLayout(topLabel);
    qDebug() << "Added top Label ";
    layout->addLayout(bottomLabel);
    qDebug() << "Added bottom Label ";
    layout->addStretch();
    qDebug() << "Stretch added ";
//    QLabel *testLab = new QLabel;
//    testLab->setText("Please do something");
//    layout->addWidget(testLab);

    // Wrap it all with a QVBoxLayout -- Not working?
    QVBoxLayout *wrapper = new QVBoxLayout;
    wrapper->addLayout(layout);
    qDebug() << "Are we wrapping? ";
}

//QVBoxLayout CustomListWidget::getLabelItem()
//{
//    return layout;
//}

void CustomListWidget::addArrows()
{
    backArrow = new QPushButton;
    nextArrow = new QPushButton;
    // Disable the back arrow by default
    backArrow->setDisabled(true);

    backArrow->setIcon(QIcon(":/images/pageLeft.png"));
    nextArrow->setIcon(QIcon(":/images/pageRight.png"));

    QHBoxLayout *arrowContainer = new QHBoxLayout;
//    arrowContainer->addSpacing(300);
    arrowContainer->setAlignment(Qt::AlignRight);
    arrowContainer->addWidget(backArrow);
    arrowContainer->addWidget(nextArrow);
    connect(nextArrow, &QPushButton::clicked,this,nextPage);
    layout->addLayout(arrowContainer);
    connect(backArrow, &QPushButton::clicked,this,backPage);
    layout->addLayout(arrowContainer);
//    connect(nextArrow, &QPushButton::clicked,&handlePageMoves,&handlePageMoves::goToNextPage);
//    connect(this->nextArrow,&QPushButton::clicked, std::bind(EUHistory::goToNextPage,this));
//    connect(nextArrow,&QPushButton::clicked,
//            [](){&EUHistory::goToNextPage};);

//            [EUHistorytestObj](){EUHistory::goToNextPage();});

}

// Displays the page number if there's more than one page, but also
// returns the current page number
void CustomListWidget::addPageNumDisplay(int page, int totalPages)
{
    QHBoxLayout *pageNumContainer = new QHBoxLayout;
    pageNumContainer->setAlignment(Qt::AlignRight);

    QString pageOfPage = QString::number(page) + " of " + QString::number(totalPages);

    dispPageNum->setText(pageOfPage);

    qDebug() << "page of pages is " << pageOfPage;
    qDebug() << "GetTotalPages " << getTotalPages();
    qDebug() << "GETTEXT outside loop " << dispPageNum->text();
    if(getTotalPages() >= 1)     // Means that this has already been set
    {
//        pageNumContainer->removeWidget(dispPageNum);
        // Update pageNums
        qDebug() << "GETTEXT inside loop " << dispPageNum->text();
        dispPageNum->setText(pageOfPage);
        qDebug() << "You are updating the page num display";
    }
    else        // Add pageNums
    {
        qDebug() << "You are trying to add a page num display";

        dispPageNum->setText(pageOfPage);
        pageNumContainer->addWidget(dispPageNum);
        layout->addLayout(pageNumContainer);

        qDebug() << "You should have successfully set the page num display";

    }

    layout->addLayout(pageNumContainer);


    // Set the current page and total pages for updating
    setPage(page);
    setTotalPages(totalPages);
    qDebug() << "Your getPage() is " <<  getPage() << " and getTotalPages() is " << getTotalPages();

    if (getPage() == getTotalPages())
    {
        nextArrow->setDisabled(true);
    }
    if(getPage() == 1)
    {
        backArrow->setDisabled(true);
    }

}

void CustomListWidget::nextPage()
{
    int retPage = getPage() + 1;
    int retTotalPages = getTotalPages();
    addPageNumDisplay(retPage, retTotalPages);
    backArrow->setEnabled(true);
}

void CustomListWidget::backPage()
{
    int retPage = getPage() - 1;
    int retTotalPages = getTotalPages();
    addPageNumDisplay(retPage, retTotalPages);
    nextArrow->setEnabled(true);
}
