#ifndef HOMEWORKMANAGER_HWMTERMINAL_H
#define HOMEWORKMANAGER_HWMTERMINAL_H

#include "../ProjectInfo/ProjectInfo.h"

/*
 * This class is meant to handle everything related to the terminal
 *
 */

class HWMTerminal {

private:
    ProjectInfo* projectInfo;

public:
    HWMTerminal(ProjectInfo* projectInfo);

    void printMainPage();
    ProjectInfo* getProjectInfo();

};

#endif
