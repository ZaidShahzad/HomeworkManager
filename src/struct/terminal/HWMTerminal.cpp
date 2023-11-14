#include "HWMTerminal.h"
#include <iostream>

HWMTerminal::HWMTerminal(ProjectInfo* projectInfo) {
    this->projectInfo = projectInfo;
    this->currentPage = MAIN_MENU;
}

// This will return the page the user is on
Page HWMTerminal::getCurrentPage() {
    return this->currentPage;
}

// This will allow you to set the page the user is on
Page HWMTerminal::setCurrentPage(Page page) {
    this->currentPage = page;
}

// This function will get a response from the user and return a vector as the user's response
// EX: If the user typed "create Biology", it will return a vector like ["create", "Biology"]
std::vector<std::string> HWMTerminal::getResponseFromUser() {

    std::string response;
    std::vector<std::string> args;
    std::getline(std::cin, response);

    std::string word = "";
    for(int i = 0; i < response.size(); i++) {
        if(response[i] == ' ') {
            args.push_back(word);
            word = "";
        }
        else {
            word += response[i];
        }
    }

    if(word != "") args.push_back(word);

    return args;
}

// This function will print the main menu (first page you land on when program starts)
void HWMTerminal::printMainMenu() {
    std::cout << "\n";
    std::cout << "-*- Homework Manager (" << this->projectInfo->getVersion() << ") | Main Page -*-\n";
    std::cout << "\n";
    std::cout << "Your Courses\n";
    std::cout << "  * No courses found :(\n";
    std::cout << "\n";
    std::cout << "Create or Delete Course:\n";
    std::cout << "  * Enter '/createcourse <className>'          Create a course\n";
    std::cout << "  * Enter '/deletecourse <className>'          Delete a Course\n";
    std::cout << "\n";
    std::cout << "View Assignments\n";
    std::cout << " * Enter '/today'                              View what assignments are due today\n";
    std::cout << " * Enter '/all'                                View assignments of all courses\n";
    std::cout << " * Enter '/view <courseName>'                  View assignments of a specific course\n";
    std::cout << "\n";
    std::cout << "ACTION: Please type in a command to continue.\n";
    std::cout << "\n";
    std::cout << "";
}

// This function will print the page where it will show all assignments that are due today
void HWMTerminal::printDueTodayAssignmentsPage() {

}

// This function will print the page where it will show all assignments
void HWMTerminal::printAllAssignmentsPage() {

}

// This function will print the page where it will show all assignments for a specific course
void HWMTerminal::printViewCourseAssignmentsPage(std::string courseName) {

}


// This function goes to the Due Today Assignment page
void HWMTerminal::gotoDueTodayAssignmentsPage() {
    this->setCurrentPage(DUE_TODAY_ASSIGNMENTS);
    this->printDueTodayAssignmentsPage();
}

// This function goes to the All Assignments Page
void HWMTerminal::gotoAllAssignmentsPage() {
    this->setCurrentPage(ALL_ASSIGNMENTS);
    this->printAllAssignmentsPage();
}

// This function goes to the Course Assignments Page
void HWMTerminal::gotoViewCourseAssignmentsPage(std::string courseName) {
    this->setCurrentPage(VIEW_COURSE_ASSIGNMENTS);
    this->printViewCourseAssignmentsPage(courseName);
}

// This function will send the user to the Main Menu and wait for a response. When the response is given,
// it will do the necessary actions depending on the response.
void HWMTerminal::gotoMainMenu() {
    this->setCurrentPage(MAIN_MENU);
    this->printMainMenu();

    std::vector<std::string> userInput = getResponseFromUser();

    std::string command = userInput[0];

    // Handle commands
    if(command == "/createcourse") {
        std::string className = userInput[1];
        // Handle creation of class
    }
    else if(command == "/deletecourse") {
        std::string className = userInput[1];
        // Handle deletion of class
    }
    else if(command == "/today") {
       this->gotoDueTodayAssignmentsPage();
    }
    else if(command == "/all") {
        this->gotoAllAssignmentsPage();
    }
    else if(command == "/view") {
        std::string className = userInput[1];
        this->gotoViewCourseAssignmentsPage(className);
    }
}