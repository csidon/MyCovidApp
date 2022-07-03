#include "addvaccination.h"
#include "ui_addvaccination.h"
#include "dose.h"

AddVaccination::AddVaccination(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddVaccination)
{
    ui->setupUi(this);
}

AddVaccination::~AddVaccination()
{
    delete ui;
}

void AddVaccination::on_pushButton_clicked()
{
    Dose collectDoseInfo;

}

