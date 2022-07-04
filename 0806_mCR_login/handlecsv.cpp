#include "handlecsv.h"


HandleCSV::HandleCSV()
{

}

//-----------------------------------------------------------
// Returning the database path based on shortname
QString HandleCSV::returnCSVFilePath(QString dbName)
{
    QString filePath;
    if (dbName == "dbPID")
    {
        filePath = "./database/dummyPID.csv";
    }
    else if (dbName == "dbTest")
    {
        filePath = "database/MasterTests.csv";
    }
    else if (dbName == "dbDose")
    {
        filePath = "./database/MasterDoses.csv";
    }
    else if (dbName == "dbQRRequests")
    {
        filePath = "database/QRCodeRequests.csv";
    }
    else if (dbName == "dbReports")
    {
        filePath = "database/ErrorReports.csv";
    }
    // ** Add any other database/path here
    else
    {
        qDebug() << "Not a recognised keyword. Passing custom input";
        return dbName;
    }
    return filePath;
}

//-----------------------------------------------------------
// Mapping database header fields to specific indexes
int HandleCSV::returnHeaderIndex(QString dbName, QString headerName)
{
    int headerIndex = -1;

    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    QString filepath = returnCSVFilePath(dbName);

    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        QFile f{filepath};
        if (f.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            // Read the header line and get the value of each cell
            QString headers = f.readLine().trimmed();
            QStringList headerRowValues = headers.split(',');

            // Compare that cell value to the colHeader search value
            // and grab the column index that we are retrieving
            for(int i = 0; i < headerRowValues.size(); i++)
            {
                if(headerRowValues.at(i) == headerName)
                {
                    return i;
                }
            }
        }
    }
    return headerIndex;
}

//-----------------------------------------------------------
// Get all data in a column for a specified header for a CSV file
QStringList HandleCSV::getColData(QString headerName, QString dbName)
{
    QStringList data;
    int headerIndex = returnHeaderIndex(dbName,headerName);

    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    QString filePath = returnCSVFilePath(dbName);

    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        QFile file{filePath};
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Is file open?: "<< file.isOpen()  << file.errorString()
                     << "Filepath for getUserAccount = " << filePath;
            return data;
        }

        // Retrieve all of the values in that headerIndex's column
        while(!file.atEnd())
        {
            // Read the lines and store it
            QString row = file.readLine().trimmed();
            QStringList rowValues = row.split(',');
            //handle commas, which are stored as tildes (~)
            if( headerName == "Text" || headerName == "Title"){//add a header here if you want to turn tildes in the csv under that header into commas
                for(int i=0; i < rowValues.size(); i++){
                    for(int j = 0; j < rowValues.at(i).size(); j++){
                        if(rowValues.at(i)[j] == '~'){
                            QString recomma = "";
                            for(int k = 0; k < j; k++){
                                recomma = recomma + rowValues.at(i)[k];
                            }
                            recomma = recomma + ',';
                            for(int k = j+1; k < rowValues.at(i).size(); k++){
                                recomma = recomma + rowValues.at(i)[k];
                            }
                            rowValues.remove(i);
                            rowValues.insert(i, recomma);
                        }
                        if(rowValues.at(i)[j] == '`'){
                            QString reslash = "";
                            for(int k = 0; k < j; k++){
                                reslash = reslash + rowValues.at(i)[k];
                            }
                            reslash = reslash + '\n';
                            for(int k = j+1; k < rowValues.at(i).size(); k++){
                                reslash = reslash + rowValues.at(i)[k];
                            }
                            rowValues.remove(i);
                            rowValues.insert(i, reslash);
                        }
                    }
                }
            }
            data << rowValues.at(headerIndex);
        }
        file.close();
    }
    return data;    // Returns all the data in that column as a QStringList
}


