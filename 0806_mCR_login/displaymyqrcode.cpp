#include "displaymyqrcode.h"
#include "ui_displaymyqrcode.h"

DisplayMyQRCode::DisplayMyQRCode(QWidget *parent, int userID) :
    QWidget(parent),
    ui(new Ui::DisplayMyQRCode)
{
    ui->setupUi(this);
    HandleCSV readUser;
    UserAccount loggedInUser = readUser.getUserAccount(userID);
    QString formattedName = formatNameForDisplay(loggedInUser);
    ui->lbl_name->setText(formattedName);
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    //set image based on user's stored address
    QPixmap QRCode(loggedInUser.getUserQRCodeAddress(), nullptr, Qt::AutoColor);
    ui->lbl_QR->setPixmap(QRCode);
}

QString DisplayMyQRCode::formatNameForDisplay(UserAccount dataSource)
{
    //Format name
    QString toPrint = "";// Should stay blank if no name found
    if(dataSource.getUserFirstName() != ""){//Checks if name is blank
        toPrint = dataSource.getUserFirstName() + " " + dataSource.getUserLastName();//spaces names
       if(dataSource.getUserFirstName() != dataSource.getUserPreferredName()){//Adds preferred name in brackets if different from first name
           toPrint = toPrint + " (" + dataSource.getUserPreferredName() + ")";
       }
    }
    return toPrint;
}


DisplayMyQRCode::~DisplayMyQRCode()
{
    delete ui;
}

void DisplayMyQRCode::on_btn_backToHome_clicked()
{
    this->close();
}

