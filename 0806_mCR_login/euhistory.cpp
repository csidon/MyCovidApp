#include "euhistory.h"
#include "ui_euhistory.h"

#include "mainwindow.h"

EUHistory::EUHistory(QWidget *parent, int loggedInUserID) :
    QWidget(parent),
    ui(new Ui::EUHistory)
{
    ui->setupUi(this);
    setLoggedInUserID(loggedInUserID);
    overarchingLayout = new QVBoxLayout;
    overallWrapper = new QVBoxLayout;

    //------------------------------------------------------------------------
    // Initialising pointer variables to be used "globally" within this class
    // (These are not global variables, just variables that will be used
    // across all functions within this class)
    //------
//    pageHeader = new QLabel;
//    dispUserName = new QLabel;
//    dispNHI = new QLabel;
    toolBox = new ExpandingToolBox;
    c19TestList = new CustomListWidget;
    testTypeUL = new QLabel;
    dateLabelUR = new QLabel;
    reportTypeBL = new QLabel;
    testResultBR = new QLabel;
    allTestLabelValues = new QVector<CustomListWidget>;


//    //------
//    // Setting stylesheets for labels to be displayed
//    pageHeader->setStyleSheet("font-size: 22px;"
//                            "font-weight: bold;"
//                            "padding-top: 10px;");
//    pageHeader->setWordWrap(true);
//    dispUserName->setStyleSheet("font-size: 18px;"
//                                "font-weight: normal;");
//    dispNHI->setStyleSheet("font-size: 18px;"
//                                "font-weight: normal;");
//    pageHeader->setAlignment(Qt::AlignHCenter);
//    dispUserName->setAlignment(Qt::AlignHCenter);
//    dispNHI->setAlignment(Qt::AlignHCenter);
//    QVBoxLayout *overallWrapper = new QVBoxLayout;
//    //--- Test Stylesheets---
////    testTypeUL->setText("Rapid Antigen Test");


//    //---------------------------------------------
//    // Retrieving user information
//    //--------
//    HandleCSV accountReader;
//    UserAccount loggedInUser = accountReader.getUserAccount(loggedInUserID);

//    //---------------------------------------------
//    // Shows user information at the top
//    //-----------------------
//    pageHeader->setText("Vaccination Record \n& Reported Test Results");
//    QString displayUserName = loggedInUser.getUserPreferredName() + " " + loggedInUser.getUserFirstName()
//            + " " + loggedInUser.getUserLastName();
//    QString displayNHI;
//    if (loggedInUser.getUserNHINumber() == "")
//    {
//        displayNHI = "NHI: Not Entered";
//    }
//    else
//    {
//        displayNHI = "NHI: " + loggedInUser.getUserNHINumber();
//    }
//    dispUserName->setText(displayUserName);
//    dispNHI->setText(displayNHI);

//    QVBoxLayout *pageIntro = new QVBoxLayout;
//    pageIntro->addWidget(pageHeader);
//    pageIntro->addWidget(dispUserName);
//    pageIntro->addWidget(dispNHI);




    //----------------------------------------------
    // List to show if user clicks on Test History
    //-----
    // Open UserTests folder and search for a CSV file with their UID
//    HandleCSV checkCSV;
    setNumRows(0);
    qDebug() << "Opening UserTests folder and looking for UID >>> " << getLoggedInUserID();
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    QString filepath = "database/UserTests/" + QString::number(getLoggedInUserID()) + ".csv";
    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        qDebug() << "Searching for " << getLoggedInUserID() << ".csv" << "...";
        QFile searchFile{filepath};
        if (searchFile.open(QIODevice::ReadOnly| QIODevice::Text))
        {
            qDebug() << "The file has been found and opened. ";

            // File found. Now extract data for display
            QStringList testDates;
            QString row;
            QStringList rowValues;


            while(!searchFile.atEnd())
            {
                // Read and split the rows
                row = searchFile.readLine().trimmed();
                rowValues = row.split(',');
                //Grabbing the rows' values
                testDates << rowValues.at(0);
                qDebug() << "Full row values are: " << rowValues;
                qDebug() << "Storing the test date for ROW " << numRows << " into vector";
                QString testDateRow = rowValues.at(0);
                // Push all users' test dates/results into a vector and (later) sets this
                // so that it can used in any function
                allTestDateValues.push_back(testDateRow);

                QString testResultRow;
                if (rowValues.at(1).toInt() == 1)
                {
                    testResultRow = "Positive";
                }
                else
                {
                    testResultRow = "Negative";
                }
                allTestResultValues.push_back(testResultRow);
//                qDebug() << "The value of testResult at row " << numRows << " is " << allTestDateValues.at(numRows);
                numRows++;
            }
            qDebug() << "Total number of tests (rows) = " << numRows;
            setNumRows(numRows);    // ***Do I need to set this?
            qDebug() << "Total pages before setter is " << totalPages;


            // Deriving the number of pages needed to display tests
            int totalNoOfPages = numRows / 5; // Rounds up and gives the total number of pages
            if (numRows % 5 != 0)
            {
                totalNoOfPages++;   // Increase the total number of pages if % is 0
            }

            qDebug() << "Total num of Rows in UID's test file: " << numRows;
            qDebug() << "Total pages: " << totalNoOfPages;
            setTotalPages(totalNoOfPages);
            setCurrentPage(1);
            setMovingToPage(1);

            // If there's only 1 test page, just display the tests in the
            // expandingtoolbox "slot"
//            if (totalNoOfPages == 1)
//            {
//                for (int i = 0; i < numRows; i++)
//                {
//                    dateToSet = allTestDateValues.at(i);
//                    resultToSet = allTestResultValues.at(i);
//                    dateLabelUR->setText(dateToSet);
//                    testResultBR->setText(resultToSet);
//                    c19TestList->addLabelItem(testTypeUL,dateLabelUR,reportTypeBL,testResultBR);
//                    qDebug() << "Set labels for single page, row " << i;
//                }
//                toolBox->addItem(new ToolItem(new QLabel("YOUR COVID-19 HISTORY"), c19TestList));
//            }
//            else    // print 5 test summaries and add a page button
//            {
//                // Figure out which page you're printing

//                for (int i = 0; i < 5; i++)
//                {
//                    //-----------------------
////                    QLabel *testTypeUL = new QLabel;
////                    testTypeUL->setStyleSheet("font-size: 14px;"
////                                              "font-weight: normal;");
////                    testTypeUL->setText("Rapid Antigen Test");

////                    QLabel *dateLabelUR = new QLabel;
////                    dateLabelUR->setStyleSheet("font-size: 14px;"
////                                               "font-weight: normal;");
////                    QLabel *reportTypeBL = new QLabel;
////                    reportTypeBL->setStyleSheet("font-size: 10px;"
////                                                "font-weight: normal;"
////                                                "margin-bottom: 10px;");
////                    reportTypeBL->setText("Self-reported");

////                    QLabel *testResultBR = new QLabel;

////                    testResultBR->setStyleSheet("font-size: 10px;"
////                                                "font-weight: normal;"
////                                                "margin-bottom: 10px;");

//                    // For the creation of each label, a new label has to be created
//                    // and styled, then pushed to the customListWidget

//                    testTypeUL = new QLabel;
//                    dateLabelUR = new QLabel;
//                    reportTypeBL = new QLabel;
//                    testResultBR = new QLabel;
//                    // Set stylesheets
//                    testTypeUL->setStyleSheet("font-size: 14px;"
//                                              "font-weight: normal;");
//                    dateLabelUR->setStyleSheet("font-size: 14px;"
//                                               "font-weight: normal;");
//                    reportTypeBL->setStyleSheet("font-size: 10px;"
//                                                "font-weight: normal;"
//                                                "margin-bottom: 10px;");
//                    testResultBR->setStyleSheet("font-size: 10px;"
//                                                "font-weight: normal;"
//                                                "margin-bottom: 10px;");
//                    //--------------------------------
//                    testTypeUL->setText("Rapid Antigen Test");
//                    reportTypeBL->setText("Self-reported");
//                    dateToSet = allTestDateValues.at(i);
//                    resultToSet = allTestResultValues.at(i);
//                    dateLabelUR->setText(dateToSet);
//                    testResultBR->setText(resultToSet);
//                    c19TestList->addLabelItem(testTypeUL,dateLabelUR,reportTypeBL,testResultBR);
////                    allTestLabelValues->push_back(c19TestList);

//                }
//                toolBox->addItem(new ToolItem(new QLabel("YOUR COVID-19 HISTORY"), c19TestList));
//                c19TestList->addArrows();   // Code behaviour of arrows below
//                c19TestList->addPageNumDisplay(1,totalNoOfPages);
//            }
        }

        else
        {
            // Check if file can't be found, or file has difficulty opening
            qDebug() << "What's the QFile error? " << searchFile.errorString();
            if (searchFile.errorString() == "The system cannot find the file specified.")
            {
                // TotalPages remains at 0
                printHistoryPage();
//                QListWidget *emptyTestList = new QListWidget;
//                emptyTestList->addItem("You have no recorded COVID-19 tests");
//                toolBox->addItem(new ToolItem(new QLabel("YOUR COVID-19 HISTORY"), emptyTestList));
            }
            else
            {

            }
        }
    }

    //-------------------------------------------------
    // List to show if user clicks on Vaccination Record
    //-----
    // Same standardPath, different filepath

