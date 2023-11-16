#include <iostream>
#include "struct/utils/Utils.h"

Utils* Utils::INSTANCE = nullptr;

/* Driver Code */

int main() {
    ProjectHandler handler = Utils::getInstance()->getProjectHandler();
    handler.getTerminal().gotoMainMenu();
    return 0;
}