//-----------------------------------------------------------
// Validates if any of the values in the column exist
// and returns the row index if yes
int HandleCSV::rowIndexOfCellMatchingSearch(QStringList colData, QString searchValue)
{
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

    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    QString filePath = returnCSVFilePath(dbName);

    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        QFile file{filePath};
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
            for (int i = 1; i < rowIn; i++)
            {
                file.readLine();
            }
            QString row = file.readLine().trimmed();
            QStringList rowValues = row.split(',');
            cellValue = rowValues.at(headerIn);
            file.close();
            return cellValue;
        }
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
        auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
        if (path.isEmpty()) qFatal("Cannot determine settings storage location");
        QDir d{path};
        QString filePath = returnCSVFilePath("dbPID");

        if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
        {
            QFile file{filePath};

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
    return grabbedUser;

}

UserAccount HandleCSV::getUserAccount(int uid)
{
    UserAccount grabbedUser;
    // Getting all the users from userIDNumber column of dbPID
    // and storing it as a QStringList
    QStringList allUserIDs = getColData("userIDNumber","dbPID");

    // Searching all uids in retrieved QStringList for target uid
    int userFoundInRowIndex = rowIndexOfCellMatchingSearch(allUserIDs,QString::number(uid));
    if (userFoundInRowIndex <0)
    {
        qDebug() << "User with uid " << uid << " not found";
    }
    else
    {
        //Get all the data from that user based on row index
        auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
        if (path.isEmpty()) qFatal("Cannot determine settings storage location");
        QDir d{path};
        QString filePath = returnCSVFilePath("dbPID");

        if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
        {
            QFile file{filePath};
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
    }
    return grabbedUser;
}

ErrorReport HandleCSV::getErrorReport(int index)
{
    //Reads document into lists and returns values at argument index as single object
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    QStringList title = getColData("Title", "dbReports");
    QStringList text = getColData("Text", "dbReports");
    QStringList date = getColData("Date", "dbReports");
    QStringList sender = getColData("Sender", "dbReports");
    QStringList isNew = getColData("isNew", "dbReports");
    ErrorReport report;
    report.setTitle(title.at(index));
    report.setText(text.at(index));
    report.setDate(date.at(index).toInt());
    report.setSender(sender.at(index).toInt());
    if(isNew.at(index) == "TRUE"){
        report.setIsNew(true);
    }
    else if(isNew.at(index) == "FALSE"){
        report.setIsNew(false);
    }
    else{
        qDebug() << "Error reading bool from file: " << isNew.at(index);
    }
    return report;
}

void HandleCSV::writeToPIDCSV(UserAccount newUser)
{
    // Mapping info in userConstructor to cells
    QString email, pass, fn, ln, pn, nhi, qrAdd;
    int uid, ph, vaxstat,qrstat;
    uid = newUser.getUserIDNumber();
    email = newUser.getUserEmail();
    pass = newUser.getUserPassword();
    fn = newUser.getUserFirstName();
    ln = newUser.getUserLastName();
    pn = newUser.getUserPreferredName();
    nhi = newUser.getUserNHINumber();
    qrAdd = newUser.getUserQRCodeAddress();
    ph = newUser.getUserPhoneNumber();
    vaxstat = newUser.getUserVaccinationStatus();
    qrstat = newUser.getUserQRStatus();

    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    QString filepath = returnCSVFilePath("dbPID");

    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        qDebug() << "Writing to " << QDir::currentPath();
        QFile f{filepath};
        if (!f.open(QIODevice::ReadWrite | QIODevice::Append))
        {
            qDebug() << "Is the file open? " << f.isOpen();
            qDebug() << "File error: " << f.error();
            qDebug() << "Error string: " << f.errorString();
        }
        else
        {
            QTextStream stream(&f);
            stream << uid << "," << email << "," << pass << "," << fn << ","
                   << ln << "," << pn << "," << nhi << "," << ph << ","
                   << vaxstat << "," << qrstat << "," << qrAdd << "\n";
        }
    }

}

