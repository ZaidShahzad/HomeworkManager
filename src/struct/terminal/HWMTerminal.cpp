#include "HWMTerminal.h"
#include <iostream>
#include <algorithm>
#include "../utils/Utils.h"
#include <cstdlib>
#include <sstream>
#include <iomanip>

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
        std::cout << "     * " << course->getCourseName() << "\n";
    }
}

// This function will print the main menu (first page you land on when program starts)
void HWMTerminal::printMainMenu() {
    std::cout << "\n";
    std::cout << termcolor::bright_green << "-*- Homework Manager (" << termcolor::bright_white << projectInfo.getVersion() << termcolor::bright_green << ") | Main Page -*-\n" << termcolor::reset;
    std::cout << "\n";

    std::cout << termcolor::bright_green << "    Courses:\n" << termcolor::reset << termcolor::bright_cyan;
    if(handler.getCourses().empty()) {
        // Make the text colored red below
        std::cout << termcolor::red << "     * No courses found :(\n" << termcolor::reset;
    }
    else {
        this->printCourses();
    }
    std::cout << "\n";
    std::cout << termcolor::bright_green << "    Commands:\n" << termcolor::reset;
    std::cout << "     - " << termcolor::bright_white << "/cc <course name>" << termcolor::reset << " - Create a course\n";
    std::cout << "     - " << termcolor::bright_white << "/dc <course name>" << termcolor::reset << " - Delete a course\n";
    std::cout << "     - " << termcolor::bright_white << "/ca <course name> <assignment name> <priority level (1-5)> <due date (mm-dd-yyyy)>" << termcolor::reset << " - Create an assignment\n";
    std::cout << "     - " << termcolor::bright_white << "/d <assignment ID>" << termcolor::reset << " - Delete an assignment\n";
    std::cout << "     - " << termcolor::bright_white << "/cm <assignment ID>" << termcolor::reset << " - Complete an assignment\n";
    std::cout << "     - " << termcolor::bright_white << "/sa <query>" << termcolor::reset << " - Search for an assignment\n";
    std::cout << "     - " << termcolor::bright_white << "/sh <query>" << termcolor::reset << " - Search for an assignment in history\n";
    std::cout << "     - " << termcolor::bright_white << "/history" << termcolor::reset << " - View completed assignments history\n";
    std::cout << "     - " << termcolor::bright_white << "/today" << termcolor::reset << " - View assignments due today\n";
    std::cout << "     - " << termcolor::bright_white << "/all" << termcolor::reset << " - View all assignments\n";
    std::cout << "     - " << termcolor::bright_white << "/view <course name>" << termcolor::reset << " - View assignments for a course\n";
    std::cout << "     - " << termcolor::bright_white << "/todolist" << termcolor::reset << " - View auto todo list\n";
    std::cout << "\n";
    std::cout << termcolor::bright_green << "    <- " << termcolor::reset <<  termcolor::bright_white << "/generate <# of courses> <# of assignments in courses>" << termcolor::reset << termcolor::bright_green << " - Generate assignments & courses to test benchmarking\n" << termcolor::reset;
    std::cout << termcolor::bright_green << "    <- " << termcolor::reset <<  termcolor::bright_white << "/main" << termcolor::reset << termcolor::bright_green << " - Go back to main menu\n" << termcolor::reset;
    std::cout << "\n";
}

