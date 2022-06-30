#include "adminsearchusers.h"
#include "handlecsv.h"
#include "ui_adminsearchusers.h"
#include "useraccount.h"

QStringList AdminSearchUsers::getSearchResultIDs()
{
    return searchResultIDs;
}

void AdminSearchUsers::setSearchResultIDs( QStringList newSearchResultIDs)
{
    searchResultIDs = newSearchResultIDs;
}

void AdminSearchUsers::setDisplayedResults()
{
    int firstResult = ((pageNumber-1)*6)+1;
    int i = 0;
    HandleCSV getUser;
    UserAccount gotUser;
    while( i < 6 && firstResult <= searchResultIDs.size()){
        gotUser = getUser.getUserAccount(searchResultIDs.at(firstResult-1).toInt());
        labels[i]->setText(formatNameForDisplay(gotUser));
        i++;
        firstResult++;
    }
    for(i = i; i < 6; i++){
        labels[i]->setText("");
    }
    if(pageNumber == 1){
        ui->btn_pageLeft->setEnabled(false);
    }
    else {
        ui->btn_pageLeft->setEnabled(true);
    }
    int noOfPages = searchResultIDs.size()/6;
    if(searchResultIDs.size()%6 !=0){
        noOfPages++;
    }
    if(pageNumber >= noOfPages){
        ui->btn_pageRight->setEnabled(false);
    }
    else {
        ui->btn_pageRight->setEnabled(true);
    }
    ui->lbl_currentPage->setText(QString::number(pageNumber) + " of " + QString::number(noOfPages));
}

QString AdminSearchUsers::formatNameForDisplay(UserAccount user)
{
    //Format name
    qDebug() << user.getUserFirstName() << "was first name";
    QString toPrint = "";// Should stay blank if no name found
    if(user.getUserFirstName() != ""){//Checks if name is blank
        toPrint = user.getUserFirstName() + " " + user.getUserLastName();//spaces names
       if(user.getUserFirstName() != user.getUserPreferredName()){//Adds preferred name in brackets if different from first name
           toPrint = toPrint + " (" + user.getUserPreferredName() + ")";
       }
    }
    return toPrint;
}

int AdminSearchUsers::getPageNumber()
{
    return pageNumber;
}

void AdminSearchUsers::setPageNumber(int newPageNumber)
{
    pageNumber = newPageNumber;
}

AdminSearchUsers::AdminSearchUsers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminSearchUsers)
{
    ui->setupUi(this);
    labels[0] = ui->lbl_foundName_1;
    labels[1] = ui->lbl_foundName_2;
    labels[2] = ui->lbl_foundName_3;
    labels[3] = ui->lbl_foundName_4;
    labels[4] = ui->lbl_foundName_5;
    labels[5] = ui->lbl_foundName_6;
    for(int i = 0; i < 6; i++){
        labels[i]->setText("");
    }
    ui->btn_pageRight->setEnabled(false);
    ui->btn_pageLeft->setEnabled(false);
    ui->lbl_currentPage->setText("");
}

AdminSearchUsers::~AdminSearchUsers()
{
    delete ui;
}

QStringList AdminSearchUsers::searchFNames(QString search)
{
    HandleCSV readNames;
    QStringList fNames = readNames.getColData("userFirstName", "dbPID");
    QStringList userIDs = readNames.getColData("userIDNumber", "dbPID");
    QStringList matchingIDs;
    for(int i = 0; i < fNames.size(); i++){
        if(fNames.at(i) == search){
            matchingIDs.append(userIDs.at(i));
        }
    }
    return matchingIDs;
}

QStringList AdminSearchUsers::searchLNames(QString search)
{
    HandleCSV readNames;
    QStringList lNames = readNames.getColData("userLastName", "dbPID");
    QStringList userIDs = readNames.getColData("userIDNumber", "dbPID");
    QStringList matchingIDs;
    for(int i = 0; i < lNames.size(); i++){
        if(lNames.at(i) == search){
            matchingIDs.append(userIDs.at(i));
        }
    }
    return matchingIDs;
}

QStringList AdminSearchUsers::searchPNames(QString search)
{
    HandleCSV readNames;
    QStringList pNames = readNames.getColData("userPreferredName", "dbPID");
    QStringList userIDs = readNames.getColData("userIDNumber", "dbPID");
    QStringList matchingIDs;
    for(int i = 0; i < pNames.size(); i++){
        if(pNames.at(i) == search){
            matchingIDs.append(userIDs.at(i));
        }
    }
    return matchingIDs;
}

void AdminSearchUsers::on_btn_search_clicked()
{
    //Search all 3 names, get uids and store in a single QStringList removign any duplicates if someone has the same name in two variables
    QString searchTerms = ui->textEdit_searchBar->toPlainText();
    QStringList foundFNames = searchFNames(searchTerms);
    QStringList foundLNames = searchLNames(searchTerms);
    QStringList foundPNames = searchPNames(searchTerms);
    QStringList combinedUserIDList;
    for(int i = 0; i < foundFNames.size(); i++){
        combinedUserIDList.append(foundFNames.at(i));
    }
    bool dupFlag = false;
    for(int i = 0; i < foundLNames.size(); i++){
        dupFlag = false;
        for(int j = 0; j < combinedUserIDList.size(); j++){
            if(foundLNames.at(i) == combinedUserIDList.at(j)){
                dupFlag = true;
            }
        }
        if(dupFlag == false){
            combinedUserIDList.append(foundLNames.at(i));
        }
    }
    for(int i = 0; i < foundPNames.size(); i++){
        dupFlag = false;
        for(int j = 0; j < combinedUserIDList.size(); j++){
            if(foundPNames.at(i) == combinedUserIDList.at(j)){
                dupFlag = true;
            }
        }
        if(dupFlag == false){
            combinedUserIDList.append(foundPNames.at(i));
        }
    }
    setPageNumber(1);
    setSearchResultIDs(combinedUserIDList);
    setDisplayedResults();
}


void AdminSearchUsers::on_btn_pageLeft_clicked()
{
    setPageNumber(getPageNumber()-1);
    setDisplayedResults();
}


void AdminSearchUsers::on_btn_pageRight_clicked()
{
    setPageNumber(getPageNumber()+1);
    setDisplayedResults();
}

