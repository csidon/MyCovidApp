#include "euhistory.h"
#include "ui_euhistory.h"
#include <QFrame>
#include <QToolBox>
#include <QPushButton>
#include "mainwindow.h"
#include "useraccount.h"
#include "handlecsv.h"
#include <QListWidgetItem>
#include "customlistwidget.h"
#include "handlecsv.h"
#include "useraccount.h"

EUHistory::EUHistory(QWidget *parent, int loggedInUserID) :
    QWidget(parent),
    ui(new Ui::EUHistory)
{
    ui->setupUi(this);
    setLoggedInUserID(loggedInUserID);

    QVBoxLayout *overallWrapper = new QVBoxLayout;

    //---------------------------------------------
    // Retrieving user information
    //--------
    HandleCSV accountReader;
    UserAccount loggedInUser = accountReader.getUserAccount(loggedInUserID);

    //---------------------------------------------
    // Shows user information at the top
    //-----------------------
    QLabel *pageHeader = new QLabel;
    pageHeader->setText("Vaccination Record & Reported Test Results");
    pageHeader->setWordWrap(true);
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

    QLabel *dispUserName = new QLabel;
    QLabel *dispNHI = new QLabel;
    dispUserName->setText(displayUserName);
    dispNHI->setText(displayNHI);
    pageHeader->setAlignment(Qt::AlignHCenter);
    dispUserName->setAlignment(Qt::AlignHCenter);
    dispNHI->setAlignment(Qt::AlignHCenter);
    QVBoxLayout *pageIntro = new QVBoxLayout;
    pageIntro->addWidget(pageHeader);
    pageIntro->addWidget(dispUserName);
    pageIntro->addWidget(dispNHI);



    //----------------------------------------------
    // List to show if user clicks on Test History
    //-----
    // Open UserTests folder and search for a CSV file with their UID
    HandleCSV checkCSV;
    ExpandingToolBox *toolBox = new ExpandingToolBox;

    qDebug() << "Opening UserTests folder and looking for UID >>> " << getLoggedInUserID();
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    QString filepath = "database/UserTests/" + QString::number(getLoggedInUserID()) + ".csv";
    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        qDebug() << "Searching for " << getLoggedInUserID() << ".csv" << "...";
        QFile searchFile{filepath};
        CustomListWidget *c19TestList = new CustomListWidget;
        if (searchFile.open(QIODevice::ReadOnly| QIODevice::Text))
        {
            qDebug() << "The file has been found and opened. ";
            // File found. Now extract data for display
            int numRows = 0;
            QStringList testDates;
            QString row;
            QStringList rowValues;


            while(!searchFile.atEnd())
            {
                // Read and split the rows
                row = searchFile.readLine().trimmed();
                rowValues = row.split(',');
                testDates << rowValues.at(0);
                qDebug() << "Full row values are: " << rowValues;
                qDebug() << "Storing the test date for this row " << numRows;
                QString rowTestDate = rowValues.at(0);
                QString rowTestResult;
                if (rowValues.at(1).toInt() == 1)
                {
                    rowTestResult = "Positive";
                }
                else
                {
                    rowTestResult = "Negative";
                }

                QLabel *testTypeUL = new QLabel;
                testTypeUL->setText("Rapid Antigen Test");
//                dateLabelUR->setWordWrap(true);
                QLabel *dateLabelUR = new QLabel;
                dateLabelUR->setText(rowTestDate);
                QLabel *reportTypeBL = new QLabel;
                reportTypeBL->setText("Self-reported");
                QLabel *testResultBR = new QLabel;
                testResultBR->setText(rowTestResult);

                c19TestList->addLabelItem(testTypeUL, dateLabelUR, reportTypeBL, testResultBR);
                qDebug() << "Test dates recorded are " << testDates;
                numRows++;
            }
            toolBox->addItem(new ToolItem(new QLabel("YOUR COVID-19 HISTORY"), c19TestList));
            qDebug() << "The number of entries (rows) are: " << numRows;
        }
        else
        {
            // Check if file can't be found, or file has difficulty opening
            qDebug() << "What's the QFile error? " << searchFile.errorString();
            if (searchFile.errorString() == "The system cannot find the file specified.")
            {
                QListWidget *emptyTestList = new QListWidget;
                emptyTestList->addItem("You have no recorded COVID-19 tests");
                toolBox->addItem(new ToolItem(new QLabel("YOUR COVID-19 HISTORY"), emptyTestList));
            }
        }


    }

    //-------------------------------------------------
    // List to show if user clicks on Vaccination Record
    //-----
    // Same standardPath, different filepath
    QString doseFilepath = "database/UserDoses/" + QString::number(getLoggedInUserID()) + ".csv";
    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        qDebug() << "Searching for " << getLoggedInUserID() << ".csv" << "...";
        QFile searchFile{doseFilepath};
        CustomListWidget *c19VacHistory = new CustomListWidget;
        if (searchFile.open(QIODevice::ReadOnly| QIODevice::Text))
        {
            qDebug() << "The file has been found and opened. ";
            // File found. Now extract data for display
            int numRows = 0;    // In this case, numRows also indicates number of doses
            QStringList vaxDates;
            QString row;
            QStringList rowValues;

            while(!searchFile.atEnd())
            {
                // Read and split the rows
                row = searchFile.readLine().trimmed();
                rowValues = row.split(',');
                vaxDates << rowValues.at(0);
                qDebug() << "Full row values are: " << rowValues;
                qDebug() << "Storing the vaccination dates for this row " << numRows;
                QString extractedDate = rowValues.at(0);
                QDate rowVaxQDate = QDate::fromString(extractedDate, "yyyyMMdd");
                QString rowVaxDate = rowVaxQDate.toString("dd MMM yyyy");
                qDebug() << "The rowVaxDate is " << rowVaxDate << " and vaxQdate is " << rowVaxQDate;

//                QString rowVaxDate = QDate::toString(extractedDate,"yy.MM.dd");
//                QString rowVaxDate = rowValues.at(0).toString("yy.MM.dd");
                QString doseManuf;

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

                QLabel *numDosesUL = new QLabel;
                qDebug() << "The number of rows are: " << numRows;
                QString doseNum = "Dose " + QString::number(numRows + 1);
                numDosesUL->setText(doseNum);
                QLabel *emptyUR = new QLabel;
                emptyUR->setText("");
                QLabel *vaxDateBL = new QLabel;
                vaxDateBL->setText(rowVaxDate);
                QLabel *manufBR = new QLabel;
                manufBR->setText(doseManuf);

                c19VacHistory->addLabelItem(numDosesUL, emptyUR, vaxDateBL, manufBR);
                qDebug() << "Vaccination dates recorded are " << vaxDates;
                numRows++;
            }
            toolBox->addItem(new ToolItem(new QLabel("COVID-19 VACCINATION RECORD"), c19VacHistory));
            qDebug() << "The number of entries (rows) are: " << numRows;
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

    QVBoxLayout *overarchingLayout = new QVBoxLayout;
    overarchingLayout->addWidget(toolBox);

//    setLayout(overarchingLayout);

    overallWrapper->addLayout(pageIntro);
    overallWrapper->addLayout(overarchingLayout);
    setLayout(overallWrapper);





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