//    // DUP FOR TESTING TO DELETE
//    qDebug() << "Opening UserTests folder and looking for UID >>> " << getLoggedInUserID();
//    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
//    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
//    QDir d{path};
//    QString filepath = "database/UserTests/" + QString::number(getLoggedInUserID()) + ".csv";
//    // DUPLICATE FOR TESTING ^^ TO DELETE ^^


    QString doseFilepath = "database/UserDoses/" + QString::number(getLoggedInUserID()) + ".csv";
    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        qDebug() << "Searching for " << getLoggedInUserID() << ".csv" << "...";
        QFile searchFile{doseFilepath};
        c19VaxHistory = new CustomListWidget;
        if (searchFile.open(QIODevice::ReadOnly| QIODevice::Text))
        {
            qDebug() << "The file has been found and opened. ";
            // File found. Now extract data for display         
            // [LOCAL VARS] Used for splitting and reading lines
            QString row;
            QStringList rowValues;

            while(!searchFile.atEnd())
            {
                // Read and split the rows
                row = searchFile.readLine().trimmed();
                rowValues = row.split(',');
//                vaxDates << rowValues.at(0);
                qDebug() << "Full row values are: " << rowValues;
                qDebug() << "Storing the vaccination dates for this row " << vaxRows;
                QString extractedDate = rowValues.at(0);
//                QString extractedDate = vaxDate(vaxRows);
                QDate rowVaxQDate = QDate::fromString(extractedDate, "yyyyMMdd");
                QString rowVaxDate = rowVaxQDate.toString("dd MMM yyyy");
                qDebug() << "The rowVaxDate is " << rowVaxDate << " and vaxQdate is " << rowVaxQDate;
                allVaxDates << rowVaxDate;

                QString doseManuf;      // Translating the stored int to QString
                if (rowValues.at(1).toInt() == 1)
                {
                    doseManuf = "Pfizer-BioNTech";
                }
                else if (rowValues.at(1).toInt() == 2)
                {
                    doseManuf = "Novavax";
                }
                else
                {
                    doseManuf = "GlaxoSmithKline";
                }
                // Storing in QStringList allVaxManufs
                allVaxManufs << doseManuf;

//                QLabel *numDosesUL = new QLabel;
//                qDebug() << "The number of vax rows are: " << vaxRows;
//                QString doseNum = "Dose " + QString::number(vaxRows + 1);
//                numDosesUL->setText(doseNum);
//                QLabel *emptyUR = new QLabel;
//                emptyUR->setText("");
//                QLabel *vaxDateBL = new QLabel;
//                vaxDateBL->setText(rowVaxDate);
//                QLabel *manufBR = new QLabel;
//                manufBR->setText(doseManuf);

//                c19VacHistory->addLabelItem(numDosesUL, emptyUR, vaxDateBL, manufBR);
//                qDebug() << "Vaccination dates recorded are " << vaxDates;
                vaxRows++;
            }
//            toolBox->addItem(new ToolItem(new QLabel("COVID-19 VACCINATION RECORD"), c19VaxHistory));
//            qDebug() << "The number of vax entries (rows) are: " << vaxRows;

        }
        else
        {
            // Check if file can't be found, or file has difficulty opening
            qDebug() << "What's the QFile error? " << searchFile.errorString();
            if (searchFile.errorString() == "The system cannot find the file specified.")
            {
                QListWidget *emptyVaxList = new QListWidget;
                emptyVaxList->addItem("You have no recorded COVID-19 vaccinations");
                toolBox->addItem(new ToolItem(new QLabel("COVID-19 VACCINATION RECORD"), emptyVaxList));

            }
        }
        printHistoryPage();

    }


    QListWidget *list = new QListWidget;
