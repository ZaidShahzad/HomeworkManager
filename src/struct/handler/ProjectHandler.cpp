#include "ProjectHandler.h"
#include "../course/Course.h"

ProjectHandler::ProjectHandler() {}

ProjectInfo ProjectHandler::getProjectInfo() {
    return this->projectInfo;
}

HWMTerminal ProjectHandler::getTerminal() {
    return this->terminal;
}

std::vector<Course*>& ProjectHandler::getCourses() {
    return this->courses;
}

// This function will check if a course exists (if does, returns true, if not, returns false)
bool ProjectHandler::courseExists(std::string courseName) {
    for(Course* course : getCourses()) {
        if(course->getCourseName() == courseName) return true;
    }
    return false;
}

// This function creates a course. If it's done successfully, it returns true, if not, returns false
bool ProjectHandler::createCourse(std::string courseName) {
    if(courseExists(courseName)) return false;

    Course* course = new Course(courseName);
    this->getCourses().push_back(course);
    return true;
}