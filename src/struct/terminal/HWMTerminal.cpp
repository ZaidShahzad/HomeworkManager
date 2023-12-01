#include "HWMTerminal.h"
#include <iostream>
#include <algorithm>
#include "../utils/Utils.h"
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <unistd.h>

ProjectHandler handler = Utils::getInstance()->getProjectHandler();
ProjectInfo projectInfo = Utils::getInstance()->getProjectHandler().getProjectInfo();

HWMTerminal::HWMTerminal() {
    this->currentPage = MAIN_MENU;
}

// This will return the page the user is on
Page HWMTerminal::getCurrentPage() {
    return this->currentPage;
}


// This will allow you to set the page the user is on
void HWMTerminal::setCurrentPage(Page page) {
    this->currentPage = page;
}

void HWMTerminal::setCourseNameFromViewCoursePage(std::string courseName) {
    this->courseNameFromViewCoursePage = courseName;
}

std::string HWMTerminal::getCourseNameFromViewCoursePage() {
    return this->courseNameFromViewCoursePage;
}

void HWMTerminal::clearTerminal() {
//#ifdef _WIN32
//    std::system("cls"); // For Windows
//    usleep(10000);
//#else
//    std::system("clear"); // For Unix/Linux/MacOS
//    usleep(10000);
//#endif
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

void HWMTerminal::printCourses() {
    for(Course* course : handler.getCourses()) {
        std::cout << "  " << course->getCourseName() << "\n";
    }
}

void HWMTerminal::printAssignmentsForCourse(std::string courseName) {
    Course* courseFound = handler.findCourseByName(courseName);

    std::cout << courseFound->getCourseName() << "'s Assignments:\n";
    if(courseFound->getAssignments().empty()) {
        std::cout << " * There are no assignments for this class :)\n";
    } else {
        for(const auto& assignment : courseFound->getAssignments()) {
            std::cout << " * " << assignment->getTitle() << "\n"
                      << "   - Due Date: " << assignment->getFormattedDueDate() << " ("
                      << assignment->getTimeLeft() << ")\n"
                      << "   - Priority Level: " << assignment->getPriorityLevel() << "\n"
                      << "   - Delete?: Type /d " << assignment->getAssignmentID() << "\n";
        }
    }
    std::cout << "\n";
}
// This function will print the main menu (first page you land on when program starts)
void HWMTerminal::printMainMenu() {
    std::cout << "\n";
    std::cout << "-*- Homework Manager (" << projectInfo.getVersion() << ") | Main Page -*-\n";
    std::cout << "\n";
    std::cout << "Your Courses\n";
    if(handler.getCourses().empty()) {
        std::cout << "  * No courses found :(\n";
    }
    else {
        printCourses();
    }
    std::cout << "\n";
    std::cout << "Create or Delete Course:\n";
    std::cout << "  * /cc <className>                                                      Create a course\n";
    std::cout << "  * /dc <className>                                                      Delete a Course\n";
    std::cout << "\n";
    std::cout << "Create Assignment for Course:\n";
    std::cout << "  * /ca <className> <nameOfAssignment> <priorityLevel> <dueDate>        Add a assignment to a course\n";
    std::cout << "      - Due Date Example: 1-1-2023\n";
    std::cout << "      - Priority Level Example: 1 -> 5\n";
    std::cout << "\n";
    std::cout << "View Assignments\n";
    std::cout << " * /today                                                                View what assignments are due today\n";
    std::cout << " * /all                                                                  View assignments of all courses\n";
    std::cout << " * /view <className>                                                    View assignments of a specific course\n";
    std::cout << " * /todolist                                                             View Todo List\n";
    std::cout << "\n";
    std::cout << "ACTION: Please type in a command to continue.\n";
    std::cout << "\n";
}

// This function will print the page where it will show all assignments that are due today
void HWMTerminal::printDueTodayAssignmentsPage() {
    std::cout << "\n";
    std::cout << "-*- Homework Manager (" << projectInfo.getVersion() << ") | Due Today -*-\n";
    std::cout << "\n";
    std::cout << "There is nothing due today :)\n";
    std::cout << "\n";
    std::cout << "--> Enter '/main' to go back to main menu\n";
    std::cout << "\n";
}

// This function will print the page where it will show all assignments
void HWMTerminal::printAllAssignmentsPage() {
    std::cout << "\n";
    std::cout << "-*- Homework Manager (" << projectInfo.getVersion() << ") | All Assignments -*-\n";
    std::cout << "\n";
    if(handler.getCourses().empty()) {
        std::cout << "  * No courses found :(\n";
    }
    else {
        for(Course* course : handler.getCourses()) {
            printAssignmentsForCourse(course->getCourseName());
        }
    }
    std::cout << "--> Enter '/main' to go back to main menu\n";
    std::cout << "\n";
}

// This function will print the page where it will show all assignments for a specific course
void HWMTerminal::printViewCourseAssignmentsPage(std::string courseName) {
    Course* course = handler.findCourseByName(courseName);
    std::cout << "\n";
    std::cout << "-*- Homework Manager (" << projectInfo.getVersion() << ") | " << course->getCourseName() << "'s Assignments -*-\n";
    std::cout << "\n";
    this->printAssignmentsForCourse(courseName);
    std::cout << "--> Enter '/main' to go back to main menu\n";
    std::cout << "\n";
}

void HWMTerminal::refreshPage() {
    switch(this->getCurrentPage()) {
        case MAIN_MENU:
            this->gotoMainMenu();
            break;
        case ALL_ASSIGNMENTS:
            this->gotoAllAssignmentsPage();
            break;
        case DUE_TODAY_ASSIGNMENTS:
            this->gotoDueTodayAssignmentsPage();
            break;
        case AUTO_TODO_LIST:
            this->gotoAutoTodoList();
            break;
        case VIEW_COURSE_ASSIGNMENTS:
            this->gotoViewCourseAssignmentsPage(this->getCourseNameFromViewCoursePage());
            break;
    }
}


// This function goes to the Due Today assignment page
void HWMTerminal::gotoDueTodayAssignmentsPage() {
    this->clearTerminal();
    this->setCurrentPage(DUE_TODAY_ASSIGNMENTS);
    this->printDueTodayAssignmentsPage();
    this->handleCommands();
}

// This function goes to the All Assignments Page
void HWMTerminal::gotoAllAssignmentsPage() {
    this->clearTerminal();
    this->setCurrentPage(ALL_ASSIGNMENTS);
    this->printAllAssignmentsPage();
    this->handleCommands();
}

// This function goes to the Course Assignments Page
void HWMTerminal::gotoViewCourseAssignmentsPage(std::string courseName) {
    this->clearTerminal();
    if(!handler.courseExists(courseName)) {
        std::cout << "That course does not exist!\n";
        this->gotoMainMenu();
        return;
    }

    this->setCurrentPage(VIEW_COURSE_ASSIGNMENTS);
    this->setCourseNameFromViewCoursePage(courseName);
    this->printViewCourseAssignmentsPage(courseName);
    this->handleCommands();
}

///TODO -essam
void HWMTerminal::gotoAutoTodoList() {
    this->clearTerminal();
    this->setCurrentPage(AUTO_TODO_LIST);
    std::cout << "How many days in advance do you wish to start your work? [Enter a number]\n";

    return;
}

// This function will send the user to the Main Menu and wait for a response. When the response is given,
// it will do the necessary actions depending on the response.
void HWMTerminal::gotoMainMenu() {
    this->clearTerminal();
    this->setCurrentPage(MAIN_MENU);
    this->printMainMenu();
    this->handleCommands();
}

void HWMTerminal::handleCommands() {
    std::vector<std::string> userInput = getResponseFromUser();
    std::string command = userInput[0];
    int args = userInput.size();

    // Handle commands
    if(args == 2 && command == "/cc") {
        std::string className = userInput[1];
        bool courseCreated = handler.createCourse(className);

        if(courseCreated) {
            std::cout << "You have created the Course '" << className << "'.\n";
        }
        else {
            std::cout << "Unfortunately, that course could not be created!\n";
        }
        this->refreshPage();
    }
    else if(args == 2 && command == "/dc") {
        std::string className = userInput[1];
        bool courseDeleted = handler.deleteCourse(className);

        if(courseDeleted) {
            std::cout << "You have deleted the Course '" << className << "'.\n";
        }
        else {
            std::cout << "Unfortunately, that course could not be deleted!\n";
        }
        this->refreshPage();
    }
    else if(args == 5 && command == "/ca") {
        std::string assignmentName = userInput[2];
        int priorityLevel = 1;
        try {
            priorityLevel = std::stoi(userInput[3]);
        }
        catch (std::invalid_argument exception) {
            std::cout << "Your priority level was invalid. Defaulting to 1.\n";
        }
        if(priorityLevel < 1 || priorityLevel > 5) {
            std::cout << "Please make sure your priority level is between 1-5.\n";
            this->refreshPage();
            return;
        }
        std::string dueDate = userInput[4];

        std::string courseName = userInput[1];
        bool assignmentCreated = handler.createAssignment(courseName, assignmentName, priorityLevel,dueDate);
        if(assignmentCreated) {
            std::cout << "Created " << assignmentName << "! Now in " << courseName << " Course!\n";
            std::cout << " * Due Date: " << dueDate << std::endl;
            std::cout << " * Priority: " << priorityLevel << std::endl;
        }
        else {
            std::cout << "Unfortunately, the assignment could not be created!\n";
        }
        this->refreshPage();
    }
    else if(args == 1 && command == "/today") {
        this->gotoDueTodayAssignmentsPage();
    }
    else if(args == 1 && command == "/all") {
        this->gotoAllAssignmentsPage();
    }
    else if(args == 2 && command == "/view") {
        std::string className = userInput[1];
        this->gotoViewCourseAssignmentsPage(className);
    }
    else if(args == 1 && command == "/todolist") {
        this->gotoAutoTodoList();
    }
    else if(args == 1 && command == "/main") {
        this->gotoMainMenu();
    }
        // Invalid args check
    else {
        std::cout << "Invalid Args, you have typed a command incorrectly.\n";
        this->refreshPage();
        return;
    }
}
