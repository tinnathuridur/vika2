#include "models/computer.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
using namespace std;

Computer::Computer():name(" "), yearBuilt(0), type(), wasBuilt(0)
{

}

Computer::Computer(string name, int yearBuilt, computerType type, bool wasBuilt)
{
    this->name = name;
    this->yearBuilt = yearBuilt;
    this->type = type;
    this->wasBuilt = wasBuilt;
}

string Computer::getName() const
{
    return name;
}

int Computer::getYearBuilt() const
{
    return yearBuilt;
}

computerType Computer::getType() const
{
    return type;
}

bool Computer::getWasBuilt() const
{
    return wasBuilt;
}

bool Computer::contains(std::string searchTerm)
{
    string searchTermLower = utils::stringToLower(searchTerm);

    string nameLower = utils::stringToLower(name);
    if (nameLower.find(searchTermLower) != string::npos)
    {
        return true;
    }

    if (searchTermLower == "mechanical" && type == computerType::mechanical)
    {
        return true;
    }

    if (searchTermLower == "electronic" && type == computerType::electronic)
    {
        return true;
    }

    if (searchTermLower == "transitor" && type == computerType::transitor)
    {
        return true;
    }

    return false;
}
