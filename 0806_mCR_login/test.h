#ifndef TEST_H
#define TEST_H


class Test
{
private:
    int testUserID;
    int testDate;
    bool testResult;
public:
    //Getters
    int getTestUserID();
    int getTestDate();
    bool getTestResult();

    //Setters
    void setTestUserID(int userID);
    void setTestDate(int date);
    void setTestResult(bool result);

    //Constructor
    Test();
};

#endif // TEST_H
