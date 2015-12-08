#include <iostream>
#include <QtSql>
#include "database.h"
#include "utilities/constants.h"

using namespace std;

Database::Database()
{

}

QSqlDatabase Database::connect()
{
    QSqlDatabase db;
    if(QSqlDatabase::contains(constants::CONNECTION_NAME))
    {
        db = QSqlDatabase::database((constants::CONNECTION_NAME));
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("ComputerHistory_db.sqlite");
        db. open();
        createTables();
    }

    if (!db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

    return db;
}

void Database::createTables()
{
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS Computers"
               "(`ID_computer` INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,"
               "`Name` VarChar(100) NOT NULL ,"
               "`BuildYear` int(11),"
               " `ComputerType` VARCHAR(100),"
               "`BuiltOrNot` BOOLEAN)");

    query.exec("CREATE TABLE IF NOT EXISTS Scientists"
               "(`ID_scientist`  INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,"
               "`Name` VarChar(100) NOT NULL ,"
               "`Sex` VarChar(100),"
               "`YearBirth` int(5),"
               "`YearDeath` int(5))");



    query.exec("CREATE TABLE IF NOT EXISTS ConnectionTable"
               "(`ID` INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,"
               "`ID_scientist` int(11) NOT NULL,"
               "`ID_computer` int(11),"
               "PRIMARY KEY (ID),"
               "UNIQUE (ID_scientist, ID_computer),"
               "FOREIGN KEY (ID_computer) REFERENCES computer(ID_computer),"
               "FOREIGN KEY (ID_scientist) REFERENCES scientist(ID_scientist))");
}

void Database::disconnect()
{
    db.close();
}
