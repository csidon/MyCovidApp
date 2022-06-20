#include "adminqrrequests.h"
#include "handlecsv.h"
#include "ui_adminqrrequests.h"
#include "useraccount.h"



int AdminQRRequests::getPageNumber()
{
    return pageNumber;
}

void AdminQRRequests::setPageNumber(int newPageNumber)
{
    pageNumber = newPageNumber;
}

void AdminQRRequests::updatePageNumberDisplay()
{
    HandleCSV countQRRequests;
    QStringList QRRequests = countQRRequests.getColData("userIDNumber", ":/database/QRCodeRequests.csv");
    ui->lbl_currentPage->setText(QString::number(getPageNumber())+" of " + QString::number((QRRequests.size()/6)+1));
}

QString AdminQRRequests::formatNameForDisplay(UserAccount dataSource)
{
    QString toPrint = "";
    if(dataSource.getUserFirstName() != ""){
        toPrint = dataSource.getUserFirstName() + " " + dataSource.getUserLastName();
       if(dataSource.getUserFirstName() != dataSource.getUserPreferredName()){
           toPrint = toPrint + " (" + dataSource.getUserPreferredName() + ")";
       }
    }
    return toPrint;
}

AdminQRRequests::AdminQRRequests(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminQRRequests)
{
    ui->setupUi(this);
    connect(this, SIGNAL(pageTurned(int topUser)), this, SLOT(setDisplay(int topUser)));
    setPageNumber(1);
    updatePageNumberDisplay();
    setDisplayedUsers(getPageNumber());
}

AdminQRRequests::~AdminQRRequests()
{
    delete ui;
}

void AdminQRRequests::setDisplayedUsers(int topUser)
{
           qDebug() << "Bongo";
    int firstUser = ((topUser - 1) * 6) + 1;
    HandleCSV readQRRequests;
       qDebug() << "Bongo";
    QStringList requestingUsers = readQRRequests.getColData("userIDNumber", ":/database/QRCodeRequests.csv");
    qDebug() << "handled first csv";
    if(firstUser+5 <= requestingUsers.size()){
        ui->btn_pageRight->setEnabled(true);
    }
    else{
        ui->btn_pageRight->setEnabled(false);
    }
    if(getPageNumber() == 1){
        ui->btn_pageLeft->setEnabled(false);
    }
    else{
        ui->btn_pageLeft->setEnabled(true);
    }
    //This next part could be a loop if not for the need to change object name for the labels - maybe I make an array of pointers to them?
    UserAccount dataSource = readQRRequests.getUserAccount(requestingUsers.at(firstUser).toInt());
    QString toPrint = formatNameForDisplay(dataSource);
    ui->lbl_name_1->setText(toPrint);
    dataSource = readQRRequests.getUserAccount(requestingUsers.at(firstUser+1).toInt());
    toPrint = formatNameForDisplay(dataSource);
    ui->lbl_name_2->setText(toPrint);
    dataSource = readQRRequests.getUserAccount(requestingUsers.at(firstUser+2).toInt());
    toPrint = formatNameForDisplay(dataSource);
    ui->lbl_name_3->setText(toPrint);
    dataSource = readQRRequests.getUserAccount(requestingUsers.at(firstUser+3).toInt());
    toPrint = formatNameForDisplay(dataSource);
    ui->lbl_name_4->setText(toPrint);
    dataSource = readQRRequests.getUserAccount(requestingUsers.at(firstUser+4).toInt());
    toPrint = formatNameForDisplay(dataSource);
    ui->lbl_name_5->setText(toPrint);
    dataSource = readQRRequests.getUserAccount(requestingUsers.at(firstUser+5).toInt());
    ui->lbl_name_6->setText(toPrint);
}

//STILL NEEDED - the ability to upload a QR Code and associate it with a user that you click on, change their QRStatus, then overwrite the QRRequests file with the full list minus the person who just got their code

void AdminQRRequests::on_btn_pageRight_clicked()
{
    HandleCSV countQRRequests;
    QStringList QRRequests = countQRRequests.getColData("userIDNumber", ":/database/QRCodeRequests.csv");
    int noOfPages = QRRequests.size()/6;
    if(QRRequests.size()%6>1){
        noOfPages++;
    }
    if(this->getPageNumber() < noOfPages){
    setPageNumber(getPageNumber()+1);
    }
    this->updatePageNumberDisplay();
    //this->setDisplayedUsers(getPageNumber());
}


void AdminQRRequests::on_btn_pageLeft_clicked()
{
    if(this->getPageNumber() !=1){
        setPageNumber(getPageNumber()-1);
    }
    this->updatePageNumberDisplay();
}


void AdminQRRequests::on_btn_backToAdminHome_clicked()
{
    this->close();
}

void AdminQRRequests::setDisplay(int topUser){
    int firstUser = ((topUser - 1) * 6) + 1;
    HandleCSV readQRRequests;
       qDebug() << "Bongo";
    QStringList requestingUsers = readQRRequests.getColData("userIDNumber", ":/database/QRCodeRequests.csv");
    qDebug() << "handled first csv";
    if(firstUser+5 <= requestingUsers.size()){
        ui->btn_pageRight->setEnabled(true);
    }
    else{
        ui->btn_pageRight->setEnabled(false);
    }
    if(getPageNumber() == 1){
        ui->btn_pageLeft->setEnabled(false);
    }
    else{
        ui->btn_pageLeft->setEnabled(true);
    }
    //This next part could be a loop if not for the need to change object name for the labels - maybe I make an array of pointers to them?
    UserAccount dataSource = readQRRequests.getUserAccount(requestingUsers.at(firstUser).toInt());
    QString toPrint = formatNameForDisplay(dataSource);
    ui->lbl_name_1->setText(toPrint);
    dataSource = readQRRequests.getUserAccount(requestingUsers.at(firstUser+1).toInt());
    toPrint = formatNameForDisplay(dataSource);
    ui->lbl_name_2->setText(toPrint);
    dataSource = readQRRequests.getUserAccount(requestingUsers.at(firstUser+2).toInt());
    toPrint = formatNameForDisplay(dataSource);
    ui->lbl_name_3->setText(toPrint);
    dataSource = readQRRequests.getUserAccount(requestingUsers.at(firstUser+3).toInt());
    toPrint = formatNameForDisplay(dataSource);
    ui->lbl_name_4->setText(toPrint);
    dataSource = readQRRequests.getUserAccount(requestingUsers.at(firstUser+4).toInt());
    toPrint = formatNameForDisplay(dataSource);
    ui->lbl_name_5->setText(toPrint);
    dataSource = readQRRequests.getUserAccount(requestingUsers.at(firstUser+5).toInt());
    ui->lbl_name_6->setText(toPrint);
}


