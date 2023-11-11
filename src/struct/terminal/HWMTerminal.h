#ifndef HOMEWORKMANAGER_HWMTERMINAL_H
#define HOMEWORKMANAGER_HWMTERMINAL_H

#include "../ProjectInfo/ProjectInfo.h"

/*
 *
 * This class is meant to handle everything related to the terminal
 *
 */

enum Page {
    MAIN_MENU
};

class HWMTerminal {

private:
    Page currentPage;
    ProjectInfo* projectInfo;

public:
    HWMTerminal(ProjectInfo* projectInfo);

    void printMainPage();

    void gotoMainMenu();

    std::vector<std::string> getResponseFromUser();

    Page getCurrentPage();
    Page setCurrentPage(Page page);


};

#endif
