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
    explicit AddVaccination(QWidget *parent = nullptr, int loggedInUserID = 0);
    ~AddVaccination();

    int getLoggedInUserID() const;
    void setLoggedInUserID(int newLoggedInUserID);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_btn_backToAdminHome_clicked();

private:
    int loggedInUserID;
    Ui::AddVaccination *ui;
};

#endif // ADDVACCINATION_H
