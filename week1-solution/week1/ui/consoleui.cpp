#include "ui/consoleui.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

#include <iostream>
#include <iomanip>

using namespace std;

ConsoleUI::ConsoleUI()
{
    lastCommand = command::menu;
    sortBy = "name";
    sortAscending = true;
}

int ConsoleUI::begin()
{
    int a = 0;

    cout << endl << "Choose (1) for Scientist Menu or (2) for Computer Menu" << endl;
    cin >> a;

    if (a == 1) {
        startScientist();
    }
    else if (a == 2) {
        startComputer();
    }
    else {
        cout << "You did not make a valid entry! Try again." << endl;
        begin();
    }

    return 1;
}

int ConsoleUI::startScientist()
{
    while(lastCommand != command::quit)
    {
        displayScientist();
        readInputScientist();
    }

    return 0;
}

int ConsoleUI::startComputer()
{
    while(lastCommand != command::quit)
    {
        displayComputer();
        readInputComputer();
    }

    return 0;
}


//-------------------------------------------------------------------------------------
//------------------------------------ Scientist --------------------------------------
//-------------------------------------------------------------------------------------


void ConsoleUI::displayScientist()
{
    switch (lastCommand)
    {
        case command::menu:
            displayScientistMenu();
            break;
        case command::add:
            displayAddScientistMenu();
            break;
        case command::display:
            displayAllScientists();
            break;
        case command::search:
            displayScientistSearchMenu();
            break;
        case command::sort:
            displayScientistSortMenu();
            break;
        default:
            displayUnknownCommandMenu();
            break;
    }
}

void ConsoleUI::readInputScientist()
{
    if (lastCommand == command::display)
    {
        lastCommand = command::sort;
        return;
    }

    string userInput;
    getline(cin, userInput);

    cout << "\n\n";

    bool shouldTreatInputAsCommand = (lastCommand != command::search);

    if (userInput == "display" && shouldTreatInputAsCommand)
    {
        lastCommand = command::sort;
    }
    else if (userInput == "add" && shouldTreatInputAsCommand)
    {
        lastCommand = command::add;
    }
    else if (userInput == "search" && shouldTreatInputAsCommand)
    {
        lastCommand = command::search;
    }
    else if (userInput == "back")
    {
        lastCommand = command::menu;
    }
    else if (userInput == "quit")
    {
        lastCommand = command::quit;
    }
    else
    {
        if (lastCommand == command::add)
        {
            addScientistCommandHandler(userInput);
        }
        else if (lastCommand == command::sort)
        {
            sortScientistCommandHandler(userInput);
        }
        else if (lastCommand == command::search)
        {
            searchScientistCommandHandler(userInput);
        }
        else
        {
            lastCommand = command::unknown;
        }
    }
}

void ConsoleUI::addScientistCommandHandler(string userInput)
{
    if (addScientist(userInput)) {
        cout << "Successfully added a scientist\n\n";
        lastCommand = command::menu;
    }
    else
    {
        displayError("There was an error in your input.");
    }
}

void ConsoleUI::sortScientistCommandHandler(string userInput)
{
    if (setScientistSort(userInput))
    {
        lastCommand = command::display;
    }
    else
    {
        displayError("Your input did not match any of the sort commands");
    }
}

void ConsoleUI::searchScientistCommandHandler(string userInput)
{
    displayScientists(scientistService.searchForScientists(userInput));
}

bool ConsoleUI::addScientist(string data)
{
    vector<string> fields = utils::splitString(data, ',');

    if (fields.size() > 2 && fields.size() < 5)
    {
        string name = fields.at(0);

        enum sexType sex;
        if (fields.at(1) == "male")
        {
            sex = sexType::Male;
        }
        else
        {
            sex = sexType::Female;
        }
        int yearBorn = utils::stringToInt(fields.at(2));

        if (fields.size() == 3)
        {
            return scientistService.addScientist(Scientist(name, sex, yearBorn));
        }
        else
        {
            int yearDied = utils::stringToInt(fields.at(3));

            return scientistService.addScientist(Scientist(name, sex, yearBorn, yearDied));
        }
    }

    return false;
}

