#ifndef DATABASE_H
#define DATABASE_H

class Database
{
public:
    Database();
    void connect();
    void createTables();
    QSqlDatabase getDb();

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
