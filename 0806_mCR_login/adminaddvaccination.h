#ifndef ADMINADDVACCINATION_H
#define ADMINADDVACCINATION_H

#include <QWidget>

namespace Ui {
class AdminAddVaccination;
}

class AdminAddVaccination : public QWidget
{
    Q_OBJECT

public:
    explicit AdminAddVaccination(QWidget *parent = nullptr);
    ~AdminAddVaccination();

private:
    Ui::AdminAddVaccination *ui;
};

#endif // ADMINADDVACCINATION_H
