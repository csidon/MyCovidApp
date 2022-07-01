#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "authdialog.h"
#include "displaymyqrcode.h"
#include "submiterrorreport.h"
#include <QObject>

MainWindow::MainWindow(QWidget *parent, int loggedInUserID)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    HandleCSV accountReader;
    ui->setupUi(this);
    qDebug() << "OI! MainWindow received uid: " << loggedInUserID;
    UserAccount loggedInUser = accountReader.getUserAccount(loggedInUserID);
    ui->lbl_welcomeMsg->setText("Kia Ora " + loggedInUser.getUserPreferredName());
    this->setLoggedInUserID(loggedInUserID);
    submitErrorReport.setLoggedInUser(loggedInUserID);
    if(loggedInUser.getUserQRStatus()==0)
    {
        qDebug() << "The logged In user QR status is 0";
        ui->btn_requestQR->show();
        ui->btn_QRrequested->hide();
        ui->btn_displayQR->hide();
    }
    else if(loggedInUser.getUserQRStatus()==1)
    {
        ui->btn_requestQR->hide();
        ui->btn_QRrequested->show();
        ui->btn_displayQR->hide();
    }
    else
    {
        ui->btn_requestQR->hide();
        ui->btn_QRrequested->hide();
        ui->btn_displayQR->show();
    }


    // Creating a hidden label for UID
//    QLabel* hiddenUIDlabel = new QLabel(this);
//    hiddenUIDlabel->setGeometry(300,70,62,20);
//    hiddenUIDlabel->setNum(uid);
    ui->lbl_UID_toHide->setNum(loggedInUserID);
    if(loggedInUserID == 0){
        this->hide();
        qDebug() << "shoulda closed";
    }
   // ui->setupUi(this);

}

int MainWindow::getLoggedInUserID()
{
    return loggedInUserID;
}

void MainWindow::setLoggedInUserID(int newLoggedInUserID)
{
    loggedInUserID = newLoggedInUserID;
}

void MainWindow::openCovidTestWindow()
{
    int uid = getLoggedInUserID();
    qDebug() << "You have cliecked the reportRAT button and want to pass uid " << uid;
    covidTestWindow = new CovidTestForms(nullptr, uid);
    covidTestWindow->show();
}

void MainWindow::openEUHistoryWindow()
{
    int uid = getLoggedInUserID();
    qDebug() << "You have clicked the EU History button and want to pass uid " << uid;
    euHistoryWindow = new EUHistory(nullptr, uid);
    euHistoryWindow->show();


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
    HandleCSV readWriteQRRequest;
    UserAccount loggedInUser = readWriteQRRequest.getUserAccount(getLoggedInUserID());
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
        loggedInUser.setUserQRStatus(1);

        // Testing what's in LoggedInUser
        qDebug() << "UID: " <<loggedInUser.getUserIDNumber();
        qDebug() << "Email: " << loggedInUser.getUserEmail();
        qDebug() << "Passwd: " << loggedInUser.getUserPassword();
        qDebug() << "FirstName: " << loggedInUser.getUserFirstName();
        qDebug() << "LastName: " << loggedInUser.getUserLastName();
        qDebug() << "Pref Name: " << loggedInUser.getUserPreferredName();
        qDebug() << "NHI: " << loggedInUser.getUserNHINumber();
        qDebug() << "Phone: " << loggedInUser.getUserPhoneNumber();
        qDebug() << "VaxStat: " << loggedInUser.getUserVaccinationStatus();
        qDebug() << "QRStat: " << loggedInUser.getUserQRStatus();
        qDebug() << "QRAdd: " << loggedInUser.getUserQRCodeAddress();

        // To implement actual write-to-QRCodeRequests.csv and write to
        // userPID file

    }
}


void MainWindow::on_btn_reportRat_clicked()
{
    openCovidTestWindow();

}


void MainWindow::on_btn_vaxHistory_clicked()
{
    openEUHistoryWindow();
}


void MainWindow::on_btn_displayQR_clicked()
{
    int uid = getLoggedInUserID();
    qDebug() << "You have clicked the EU History button and want to pass uid " << uid;
    displayQRWindow = new DisplayMyQRCode(nullptr, uid);
    displayQRWindow->show();
}


void MainWindow::on_btn_accountDetails_clicked()
{
   // SubmitErrorReport submitErrorReport = SubmitErrorReport(nullptr, loggedInUserID);
    submitErrorReport.show();
}

