#include "services/computerservice.h"
#include "utilities/computercomparator.h"

#include <algorithm>
#include <vector>
#include <string>

using namespace std;


ComputerService::ComputerService()
{

}

/*std::vector<Computer> ComputerService::getAllComputers(std::string orderBy, bool orderAscending)
{
    vector<Computer> computers = computerRepo.getAllComputers();

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
*/