bool ConsoleUI::setScientistSort(string sortCommand)
{
    if (sortCommand == constants::SORT_SCIENTIST_NAME_ASCENDING)
    {
        sortBy = "name";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_NAME_DESCENDING)
    {
        sortBy = "name";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_BORN_ASCENDING)
    {
        sortBy = "yearBorn";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_BORN_DESCENDING)
    {
        sortBy = "yearBorn";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_DIED_ASCENDING)
    {
        sortBy = "yearDied";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_DIED_DESCENDING)
    {
        sortBy = "yearDied";
        sortAscending = false;
    }
    else
    {
        return false;
    }

    return true;
}

void ConsoleUI::displayScientistMenu()
{
    cout << "Enter a command:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "add:" << "Adds a scientist\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "display:" << "Displays scientists\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "search:" << "Search for a scientist\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "quit:" << "Quits the program\n\n";

    cout << "Command: ";
}

void ConsoleUI::displayAddScientistMenu()
{
    cout << "To add a scientist, type in:\n";
    cout << "Name,sex,yearBorn,yearDied (optional)\n";
    cout << "Comma separated like in the example above.\n\n";
    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displayAllScientists()
{
    vector<Scientist> scientists = scientistService.getAllScientists(sortBy, sortAscending);

    displayScientists(scientists);

    cout << '\n';

    lastCommand = command::display;
}

void ConsoleUI::displayScientistSearchMenu()
{
    cout << "Search for a scientist.\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displayScientistSortMenu()
{
    cout << "How should the list be sorted:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_NAME_ASCENDING << "Sorts by name, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_NAME_DESCENDING << "Sorts by name, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_BORN_ASCENDING << "Sorts by year born, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_BORN_DESCENDING << "Sorts by year born, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_DIED_ASCENDING << "Sorts by year died, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_DIED_DESCENDING << "Sorts by year died, descending.\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";

    cout << "Command: ";
}

void ConsoleUI::displayScientists(std::vector<Scientist> scientists)
{
    if (scientists.size() == 0)
    {
        cout << "No scientist found.\n";
        return;
    }

    cout << "Printing all scientists:\n";

    cout << setw(20) << std::left << "Name:"
         << setw(8) << std::left << "Sex:"
         << setw(12) << std::left << "Year born:"
         << setw(12) << std::left << "Year died:" << endl;

    for (unsigned int i = 0; i < scientists.size(); i++)
    {
        string scientistSex = (scientists.at(i).getSex() == sexType::Male) ? "Male" : "Female";

        int yearDied = scientists.at(i).getYearDied();
        string died = (yearDied == constants::YEAR_DIED_DEFAULT_VALUE) ? "Alive" : utils::intToString(yearDied);

        cout << setw(20) << std::left << scientists.at(i).getName()
             << setw(8) << std::left << scientistSex
             << setw(12) << std::left << scientists.at(i).getYearBorn()
             << setw(12) << std::left << died << endl;
    }
}


//-------------------------------------------------------------------------------------
//------------------------------------ Computer ---------------------------------------
//-------------------------------------------------------------------------------------

void ConsoleUI::displayComputer()
{
    switch (lastCommand)
    {
        case command::menu:
            displayComputerMenu();
            break;
        case command::add:
            displayAddScientistMenu();
            break;
        case command::display:
            displayAllScientists();
            break;
        case command::search:
            displayScientistSearchMenu();
            break;
        case command::sort:
            displayScientistSortMenu();
            break;
        default:
            displayUnknownCommandMenu();
            break;
    }
}

void ConsoleUI::readInputComputer()
{
    if (lastCommand == command::display)
    {
        lastCommand = command::sort;
        return;
    }

    string userInput;
    getline(cin, userInput);

    cout << "\n\n";

    bool shouldTreatInputAsCommand = (lastCommand != command::search);

    if (userInput == "display" && shouldTreatInputAsCommand)
    {
        lastCommand = command::sort;
    }
    else if (userInput == "add" && shouldTreatInputAsCommand)
    {
        lastCommand = command::add;
    }
    else if (userInput == "search" && shouldTreatInputAsCommand)
    {
        lastCommand = command::search;
    }
    else if (userInput == "back")
    {
        lastCommand = command::menu;
    }
    else if (userInput == "quit")
    {
        lastCommand = command::quit;
    }
    else
    {
        if (lastCommand == command::add)
        {
            addComputerCommandHandler(userInput);
        }
        else if (lastCommand == command::sort)
        {
            sortComputerCommandHandler(userInput);
        }
        else if (lastCommand == command::search)
        {
            searchComputerCommandHandler(userInput);
        }
        else
        {
            lastCommand = command::unknown;
        }
    }
}

void ConsoleUI::addComputerCommandHandler(string userInput)
{
    if (addComputer(userInput)) {
        cout << "Successfully added a computer\n\n";
        lastCommand = command::menu;
    }
    else
    {
        displayError("There was an error in your input.");
    }
}

void ConsoleUI::sortComputerCommandHandler(string userInput)
{
    if (setComputerSort(userInput))
    {
        lastCommand = command::display;
    }
    else
    {
        displayError("Your input did not match any of the sort commands");
    }
}

void ConsoleUI::searchComputerCommandHandler(string userInput)
{
    displayComputers(computerService.searchForComputers(userInput));
}

bool ConsoleUI::addComputer(string data)
{
    vector<string> fields = utils::splitString(data, ',');

    if (fields.size() > 2 && fields.size() < 5)
    {
        string name = fields.at(0);

        int yearInvented = utils::stringToInt(fields.at(1));

        enum computerType type;
        if (fields.at(2) == "Mechanical")
        {
            type = computerType::Mechanical;
        }
        else if (fields.at(2) == "Electronic")
        {
            type = computerType::Electronic;
        }
        else if(fields.at(2) == "Transitor")
        {
            type = computerType::Transitor;
        }

        string wasBuilt = fields.at(3);

        return computerService.addComputer(Computer(name, yearInvented, type, wasBuilt));
    }

    return false;
}

bool ConsoleUI::setComputerSort(string sortCommand)
{
    if (sortCommand == constants::SORT_COMPUTER_NAME_ASCENDING)
    {
        sortBy = "name";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_NAME_DESCENDING)
    {
        sortBy = "name";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_COMPUTER_YEAR_INVENTED_ASCENDING)
    {
        sortBy = "inv";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_YEAR_INVENTED_DESCENDING)
    {
        sortBy = "inv";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_COMPUTER_TYPE_ASCENDING)
    {
        sortBy = "type";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_TYPE_DESCENDING)
    {
        sortBy = "type";
        sortAscending = false;
    }
    else
    {
        return false;
    }

    return true;
}

void ConsoleUI::displayComputerMenu()
{
    cout << "Enter a command:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "add:" << "Adds a computer\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "display:" << "Displays computers\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "search:" << "Search for a computer\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "quit:" << "Quits the program\n\n";

    cout << "Command: ";
}

void ConsoleUI::displayAddComputerMenu()
{
    cout << "To add a computer, type in:\n";
    cout << "Name,yearInvented,type,wasBuilt\n";
    cout << "Comma separated like in the example above.\n\n";
    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displayAllComputers()
{
    vector<Computer> computer = computerService.getAllComputers(sortBy, sortAscending);

    displayComputers(computer);

    cout << '\n';

    lastCommand = command::display;
}

void ConsoleUI::displayComputerSearchMenu()
{
    cout << "Search for a computer.\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displayComputerSortMenu()
{
    cout << "How should the list be sorted:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_NAME_ASCENDING << "Sorts by name, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_NAME_DESCENDING << "Sorts by name, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_YEAR_INVENTED_ASCENDING << "Sorts by year invented, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_YEAR_INVENTED_DESCENDING << "Sorts by year invented, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_TYPE_ASCENDING << "Sorts by type, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_TYPE_DESCENDING << "Sorts by type, descending.\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";

    cout << "Command: ";
}

void ConsoleUI::displayComputers(std::vector<Computer> computers)
{
    if (computers.size() == 0)
    {
        cout << "No computer found.\n";
        return;
    }

    cout << "Printing all computers:\n";

    cout << setw(20) << std::left << "Name:"
         << setw(8) << std::left << "Type:"
         << setw(12) << std::left << "Year Invented:"
         << setw(12) << std::left << "Was it built:" << endl;

    for (unsigned int i = 0; i < computers.size(); i++)
    {
        cout << setw(20) << std::left << computers.at(i).getName()
             << setw(8) << std::left << computers.at(i).getType()
             << setw(12) << std::left << computers.at(i).getYearInvented()
             << setw(12) << std::left << computers.at(i).getWasBuilt() << endl;
    }
}


//-------------------------------------------------------------------------------------
//------------------------------------ Various ---------------------------------------
//-------------------------------------------------------------------------------------

void ConsoleUI::displayUnknownCommandMenu()
{
    displayError("Unknown command");
    cout << "Command: ";
}

void ConsoleUI::displayError(string error)
{
    cout << "There was an error: " << error << "\n";
    cout << "Please try again or type 'back' to go back.\n\n";
}
