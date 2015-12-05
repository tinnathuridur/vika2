#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

enum computerType {
    mechanical,
    electronic,
    transitor
};

class Computer
{
public:
    Computer();
    Computer(std::string name, int yearBuilt, computerType type, bool wasBuilt);

    std::string getName() const;
    int getYearBuilt() const;
    enum computerType getType() const;
    bool getWasBuilt() const;

    bool contains(std::string searchTerm);

private:
    std::string name;
    int yearBuilt;
    enum computerType type;
    bool wasBuilt;
};

#endif // COMPUTER_H
