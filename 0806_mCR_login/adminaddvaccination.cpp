#include "adminaddvaccination.h"
#include "ui_adminaddvaccination.h"

AdminAddVaccination::AdminAddVaccination(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminAddVaccination)
{
    ui->setupUi(this);
}

AdminAddVaccination::~AdminAddVaccination()
{
    delete ui;
}