//    list->addItem("One");
//    list->addItem("Two");
//    list->addItem("Three");
    for(int i = 0; i < 5; i++)
    {
        list->addItem("testText");
    }



//    ExpandingToolBox *toolBox = new ExpandingToolBox;

//    toolBox->addItem(new ToolItem("Title 1\nSubTitles", new QLabel("Some text here\nDoes this work?")));
//    toolBox->addItem(new ToolItem("Title 2", list));
//    toolBox->addItem(new ToolItem("Fancy Title", new QLabel("Lorem Ipsum..")));
//    toolBox->addItem(new ToolItem(new QLabel("Fancy Title"), list));
//    toolBox->addItem(new ToolItem(new QLabel("Fancy Title"), new QLabel("Lorem Ipsum..")));

//    QVBoxLayout *overarchingLayout = new QVBoxLayout;
//    overarchingLayout->addWidget(toolBox);


////    setLayout(overarchingLayout);

//    overallWrapper->addLayout(pageIntro);
//    overallWrapper->addLayout(overarchingLayout);
//    setLayout(overallWrapper);


}

EUHistory::~EUHistory()
{
    delete ui;
}

int EUHistory::getLoggedInUserID()
{
    return userID;
}

void EUHistory::setLoggedInUserID(int newLoggedInUserID)
{
    this->userID = newLoggedInUserID;
}

