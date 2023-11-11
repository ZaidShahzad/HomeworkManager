#ifndef HOMEWORKMANAGER_PROJECTHANDLER_H
#define HOMEWORKMANAGER_PROJECTHANDLER_H

#include "../terminal/HWMTerminal.h"
#include "../ProjectInfo/ProjectInfo.h"


/*
 * This class will handle everything and anything related to the project
 *
 */
class ProjectHandler {

private:
    ProjectInfo* projectInfo;
    HWMTerminal* terminal;

public:
    ProjectHandler();
    ProjectInfo* getProjectInfo();
    HWMTerminal* getTerminal();

};


#endif
