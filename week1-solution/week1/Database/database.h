#include <QCoreApplication>
using namespace std;

#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <sqlite3.h>

class Database
{
public:
    Database(char* filename);
    ~Database();

    bool open(char* filename);
    vector<vector<string> > query(char* query);
    bool close(char* filename);

private:
    sqlite3 *database;


};

#endif // DATABASE_H
