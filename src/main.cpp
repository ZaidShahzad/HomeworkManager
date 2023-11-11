#include <iostream>

#include "struct/manager/ProjectHandler.h"


/* Driver Code */

int main() {

    ProjectHandler* handler = new ProjectHandler();
    handler->getTerminal()->printMainPage();


    return 0;
}
