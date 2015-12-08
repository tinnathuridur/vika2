#include "ui/consoleui.h"
#include "Database/database.h"

int main()
{
    ConsoleUI ui;

    Database oli;
    oli.connect();

    return ui.start();
    oli.disconnect();
}

