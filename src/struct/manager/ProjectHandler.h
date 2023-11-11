#ifndef HOMEWORKMANAGER_PROJECTHANDLER_H
#define HOMEWORKMANAGER_PROJECTHANDLER_H

#include "../terminal/HWMTerminal.h"
#include "../ProjectInfo/ProjectInfo.h"


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
