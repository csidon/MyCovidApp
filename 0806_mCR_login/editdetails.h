#ifndef EDITDETAILS_H
#define EDITDETAILS_H

#include <QWidget>

#include "useraccount.h"
#include "handlecsv.h"

namespace Ui {
class editDetails;
}

class editDetails : public QWidget
{
    Q_OBJECT
private:
    int selectedUserID;
public:
    explicit editDetails(QWidget *parent = nullptr);
    ~editDetails();

    int getSelectedUserID();
    void setSelectedUserID(int newSelectedUserID);

    void displayCurrentDetails();

private slots:
    void on_btn_submit_clicked();

    void on_btn_backToHome_clicked();

private:
    Ui::editDetails *ui;
};

#endif // EDITDETAILS_H
