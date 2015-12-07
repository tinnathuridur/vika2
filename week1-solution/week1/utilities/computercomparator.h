#ifndef COMPUTERCOMPARATOR_H
#define COMPUTERCOMPARATOR_H
#include "models/computer.h"
//Computercomparator can compare two computers by rules set in the constructor when used with a sort funciton

class Computercomparator
{
public:
    Computercomparator(std::string sortColumn, bool sortInAscendingOrder);

    bool operator() (const Computer& first, const Computer& second);
private:
    std::string sortColumn;
    bool sortInAscendingOrder;
};

#endif // COMPUTERCOMPARATOR_H
