#include "computer.h"

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

//bool contains(std::string searchTerm);
