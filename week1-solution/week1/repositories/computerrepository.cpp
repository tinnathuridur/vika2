#include "computerrepository.h"
#include <vector>
#include <string>
#include "utilities/utils.h"
#include "utilities/constants.h"
#include "Database/database.h"
#include <cstdlib>
#include <iostream>

using namespace std;

ComputerRepository::ComputerRepository()
{

}

std::vector<Computer> ComputerRepository::getAllComputers()
{
    Database theBase;
    theBase.connect();

    vector<Computer> computers;
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

    return computers;
}

vector<Computer> ComputerRepository::searchForComputers(string searchTerm)
{
    vector<Computer> allComputers = getAllComputers();
    vector<Computer> filteredComputers;

    for (unsigned int i = 0; i < allComputers.size(); i++)
    {
        if (allComputers.at(i).contains(searchTerm))
        {
            filteredComputers.push_back(allComputers.at(i));
        }
    }

    return filteredComputers;
}

bool ComputerRepository::addComputerToDatabase(const Computer obj)
{
    Database theBase;
    theBase.connect();

   bool success = false;

   enum computerType enumType = obj.getType();
   string type;
   if(enumType == computerType::Mechanical){
       type = "Mechanical";
   }
   else if(enumType == computerType::Electronic){
       type = "Electronic";
   }
   else if(enumType == computerType::Transitor){
       type = "Transitor";
   }

   QSqlQuery query;
   query.prepare("INSERT INTO Computers (Name, BuildYear, ComputerType, BuiltOrNot) VALUES (:name, :buildYear, :ComputerType, :BuiltOrNot)");
   query.bindValue(":name", QString::fromStdString(obj.getName()));
   query.bindValue(":buildYear", obj.getYearInvented());
   query.bindValue(":ComputerType", QString::fromStdString(type));
   query.bindValue(":BuiltOrNot", obj.getWasBuilt());
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