QString EUHistory::getTestDate()
{
    return testDate;
}

void EUHistory::setTestDate(QString tDate)
{
    this->testDate = tDate;
}

//CustomListWidget EUHistory::printTestSummary(int pageNum, std::vector<QString> allTestDateValues, std::vector<QString> allTestResultValues)
//{
//    CustomListWidget eachTestSummary;

////    allTestDateValues[i]      //########### IMPLEMENT THIS AFTER TKD!!
//    QLabel *testTypeUL = new QLabel;
////                testTypeUL->setFixedHeight(25);
//    testTypeUL->setText("Rapid Antigen Test");
//    testTypeUL->setStyleSheet("font-size: 14px;"
//                              "font-weight: normal;"
//                              );
////                dateLabelUR->setWordWrap(true);
//    QLabel *dateLabelUR = new QLabel;
////                testTypeUL->setFixedHeight(25);
//    dateLabelUR->setText(testDateRow);
//    dateLabelUR->setStyleSheet("font-size: 14px;"
//                               "font-weight: normal;");
//    QLabel *reportTypeBL = new QLabel;
////                testTypeUL->setFixedHeight(25);
//    reportTypeBL->setText("Self-reported");
//    reportTypeBL->setStyleSheet("font-size: 10px;"
//                                "font-weight: normal;"
//                                "margin-bottom: 10px;");
//    QLabel *testResultBR = new QLabel;
////                testTypeUL->setFixedHeight(25);
//    testResultBR->setText(testResultRow);
//    testResultBR->setStyleSheet("font-size: 10px;"
//                                "font-weight: normal;"
//                                "margin-bottom: 10px;");

//    eachTestSummary->addLabelItem(testTypeUL, dateLabelUR, reportTypeBL, testResultBR);
//    return eachTestSummary;
//}



void EUHistory::on_btn_backToAdminHome_clicked()
{
    this->close();
}

int EUHistory::getNumRows() const
{
    return numRows;
}

void EUHistory::setNumRows(int newNumRows = 0)
{
    numRows = newNumRows;
}

