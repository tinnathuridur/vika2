#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H
#include <vector>
#include <string>
#include "models/computer.h"


class ComputerRepository
{
public:
    ComputerRepository();
    std::vector<Computer>getAllComputers();
    std::vector<Computer>searchForComputers(std::string searchTerm);
    bool addComputerToDatabase(const Computer obj);
private:
    std::string fileName;

};

#endif // COMPUTERREPOSITORY_H
