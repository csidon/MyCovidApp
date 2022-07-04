#ifndef ADMINSEARCHUSERS_H
#define ADMINSEARCHUSERS_H

#include "adminuserselected.h"
#include "useraccount.h"
#include "handlecsv.h"

#include <QWidget>
#include "qdatetime.h"
#include "qlabel.h"

namespace Ui {
class AdminSearchUsers;
}

class AdminSearchUsers : public QWidget
{
    Q_OBJECT
private:
    QStringList searchResultIDs;
    int pageNumber;
    QLabel* labels[6];
    QPushButton* buttons[6];
    AdminUserSelected userSelectedWindow;

public:
    explicit AdminSearchUsers(QWidget *parent = nullptr);
    ~AdminSearchUsers();
    QStringList searchFNames(QString search);
    QStringList searchLNames(QString search);
    QStringList searchPNames(QString search);

    QStringList getSearchResultIDs();
    void setSearchResultIDs(QStringList newSearchResultIDs);

    void setDisplayedResults();

    QString formatNameForDisplay(UserAccount user);

    void button(int btnNumber);

    int getPageNumber();
    void setPageNumber(int newPageNumber);

private slots:
    void on_btn_search_clicked();

    void on_btn_pageLeft_clicked();

    void on_btn_pageRight_clicked();

    void on_btn_user_1_clicked();

    void on_btn_user_2_clicked();

    void on_btn_user_3_clicked();

    void on_btn_user_4_clicked();

    void on_btn_user_5_clicked();

    void on_btn_user_6_clicked();

    void on_btn_backToAdminHome_clicked();

    void on_lineEdit_searchBar_returnPressed();

private:
    Ui::AdminSearchUsers *ui;
};

#endif // ADMINSEARCHUSERS_H