void HandleCSV::updatePID(UserAccount modifiedUser)
{

   //Find user's position in the file
   QStringList allIDs = getColData("userIDNumber", "dbPID");
   int modifiedIndex = 0;
   for(int i = 0; i < allIDs.size(); i++){
       if(allIDs.at(i) == QString::number(modifiedUser.getUserIDNumber())){
           modifiedIndex = i;
           break;
       }
   }
   //Set up column headers in new file
   auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
   if (path.isEmpty()) qFatal("Cannot determine settings storage location");
   QDir d{path};
   QString filepath = returnCSVFilePath("./database/newPID.csv");

   if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
   {
       qDebug() << "Writing to " << QDir::currentPath();
       QFile f{filepath};
       if (!f.open(QIODevice::ReadWrite | QIODevice::Append))
       {
           qDebug() << "Is the file open? " << f.isOpen();
           qDebug() << "File error: " << f.error();
           qDebug() << "Error string: " << f.errorString();
       }
       else
       {
           QTextStream stream(&f);
           stream << "userIDNumber" << "," << "userEmail" << "," << "userPassword" << "," << "userFirstName" << ","
                  << "userLastName" << "," << "userPreferredName" << "," << "userNHINumber" << "," << "userPhoneNumber" << ","
                  << "userVaccinationStatus" << "," << "userQRStatus" << "," << "userQRCodeAddress" << "\n";
       }
   }
   //Write all positions before the user from the old file into the new file
   UserAccount writingUser;
   for(int i = 1; i < modifiedIndex; i++){
       writingUser = getUserAccount(allIDs.at(i).toInt());
       writeToNewPID(writingUser);
   }

   //Write the modified user from the argument
   writeToNewPID(modifiedUser);

   //Wrtite all the following positions from the old file
   for( int i = modifiedIndex+1; i < allIDs.size(); i++){
       writingUser = getUserAccount(allIDs.at(i).toInt());
       writeToNewPID(writingUser);
   }

   //Delete the old file
   remove("./database/dummyPID.csv");// NOTE this funtion wouldn't accpet a QString so I couldn't use the filepath function - we have to upadte this wil the final PID name

   //Change the name of the new file
   rename("./database/newPID.csv", "./database/dummyPID.csv");
}

void HandleCSV::writeToNewPID(UserAccount userBeingWritten)
{
    // Mapping info in userBeingWritten to cells
    QString email, pass, fn, ln, pn, nhi, qrAdd;
    int uid, ph, vaxstat,qrstat;
    uid = userBeingWritten.getUserIDNumber();
    email = userBeingWritten.getUserEmail();
    pass = userBeingWritten.getUserPassword();
    fn = userBeingWritten.getUserFirstName();
    ln = userBeingWritten.getUserLastName();
    pn = userBeingWritten.getUserPreferredName();
    nhi = userBeingWritten.getUserNHINumber();
    qrAdd = userBeingWritten.getUserQRCodeAddress();
    ph = userBeingWritten.getUserPhoneNumber();
    vaxstat = userBeingWritten.getUserVaccinationStatus();
    qrstat = userBeingWritten.getUserQRStatus();

    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    QString filepath = returnCSVFilePath("./database/newPID.csv");//creates new file

    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        qDebug() << "Writing to " << QDir::currentPath();
        QFile f{filepath};
        if (!f.open(QIODevice::ReadWrite | QIODevice::Append))
        {
            qDebug() << "Is the file open? " << f.isOpen();
            qDebug() << "File error: " << f.error();
            qDebug() << "Error string: " << f.errorString();
        }
        else
        {
            QTextStream stream(&f);
            stream << uid << "," << email << "," << pass << "," << fn << ","
                   << ln << "," << pn << "," << nhi << "," << ph << ","
                   << vaxstat << "," << qrstat << "," << qrAdd << "\n";
        }
    }
}

void HandleCSV::removeQRRequest(QStringList newListOfRequestingUsers)
{

    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    QString filepath = returnCSVFilePath("./database/newQRCodeRequests.csv");//creates new file

    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        qDebug() << "Writing to " << QDir::currentPath();
        QFile f{filepath};
        if (!f.open(QIODevice::ReadWrite | QIODevice::Append))
        {
            qDebug() << "Is the file open? " << f.isOpen();
            qDebug() << "File error: " << f.error();
            qDebug() << "Error string: " << f.errorString();
        }
        else
        {
            QTextStream stream(&f);
            for(int i = 0; i < newListOfRequestingUsers.size(); i++){
                stream << newListOfRequestingUsers.at(i) << "\n";
            }
        }
    }
    //Delete the old file
    remove("./database/QRCodeRequests.csv");// NOTE this funtion wouldn't accpet a QString so I couldn't use the filepath function - we have to upadte this wil the final PID name

    //Change the name of the new file
    rename("./database/newQRCodeRequests.csv", "./database/QRCodeRequests.csv");
}

