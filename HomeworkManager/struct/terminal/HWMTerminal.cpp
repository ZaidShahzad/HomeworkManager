#include "HWMTerminal.h"
#include <iostream>

HWMTerminal::HWMTerminal(ProjectInfo* projectInfo) {
    this->projectInfo = projectInfo;
}

ProjectInfo *HWMTerminal::getProjectInfo() {
    return this->projectInfo;
}

void HWMTerminal::printMainPage() {
    std::cout << "-*- Homework Manager (" << this->projectInfo->getVersion() << ") -*-\n\n";
    std::cout << "1) Create or Delete Class\n";
}