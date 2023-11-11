#include <iostream>

#include "struct/handler/ProjectHandler.h"


/* Driver Code */

int main() {
    ProjectHandler* handler = new ProjectHandler();
    handler->getTerminal()->gotoMainMenu();
    return 0;
}
