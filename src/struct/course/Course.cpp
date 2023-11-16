#include "Course.h"

Course::Course(std::string courseName) {
    this->courseName = courseName;
    this->assignments = {};
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
std::vector<Assignment*> Course::getAssignments() {
    return this->assignments;
}