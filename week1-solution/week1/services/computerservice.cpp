#include "services/computerservice.h"
#include "utilities/computercomparator.h"

#include <algorithm>

using namespace std;


Computerservice::Computerservice()
{

}

std::vector<Computer> ComputerService::getAllComputers(std::string orderBy, bool orderAscending)
{
    vector<Computer> computers = comuterRepo.getAllComputers();

    std::sort(computers.begin(), computers.end(), ComputerComparator(orderBy, orderAscending));

    return computers;
}

std::vector<Computer> ComputerService::searchForComputers(std::string searchTerm)
{
    return computerRepo.searchForComputers(searchTerm);
}

bool ComputerService::addComputer(Computer computer)
{
    return computerRepo.addComputer(computer);
}
