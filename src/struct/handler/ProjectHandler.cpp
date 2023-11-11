#include "ProjectHandler.h"

ProjectHandler::ProjectHandler() {
    this->projectInfo = new ProjectInfo();
    this->terminal = new HWMTerminal(this->projectInfo);
}

ProjectInfo* ProjectHandler::getProjectInfo() {
    return this->projectInfo;
}

HWMTerminal* ProjectHandler::getTerminal() {
    return this->terminal;
}