#include "ProjectHandler.h"

ProjectHandler::ProjectHandler() {}

ProjectInfo ProjectHandler::getProjectInfo() {
    return this->projectInfo;
}

HWMTerminal ProjectHandler::getTerminal() {
    return this->terminal;
}

std::map<std::string, std::vector<Assignment *>> ProjectHandler::getCourses() {
    return this->courses;
}