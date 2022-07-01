#include "adminerrorreports.h"
#include "adminhome.h"
#include "handlecsv.h"
#include "ui_adminerrorreports.h"
#include "useraccount.h"

AdminErrorReports::AdminErrorReports(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminErrorReports)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->btn_pageLeft->setEnabled(false);//start on page one; there's no page zero, so left button goes nowhere
    //populate arrays with pointers to facilitate looping
    reportLabels[0] = ui->lbl_report_1;
    reportLabels[1] = ui->lbl_report_2;
    reportLabels[2] = ui->lbl_report_3;
    reportLabels[3] = ui->lbl_report_4;
    reportLabels[4] = ui->lbl_report_5;
    reportLabels[5] = ui->lbl_report_6;
    nameLabels[0] = ui->lbl_name_1;
    nameLabels[1] = ui->lbl_name_2;
    nameLabels[2] = ui->lbl_name_3;
    nameLabels[3] = ui->lbl_name_4;
    nameLabels[4] = ui->lbl_name_5;
    nameLabels[5] = ui->lbl_name_6;
    dateLabels[0] = ui->lbl_date_1;
    dateLabels[1] = ui->lbl_date_2;
    dateLabels[2] = ui->lbl_date_3;
    dateLabels[3] = ui->lbl_date_4;
    dateLabels[4] = ui->lbl_date_5;
    dateLabels[5] = ui->lbl_date_6;
    newLabels[0] = ui->lbl_new_1;
    newLabels[1] = ui->lbl_new_2;
    newLabels[2] = ui->lbl_new_3;
    newLabels[3] = ui->lbl_new_4;
    newLabels[4] = ui->lbl_new_5;
    newLabels[5] = ui->lbl_new_6;
    setPageNumber(1);//start on page one
    updatePageNumberDisplay();
    if(getNoOfPages() < 2){//this variable is set as part of the previous function. If there isn't a page two, the code doesn't need the right button
        ui->btn_pageRight->setEnabled(false);
    }
    setDisplayedReports();
    updatePageNumberDisplay();
    ui->lbl_errorText->setWordWrap(true);
    ui->lbl_sender->setWordWrap(true);
}

AdminErrorReports::~AdminErrorReports()
{
    delete ui;
}

void AdminErrorReports::on_btn_backToAdminHome_clicked()
{
    this->close();
}

//Getters
int AdminErrorReports::getPageNumber()
{
    return pageNumber;
}

int AdminErrorReports::getNoOfPages()
{
    return noOfPages;
}

//Setters
void AdminErrorReports::setPageNumber(int newPageNumber)
{
    pageNumber = newPageNumber;
}

void AdminErrorReports::setNoOfPages(int newNoOfPages)
{
    noOfPages = newNoOfPages;
}



void AdminErrorReports::setDisplayedReports()
{
    //Calculate what index to start reports at for the current page
    int printReport = ((getPageNumber() - 1) * 6) + 1;
    //read from files
    HandleCSV readReports;
    QStringList reports = readReports.getColData("Title", "dbReports");
    QStringList dates = readReports.getColData("Date", "dbReports");
    QStringList names = readReports.getColData("Sender", "dbReports");
    QStringList news = readReports.getColData("isNew", "dbReports");
    //Display
    int i=0;
    UserAccount user;
    QString toPrint = "";
    while(printReport < reports.size() && i < 6){//display user names
       //Elide long titles
       QFontMetrics metricsTitle(reportLabels[i]->font());
       QString elidedTitle = metricsTitle.elidedText(reports.at(printReport), Qt::ElideRight, reportLabels[i]->width());
       reportLabels[i]->setText(elidedTitle);
       //Get DD/MM for display
       QString dateToPrint = dates.at(printReport);
       toPrint = dateToPrint[6];
       toPrint += dateToPrint[7];
       toPrint += "/";
       toPrint += dateToPrint[4];
       toPrint += dateToPrint[5];
       dateLabels[i]->setText(toPrint);
       //Get name
       user = readReports.getUserAccount(names.at(printReport).toInt());
       toPrint = formatNameForDisplay(user);
       //Elide long names
       QFontMetrics metricsName(nameLabels[i]->font());
       QString elidedName = metricsName.elidedText(toPrint, Qt::ElideRight, nameLabels[i]->width());
       nameLabels[i]->setText(elidedName);
       //Check if new
       if(news.at(printReport) == "TRUE"){
           newLabels[i]->show();
       }
       else if(news.at(printReport) == "FALSE"){
           newLabels[i]->hide();
       }
       else{
           qDebug() << "Error reading bool values as QStrings and comparing to QStrings";
       }
       i++;
       printReport++;
    }
    //blank out the spaces after the last user
    toPrint = "";
    while(printReport >= reports.size() && i < 6){
       reportLabels[i]->setText(toPrint);
       dateLabels[i]->setText(toPrint);
       nameLabels[i]->setText(toPrint);
       newLabels[i]->hide();
       i++;
    }

}

void AdminErrorReports::updatePageNumberDisplay()
{
    HandleCSV countReports;
    QStringList Reports = countReports.getColData("Sender", "dbReports");
    Reports.takeFirst();//drops the header

    //How many pages do we need?
    setNoOfPages(Reports.size()/6);
    if(Reports.size()%6!=0){
        setNoOfPages(getNoOfPages()+1);
    }
    //Send to label
    ui->lbl_currentPage->setText(QString::number(getPageNumber())+" of " + QString::number(getNoOfPages()));
    //Set Buttons
    if(getPageNumber() == getNoOfPages()){
        ui->btn_pageRight->setEnabled(false);
    }
    else{
        ui->btn_pageRight->setEnabled(true);
    }
    if(getPageNumber() == 1){
        ui->btn_pageLeft->setEnabled(false);
    }
    else{
        ui->btn_pageLeft->setEnabled(true);
    }
}