void EUHistory::printHistoryPage()
{
    pageHeader = new QLabel;
    dispUserName = new QLabel;
    dispNHI = new QLabel;
    toolBox = new ExpandingToolBox;
    //------
    // Setting stylesheets for labels to be displayed
    pageHeader->setStyleSheet("font-size: 22px;"
                            "font-weight: bold;"
                            "padding-top: 10px;");
    pageHeader->setWordWrap(true);
    dispUserName->setStyleSheet("font-size: 18px;"
                                "font-weight: normal;");
    dispNHI->setStyleSheet("font-size: 18px;"
                                "font-weight: normal;");
    pageHeader->setAlignment(Qt::AlignHCenter);
    dispUserName->setAlignment(Qt::AlignHCenter);
    dispNHI->setAlignment(Qt::AlignHCenter);

    //--- Test Stylesheets---
//    testTypeUL->setText("Rapid Antigen Test");


    //---------------------------------------------
    // Retrieving user information
    //--------
    HandleCSV accountReader;
    UserAccount loggedInUser = accountReader.getUserAccount(getLoggedInUserID());

    //---------------------------------------------
    // Shows user information at the top
    //-----------------------
    pageHeader->setText("Vaccination Record \n& Reported Test Results");
    QString displayUserName = loggedInUser.getUserPreferredName() + " " + loggedInUser.getUserFirstName()
            + " " + loggedInUser.getUserLastName();
    QString displayNHI;
    if (loggedInUser.getUserNHINumber() == "")
    {
        displayNHI = "NHI: Not Entered";
    }
    else
    {
        displayNHI = "NHI: " + loggedInUser.getUserNHINumber();
    }
    dispUserName->setText(displayUserName);
    dispNHI->setText(displayNHI);

    QVBoxLayout *pageIntro = new QVBoxLayout;
    pageIntro->addWidget(pageHeader);
    pageIntro->addWidget(dispUserName);
    pageIntro->addWidget(dispNHI);


    qDebug() << "Printing the pages' toolbox with content";
    qDebug() << "for totalPages = " << totalPages << " currentPage =  " <<
                currentPage << " moving to page = " << movingToPage;

    QString dateToSet = "";
    QString resultToSet = "";

    // Prepare the vaccination history data (there will always only be 1 page)
    if (vaxRows == 0)
    {
        QListWidget *emptyVaxList = new QListWidget;
        emptyVaxList->addItem("You have no recorded COVID-19 vaccinations");
        toolBox->addItem(new ToolItem(new QLabel("COVID-19 VACCINATION RECORD"), emptyVaxList));
    }
    else
    {
        for (int i = 0; i < vaxRows; i++)
        {
            // For the printing of each label, a new label has to be created
            // and styled, then pushed to the customListWidget
            QLabel *numDosesUL = new QLabel;    // Header
            qDebug() << "The number of vax rows are: " << vaxRows;
            QString doseNum = "Dose " + QString::number(i + 1);
            numDosesUL->setText(doseNum);

            QLabel *emptyUR = new QLabel;       // Empty label (not needed)
            emptyUR->setText(" ");

            QLabel *vaxDateBL = new QLabel;
            vaxDateBL->setText(allVaxDates.at(i));

            QLabel *manufBR = new QLabel;
            manufBR->setText(allVaxManufs.at(i));

            c19VaxHistory->addLabelItem(numDosesUL, emptyUR, vaxDateBL, manufBR);
        }
    }

    // Check if there's only one testHistory sub-page
    if (totalPages == 0)
    {
        QListWidget *emptyTestList = new QListWidget;
        emptyTestList->addItem("You have no recorded COVID-19 tests");
        toolBox->addItem(new ToolItem(new QLabel("YOUR COVID-19 HISTORY"), emptyTestList));
    }
    else if (totalPages == 1)
    {

        // Print whatever is on the page for tests
        for (int i = 0; i < numRows; i++)
        {
            // For the printing of each label, a new label has to be created
            // and styled, then pushed to the customListWidget

            testTypeUL = new QLabel;
            dateLabelUR = new QLabel;
            reportTypeBL = new QLabel;
            testResultBR = new QLabel;
            // Set stylesheets
            testTypeUL->setStyleSheet("font-size: 14px;"
                                      "font-weight: normal;");
            dateLabelUR->setStyleSheet("font-size: 14px;"
                                       "font-weight: normal;");
            reportTypeBL->setStyleSheet("font-size: 10px;"
                                        "font-weight: normal;"
                                        "margin-bottom: 10px;");
            testResultBR->setStyleSheet("font-size: 10px;"
                                        "font-weight: normal;"
                                        "margin-bottom: 10px;");
            //--------------------------------
            testTypeUL->setText("Rapid Antigen Test");
            reportTypeBL->setText("Self-reported");
            dateToSet = allTestDateValues.at(i);
            resultToSet = allTestResultValues.at(i);
            qDebug() << "About to set date: " << dateToSet << " and result: " << resultToSet;
            dateLabelUR->setText(dateToSet);
            testResultBR->setText(resultToSet);
            c19TestList->addLabelItem(testTypeUL,dateLabelUR,reportTypeBL,testResultBR);

        }
        // Then add list to layout
        toolBox->addItem(new ToolItem(new QLabel("YOUR COVID-19 HISTORY"), c19TestList));
    }
    else
    {
        // Determine the page that you're trying to print
        int pageToPrint = getMovingToPage();
        int rowToPrintTo;
        qDebug() << "The page you're going to print (moveTo) is " << pageToPrint;
        qDebug() << "Total num of rows should be " << numRows;
        int startingRow = ((pageToPrint - 1) * 5) + 1;  \

        // If i'm not printing the last page
        if ((pageToPrint != totalPages) || (numRows % 5 == 0))
        {
            rowToPrintTo = pageToPrint * 5;
        }
        else    // I'm printing the last page with less than 5 entries
        {
            rowToPrintTo = (numRows % 5) + ((pageToPrint - 1) * 5);
        }
        // StartingRow - 1 because vector starts at index 0woo@kie.com
        for (int i = (startingRow - 1); i < rowToPrintTo; i++)
        {
            // For the printing of each label, a new label has to be created
            // and styled, then pushed to the customListWidget
            testTypeUL = new QLabel;
            dateLabelUR = new QLabel;
            reportTypeBL = new QLabel;
            testResultBR = new QLabel;
            // Set stylesheets
            testTypeUL->setStyleSheet("font-size: 14px;"
                                      "font-weight: normal;");
            dateLabelUR->setStyleSheet("font-size: 14px;"
                                       "font-weight: normal;");
            reportTypeBL->setStyleSheet("font-size: 10px;"
                                        "font-weight: normal;"
                                        "margin-bottom: 10px;");
            testResultBR->setStyleSheet("font-size: 10px;"
                                        "font-weight: normal;"
                                        "margin-bottom: 10px;");
            //--------------------------------
            testTypeUL->setText("Rapid Antigen Test");
            reportTypeBL->setText("Self-reported");
            dateToSet = allTestDateValues.at(i);
            resultToSet = allTestResultValues.at(i);
            qDebug() << "About to set date: " << dateToSet << " and result: " << resultToSet;
            dateLabelUR->setText(dateToSet);
            testResultBR->setText(resultToSet);
            c19TestList->addLabelItem(testTypeUL,dateLabelUR,reportTypeBL,testResultBR);

        }
        // Then add list to layout
        c19TestList->addArrows();
        c19TestList->addPageNumDisplay(pageToPrint,totalPages);
        toolBox->addItem(new ToolItem(new QLabel("YOUR COVID-19 HISTORY"), c19TestList));
//        connect(c19TestList->CustomListWidget::nextArrow,&QPushButton::connect,this,&EUHistory::goToNextPage);
//        connect(&CustomListWidget::nextArrow, &QPushButton::clicked,this->goToNextPage);
        connect(c19TestList->nextArrow,&QPushButton::clicked,this,goToNextPage);

    }

    // This does the actual printing
    qDebug() << "Trying to actually print ";
    toolBox->addItem(new ToolItem(new QLabel("COVID-19 VACCINATION RECORD"), c19VaxHistory));
//    QVBoxLayout *overarchingLayout = new QVBoxLayout;
    overarchingLayout->addWidget(toolBox);
    overallWrapper->addLayout(pageIntro);
    overallWrapper->addLayout(overarchingLayout);
    setLayout(overallWrapper);

}