// This function will print the page where it will show all assignments that are due today
void HWMTerminal::printDueTodayAssignmentsPage() {
    std::cout << "\n";
    std::cout << termcolor::bright_green << "-*- Homework Manager (" << termcolor::bright_white << projectInfo.getVersion() << termcolor::bright_green << ") | Due Today -*-\n" << termcolor::reset;
    std::cout << "\n";
    if(handler.getCourses().empty()) {
        std::cout << termcolor::red << "    No courses found :(\n" << termcolor::reset;
        std::cout << "\n";
    }
    else {
        for(Course* course : handler.getCourses()) {
            std::cout << termcolor::bright_green << "    " << course->getCourseName() << "'s Assignments:\n" << termcolor::reset;
            if(course->getAssignments().empty()) {
                std::cout << "     * There are no assignments for this class :)\n";
            } else {
                for(const auto& assignment : course->getAssignments()) {
                    if(assignment->isDueToday()) {
                        std::cout << "     * " << termcolor::bright_white << assignment->getTitle() << termcolor::reset << "\n"
                                  << "       - Due Date: " << termcolor::bright_white << assignment->getFormattedDueDate() << " ("
                                  << assignment->getTimeLeft() << ")" << termcolor::reset << "\n"
                                  << "       - Priority Level: " << termcolor::bright_white << assignment->getPriorityLevel() << termcolor::reset <<"\n"
                                  << "       - Complete? (Run Command): " << termcolor::bright_white << "/cm " << termcolor::bright_white << assignment->getAssignmentID() << termcolor::reset <<"\n"
                                  << "       - Delete? (Run Command): " << termcolor::bright_white << "/d " << assignment->getAssignmentID() << termcolor::reset <<"\n";
                    }
                }
            }
            std::cout << "\n";
        }
    }
    std::cout << termcolor::bright_green << "    <- " << termcolor::reset <<  termcolor::bright_white << "/main" << termcolor::reset << termcolor::bright_green << " - Go back to main menu\n" << termcolor::reset;
    std::cout << "\n";

}

// This function will print the page where it will show all assignments
void HWMTerminal::printAllAssignmentsPage() {
    std::cout << "\n";
    std::cout << termcolor::bright_green << "-*- Homework Manager (" << termcolor::bright_white << projectInfo.getVersion() << termcolor::bright_green << ") | All Assignments -*-\n" << termcolor::reset;
    std::cout << "\n";
    if(handler.getCourses().empty()) {
        std::cout << termcolor::red << "    No courses found :(\n" << termcolor::reset;
        std::cout << "\n";
    }
    else {
        for(Course* course : handler.getCourses()) {
            std::cout << termcolor::bright_green << "    " << course->getCourseName() << "'s Assignments:\n" << termcolor::reset;
            if(course->getAssignments().empty()) {
                std::cout << "     * There are no assignments for this class :)\n";
            } else {
                for(const auto& assignment : course->getAssignments()) {
                    std::cout << "     * " << termcolor::bright_white << assignment->getTitle() << termcolor::reset << "\n"
                              << "       - Due Date: " << termcolor::bright_white << assignment->getFormattedDueDate() << " ("
                              << assignment->getTimeLeft() << ")" << termcolor::reset << "\n"
                              << "       - Priority Level: " << termcolor::bright_white << assignment->getPriorityLevel() << termcolor::reset <<"\n"
                              << "       - Complete? (Run Command): " << termcolor::bright_white << "/cm " << termcolor::bright_white << assignment->getAssignmentID() << termcolor::reset <<"\n"
                              << "       - Delete? (Run Command): " << termcolor::bright_white << "/d " << assignment->getAssignmentID() << termcolor::reset <<"\n";
                }
            }
            std::cout << "\n";
        }
    }
    std::cout << termcolor::bright_green << "    <- " << termcolor::reset <<  termcolor::bright_white << "/main" << termcolor::reset << termcolor::bright_green << " - Go back to main menu\n" << termcolor::reset;
    std::cout << "\n";
}

// This function will print the page where it will show all assignments for a specific course
void HWMTerminal::printViewCourseAssignmentsPage(std::string courseName) {
    std::cout << "\n";
    courseName[0] = std::toupper(courseName[0]);
    std::cout << termcolor::bright_green << "-*- Homework Manager (" << termcolor::bright_white << projectInfo.getVersion() << termcolor::bright_green << ") | " << courseName << "'s Assignments -*-\n" << termcolor::reset;
    std::cout << "\n";
    if(handler.getCourses().empty()) {
        std::cout << "  * No courses found :(\n";
        std::cout << "\n";
    }
    else {
        Course* course = handler.findCourseByName(courseName);
        std::cout << termcolor::bright_green << "    " << course->getCourseName() << "'s Assignments:\n" << termcolor::reset;
        if(course->getAssignments().empty()) {
            std::cout << "     * There are no assignments for this class :)\n";
        } else {
            for(const auto& assignment : course->getAssignments()) {
                std::cout << "     * " << termcolor::bright_white << assignment->getTitle() << termcolor::reset << "\n"
                          << "       - Due Date: " << termcolor::bright_white << assignment->getFormattedDueDate() << " ("
                          << assignment->getTimeLeft() << ")" << termcolor::reset << "\n"
                          << "       - Priority Level: " << termcolor::bright_white << assignment->getPriorityLevel() << termcolor::reset <<"\n"
                          << "       - Complete? (Run Command): " << termcolor::bright_white << "/cm " << termcolor::bright_white << assignment->getAssignmentID() << termcolor::reset <<"\n"
                          << "       - Delete? (Run Command): " << termcolor::bright_white << "/d " << assignment->getAssignmentID() << termcolor::reset <<"\n";
            }
        }
        std::cout << "\n";
    }
    std::cout << termcolor::bright_green << "    <- " << termcolor::reset <<  termcolor::bright_white << "/main" << termcolor::reset << termcolor::bright_green << " - Go back to main menu\n" << termcolor::reset;
    std::cout << "\n";
}

