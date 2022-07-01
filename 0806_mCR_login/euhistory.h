#ifndef EUHISTORY_H
#define EUHISTORY_H

#include <QWidget>
#include "toolitem.h"
#include "expandingtoolbox.h"
#include <QListWidget>
#include <QDateTime>
#include "customlistwidget.h"

namespace Ui {
class EUHistory;
}

class EUHistory : public QWidget
{
    Q_OBJECT

public:
    explicit EUHistory(QWidget *parent = nullptr, int loggedInUserID = 0);
    ~EUHistory();
    int getLoggedInUserID();
    void setLoggedInUserID(int newLoggedInUserID);
    QString getTestDate();
    void setTestDate(QString tDate);
//    CustomListWidget printTestSummary(int pageNum, std::vector<QString>, std::vector<QString>);

private slots:
    void on_btn_backToAdminHome_clicked();

private:
    int userID;
    QString testDate;
//    std::vector<QString> allTestDateValues;
//    std::vector<QString> allTestResultValues;

    Ui::EUHistory *ui;
};

#endif // EUHISTORY_H
