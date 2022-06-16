#include "adminqrrequests.h"
#include "ui_adminqrrequests.h"

adminQRRequests::adminQRRequests(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminQRRequests)
{
    ui->setupUi(this);
//    QPixmap backButton(":/images/backArrow.png");
//    QIcon adminHomeBack(backButton);
//    ui->btn_backToAdminHome->setIcon(adminHomeBack);
}

adminQRRequests::~adminQRRequests()
{
    delete ui;
}
