#ifndef HANDLECSV_H
#define HANDLECSV_H

#include <QStringList>
#include <QDir>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QMap>
#include <QTextStream>

#include <QDebug>

class UserAccount;


class HandleCSV
{
public:
    HandleCSV();

    // ################# Functions ####################
    // Returning the database path based on shortname
    QString returnCSVFilePath(QString dbName);

    // Mapping database header fields to specific indexes
    int returnHeaderIndex(QString dbName, QString headerName);

    // Get all data in a column for a specified header for a CSV file
    QStringList getColData(QString headerName, QString dbName);

    // Validates if any of the values in the column exist
    // and returns the row index if yes
    int rowIndexOfCellMatchingSearch(QStringList colData, QString searchValue);

    // Gets a specific cell's value based on header and row index
    QString getCellValue(QString dbName, int headerIn, int rowIn);

    // Gets a specific cell's value based on header and row index
    UserAccount getUserAccount(QString email);
    //Overload the function to be able to call based on email add or UID
    UserAccount getUserAccount(int uid);

    // Writing data to db
    void writeToPIDCSV(UserAccount userConstructor);

    //Update the PID with a single modified user
    void updatePID(UserAccount modifiedUser);

    //Write user to newPID file
    void writeToNewPID(UserAccount userBeingWritten);

    //Remove user ID from QR requests file
    void removeQRRequest(QStringList newListofRequestingUsers);

//    // Updating a single row (user's details) in dbPID based on UID
//    void updatePID(int uid, UserAccount updatedUser);

};

#endif // HANDLECSV_H
