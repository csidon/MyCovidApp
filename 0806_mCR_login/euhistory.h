#ifndef EUHISTORY_H
#define EUHISTORY_H

#include <QWidget>
#include "toolitem.h"
#include "expandingtoolbox.h"
#include <QListWidget>

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

private:
    int userID;
    Ui::EUHistory *ui;
};

#endif // EUHISTORY_H
