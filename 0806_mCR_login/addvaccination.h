#ifndef ADDVACCINATION_H
#define ADDVACCINATION_H

#include <QWidget>

namespace Ui {
class AddVaccination;
}

class AddVaccination : public QWidget
{
    Q_OBJECT

public:
    explicit AddVaccination(QWidget *parent = nullptr);
    ~AddVaccination();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddVaccination *ui;
};

#endif // ADDVACCINATION_H