void EUHistory::clearPage()
{
//    if(overallWrapper->layout() != NULL)
//    {
//        QLayoutItem *item;
//        while (item = overallWrapper->layout()->takeAt(0) != NULL)
//        {
//            delete item->widget();
//            delete item;
//        }
//        delete overallWrapper->layout();)
//    }

//    QLayoutItem *child;
//    while ((child = delLay->takeAt(0)) != 0 )
//    {
//        if (child->layout() != 0)
//        {
//            remove(child->widget());
//        }
//        else if (child->widget() != 0)
//        {
//            delete child->widget();
//        }
//        delete child;
//    }
}

void EUHistory::goToNextPage()
{
    this->close();
    this->show();
    int pageNow = getCurrentPage();
    int pageTo = pageNow + 1;
    setMovingToPage(pageTo);
    printHistoryPage();
}

int EUHistory::getMovingToPage() const
{
    return movingToPage;
}

void EUHistory::setMovingToPage(int newMovingToPage = 0)
{
    movingToPage = newMovingToPage;
}

int EUHistory::getTotalPages() const
{
    return totalPages;
}

void EUHistory::setTotalPages(int newTotalPages = 0)
{
    totalPages = newTotalPages;
}

int EUHistory::getCurrentPage() const
{
    return currentPage;
}

void EUHistory::setCurrentPage(int newCurrentPage = 0)
{
    currentPage = newCurrentPage;
}

