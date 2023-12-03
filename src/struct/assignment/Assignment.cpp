#include "Assignment.h"
#include <chrono>
#include <sstream>

Assignment::Assignment(std::string title, std::string parentCourse) {
    this->title = title;
    this->priorityLevel = 1;
    this->assignmentID = parentCourse + "-" + title;
}

Assignment::Assignment(Assignment* assignmentToCopyFrom) {
    this->title = assignmentToCopyFrom->title;
    this->parentCourseName = assignmentToCopyFrom->parentCourseName;
    this->priorityLevel = assignmentToCopyFrom->priorityLevel;
    this->assignmentID = assignmentToCopyFrom->assignmentID;
    this->dueDate = assignmentToCopyFrom->dueDate;
}

// Getter for title
std::string Assignment::getTitle() {
    return this->title;
}

// Setter for title
void Assignment::setTitle(std::string newTitle) {
    this->title = newTitle;
}

// Getter for priorityLevel
int Assignment::getPriorityLevel() {
    return this->priorityLevel;
}

void Assignment::setPriorityLevel(int priorityLevel) {
    this->priorityLevel = priorityLevel;
}

std::string Assignment::getFormattedDueDate() {
    return date::format("%m-%d-%Y", this->dueDate);
}

void Assignment::setDueDate(sys_days dueDate) {
    this->dueDate = dueDate;
}

std::string Assignment::getAssignmentID() {
    return this->assignmentID;
}

std::string Assignment::getParentCourseName() {
    return this->parentCourseName;
}
void Assignment::setParentCourseName(std::string parentCourseName) {
    this->parentCourseName = parentCourseName;
}

std::string Assignment::getTimeLeft() {
    auto now = system_clock::now();
    auto nowDays = floor<days>(now);
    auto daysDiff = dueDate - nowDays;
    daysDiff += days(1);
    std::stringstream timeLeftStream;
    if(daysDiff.count() == 0) {
        timeLeftStream << termcolor::bright_red << "Due Today" << termcolor::reset;
    } else if(daysDiff.count() > 5) {
        timeLeftStream << termcolor::bright_green << "Due in " << daysDiff.count() << " Days"<< termcolor::reset;
    }
    else if(daysDiff.count() > 2) {
        timeLeftStream << termcolor::yellow << "Due in " << daysDiff.count() << " Days" << termcolor::reset;
    }
    else {
        timeLeftStream << termcolor::red << "Overdue [" << daysDiff.count() * -1 << " Days Ago]" << termcolor::reset;
    }
    return timeLeftStream.str();
}

int Assignment::getDaysLeft() {
    auto now = system_clock::now();
    auto nowDays = floor<days>(now);
    auto daysDiff = dueDate - nowDays;
    daysDiff += days(1);
    return daysDiff.count();
}

bool Assignment::isDueToday() {
    return this->getTimeLeft() == "Due Today";
}

