#include "handlecsv.h"
#include "useraccount.h"
HandleCSV::HandleCSV()
{

}

//-----------------------------------------------------------
// Returning the database path based on shortname
QString HandleCSV::returnCSVFilePath(QString dbName)
{
    QString filePath;
    qDebug() << "dbName passed is " << dbName;
    if (dbName == "dbPID")
    {
        filePath = ":/database/dummyPID.csv";
//        qDebug() << "You have found dbPID with filepath " << filePath;
    }
    else if (dbName == "dbTest")
    {
        filePath = ":/database/MasterTests.csv";
    }
    else if (dbName == "dbDose")
    {
        filePath = ":/database/MasterDoses.csv";
    }
    // ** Add any other database/path here
    else
    {
        qDebug() << "Error with the file path you passed, returning entire string";
        return dbName;
    }
    qDebug() << "about to return" << filePath;
    return filePath;
}

//-----------------------------------------------------------
// Mapping database header fields to specific indexes
int HandleCSV::returnHeaderIndex(QString dbName, QString headerName)
{
    int headerIndex = -1;

    QString filePath = returnCSVFilePath(dbName);
    qDebug() << "File path is " <<  filePath;

    // Open CSV filepath retrieved from associated dbName
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "IsOpen?: "<< file.isOpen()  << file.errorString()
                 << "Filepath for getUserAccount = " << filePath;
        return headerIndex;
    }

    // Read the header line and get the value of each cell
    QString headers = file.readLine().trimmed();
    QStringList headerRowValues = headers.split(',');

    // Compare that cell value to the colHeader search value
    // and grab the column index that we are retrieving
    for(int i = 0; i < headerRowValues.size(); i++)
    {
        qDebug() << "Comparing colHeaders...";
        if(headerRowValues.at(i) == headerName)
        {
            return i;
        }
    }
    return headerIndex;
}

//-----------------------------------------------------------
// Get all data in a column for a specified header for a CSV file
QStringList HandleCSV::getColData(QString headerName, QString dbName)
{
    QStringList data;
    qDebug() << "getColData before the returnCSVfilepath";
    QString filePath = returnCSVFilePath(dbName);
    qDebug() << "You are in getColData and your filepath is " << filePath;

    int headerIndex = returnHeaderIndex(dbName,headerName);

    // Open CSV filepath retrieved from associated dbName
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "IsOpen?: "<< file.isOpen()  << file.errorString()
                 << "Filepath for getUserAccount = " << filePath;
        return data;
    }

    // Retrieve all of the values in that headerIndex's column
    while(!file.atEnd())
    {
        // Read the line and store it
        QString row = file.readLine().trimmed();
        QStringList rowValues = row.split(',');
        data << rowValues.at(headerIndex);
    }
    file.close();
    return data;    // Returns all the data in that column as a QStringList
}


//-----------------------------------------------------------
// Validates if any of the values in the column exist
// and returns the row index if yes
int HandleCSV::rowIndexOfCellMatchingSearch(QStringList colData, QString searchValue)
{
    qDebug() << "checking list for " << searchValue;
    for(int i = 0; i < colData.size(); i++)
    {
        if(colData.at(i) == searchValue)
        {
            return ++i; // Return rowIndex where search value (i.e. username) was found
        }
    }
    return -1;      // If not found return -1
}


//-------------------------------------------------------------
// Gets a specific cell's value based on header and row index
QString HandleCSV::getCellValue(QString dbName, int headerIn, int rowIn)
{
    QString cellValue;
    QString filePath = returnCSVFilePath(dbName);
    qDebug() << "Filepath for getCellVal = "<< filePath;

    // Open CSV filepath retrieved from associated dbName
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "IsOpen?: "<< file.isOpen()  << file.errorString()
                 << "Filepath for getUserAccount = " << filePath;
        return cellValue;
    }

    // Retrieve all of the values in that headerIndex's column
    while(!file.atEnd())
    {

        // Skip the number of rows that are inapplicable
        int rowNum = 1;
        do
        {
            file.readLine();
            rowNum++;
        } while(rowNum < rowIn);

        QString row = file.readLine().trimmed();
        QStringList rowValues = row.split(',');
        cellValue = rowValues.at(headerIn);
//        qDebug() << "You made it here!";
        file.close();
        return cellValue;
    }

    return cellValue;

}

