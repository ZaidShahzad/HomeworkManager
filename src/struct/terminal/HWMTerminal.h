#ifndef HOMEWORKMANAGER_HWMTERMINAL_H
#define HOMEWORKMANAGER_HWMTERMINAL_H

#include "../ProjectInfo/ProjectInfo.h"

class HWMTerminal {

private:
    ProjectInfo* projectInfo;

public:

    HWMTerminal(ProjectInfo* projectInfo);
    void printMainPage();
    ProjectInfo* getProjectInfo();

};

#endif
