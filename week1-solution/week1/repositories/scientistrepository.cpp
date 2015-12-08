#include "repositories/scientistrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
#include "Database/database.h"
#include <cstdlib>

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
   bool success = false;
   string sex;
   enum sexType enumSex = obj.getSex();
   if(enumSex == 'male'){
       sex = "male";
   }
   else if(enumSex == 'female'){
       sex = "female";
   }
   else{
       sex = "annað";
   }
   QSqlQuery query;
   query.prepare("INSERT INTO Scientists (name, sex, yearbirth, yeardeath) VALUES (:name, :sex, :yearbirth, :yeardeath)");
   query.bindValue(":name", QString::fromStdString(obj.getName()));
   query.bindValue(":sex", QString::fromStdString(sex));
   query.bindValue(":yearbirth", obj.getYearBorn());
   query.bindValue(":yeardeath", obj.getYearDied());
   if(query.exec())
   {
       success = true;
   }
   else
   {
        qDebug() << "addPerson error:  "
                 << query.lastError();
   }

   return success;
}
