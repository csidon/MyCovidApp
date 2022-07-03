#ifndef VACCINEHISTORY_H
#define VACCINEHISTORY_H

#include "qlabel.h"
#include <QWidget>

namespace Ui {
class VaccineHistory;
}

class VaccineHistory : public QWidget
{
    Q_OBJECT
private:
    QLabel* types[6];
    QLabel* dates[6];
    int loggedInUser;
    int noOfPages;
    int currentPage;
public:
    explicit VaccineHistory(QWidget *parent = nullptr, int loggedInUserID = 0);
    ~VaccineHistory();

    int getLoggedInUser();
    void setLoggedInUser(int newLoggedInUser);

    void setDisplayedDoses();
    void setPageNumbersDisplay();

    int getNoOfPages();
    void setNoOfPages(int newNoOfPages);

    int getCurrentPage();
    void setCurrentPage(int newCurrentPage);

private slots:
    void on_btn_pageLeft_clicked();

    void on_btn_pageRight_clicked();

    void on_btn_backToChoose_clicked();

private:
    Ui::VaccineHistory *ui;
};

#endif // VACCINEHISTORY_H
