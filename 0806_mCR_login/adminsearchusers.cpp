#include "adminsearchusers.h"
#include "ui_adminsearchusers.h"


//Getters
int AdminSearchUsers::getPageNumber()
{
    return pageNumber;
}

QStringList AdminSearchUsers::getSearchResultIDs()
{
    return searchResultIDs;
}

//Setters
void AdminSearchUsers::setSearchResultIDs(QStringList newSearchResultIDs)
{
    searchResultIDs = newSearchResultIDs;
}

void AdminSearchUsers::setPageNumber(int newPageNumber)
{
    pageNumber = newPageNumber;
}

void AdminSearchUsers::setDisplayedResults()
{
    //Calculate index in list for first user to display on current page
    int firstResult = ((pageNumber-1)*6)+1;
    //print that user and the following five (or up to five if there are fewer)
    int i = 0;
    HandleCSV getUser;
    UserAccount gotUser;
    //disable buttons
    for(int i = 0; i < 6; i++){
        buttons[i]->setEnabled(false);
    }
    while( i < 6 && firstResult <= searchResultIDs.size()){
        gotUser = getUser.getUserAccount(searchResultIDs.at(firstResult-1).toInt());
        labels[i]->setText(formatNameForDisplay(gotUser));
        buttons[i]->setEnabled(true);
        i++;
        firstResult++;       
    }
    //blank out any remaining slots
    for(i = i; i < 6; i++){
        labels[i]->setText("");
    }
    //set buttons
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
    //set page number display
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

void AdminSearchUsers::button(int btnNumber)
{
    //Pass the correctUID to the next menu based on which button is clicked
    QStringList results = getSearchResultIDs();
    int result = ((pageNumber-1)*6)+btnNumber -1;
    userSelectedWindow.setSelectedUserID(results.at(result).toInt());
    userSelectedWindow.show();
    userSelectedWindow.setTitleText();
}


AdminSearchUsers::AdminSearchUsers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminSearchUsers)
{
    ui->setupUi(this);
    //populate arrays to enable looping
    labels[0] = ui->lbl_foundName_1;
    labels[1] = ui->lbl_foundName_2;
    labels[2] = ui->lbl_foundName_3;
    labels[3] = ui->lbl_foundName_4;
    labels[4] = ui->lbl_foundName_5;
    labels[5] = ui->lbl_foundName_6;
    buttons[0] = ui->btn_user_1;
    buttons[1] = ui->btn_user_2;
    buttons[2] = ui->btn_user_3;
    buttons[3] = ui->btn_user_4;
    buttons[4] = ui->btn_user_5;
    buttons[5] = ui->btn_user_6;
    //disable buttons
    for(int i = 0; i < 6; i++){
        buttons[i]->setEnabled(false);
    }
    //blank out as no search is yet made
    for(int i = 0; i < 6; i++){
        labels[i]->setText("");
    }
    //disable buttons for empty page
    ui->btn_pageRight->setEnabled(false);
    ui->btn_pageLeft->setEnabled(false);
    ui->lbl_currentPage->setText("");
}

AdminSearchUsers::~AdminSearchUsers()
{
    delete ui;
}

//These next few functions search different name types for their arguments. They are individual functions so that the lifetime of their potentially 5 million long QStringLists aren't concurrent
QStringList AdminSearchUsers::searchFNames(QString search)
{
    HandleCSV readNames;
    QStringList fNames = readNames.getColData("userFirstName", "dbPID");
    QStringList userIDs = readNames.getColData("userIDNumber", "dbPID");
    QStringList matchingIDs;
    for(int i = 0; i < fNames.size(); i++){
        if(fNames.at(i).toLower() == search.toLower()){
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
        if(lNames.at(i).toLower() == search.toLower()){
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
        if(pNames.at(i).toLower() == search.toLower()){
            matchingIDs.append(userIDs.at(i));
        }
    }
    return matchingIDs;
}

void AdminSearchUsers::on_btn_search_clicked()
{
    //Search all 3 names, get uids and store in a single QStringList removing any duplicates if someone has the same name in two variables
    qDebug() << "Enter or search icon is working";
    QString searchTerms = ui->lineEdit_searchBar->text();
    QStringList foundFNames = searchFNames(searchTerms);
    QStringList foundLNames = searchLNames(searchTerms);
    QStringList foundPNames = searchPNames(searchTerms);
    QStringList combinedUserIDList;
    for(int i = 0; i < foundFNames.size(); i++){
        combinedUserIDList.append(foundFNames.at(i));
    }
    //Check for duplicates in case someone has the same name in multiple fields
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
    //set and update display
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


void AdminSearchUsers::on_btn_user_1_clicked()
{
    button(1);
}


void AdminSearchUsers::on_btn_user_2_clicked()
{
     button(2);
}


void AdminSearchUsers::on_btn_user_3_clicked()
{
     button(3);
}


void AdminSearchUsers::on_btn_user_4_clicked()
{
     button(4);
}


void AdminSearchUsers::on_btn_user_5_clicked()
{
     button(5);
}


void AdminSearchUsers::on_btn_user_6_clicked()
{
     button(6);
}


void AdminSearchUsers::on_btn_backToAdminHome_clicked()
{
    this->close();
}


void AdminSearchUsers::on_lineEdit_searchBar_returnPressed()
{
    //Search all 3 names, get uids and store in a single QStringList removign any duplicates if someone has the same name in two variables
    QString searchTerms = ui->lineEdit_searchBar->text();
    QStringList foundFNames = searchFNames(searchTerms);
    QStringList foundLNames = searchLNames(searchTerms);
    QStringList foundPNames = searchPNames(searchTerms);
    QStringList combinedUserIDList;
    for(int i = 0; i < foundFNames.size(); i++){
        combinedUserIDList.append(foundFNames.at(i));
    }
    //Check for duplicates in case someone has the same name in multiple fields
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
    //set and update display
    setPageNumber(1);
    setSearchResultIDs(combinedUserIDList);
    setDisplayedResults();
}

