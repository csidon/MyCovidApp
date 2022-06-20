#ifndef TEST_H
#define TEST_H
#include <QWidget>

namespace Ui {
class Test;
}

class Test : public QWidget
{
    Q_OBJECT
private:
    Ui::Test *ui;
    int testUserID;
    int testDate;
    bool testResult;
    bool testIsNew;
public:
    //Getters
    int getTestUserID();
    int getTestDate();
    bool getTestResult();
    bool getTestIsNew();

    //Setters
    void setTestUserID(int userID);
    void setTestDate(int date);
    void setTestResult(bool result);
    void setTestIsNew(bool isNew);

    //Constructor
    Test();
};

#endif // TEST_H
