#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

enum computerType {
    Mechanical,
    Electronic,
    Transitor
};

class Computer
{
public:
    Computer();
    Computer(std::string name, int yearInvented, computerType type, std::string wasBuilt);

    std::string getName() const;
    int getYearInvented() const;
    enum computerType getType() const;
    std::string getWasBuilt() const;

    bool contains(std::string searchTerm);

private:
    std::string name;
    int yearInvented;
    enum computerType type;
    std::string wasBuilt;
};

#endif // COMPUTER_H