void HWMTerminal::printViewHistoryPage() {
    std::cout << "\n";
    std::cout << termcolor::bright_green << "-*- Homework Manager (" << termcolor::bright_white << projectInfo.getVersion() << termcolor::bright_green << ") | Completed Assignments History -*-\n" << termcolor::reset;
    std::cout << "\n";
    std::cout << termcolor::bright_green << "    Completed Assignments:\n" << termcolor::reset;
    if(handler.getCompletedAssignmentsHistory().empty()) {
        std::cout << termcolor::red << "     * No completed assignments found :(\n" << termcolor::reset;
    }
    else {
        for(Assignment* assignment : handler.getCompletedAssignmentsHistory()) {
            std::cout << "     * " << termcolor::bright_white << assignment->getTitle() << termcolor::reset << "\n"
                      << "       - Class: " << termcolor::bright_white << assignment->getParentCourseName() << termcolor::reset << "\n"
                      << "       - Due Date: " << termcolor::bright_white <<assignment->getFormattedDueDate() << termcolor::reset <<"\n";
        }
    }
    std::cout << "\n";
    std::cout << termcolor::bright_green << "    <- " << termcolor::reset <<  termcolor::bright_white << "/main" << termcolor::reset << termcolor::bright_green << " - Go back to main menu\n" << termcolor::reset;
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
        case VIEW_HISTORY:
            this->gotoViewHistoryPage();
            break;
        default:
            this->gotoMainMenu();
    }
}

void HWMTerminal::gotoViewHistoryPage() {
    this->clearTerminal();
    this->setCurrentPage(VIEW_HISTORY);
    this->printViewHistoryPage();
    this->handleCommands();
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
        std::cerr << "That course does not exist!\n";
        this->gotoMainMenu();
        return;
    }

    this->setCurrentPage(VIEW_COURSE_ASSIGNMENTS);
    this->setCourseNameFromViewCoursePage(courseName);
    this->printViewCourseAssignmentsPage(courseName);
    this->handleCommands();
}

