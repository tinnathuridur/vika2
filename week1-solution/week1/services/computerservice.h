#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include "repositories/computerrepository.h"
#include <vector>
#include <string>


class ComputerService
{
public:
    ComputerService();

    std::vector<Computer> getAllComputers(std::string orderBy, bool orderAscending);
    std::vector<Computer> searchForComputers(std::string searchTerm);

    bool addComputer(Computer computer);

private:
    ComputerRepository computerRepo;
};

#endif // COMPUTERSERVICE_H
