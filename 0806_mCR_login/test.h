#ifndef TEST_H
#define TEST_H
#include <QWidget>
#include <QDate>

namespace Ui {
class Test;
}

class Test : public QWidget
{
    Q_OBJECT
private:
    Ui::Test *ui;
    int testUserID;
    QString testDate;
    bool testResult;
    QString testRecDate;
public:
    //Getters
    int getTestUserID();
    QString getTestDate();
    bool getTestResult();
    QString getTestRecDate();

    //Setters
    void setTestUserID(int userID);
    void setTestDate(QString date);
    void setTestResult(bool result);
    void setTestRecDate(QString recDate);

    //Constructor
    Test();
};

#endif // TEST_H
