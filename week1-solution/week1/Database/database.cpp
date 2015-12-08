#include <iostream>
#include <QtSql>
#include "database.h"
#include "utilities/constants.h"

using namespace std;

Database::Database()
{

}

void Database::connect()
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

}

void Database::createTables()
{
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS Computers(`ID_computer` "
               "int(11) NOT NULL UNIQUE PRIMARY KEY,"
               "`Name` int(11) NOT NULL ,"
               "`BuildYear` int(11),"
               " `ComputerType` VARCHAR(100),"
               "`BuiltOrNot` BOOLEAN)");

    query.exec("CREATE TABLE IF NOT EXISTS Scientists("
               "`ID_scientist` int(11) NOT NULL UNIQUE PRIMARY KEY,"
               "`Name` int(11) NOT NULL ,"
               "`Sex` VarChar(100),"
               "`YearBirth` int(5),"
               "`YearDeath` int(5),)");

    query.exec("CREATE TABLE IF NOT EXISTS ConntectionTable("
               "`ID` int NOT NULL,"
               "`ID_scientist` int(11) NOT NULL,"
               "`ID_computer` int(11),"
               "PRIMARY KEY (ID),"
               "UNIQUE (ID_scientist, ID_computer),"
               "FOREIGN KEY (ID_computer) REFERENCES computer(ID_computer),"
               "FOREIGN KEY (ID_scientist) REFERENCES scientist(ID_scientist))");
}

QSqlDatabase Database::getDb()
{
    return db;
}
