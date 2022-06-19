#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "authdialog.h"
#include <QObject>



MainWindow::MainWindow(QWidget *parent, int loggedInUserID)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    HandleCSV accountReader;
    ui->setupUi(this);
    UserAccount loggedInUser = accountReader.getUserAccount(loggedInUserID);
    ui->lbl_welcomeMsg->setText("Kia Ora " + loggedInUser.getUserPreferredName());
    if(loggedInUser.getUserQRStatus()==0)
    {
        ui->btn_requestQR->show();
        ui->btn_QRrequested->hide();
    }
    if(loggedInUser.getUserQRStatus()==1)
    {
        ui->btn_requestQR->hide();
        ui->btn_QRrequested->show();
    }
    else
    {
        ui->btn_requestQR->hide();
        ui->btn_QRrequested->hide();
    }

    // Creating a hidden label for UID
//    QLabel* hiddenUIDlabel = new QLabel(this);
//    hiddenUIDlabel->setGeometry(300,70,62,20);
//    hiddenUIDlabel->setNum(uid);

}

int MainWindow::getLoggedInUserID()
{
    return loggedInUserID;
}

void MainWindow::setLoggedInUserID(int newLoggedInUserID)
{
    loggedInUserID = newLoggedInUserID;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::receiveUID(int uid)
//{
//    qDebug() << "receiveUID has been triggered";
//    ui->lbl_UID_toHide->setNum(uid);
//
//}



void MainWindow::on_btn_requestQR_clicked()
{

    UserAccount loggedInUser;
    int ret = QMessageBox::warning(this,tr("Requesting QR code"),
             tr("QR codes (Vaccination certificates) can take "
                "up to 48 hours to process. \nRequest a QR code?"),
             QMessageBox::Cancel | QMessageBox::Yes);

    qDebug() << "What have you selected? "
                "(should return 16384 for yes | 4194304 for cancel ) " << ret;

    if(ret == 16384)
    {
        ui->btn_requestQR->hide();
        ui->btn_QRrequested->show();
        loggedInUser.requestQR();
        // To implement actual write-to-QRCodeRequests.csv and write to
        // userPID file

    }
}

