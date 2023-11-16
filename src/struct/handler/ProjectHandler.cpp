#include "ProjectHandler.h"

ProjectHandler::ProjectHandler() {}

ProjectInfo ProjectHandler::getProjectInfo() {
    return this->projectInfo;
}

HWMTerminal ProjectHandler::getTerminal() {
    return this->terminal;
}