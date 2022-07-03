#include "vaccinehistory.h"
#include "handlecsv.h"
#include "ui_vaccinehistory.h"

int VaccineHistory::getLoggedInUser()
{
    return loggedInUser;
}

void VaccineHistory::setLoggedInUser(int newLoggedInUser)
{
    loggedInUser = newLoggedInUser;
}

void VaccineHistory::setDisplayedDoses()
{
    HandleCSV readFromFiles;
    QStringList readTypes = readFromFiles.getColData("doseManufacturer", "./database/UserDoses/" + QString::number(getLoggedInUser()) + ".csv");
    QStringList readDates = readFromFiles.getColData("doseDate", "./database/UserDoses/" + QString::number(getLoggedInUser()) + ".csv");
    int printIndex = ((getCurrentPage()-1)*6)+1;
    int i =0;
    QString manufacturer = "";
    while(i < 6 && printIndex < readTypes.size()){
        if(readTypes.at(printIndex).toInt() == 1){
            manufacturer = "Pfizer-BioNTech";
        }
        else if(readTypes.at(printIndex).toInt() == 2){
            manufacturer = "Novavax";
        }
        else if(readTypes.at(printIndex).toInt() == 3){
            manufacturer = "GlaxoSmithKline";
        }
        else{
            qDebug() <<"Error with manufacturer int";
            manufacturer = "";
        }
        types[i]->setText(manufacturer);
        QString formattedDate = readDates.at(printIndex)[6];
        formattedDate = formattedDate + readDates.at(printIndex)[7] + '/' + readDates.at(printIndex)[4] + readDates.at(printIndex)[5];
        dates[i]->setText(formattedDate);
        i++;
        printIndex++;
    }
    while(i < 6){
        types[i]->setText("");
        dates[i]->setText("");
        i++;
    }
}

void VaccineHistory::setPageNumbersDisplay()
{
    HandleCSV readPageNumbers;
    qDebug() << "./database/UserDoses/" + QString::number(getLoggedInUser()) + ".csv";
    QStringList doseDates = readPageNumbers.getColData("doseDate","./database/UserDoses/" + QString::number(getLoggedInUser()) + ".csv");
    int pages = doseDates.size()/6;
    if(doseDates.size()%6 != 0){
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

int VaccineHistory::getNoOfPages()
{
    return noOfPages;
}

void VaccineHistory::setNoOfPages(int newNoOfPages)
{
    noOfPages = newNoOfPages;
}

int VaccineHistory::getCurrentPage()
{
    return currentPage;
}

void VaccineHistory::setCurrentPage(int newCurrentPage)
{
    currentPage = newCurrentPage;
}

VaccineHistory::VaccineHistory(QWidget *parent, int loggedInUserID) :
    QWidget(parent),
    ui(new Ui::VaccineHistory)
{
    setLoggedInUser(loggedInUserID);
    ui->setupUi(this);
    //populate arrays for looping
    types[0] = ui->lbl_type_1;
    types[1] = ui->lbl_type_2;
    types[2] = ui->lbl_type_3;
    types[3] = ui->lbl_type_4;
    types[4] = ui->lbl_type_5;
    types[5] = ui->lbl_type_6;
    dates[0] = ui->lbl_date_1;
    dates[1] = ui->lbl_date_2;
    dates[2] = ui->lbl_date_3;
    dates[3] = ui->lbl_date_4;
    dates[4] = ui->lbl_date_5;
    dates[5] = ui->lbl_date_6;
    HandleCSV readPageNumbers;
    qDebug() << "./database/UserDoses/" + QString::number(getLoggedInUser()) + ".csv";
    QStringList doseDates = readPageNumbers.getColData("doseDate","./database/UserDoses/" + QString::number(getLoggedInUser()) + ".csv");
    int pages = doseDates.size()/6;
    if(doseDates.size()%6 != 0){
        pages++;
    }
    setNoOfPages(pages);
    setCurrentPage(1);
    setDisplayedDoses();
    setPageNumbersDisplay();

}

VaccineHistory::~VaccineHistory()
{
    delete ui;
}

void VaccineHistory::on_btn_pageLeft_clicked()
{
    setCurrentPage(getCurrentPage()-1);
    setDisplayedDoses();
    setPageNumbersDisplay();
}



void VaccineHistory::on_btn_pageRight_clicked()
{
    setCurrentPage(getCurrentPage()+1);
    setDisplayedDoses();
    setPageNumbersDisplay();
}


void VaccineHistory::on_btn_backToChoose_clicked()
{
    close();
}

