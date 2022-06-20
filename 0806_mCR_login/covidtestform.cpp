#include "covidtestform.h"
#include "ui_covidtestform.h"

CovidTestForm::CovidTestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CovidTestForm)
{
    ui->setupUi(this);
}

CovidTestForm::~CovidTestForm()
{
    delete ui;
}
