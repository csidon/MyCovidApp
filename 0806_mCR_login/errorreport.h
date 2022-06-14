#ifndef ERRORREPORT_H
#define ERRORREPORT_H


#include <QString>
class ErrorReport
{
private:
    QString title;
    QString text;
    int date;
    int sender;
    bool isNew;

public:
    //Getters
    QString getTitle();
    QString getText();
    int getDate();
    int getSender();
    bool getIsNew();

    //Setters
    void setTitle(QString newTitle);
    void setText(QString newText);
    void setDate(int newDate);
    void setSender(int newSender);
    void setIsNew(bool newIsNew);

    //Constructor
    ErrorReport();
};

#endif // ERRORREPORT_H
