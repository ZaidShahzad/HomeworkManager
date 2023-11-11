#include "HWMTerminal.h"
#include <iostream>

HWMTerminal::HWMTerminal(ProjectInfo* projectInfo) {
    this->projectInfo = projectInfo;
}

ProjectInfo *HWMTerminal::getProjectInfo() {
    return this->projectInfo;
}

void HWMTerminal::printMainPage() {
    std::cout << "\n";
    std::cout << "-*- Homework Manager (" << this->projectInfo->getVersion() << ") | Main Page -*-\n";
    std::cout << "\n";
    std::cout << "1) Create or Delete Class\n";
    std::cout << "\n";
    std::cout << "Tip: Type in a number corresponding to the command you want to fulfil.\n";
    std::cout << "";
}