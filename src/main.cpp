#include <iostream>

#include "struct/handler/ProjectHandler.h"


/* Driver Code */

int main() {

    ProjectHandler* handler = new ProjectHandler();
    handler->getTerminal()->printMainPage();

    return 0;
}
