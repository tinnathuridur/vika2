#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "services/scientistservice.h"
#include "services/computerservice.h"

/**
 * @brief Holds commands that are available in the UI
 */
enum command {
    menu,
    add,
    display,
    search,
    sort,
    back,
    quit,
    unknown
};

class ConsoleUI
{
public:
    ConsoleUI();

    /**
     * @brief start is the main run loop for the application
     * @return should indicate how the program exists, currently always safely
     */
    int begin();

    int startScientist();
    int startComputer();


private:
    /**
     * @brief display serves as a router to according display functions
     */
    void displayScientist();
    void displayComputer();

    /**
     * @brief readInput handles user input by settings commands or processing it
     */
    void readInputScientist();
    void readInputComputer();

    void displayScientistMenu();
    void displayAddScientistMenu();
    void displayAllScientists();
    void displayScientistSearchMenu();
    void displayScientistSortMenu();
    void displayScientists(std::vector<Scientist> scientists);

    void displayComputerMenu();
    void displayAddComputerMenu();
    void displayAllComputers();
    void displayComputerSearchMenu();
    void displayComputerSortMenu();
    void displayComputers(std::vector<Computer> computers);

    void displayUnknownCommandMenu();


    /**
     * @brief addCommandHandler calls the addScientist function and notifies the user how it went
     * @param userInput the input the user is trying to create a scientist from
     */
    void addScientistCommandHandler(std::string userInput);
    void addComputerCommandHandler(std::string userInput);

    /**
     * @brief sortCommandHandler calls the setSort function and notifies the user how it went
     * @param userInput the input the user is trying to change sort from
     */
    void sortScientistCommandHandler(std::string userInput);
    void sortComputerCommandHandler(std::string userInput);

    /**
     * @brief searchCommandHandler calls the scientistService displays a list of filtered users
     * @param userInput a string sent as input to the search function
     */
    void searchScientistCommandHandler(std::string userInput);
    void searchComputerCommandHandler(std::string userInput);

    /**
     * @brief addScientist attempts to add a scientist
     * @param data A string containing the user input
     * @return true if it was a success, false if it was a failure
     */
    bool addScientist(std::string data);
    bool addComputer(std::string data);

    /**
     * @brief setSort attempts to change how scientists will be sorted based on userinput
     * @param sortCommand the sort rule, rules are stored in constants.h
     * @return true if it was a success, false if it was a failure
     */
    bool setScientistSort(std::string sortCommand);
    bool setComputerSort(std::string sortCommand);

    void displayError(std::string error);


    ScientistService scientistService;
    ComputerService computerService;

    enum command lastCommand;

    std::string sortBy;
    bool sortAscending;
};

#endif // CONSOLEUI_H
