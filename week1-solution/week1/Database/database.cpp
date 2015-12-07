#include <QCoreApplication>
using namespace std;

#include "database.h"

#include <iostream>

Database::Database(char* filename) {

    database = NULL;
    open(filename);
}

//Database::~Database(char*filename) {

//}

bool Database::open(char *filename) {

    if(sqlite3_open(filename, &database) == SQLITE_OK){
        return true;
    }
    else{
        return false;
    }
}

vector<vector<string> > Database::query(char *query){

    sqlite3_stmt *statement;
    vector<vector<string> > results;

    if  (sqlite3_prepare_v2(database, query, -1, &statement, 0) == SQLITE_OK){

        int cols = sqlite3_column_count(statement);
        int result = 0;

        while(true){

            result = sqlite3_step(statement);

            if(result == SQLITE_ROW) {

                vector<string> values;
                for (int col = 0; col < cols; col++){
                    string val;
                    char* ptr = (char*)sqlite3_column_text(statement, col);

                    if (ptr) {

                        val = ptr;
                    }
                    else {

                        val = "";
                    }

                    values.push_back(val);
                }

                results.push_back(values);
            }

            else {

                break;
            }
        }

        sqlite3_finalize(statement);
    }

    string error = sqlite3_errmsg(database);
    if (error != "not an error"){

        cout << query << " " << error << endl;
    }

    return results;
}

bool Database::close(char *filename) {

    sqlite3_close(database);
}
