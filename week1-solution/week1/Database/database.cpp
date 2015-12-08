#include <iostream>
#include <QtSql>
#include "database.h"

using namespace std;

Database::Database()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
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