void AdminErrorReports::viewButtonClicked(int button)
{
    //Show indiviual report
    ui->stackedWidget->setCurrentIndex(1);
    setSingleErrorReportDisplay(((getPageNumber()-1)*6)+button);
    updatePageNumberDisplay();
}

QString AdminErrorReports::formatNameForDisplay(UserAccount user)
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

void AdminErrorReports::setSingleErrorReportDisplay(int report)
{
    //display sender
    HandleCSV readForReport;
    ErrorReport reportForDisplay = readForReport.getErrorReport(report);
    QStringList reportIDs = readForReport.getColData("Sender", "dbReports");
    UserAccount reporter = readForReport.getUserAccount(reportIDs.at(report).toInt());
    ui->lbl_sender->setText(formatNameForDisplay(reporter));
    //display 'new' marker or not
    if(!reportForDisplay.getIsNew()){
        ui->lbl_newMarker->hide();
    }
    else{
         ui->lbl_newMarker->show();
    }
    //fetch and format dd/mm date
    QString toPrint = "";
    QString date = QString::number(reportForDisplay.getDate());
    toPrint = date[6];
    toPrint += date[7];
    toPrint += "/";
    toPrint += date[4];
    toPrint += date[5];
    ui->lbl_date->setText(toPrint);
    //display other values
    ui->lbl_errorText->setText(reportForDisplay.getText());
    ui->lbl_reportTitle->setText(reportForDisplay.getTitle());
    ui->lbl_currentReport->setText(QString::number(report) + " of " + QString::number(reportIDs.size()-1));
    //set page turning buttons
    if(report == reportIDs.size()-1){
        ui->btn_nextReport->setEnabled(false);
    }
    else{
        ui->btn_nextReport->setEnabled(true);
    }
    if(report == 1){
        ui->btn_previousReport->setEnabled(false);
    }
    else{
        ui->btn_previousReport->setEnabled(true);
    }
}

void AdminErrorReports::on_btn_pageLeft_clicked()
{
    //decrease page number and display previous users
    setPageNumber(getPageNumber()-1);
    this->updatePageNumberDisplay();
    this->setDisplayedReports();
    //set buttons
    ui->btn_pageRight->setEnabled(true);
    if(this->getPageNumber() == 1){
        ui->btn_pageLeft->setEnabled(false);
    }
}


void AdminErrorReports::on_btn_pageRight_clicked()
{
    //increase page number and display more users
    setPageNumber(getPageNumber()+1);
    this->updatePageNumberDisplay();
    this->setDisplayedReports();
    //set buttons
    ui->btn_pageLeft->setEnabled(true);
    if(this->getPageNumber() >= getNoOfPages()){
        ui->btn_pageRight->setEnabled(false);
    }
}


void AdminErrorReports::on_btn_view_1_clicked()
{
    viewButtonClicked(1);
}


void AdminErrorReports::on_btn_view_2_clicked()
{
    viewButtonClicked(2);
}


void AdminErrorReports::on_btn_view_3_clicked()
{
    viewButtonClicked(3);
}


void AdminErrorReports::on_btn_view_4_clicked()
{
    viewButtonClicked(4);
}


void AdminErrorReports::on_btn_view_5_clicked()
{
    viewButtonClicked(5);
}


void AdminErrorReports::on_btn_view_6_clicked()
{
    viewButtonClicked(6);
}


void AdminErrorReports::on_btn_previousReport_clicked()
{
    //fetch page number from label
    QString pageInfo = ui->lbl_currentReport->text();
    QChar check = 'a';
    QString current = "";
    int i = 0;
    while(check != ' ') {
        check = pageInfo[i];
        if(check != ' '){
         current += check;
        }
        i++;
    }
    //decrement page
    setSingleErrorReportDisplay(current.toInt() - 1);
}


void AdminErrorReports::on_btn_nextReport_clicked()
{
    //fetch page number from label
    QString pageInfo = ui->lbl_currentReport->text();
    QChar check = 'a';
    QString current = "";
    int i = 0;
    while(check != ' ') {
        check = pageInfo[i];
        if(check != ' '){
         current = current + check;
        }
        i++;
    }
    //Increment page
    setSingleErrorReportDisplay(current.toInt() + 1);
}


void AdminErrorReports::on_btn_markAsRead_clicked()
{
    //fetch page number from label
    QString pageInfo = ui->lbl_currentReport->text();
    QChar check = 'a';
    QString current = "";
    int i = 0;
    while(check != ' ') {
        check = pageInfo[i];
        if(check != ' '){
         current = current + check;
        }
        i++;
    }
    //Send new reort to files
    HandleCSV updateIsNew;
    updateIsNew.updateIsNewOfReport(current.toInt());
    //update display
    setSingleErrorReportDisplay(current.toInt());
}


void AdminErrorReports::on_btn_backToReportList_clicked()
{
    //Return to list of reports
    ui->stackedWidget->setCurrentIndex(0);
    //update list
    setDisplayedReports();
}

