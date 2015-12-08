#ifndef COMPUTERS
#define COMPUTERS

#endif // COMPUTERS

class Computers
{
public:
    Computers(std::string name, int year, std::string built);

    std::string getName() const;
    int getYear() const;
    string getBuilt();

    bool contains(std::string searchTerm);

private:
    std::string name;
    std::string built;
    int year;



};