UserAccount HandleCSV::getUserAccount(QString email)
{
    UserAccount grabbedUser;

    // Getting all the users from userEmail column of dbPID
    // and storing it as a QStringList
    QStringList allUserEmails = getColData("userEmail","dbPID");

    // Searching all emails in retrieved QStringList for email
    int userFoundInRowIndex = rowIndexOfCellMatchingSearch(allUserEmails,email);
    if (userFoundInRowIndex <0)
    {
        qDebug() << "User with email " << email << " not found";
        return grabbedUser;
    }
    else
    {
        //Get all the data from that user based on row index

        QString filePath = returnCSVFilePath("dbPID");

        // Open CSV filepath retrieved from associated dbName
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "IsOpen?: "<< file.isOpen()  << file.errorString()
                     << "Filepath for getUserAccount = " << filePath;
            return grabbedUser;
        }

        // Skip rows that are not applicable
        int rowNum = 1;
        do
        {
            file.readLine();
            rowNum++;
        } while(rowNum < userFoundInRowIndex);

        QString row = file.readLine().trimmed();
        QStringList rowValues = row.split(',');

        grabbedUser = UserAccount(rowValues.at(0).toInt(),rowValues.at(1),rowValues.at(2),
                                  rowValues.at(3),rowValues.at(4),rowValues.at(5),
                                  rowValues.at(6),rowValues.at(7).toInt(),
                                  rowValues.at(8).toInt(),rowValues.at(9).toInt(),rowValues.at(10));
        file.close();
        return grabbedUser;
    }

}

UserAccount HandleCSV::getUserAccount(int uid)
{
    UserAccount grabbedUser;
    qDebug() << "getUserAccount received uid " << uid;
    // Getting all the users from userIDNumber column of dbPID
    // and storing it as a QStringList
    QStringList allUserIDs = getColData("userIDNumber","dbPID");
    qDebug() << "Checking this list:" << allUserIDs;

    // Searching all uids in retrieved QStringList for target uid
    int userFoundInRowIndex = rowIndexOfCellMatchingSearch(allUserIDs,QString::number(uid));
    if (userFoundInRowIndex <0)
    {
        qDebug() << "User with uid " << uid << " not found";
    }
    else
    {
        //Get all the data from that user based on row index
        QString filePath = returnCSVFilePath("dbPID");

        // Open CSV filepath retrieved from associated dbName
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "IsOpen?: "<< file.isOpen()  << file.errorString()
                     << "Filepath for getUserAccount = " << filePath;
        }

        // Skip rows that are not applicable
        int rowNum = 1;
        do
        {
            file.readLine();
            rowNum++;
        } while(rowNum < userFoundInRowIndex);

        QString row = file.readLine().trimmed();
        QStringList rowValues = row.split(',');

        grabbedUser = UserAccount(rowValues.at(0).toInt(),rowValues.at(1),rowValues.at(2),
                                  rowValues.at(3),rowValues.at(4),rowValues.at(5),
                                  rowValues.at(6),rowValues.at(7).toInt(),
                                  rowValues.at(8).toInt(),rowValues.at(9).toInt(),rowValues.at(10));
        file.close();

    }
    return grabbedUser;

}

void HandleCSV::writeToPIDCSV(UserAccount userConstructor)
{
    // Storing in userPID db
    QString filePath = returnCSVFilePath("dbPID");
    qDebug() << "File path passsed to writeToPIDCSV is " <<  filePath;

    // Mapping info in userConstructor to cells
    QString email, pass, fn, ln, pn, nhi, qrAdd;
    int uid, ph, vaxstat,qrstat;
    uid = userConstructor.getUserIDNumber();
    email = userConstructor.getUserEmail();
    pass = userConstructor.getUserPassword();
    fn = userConstructor.getUserFirstName();
    ln = userConstructor.getUserLastName();
    pn = userConstructor.getUserPreferredName();
    nhi = userConstructor.getUserNHINumber();
    qrAdd = userConstructor.getUserQRCodeAddress();
    ph = userConstructor.getUserPhoneNumber();
    vaxstat = userConstructor.getUserVaccinationStatus();
    qrstat = userConstructor.getUserQRStatus();


    // Open CSV filepath retrieved from associated dbName
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Append))
    {

        qDebug() << file.isOpen() << "error " << file.errorString();

    }
//    if (file.open(QIODevice::ReadWrite | QIODevice::Append))

    else
    {
        qDebug() << "Is the file open?" << file.isOpen();

        // Streaming info back into db
        QTextStream stream(&file);
        stream << uid << "," << email << "," << pass << "," << fn << ","
               << ln << "," << pn << "," << nhi << "," << ph << ","
               << vaxstat << "," << qrstat << "," << qrAdd << "\n";

    }


    file.close();
}
