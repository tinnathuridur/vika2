#include "utilities/computercomparator.h"

Computercomparator::Computercomparator(std::string column, bool sortInAscendingOrder)
{
    this->sortColumn = column;
    this->sortInAscendingOrder = sortInAscendingOrder;
}

bool Computercomparator::operator() (const Computer& first, const Computer& second)
{
    if (sortColumn == "name")
    {
        if (sortInAscendingOrder)
        {
            return first.getName() < second.getName();
        }
        else
        {
            return second.getName() < first.getName();
        }
    }
    else if (sortColumn == "yearInvented")
    {
        if (sortInAscendingOrder)
        {
            return first.getYearInvented() < second.getYearInvented();
        }
        else
        {
            return second.getYearInvented() < first.getYearInvented();
        }
    }

    return false;
}
