#include "dose.h"

int Dose::getDoseUserID()
{
    return this->doseUserID;
}

int Dose::getDoseManufacturer()
{
    return this->doseManufacturer;
}

int Dose::getDoseDate()
{
    return this->doseDate;
}

void Dose::setDoseUserID(int newDoseUserID)
{
    this->doseUserID = newDoseUserID;
}

void Dose::setDoseManufacturer(int newDoseManufacturer)
{
    this->doseManufacturer = newDoseManufacturer;
}

void Dose::setDoseDate(int newDoseDate)
{
    this->doseDate = newDoseDate;
}

//Constructor
Dose::Dose()
{
doseUserID = 0;
doseManufacturer = 0;
doseDate = 0;
}
