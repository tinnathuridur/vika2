#include "models/computer.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
using namespace std;

Computer::Computer():name(" "), yearInvented(0), type(), wasBuilt(0)
{

}

Computer::Computer(string name, int yearInvented, computerType type, bool wasBuilt)
{
    this->name = name;
    this->yearInvented = yearInvented;
    this->type = type;
    this->wasBuilt = wasBuilt;
}

string Computer::getName() const
{
    return name;
}

int Computer::getYearInvented() const
{
    return yearInvented;
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

    if (searchTermLower == "Mechanical" && type == computerType::Mechanical)
    {
        return true;
    }

    if (searchTermLower == "Electronic" && type == computerType::Electronic)
    {
        return true;
    }

    if (searchTermLower == "Transitor" && type == computerType::Transitor)
    {
        return true;
    }

    return false;
}
