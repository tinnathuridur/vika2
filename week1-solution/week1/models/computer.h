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
    Computer(std::string name, int yearInvented, computerType type, bool wasBuilt);

    std::string getName() const;
    int getYearInvented() const;
    enum computerType getType() const;
    bool getWasBuilt() const;

    bool contains(std::string searchTerm);

private:
    std::string name;
    int yearInvented;
    enum computerType type;
    bool wasBuilt;
};

#endif // COMPUTER_H
