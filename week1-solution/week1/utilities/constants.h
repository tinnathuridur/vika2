#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <Qstring>

/**
 * This file contains constants that this application uses
 */

namespace constants {
    const std::string DATA_FILE_NAME = "database.txt";
    const QString CONNECTION_NAME = "connection";
    const char FILE_DELIMETER = '\t';
    const int YEAR_DIED_DEFAULT_VALUE = 13337;

    const unsigned int MENU_COMMAND_WIDTH = 15;

    const std::string SORT_SCIENTIST_NAME_ASCENDING = "name-asc";
    const std::string SORT_SCIENTIST_NAME_DESCENDING = "name-desc";
    const std::string SORT_COMPUTER_NAME_ASCENDING = "name-asc";
    const std::string SORT_COMPUTER_NAME_DESCENDING = "name-desc";
    const std::string SORT_SCIENTIST_YEAR_BORN_ASCENDING = "born-asc";
    const std::string SORT_SCIENTIST_YEAR_BORN_DESCENDING = "born-desc";
    const std::string SORT_SCIENTIST_YEAR_DIED_ASCENDING = "died-asc";
    const std::string SORT_SCIENTIST_YEAR_DIED_DESCENDING = "died-desc";
    const std::string SORT_COMPUTER_YEAR_BUILT_ASCENDING = "built-asc";
    const std::string SORT_COMPUTER_YEAR_BUILT_DESCENDING = "built-desc";
    const std::string SORT_COMPUTER_YEAR_INVENTED_ASCENDING = "inv-asc";
    const std::string SORT_COMPUTER_YEAR_INVENTED_DESCENDING = "inv-desc";
    const std::string SORT_COMPUTER_TYPE_ASCENDING = "type_asc";
    const std::string SORT_COMPUTER_TYPE_DESCENDING = "type_desc";
}

#endif // CONSTANTS_H

