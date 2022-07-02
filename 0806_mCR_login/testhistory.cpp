#include "testhistory.h"
#include "handlecsv.h"
#include "ui_testhistory.h"

int TestHistory::getLoggedInUser()
{
    return loggedInUser;
}

void TestHistory::setLoggedInUser(int newLoggedInUser)
{
    loggedInUser = newLoggedInUser;
}

void TestHistory::setDisplayedTests()
{
    HandleCSV readFromFiles;
    QStringList readResults = readFromFiles.getColData("testResult", "./database/UserTests/" + QString::number(getLoggedInUser()) + ".csv");
    QStringList readDates = readFromFiles.getColData("testDate", "./database/UserTests/" + QString::number(getLoggedInUser()) + ".csv");
    int printIndex = ((getCurrentPage()-1)*6)+1;
    int i =0;
    QString result = "";
    while(i < 6 && printIndex < readResults.size()){
        if(readResults.at(printIndex).toInt() == 1){
            result = "Positive";
        }
        else if(readResults.at(printIndex).toInt() == 0){
            result = "Negative";
        }
        else{
            qDebug() <<"Error with manufacturer int";
            result = "";
        }
        results[i]->setText(result);
        QString formattedDate = readDates.at(printIndex)[6];
        formattedDate = formattedDate + readDates.at(printIndex)[7] + '/' + readDates.at(printIndex)[4] + readDates.at(printIndex)[5];
        dates[i]->setText(formattedDate);
        i++;
        printIndex++;
    }
    while(i < 6){
        results[i]->setText("");
        dates[i]->setText("");
        i++;
    }
}

void TestHistory::setPageNumbersDisplay()

{
    HandleCSV readPageNumbers;
    qDebug() << "./database/UserTests/" + QString::number(getLoggedInUser()) + ".csv";
    QStringList testDates = readPageNumbers.getColData("testDate","./database/UserTests/" + QString::number(getLoggedInUser()) + ".csv");
    qDebug() << "array is" << testDates.size();
    int pages = testDates.size()/6;
    if(testDates.size()%6 != 0){
        pages++;
    }
    setNoOfPages(pages);
    ui->lbl_currentPage->setText(QString::number(getCurrentPage()) + " of " + QString::number(getNoOfPages()));
    if(getCurrentPage() == 1){
        ui->btn_pageLeft->setEnabled(false);
    }
    else{
        ui->btn_pageLeft->setEnabled(true);
    }
    if(getCurrentPage() < getNoOfPages()){
        ui->btn_pageRight->setEnabled(true);
    }
    else{
        ui->btn_pageRight->setEnabled(false);
    }
}

int TestHistory::getNoOfPages()
{
    return noOfPages;
}

void TestHistory::setNoOfPages(int newNoOfPages)
{
    noOfPages = newNoOfPages;
}

int TestHistory::getCurrentPage()
{
    return currentPage;
}

void TestHistory::setCurrentPage(int newCurrentPage)
{
    currentPage = newCurrentPage;
}

TestHistory::TestHistory(QWidget *parent, int loggedInUserID) :
    QWidget(parent),
    ui(new Ui::TestHistory)
{
    setLoggedInUser(loggedInUserID);
    ui->setupUi(this);
    //populate arrays for looping
    results[0] = ui->lbl_result_1;
    results[1] = ui->lbl_result_2;
    results[2] = ui->lbl_result_3;
    results[3] = ui->lbl_result_4;
    results[4] = ui->lbl_result_5;
    results[5] = ui->lbl_result_6;
    dates[0] = ui->lbl_date_1;
    dates[1] = ui->lbl_date_2;
    dates[2] = ui->lbl_date_3;
    dates[3] = ui->lbl_date_4;
    dates[4] = ui->lbl_date_5;
    dates[5] = ui->lbl_date_6;
    HandleCSV readPageNumbers;
    qDebug() << "./database/UserTests/" + QString::number(getLoggedInUser()) + ".csv";
    QStringList testDates = readPageNumbers.getColData("testDate","./database/UserTests/" + QString::number(getLoggedInUser()) + ".csv");
    qDebug() << "array is" << testDates.size();
    int pages = testDates.size()/6;
    if(testDates.size()%6 != 0){
        pages++;
    }
    setNoOfPages(pages);
    setCurrentPage(1);
    setDisplayedTests();
    setPageNumbersDisplay();

}

TestHistory::~TestHistory()
{
    delete ui;
}

void TestHistory::on_btn_pageLeft_clicked()
{
    setCurrentPage(getCurrentPage()-1);
    setDisplayedTests();
    setPageNumbersDisplay();
}



void TestHistory::on_btn_pageRight_clicked()
{
    setCurrentPage(getCurrentPage()+1);
    setDisplayedTests();
    setPageNumbersDisplay();
}


void TestHistory::on_btn_backToChoose_clicked()
{
    close();
}

