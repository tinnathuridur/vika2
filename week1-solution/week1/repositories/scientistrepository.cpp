
#include "repositories/scientistrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
#include "Database/database.h"
#include <cstdlib>
#include <iostream>

using namespace std;

ScientistRepository::ScientistRepository()
{
    fileName = constants::DATA_FILE_NAME;
}

std::vector<Scientist> ScientistRepository::getAllScientists()
{
    Database theBase;
    theBase.connect();

    vector<Scientist> scientists;

    QSqlQuery query;
    QString queryString = "Select name, sex, yearBirth, yearDeath From scientists";

    query.exec(queryString);

    while (query.next()) {
        QSqlRecord record = query.record();
        qDebug() << "name:" << record.value(0).toString()
                 << "sex:" << record.value(1).toString()
                 << "yearBorn:" << record.value(2).toString()
                 << "yearDead:" << record.value(3).toString() << endl;
    }


    /*
    if (file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            vector<string> fields = utils::splitString(line, constants::FILE_DELIMETER);
            if (fields.size() >= 3)
            {
                string name = fields.at(0);
                enum sexType sex = utils::stringToSex(fields.at(1));
                int yearBorn = utils::stringToInt(fields.at(2));
                if (fields.size() == 3)
                {
                    scientists.push_back(Scientist(name, sex, yearBorn));
                }
                else
                {
                    int yearDied = utils::stringToInt(fields.at(3));
                    scientists.push_back(Scientist(name, sex, yearBorn, yearDied));
                }
            }
        }
    }*/

    theBase.disconnect();

    return scientists;
}

/*bool updataData()
{
    Database theBase;
    theBase.connect();

    QSqlQuery query;
    query.perpare("update ? set")


}*/

vector<Scientist> ScientistRepository::searchForScientists(string searchTerm)
{
    vector<Scientist> allScientists = getAllScientists();
    vector<Scientist> filteredScientists;

    for (unsigned int i = 0; i < allScientists.size(); i++)
    {
        if (allScientists.at(i).contains(searchTerm))
        {
            filteredScientists.push_back(allScientists.at(i));
        }
    }

    return filteredScientists;
}

bool ScientistRepository::addScientistToDatabase(const Scientist obj)
{
    Database theBase;
    theBase.connect();

   bool success = false;
   string sex;
   enum sexType enumSex = obj.getSex();
   if(enumSex == sexType::Male)
   {
       sex = "male";
   }
   else if(enumSex == sexType::Female)
   {
       sex = "female";
   }
   else
   {
       sex = "annað";
   }
   int yearBorn = obj.getYearBorn();
   int yearDeath = obj.getYearDied();
   while(yearBorn > yearDeath){
       cout << "Must be born before you die" << endl;
       cout << "Input correct death year or write 13337 to skip: ";
       cin >> yearDeath;
   }

   QSqlQuery query;
   query.prepare("INSERT INTO scientists (name, sex, yearbirth, yeardeath) VALUES (:name, :sex, :yearbirth, :yeardeath)");
   query.bindValue(":name", QString::fromStdString(obj.getName()));
   query.bindValue(":sex", QString::fromStdString(sex));
   query.bindValue(":yearBirth", yearBorn);
   query.bindValue(":yearDeath", yearDeath);
   if(query.exec())
   {
       success = true;
   }
   else
   {
        qDebug() << "addPerson error:  "
                 << query.lastError();
   }
   theBase.disconnect();

   return success;
}
