#ifndef COMPUTERCOMPARATOR_H
#define COMPUTERCOMPARATOR_H
#include "models/computer.h"
#include <vector>
#include <string>
//Computercomparator can compare two computers by rules set in the constructor when used with a sort funciton

class ComputerComparator
{
public:
    ComputerComparator(std::string sortColumn, bool sortInAscendingOrder);

    bool operator() (const Computer& first, const Computer& second);
private:
    std::string sortColumn;
    bool sortInAscendingOrder;
};

#endif // COMPUTERCOMPARATOR_H
