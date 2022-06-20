#ifndef COVIDTESTFORM_H
#define COVIDTESTFORM_H

#include <QWidget>

namespace Ui {
class CovidTestForm;
}

class CovidTestForm : public QWidget
{
    Q_OBJECT

public:
    explicit CovidTestForm(QWidget *parent = nullptr);
    ~CovidTestForm();

private:
    Ui::CovidTestForm *ui;
};

#endif // COVIDTESTFORM_H
