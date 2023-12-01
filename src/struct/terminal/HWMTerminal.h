#ifndef HOMEWORKMANAGER_HWMTERMINAL_H
#define HOMEWORKMANAGER_HWMTERMINAL_H

#include <iostream>
#include <vector>

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

public:
    HWMTerminal();

    void printMainMenu();
    void printDueTodayAssignmentsPage();
    void printAllAssignmentsPage();
    void printViewCourseAssignmentsPage(std::string courseName);
    void printCourses();
    void printAssignmentsForCourse(std::string courseName);

    void gotoMainMenu();
    void gotoDueTodayAssignmentsPage();
    void gotoAllAssignmentsPage();
    void gotoViewCourseAssignmentsPage(std::string courseName);
    void gotoAutoTodoList();
    void clearTerminal();


    std::vector<std::string> getResponseFromUser();

    Page getCurrentPage();
    void setCurrentPage(Page page);


};

#endif