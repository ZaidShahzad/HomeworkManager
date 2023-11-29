#include "Course.h"
#include "../utils/Utils.h"

Course::Course(std::string courseName) {
    this->courseName = courseName;
    this->assignments = {};
}

// Check if a assignment exists (by it's name)
bool Course::assignmentExists(std::string assignmentName) {
    for(Assignment* assignment : this->getAssignments()) {
        if(Utils::getInstance()->toLowerCase(assignment->getTitle()) == Utils::getInstance()->toLowerCase(assignmentName)) return true;
    }
    return false;
}

// getter for courseName
std::string Course::getCourseName(){
    return this->courseName;
}

// setter for courseName
void Course::setCourseName(std::string name) {
    this->courseName = name;
}

//getter for assignments
std::vector<Assignment*>& Course::getAssignments() {
    return this->assignments;
}