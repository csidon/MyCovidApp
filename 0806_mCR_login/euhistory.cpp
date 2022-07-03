#include "euhistory.h"
#include "ui_euhistory.h"

#include "mainwindow.h"

EUHistory::EUHistory(QWidget *parent, int loggedInUserID) :
    QWidget(parent),
    ui(new Ui::EUHistory)
{
    ui->setupUi(this);
    setLoggedInUserID(loggedInUserID);


    // These objects will not be deleted when the user hits next/back arrows
    overallWrapper = new QVBoxLayout;
    pageIntro = new QVBoxLayout;
    overarchingLayout = new QVBoxLayout;
    toolBox = new ExpandingToolBox;
    pageHeader = new QLabel;
    dispUserName = new QLabel;
    dispNHI = new QLabel;


    printPageIntro();
    collectAllTestInfo();
    collectAllVaxInfo();
    printEUHistory(1);   // Prints the overarchingLayout
    setLayout(overallWrapper);  // Can I set this here?

}

EUHistory::~EUHistory()
{
    delete ui;
}




void EUHistory::on_btn_backToAdminHome_clicked()
{
    this->close();
}

void EUHistory::printPageIntro()
{
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
    // Add this to the pageIntro layout that's been
    // initialised in EUHistory::EUHistory
    pageIntro->addWidget(pageHeader);
    pageIntro->addWidget(dispUserName);
    pageIntro->addWidget(dispNHI);
    overallWrapper->addLayout(pageIntro);
}

void EUHistory::collectAllTestInfo()
{
    // Open UserTests folder and search for a CSV file with their UID
    // If file found: Sets the "global" QStringLists with testDate and testResult values
    // Else: Returns an empty QStringList

    setNumRows(0);      // Make sure numRows is 0
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
                allTestDateValues << testDateRow;

                QString testResultRow;
                if (rowValues.at(1).toInt() == 1)
                {
                    testResultRow = "Positive";
                }
                else
                {
                    testResultRow = "Negative";
                }
                allTestResultValues << testResultRow;
//                qDebug() << "The value of testResult at row " << numRows << " is " << allTestResultValues.at(numRows);
                numRows++;
            }
            qDebug() << "Total number of tests (rows) = " << numRows;
            setNumRows(numRows);    // ***Do I need to set this?
            qDebug() << "Total pages before setter is " << totalPages;

            // Deriving the number of pages needed to display tests
            int totalNoOfPages = numRows / 5; // Rounds up and gives the total number of pages
            if (numRows % 5 != 0)
            {
                totalNoOfPages++;   // Increase the total number of pages by 1 if % is 0
            }
            qDebug() << "Total num of Rows in UID's test file: " << getNumRows();
            qDebug() << "Total pages: " << totalNoOfPages;
            setTotalPages(totalNoOfPages);
        }

        else
        {
            // Check if file can't be found, or file has difficulty opening
            qDebug() << "What's the QFile error? " << searchFile.errorString();
            if (searchFile.errorString() == "The system cannot find the file specified.")
            {
                qDebug() << "The user does not have a test CSV file";
                // TotalPages remains at 0
                allTestDateValues = {};
                allTestResultValues = {};
            }
            else
            {
                // There's another error happening. Catch error.
                qDebug() << "You have a file error when trying to find/open User Test File";
            }
        }
    }
}

void EUHistory::collectAllVaxInfo()
{
    // Open UserDoses folder and search for a CSV file with their UID
    // If file found: Sets the "global" QStringLists with vsxDate and doseManuf values
    // Else: Returns an empty QStringList
    qDebug() << "Opening UserTests folder and looking for UID >>> " << getLoggedInUserID();
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    QString doseFilepath = "database/UserDoses/" + QString::number(getLoggedInUserID()) + ".csv";
    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        qDebug() << "Searching for " << getLoggedInUserID() << ".csv" << "...";
        QFile searchFile{doseFilepath};
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
                qDebug() << "Full row values are: " << rowValues;
                qDebug() << "Storing the vaccination dates for this row " << vaxRows;
                QString extractedDate = rowValues.at(0);
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
                vaxRows++;
            }
        }
        else
        {
            // Check if file can't be found, or file has difficulty opening
            qDebug() << "What's the QFile error? " << searchFile.errorString();
            if (searchFile.errorString() == "The system cannot find the file specified.")
            {
                qDebug() << "The user does not have a dose CSV file";
                QListWidget *emptyVaxList = new QListWidget;
                emptyVaxList->addItem("You have no recorded COVID-19 vaccinations");
                toolBox->addItem(new ToolItem(new QLabel("COVID-19 VACCINATION RECORD"), emptyVaxList));
            }
            else
            {
                // There's another error happening. Catch error.
                qDebug() << "You have a file error when trying to find/open User Test File";
            }
        }
    }
}


