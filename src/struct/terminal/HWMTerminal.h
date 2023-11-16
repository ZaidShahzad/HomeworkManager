#ifndef HOMEWORKMANAGER_HWMTERMINAL_H
#define HOMEWORKMANAGER_HWMTERMINAL_H

#include "../ProjectInfo/ProjectInfo.h"

/*
 *
 * This class is meant to handle everything related to the terminal
 *
 */

enum Page {
    MAIN_MENU,
    DUE_TODAY_ASSIGNMENTS,
    ALL_ASSIGNMENTS,
    VIEW_COURSE_ASSIGNMENTS,
    AUTO_TODO_LIST
};

class HWMTerminal {

private:
    Page currentPage;
    ProjectInfo* projectInfo;

public:
    HWMTerminal(ProjectInfo* projectInfo);

    void printMainMenu();
    void printDueTodayAssignmentsPage();
    void printAllAssignmentsPage();
    void printViewCourseAssignmentsPage(std::string courseName);

    void gotoMainMenu();
    void gotoDueTodayAssignmentsPage();
    void gotoAllAssignmentsPage();
    void gotoViewCourseAssignmentsPage(std::string courseName);
    void gotoAutoTodoList();


    std::vector<std::string> getResponseFromUser();

    Page getCurrentPage();
    Page setCurrentPage(Page page);


};

#endif
