#ifndef DATABASE_H
#define DATABASE_H
//Database connects to database

class Database
{
public:
    Database();
    //connect checks if db opens, if not it creates the database and calls createTables
    void connect();
    void createTables();
    QSqlDatabase getDb();

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