void EUHistory::printEUHistory(int page)
{
    toolBox = new ExpandingToolBox;
    c19VaxHistory = new CustomListWidget;
    c19TestList = new CustomListWidget;
    //------
    setMovingToPage(page);
    qDebug() << "Printing the pages' toolbox with content";
    qDebug() << "for totalPages = " << totalPages << " currentPage =  " <<
                currentPage << " moving to page = " << movingToPage;
    //##################################
    // Printing Vaccination Data
    //---------------------------
    // Prints empty vax list
    if (allVaxDates.isEmpty())
    {
        QListWidget *emptyVaxList = new QListWidget;
        emptyVaxList->addItem("You have no recorded COVID-19 vaccinations");
        toolBox->addItem(new ToolItem(new QLabel("COVID-19 VACCINATION RECORD"), emptyVaxList));
    }
    // Otherwise prints data stored in allVaxDates/Manufs QStringList
    else
    {
        for (int i = 0; i < vaxRows; i++)
        {
            // For the printing of each label, a new label has to be created
            // and styled, then pushed to the customListWidget
            QLabel *numDosesUL = new QLabel;    // Header
            QLabel *emptyUR = new QLabel;
            QLabel *vaxDateBL = new QLabel;
            QLabel *manufBR = new QLabel;
            // Set stylesheets
            numDosesUL->setStyleSheet("font-size: 10px;"
                                      "font-weight: normal;");
            emptyUR->setStyleSheet("font-size: 10px;"
                                       "font-weight: normal;");
            vaxDateBL->setStyleSheet("font-size: 14px;"
                                        "font-weight: normal;"
                                        "margin-bottom: 10px;");
            manufBR->setStyleSheet("font-size: 14px;"
                                        "font-weight: normal;"
                                        "margin-bottom: 10px;");


            qDebug() << "The number of vax rows are: " << vaxRows;
            QString doseNum = "Dose " + QString::number(i + 1);
            numDosesUL->setText(doseNum);
            emptyUR->setText(" ");          // Empty label (no data to fill)
            vaxDateBL->setText(allVaxDates.at(i));
            manufBR->setText(allVaxManufs.at(i));


            c19VaxHistory->addLabelItem(numDosesUL, emptyUR, vaxDateBL, manufBR);
        }
        // Does the actual printing
        toolBox->addItem(new ToolItem(new QLabel("COVID-19 VACCINATION RECORD"), c19VaxHistory));
        qDebug() << "Vaccination Toolbox added for print";
    }

    //##################################
    // Printing Test Data
    //---------------------------
    // Prints empty test list
    if (allTestDateValues.isEmpty())
    {
        QListWidget *emptyTestList = new QListWidget;
        emptyTestList->addItem("You have no recorded COVID-19 tests");
        toolBox->addItem(new ToolItem(new QLabel("YOUR COVID-19 HISTORY"), emptyTestList));
    }
    QString dateToSet = "";
    QString resultToSet = "";
    // Otherwise prints data stored in allTestDateValues & allTestResultValues
    // Determines which rows to print based on movingToPage
    qDebug() << "Total rows: " << getNumRows();
    qDebug() << "Page to print (moveToPage): " << getMovingToPage();
    qDebug() << "Total pages: " << getTotalPages();
    int printingPage = getMovingToPage();

    // If totalPages is 1, print all the rows
    if (totalPages == 1)
    {
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
        setCurrentPage(printingPage);
        c19TestList->addPageNumDisplay(printingPage,totalPages);
        toolBox->addItem(new ToolItem(new QLabel("YOUR COVID-19 HISTORY"), c19TestList));
    }
    else
    {
        int startingRow, rowToPrintTo;
        //--- Determining my starting and ending rows ---
        if (printingPage != totalPages)
        {
            // You are NOT printing the last page
            startingRow = ((printingPage - 1) * 5);  // Row starts from index 0
            rowToPrintTo = (printingPage * 5);
            qDebug() << "The page you're printing (moveTo) is " << printingPage;
            qDebug() << "Total numRows is " << numRows;
            qDebug() << "Printing rows *" << startingRow << "* to *" << rowToPrintTo;
        }
        else
        {
            // I AM printing the last page of multiple pages
            startingRow = ((printingPage - 1) * 5);
            rowToPrintTo = getNumRows();
        }
        //--- Printing labels based on starting and ending rows ---
        for (int i = startingRow; i < rowToPrintTo; i++)
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
        c19TestList->addArrows(printingPage,totalPages);   // Arrows should check which page it is and enable/disable accordingly
        connect(c19TestList->nextArrow,&QPushButton::clicked,this,goToNextPage);
        connect(c19TestList->backArrow,&QPushButton::clicked,this,goToPrevPage);
        c19TestList->addPageNumDisplay(printingPage,totalPages);
        qDebug() << "You have called your pageNum display method";
        toolBox->addItem(new ToolItem(new QLabel("YOUR COVID-19 HISTORY"), c19TestList));

    }
    setCurrentPage(printingPage);
    // Add whatever is in my toolBox list to overarchingLayout
    overarchingLayout->addWidget(toolBox);
    // Then add my overarchingLayout to the overallWrapper
    overallWrapper->addLayout(overarchingLayout);

}





void EUHistory::goToNextPage()
{
    // Delete everything in my overarchingLayout but keep
    // overarchingLayout to reprint details
    qDeleteAll(overarchingLayout->findChildren<QWidget *> (QString(), Qt::FindDirectChildrenOnly));
    delete overarchingLayout;
    overarchingLayout = new QVBoxLayout;
    int pageNow = getCurrentPage();
    int pageTo = pageNow + 1;
    setMovingToPage(pageTo);
    printEUHistory(pageTo);
    setCurrentPage(pageTo);
}

void EUHistory::goToPrevPage()
{
    qDeleteAll(overarchingLayout->findChildren<QWidget *> (QString(), Qt::FindDirectChildrenOnly));
    delete overarchingLayout;
    overarchingLayout = new QVBoxLayout;
    int pageNow = getCurrentPage();
    int pageTo = pageNow - 1;
    setMovingToPage(pageTo);
    printEUHistory(pageTo);
    setCurrentPage(pageTo);
}

//################################################
// Getters and setters collated here
//-------------------------------------------
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

int EUHistory::getNumRows() const
{
    return numRows;
}

void EUHistory::setNumRows(int newNumRows = 0)
{
    numRows = newNumRows;
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


