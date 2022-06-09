#ifndef DOSE_H
#define DOSE_H

class Dose
{
private:
    int doseUserID;
    int doseManufacturer;
    int doseDate;
public:
    //Getters
    int getDoseUserID();
    int getDoseManufacturer();
    int getDoseDate();

    //Setters
    void setDoseUserID(int userID);
    void setDoseManufacturer(int manufacturer);
    void setDoseDate(int date);

    //Constructor
    Dose();
};

#endif // DOSE_H
