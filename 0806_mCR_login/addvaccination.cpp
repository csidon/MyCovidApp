#include "addvaccination.h"
#include "ui_addvaccination.h"
#include "dose.h"
#include <QDate>
#include "useraccount.h"
#include <QMessageBox>

AddVaccination::AddVaccination(QWidget *parent, int loggedInUserID) :
    QWidget(parent),
    ui(new Ui::AddVaccination)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    setLoggedInUserID(loggedInUserID);

    // This section retrieves the current date
    // and sets this as the QSpinBox default
    QDate date;
    auto thisDate = date.currentDate();
    int year = date.currentDate().year() - 2000;
    int month = date.currentDate().month();
    int day = date.currentDate().day();
    qDebug() << "The date retrieved is " << thisDate;
    qDebug() << "What is the year printed without modification? " << date.currentDate().year();
    ui->spinBox_DD->setValue(day);
    ui->spinBox_MM->setValue(month);
    ui->spinBox_YY->setValue(year);

}

AddVaccination::~AddVaccination()
{
    delete ui;
}

void AddVaccination::on_btn_submit_clicked()
{
    // Used to capture dose information
    Dose collectDoseInfo;
    collectDoseInfo.setDoseUserID(getLoggedInUserID());

    // Collecting date that user has entered in QSpinBox
    int yy = (ui->spinBox_YY->value() + 2000) * 10000;
    int mm = ui->spinBox_MM->value() * 100;
    int dd = ui->spinBox_DD->value();
    int retrievedDoseDate = yy + mm + dd;
    collectDoseInfo.setDoseDate(retrievedDoseDate);
    QString checkEnteredDate = QString::number(collectDoseInfo.getDoseDate());
    QDate retQDoseDate = QDate::fromString(checkEnteredDate, "yyyyMMdd");
    QString dispReadyDoseDate = retQDoseDate.toString("dd MMM yyyy");
    qDebug() << "retrievedDoseDate is an INTEGER registered as " << retrievedDoseDate;

    // Collecting manufacturer that user has selected
    QString retrievedManf = ui->comboBox->currentText();
    qDebug() << "The manufacturer retrieved from GUI is " << retrievedManf;
    if (retrievedManf == "Pfizer-BioNTech")
    {
        collectDoseInfo.setDoseManufacturer(1);
    }
    else if (retrievedManf == "Novavax")
    {
        collectDoseInfo.setDoseManufacturer(2);
    }
    else    // Must be GSK
    {
        collectDoseInfo.setDoseManufacturer(3);
    }
    // Write to ./database/MasterTests.csv and ./database/UserDoses folder
    // Creates a csv file with the user's ID as the document name if one does not
    // already exist, otherwise adds information to file
    UserAccount newVax;
    newVax.addDose(collectDoseInfo);

    // Displays confirmation page and data collected
    ui->stackedWidget->setCurrentIndex(1);
    ui->btn_backToAdminHome->hide();
    ui->lbl_displayVaxDate->setText(dispReadyDoseDate);
    ui->lbl_displayVaxManuf->setText(retrievedManf);

}

int AddVaccination::getLoggedInUserID() const
{
    return loggedInUserID;
}

void AddVaccination::setLoggedInUserID(int newLoggedInUserID)
{
    loggedInUserID = newLoggedInUserID;
}


void AddVaccination::on_btn_backToHome_clicked()
{
    this->close();
}


void AddVaccination::on_btn_backToAdminHome_clicked()
{
    this->close();
}

