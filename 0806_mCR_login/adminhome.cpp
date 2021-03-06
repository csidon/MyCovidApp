#include "adminhome.h"
#include "ui_adminhome.h"


AdminHome::AdminHome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminHome)
{
    ui->setupUi(this);
    HandleCSV initialReadAdmin;

    QStringList noOfNewReports = initialReadAdmin.getColData("isNew", initialReadAdmin.returnCSVFilePath("dbReports"));
    int newReportCount = 0;
    for(int i = 0; i < noOfNewReports.size(); i++){
        if(noOfNewReports.at(i) == "TRUE"){
            newReportCount++;
        }
    }
    ui->lbl_numberOfIssuesReported->setText(QString::number(newReportCount));

    QStringList noOfQRCodeRequests = initialReadAdmin.getColData("userIDNumber", initialReadAdmin.returnCSVFilePath("dbQRRequests"));
    ui->lbl_numberOfQRCodeRequests->setText(QString::number(noOfQRCodeRequests.size()-1));
}

AdminHome::~AdminHome()
{
    delete ui;
}

void AdminHome::on_btn_QRCodeRequests_clicked()
{
    adminQRRequestsWindow.show();
}


void AdminHome::on_btn_issuesReported_clicked()
{
    adminErrorReports.show();
}


void AdminHome::on_btn_searchAndManageUsers_clicked()
{
    adminSearchUsers.show();
}