void HWMTerminal::printSearchAssignmentsPage(std::string query) {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "\n";
    std::cout << termcolor::bright_green << "-*- Homework Manager (" << termcolor::bright_white << projectInfo.getVersion() << termcolor::bright_green << ") | Search Assignments -*-\n" << termcolor::reset;
    std::cout << "\n";
    std::vector<Assignment*> assignmentsFound = handler.findAssignmentsByPattern(query);
    if(assignmentsFound.empty()) {
        std::cout << termcolor::red << "    No Assignments found with the query '" << termcolor::reset << query << termcolor::red <<"':\n" << termcolor::reset;
    }
    else {
        std::cout << termcolor::bright_green << "    Assignments found with the query '" << termcolor::reset << query << termcolor::bright_green <<"':\n" << termcolor::reset;
        for(Assignment* assignment : assignmentsFound) {
            std::cout << "     * " << termcolor::bright_white << assignment->getTitle() << termcolor::reset << "\n"
                      << "       - Due Date: " << termcolor::bright_white << assignment->getFormattedDueDate() << " ("
                      << assignment->getTimeLeft() << ")" << termcolor::reset << "\n"
                      << "       - Priority Level: " << termcolor::bright_white << assignment->getPriorityLevel() << termcolor::reset <<"\n"
                      << "       - Complete? (Run Command): " << termcolor::bright_white << "/cm " << termcolor::bright_white << assignment->getAssignmentID() << termcolor::reset <<"\n"
                      << "       - Delete? (Run Command): " << termcolor::bright_white << "/d " << assignment->getAssignmentID() << termcolor::reset <<"\n";
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "\n";
    std::cout << termcolor::bright_green << "    Time taken to search: " << termcolor::reset << termcolor::bright_white << duration << "ms" << termcolor::reset << "\n";
    std::cout << termcolor::bright_green << "    <- " << termcolor::reset <<  termcolor::bright_white << "/main" << termcolor::reset << termcolor::bright_green << " - Go back to main menu\n" << termcolor::reset;
    std::cout << "\n";
}

void HWMTerminal::gotoSearchAssignmentsPage(std::string query) {
    this->clearTerminal();
    this->setCurrentPage(SEARCH_ASSIGNMENTS);
    this->printSearchAssignmentsPage(query);
    this->handleCommands();
}

void HWMTerminal::printSearchHistoryPage(std::string query) {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "\n";
    std::cout << termcolor::bright_green << "-*- Homework Manager (" << termcolor::bright_white << projectInfo.getVersion() << termcolor::bright_green << ") | Search History  -*-\n" << termcolor::reset;
    std::cout << "\n";
    std::vector<Assignment*> assignmentsFound = handler.findAssignmentsInHistoryByPattern(query);
    if(assignmentsFound.empty()) {
        std::cout << termcolor::red << "    No Assignments found with the query '" << termcolor::reset << query << termcolor::red <<"':\n" << termcolor::reset;
    }
    else {
        std::cout << termcolor::bright_green << "    Assignments found with the query '" << termcolor::reset << query << termcolor::bright_green <<"':\n" << termcolor::reset;
        for(Assignment* assignment : assignmentsFound) {
            std::cout << "     * " << termcolor::bright_white << assignment->getTitle() << termcolor::reset << "\n"
                      << "       - Class: " << termcolor::bright_white << assignment->getParentCourseName() << termcolor::reset << "\n"
                      << "       - Due Date: " << termcolor::bright_white <<assignment->getFormattedDueDate() << termcolor::reset <<"\n";
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "\n";
    std::cout << termcolor::bright_green << "    Time taken to search: " << termcolor::reset << termcolor::bright_white << duration << "ms" << termcolor::reset << "\n";
    std::cout << termcolor::bright_green << "    <- " << termcolor::reset <<  termcolor::bright_white << "/main" << termcolor::reset << termcolor::bright_green << " - Go back to main menu\n" << termcolor::reset;
    std::cout << "\n";
}

void HWMTerminal::gotoSearchHistoryPage(std::string query) {
    this->clearTerminal();
    this->setCurrentPage(SEARCH_HISTORY);
    this->printSearchHistoryPage(query);
    this->handleCommands();
}

void HWMTerminal::gotoAutoTodoList() {
    int userDaysInput;
    std::cout << "How many days in advance do you wish to start your work? [Enter a number]: ";
    std::cin >> userDaysInput;

    // Getting all assignments in order to calculate the priority of each one
    std::vector<Assignment*> assignments = handler.getAllAssignments();
    std::vector<std::pair<Assignment*, double>> filteredAssignments;

    for (auto* assignment : assignments) {

        int daysUntilDue = assignment->getDaysLeft();
        int priorityLevel = assignment->getPriorityLevel();

        double orderValue = static_cast<double>(daysUntilDue) / priorityLevel;

        if (orderValue <= userDaysInput) {
            filteredAssignments.push_back(std::make_pair(assignment, orderValue));
        }
    }

    // Sorting the assignments based on the priority of each one
    std::sort(filteredAssignments.begin(), filteredAssignments.end(),
              [](const std::pair<Assignment*, double>& a, const std::pair<Assignment*, double>& b) {
                  return a.second < b.second;
              });

    // Displaying the sorted assignments (Ordered by Priority)
    std::cout << termcolor::yellow << termcolor::bold << "Assignments to do (Ordered by Priority):" << std::endl;
    for (const auto& pair : filteredAssignments) {
        std::cout << termcolor::yellow << termcolor::bold << " * " << pair.first->getTitle() << std::endl;
    }
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
            std::cout << termcolor::bright_green << "You have created the course '" << termcolor::reset << className << termcolor::bright_green <<"'.\n" << termcolor::reset;
            handler.saveData();
        }
        else {
            std::cerr << "Unfortunately, that course could not be created!\n";
        }
        this->refreshPage();
    }
    else if(args == 2 && command == "/dc") {
        std::string className = userInput[1];
        bool courseDeleted = handler.deleteCourse(className);

        if(courseDeleted) {
            std::cout << termcolor::red << "You have deleted the course '" << termcolor::reset << className << termcolor::red <<"'.\n" << termcolor::reset;
            handler.saveData();
        }
        else {
            std::cerr << "Unfortunately, that course could not be deleted!\n";
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
        courseName[0] = ::toupper(courseName[0]);

        bool assignmentCreated = handler.createAssignment(courseName, assignmentName, priorityLevel,dueDate);
        if(assignmentCreated) {
            Assignment* assignment = handler.findAssignmentByID(courseName + "-" + assignmentName);
            std::cout << termcolor::bright_green << "You have created the assignment '" << termcolor::reset << assignment->getTitle() << termcolor::bright_green <<"'.\n" << termcolor::reset
                      << " - Due Date: " << termcolor::bright_white << assignment->getFormattedDueDate() << " ("
                      << assignment->getTimeLeft() << ")" << termcolor::reset << "\n"
                      << " - Priority Level: " << termcolor::bright_white << assignment->getPriorityLevel() << termcolor::reset <<"\n"
                      << " - Complete? (Run Command): " << termcolor::bright_white << "/cm " << termcolor::bright_white << assignment->getAssignmentID() << termcolor::reset <<"\n"
                      << " - Delete? (Run Command): " << termcolor::bright_white << "/d " << assignment->getAssignmentID() << termcolor::reset <<"\n";
            handler.saveData();
        }
        else {
            std::cerr << "Unfortunately, the assignment could not be created!\n";
        }
        this->refreshPage();
    }
    else if(args == 2 && command == "/d") {
        std::string assignmentID = userInput[1];
        bool assignmentDeleted = handler.deleteAssignment(assignmentID);

        if(assignmentDeleted) {
            std::cout << termcolor::red << "You have deleted the assignment with the ID '" << termcolor::reset << assignmentID << termcolor::red <<"'.\n" << termcolor::reset;
            handler.saveData();
        }
        else {
            std::cerr << "Unfortunately, that assignment could not be deleted!\n";
        }
        this->refreshPage();
    }
    else if(args == 2 && command == "/cm") {
        std::string assignmentID = userInput[1];
        bool completedAssignment = handler.completeAssignment(assignmentID);

        if(completedAssignment) {
            std::cout << termcolor::bright_green << "You have completed the assignment with the ID '" << termcolor::reset << assignmentID << termcolor::bright_green <<"', GOOD JOB!\n" << termcolor::reset;
            handler.saveData();
        }
        else {
            std::cerr << "Unfortunately, that assignment could not be completed!\n";
        }
        this->refreshPage();
    }
    else if(args == 2 && command == "/sa") {
        std::string query = userInput[1];
        this->gotoSearchAssignmentsPage(query);
    }
    else if(args == 2 && command == "/sh") {
        std::string query = userInput[1];
        this->gotoSearchHistoryPage(query);
    }
    else if(args == 1 && command == "/history") {
        this->gotoViewHistoryPage();
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
    else if(args == 3 && command == "/generate") {
        int numberOfCourses = 0;
        int numberOfAssignments = 0;
        try {
            numberOfCourses = std::stoi(userInput[1]);
            numberOfAssignments = std::stoi(userInput[2]);
        }
        catch (std::invalid_argument exception) {
            std::cerr << "Your number of courses or assignments was invalid.\n";
            this->refreshPage();
            return;
        }
        handler.generateAssignments(numberOfCourses, numberOfAssignments);
        std::cout << termcolor::bright_green << "Generated " << numberOfCourses << " courses with " << numberOfAssignments << " assignments each.\n" << termcolor::reset;
        this->refreshPage();
    }
    else if(args == 1 && command == "/todolist") {
        this->gotoAutoTodoList();
    }
    else if(args == 1 && command == "/main") {
        this->gotoMainMenu();
    }
    // Invalid args check
    else {
        std::cerr << "Invalid Args, you have typed a command incorrectly.\n";
        this->refreshPage();
        return;
    }
}
