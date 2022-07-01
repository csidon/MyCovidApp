#ifndef SUBMITERRORREPORT_H
#define SUBMITERRORREPORT_H

#include <QWidget>
#include <QStandardPaths>

namespace Ui {
class SubmitErrorReport;
}

class SubmitErrorReport : public QWidget
{
    Q_OBJECT
private:
    int loggedInUser;
public:
    explicit SubmitErrorReport(QWidget *parent = nullptr, int userID = 0);
    ~SubmitErrorReport();

    int getLoggedInUser();
    void setLoggedInUser(int newLoggedInUser);

private slots:
    void on_btn_backToHome_clicked();

    void on_btn_submit_clicked();

private:
    Ui::SubmitErrorReport *ui;
};

#endif // SUBMITERRORREPORT_H