void HandleCSV::updateIsNewOfReport(int updateeIndex)
{
    //Set up column headers in new file
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    QString filepath = returnCSVFilePath("./database/newErrorReports.csv");//creates new file
    HandleCSV readReports;
    //It may seem like a vector of Reports is better here than 5 QStringLists, but that would use more memory and code as we would have to convert the strings to ints/bools and back
    QStringList reportTitles = getColData("Title", "dbReports");
    //Handling commas in title
    for(int i=0; i < reportTitles.size(); i++){
        for(int j = 0; j < reportTitles.at(i).size(); j++){
            if(reportTitles.at(i)[j] == ','){
                QString retilde = "";
                for(int k = 0; k < j; k++){
                retilde = retilde + reportTitles.at(i)[k];
                }
                retilde = retilde + '~';
                for(int k = j+1; k < reportTitles.at(i).size(); k++){
                retilde = retilde + reportTitles.at(i)[k];
                }
                reportTitles.remove(i);
                reportTitles.insert(i, retilde);
            }
        }
    }
    QStringList reportTexts = getColData("Text", "dbReports");
    //Handling commas and line breaks in text - using uncommon characters ~ and ` as substitutes
    for(int i=0; i < reportTexts.size(); i++){
        for(int j = 0; j < reportTexts.at(i).size(); j++){
            if(reportTexts.at(i)[j] == ','){
                QString retilde = "";
                for(int k = 0; k < j; k++){
                retilde = retilde + reportTexts.at(i)[k];
                }
                retilde = retilde + '~';
                for(int k = j+1; k < reportTexts.at(i).size(); k++){
                retilde = retilde + reportTexts.at(i)[k];
                }
                reportTexts.remove(i);
                reportTexts.insert(i, retilde);
            }
            if(reportTexts.at(i)[j] == '\n'){
                QString regrave = "";
                for(int k = 0; k < j; k++){
                regrave = regrave + reportTexts.at(i)[k];
                }
                regrave = regrave + '`';
                for(int k = j+1; k < reportTexts.at(i).size(); k++){
                regrave = regrave + reportTexts.at(i)[k];
                }
                reportTexts.remove(i);
                reportTexts.insert(i, regrave);
            }
        }
    }
    QStringList reportDates = getColData("Date", "dbReports");
    QStringList reportSenders = getColData("Sender", "dbReports");
    QStringList reportIsNews = getColData("isNew", "dbReports");
    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath()))
    {
        QFile f{filepath};
        if (!f.open(QIODevice::ReadWrite | QIODevice::Append))
        {
            qDebug() << "Is the file open? " << f.isOpen();
            qDebug() << "File error: " << f.error();
            qDebug() << "Error string: " << f.errorString();
        }
        else
        {
            QTextStream stream(&f);
            stream << "Title" << "," << "Text" << "," << "Date" << "," << "Sender" << "," "isNew" << "\n";
            //Write all positions before the user from the old file into the new file
            for(int i = 1; i < updateeIndex; i++){
                stream << reportTitles.at(i) << "," << reportTexts.at(i) << "," << reportDates.at(i) << "," << reportSenders.at(i) << "," << reportIsNews.at(i) << "\n";
            }
            //Write the modified report with the new FALSE isNew value
            stream << reportTitles.at(updateeIndex) << "," << reportTexts.at(updateeIndex) << "," << reportDates.at(updateeIndex) << "," << reportSenders.at(updateeIndex) << "," << "FALSE" << "\n";;
            //Wrtite all the following positions from the old file
            for( int i = updateeIndex+1; i < reportIsNews.size(); i++){
                stream << reportTitles.at(i) << "," << reportTexts.at(i) << "," << reportDates.at(i) << "," << reportSenders.at(i) << "," << reportIsNews.at(i) << "\n";
            }
        }
    }
        //Delete the old file
        remove("./database/ErrorReports.csv");
        //Change the name of the new file
        rename("./database/newErrorReports.csv", "./database/ErrorReports.csv");
}

