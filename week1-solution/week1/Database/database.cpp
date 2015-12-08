#include <iostream>
#include <QtSql>
#include "database.h"

using namespace std;

Database::Database()
{

}

void Database::connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "ComputerHistory_db.sqlite";
    db.setDatabaseName(dbName);

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
    query.exec("CREATE TABLE IF NOT EXISTS computers(`ID_computer` "
               "int(11) NOT NULL UNIQUE PRIMARY KEY,"
               "`Name` int(11) NOT NULL ,"
               "`BuildYear` int(11),"
               " `ComputerType` VARCHAR(100),"
               "`BuiltOrNot` BOOLEAN)");

    query.exec("CREATE TABLE IF NOT EXISTS scientists("
               "`ID_scientist` int(11) NOT NULL UNIQUE PRIMARY KEY,"
               "`Name` int(11) NOT NULL ,"
               "`Sex` VarChar(100),"
               "`YearBirth` int(5),"
               "`YearDeath` int(5),)");

    query.exec("CREATE TABLE IF NOT EXISTS tengiTafla("
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
