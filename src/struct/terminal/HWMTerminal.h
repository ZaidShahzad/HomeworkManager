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
    VIEW_HISTORY,
    SEARCH_ASSIGNMENTS,
    SEARCH_HISTORY,
    AUTO_TODO_LIST
};

class HWMTerminal {

private:
    Page currentPage;
    std::string courseNameFromViewCoursePage;

public:
    HWMTerminal();

    void printMainMenu();
    void printDueTodayAssignmentsPage();
    void printAllAssignmentsPage();
    void printViewCourseAssignmentsPage(std::string courseName);
    void printCourses();
    void printAssignmentsForCourse(std::string courseName);
    void printViewHistoryPage();
    void printSearchAssignmentsPage(std::string query);
    void printSearchHistoryPage(std::string query);

    void gotoMainMenu();
    void gotoDueTodayAssignmentsPage();
    void gotoAllAssignmentsPage();
    void gotoViewCourseAssignmentsPage(std::string courseName);
    void gotoViewHistoryPage();
    void gotoAutoTodoList();
    void gotoSearchAssignmentsPage(std::string query);
    void gotoSearchHistoryPage(std::string query);
    void clearTerminal();
    void handleCommands();
    void refreshPage();


    std::vector<std::string> getResponseFromUser();

    Page getCurrentPage();
    void setCurrentPage(Page page);

    void setCourseNameFromViewCoursePage(std::string courseName);
    std::string getCourseNameFromViewCoursePage();


};

#endif