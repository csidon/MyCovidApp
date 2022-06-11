#ifndef DOSE_H
#define DOSE_H

class Dose
{
private:
    int doseUserID;
    int doseManufacturer;
    int doseDate;
    bool doseIsNew;
public:
    //Getters
    int getDoseUserID();
    int getDoseManufacturer();
    int getDoseDate();
    bool getDoseIsNew();

    //Setters
    void setDoseUserID(int userID);
    void setDoseManufacturer(int manufacturer);
    void setDoseDate(int date);
    void setDoseIsNew(bool isNew);

    //Constructor
    Dose();
};

#endif // DOSE_H
