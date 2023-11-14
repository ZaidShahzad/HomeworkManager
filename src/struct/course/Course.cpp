#include "course.h"

// getter for courseName
std::string Courses::getCoursName(){
    return this->courseName;
}

// setter for courseName
void Courses::setCourseName(std::string name) {
    this->courseName = name;
}

//getter for assignments
std::vector<std::string*> Courses::getAssignments() {
    return this->assignments;
}