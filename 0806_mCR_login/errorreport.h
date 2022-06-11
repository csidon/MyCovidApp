#ifndef ERRORREPORT_H
#define ERRORREPORT_H


#include <string>
class ErrorReport
{
private:
    std::string title;
    std::string text;
    int date;
    int sender;
    bool isNew;

public:
    //Getters
    std::string getTitle();
    std::string getText();
    int getDate();
    int getSender();
    bool getIsNew();

    //Setters
    void setTitle(std::string &newTitle);
    void setText(std::string &newText);
    void setDate(int newDate);
    void setSender(int newSender);
    void setIsNew(bool newIsNew);

    //Constructor
    ErrorReport();
};

#endif // ERRORREPORT_H
