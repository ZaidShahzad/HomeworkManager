#include "ProjectHandler.h"
#include "../course/Course.h"

ProjectHandler::ProjectHandler() {}

ProjectInfo ProjectHandler::getProjectInfo() {
    return this->projectInfo;
}

std::string ProjectHandler::toLowerCase(std::string string) {
    for(int i = 0; i < string.length(); i++) {
        string[i] = tolower(string[i]);
    }
    return string;
}

HWMTerminal ProjectHandler::getTerminal() {
    return this->terminal;
}

std::vector<Course*>& ProjectHandler::getCourses() {
    return this->courses;
}

// This function will check if a course exists (if does, returns true, if not, returns false)
bool ProjectHandler::courseExists(std::string courseName) {
    for(Course* course : this->getCourses()) {
        if(toLowerCase(course->getCourseName()) == toLowerCase(courseName)) return true;
    }
    return false;
}

// This function will return a course if it's found by the name passed it, if not, it will return nullptr
Course *ProjectHandler::findCourseByName(std::string courseName) {
    for(Course* course : this->getCourses()) {
        if(toLowerCase(course->getCourseName()) == toLowerCase(courseName)) return course;
    }
    return nullptr;
}

// This function will return a course index if it's found by the name passed it, if not, it will return -1
int ProjectHandler::findCourseIndexInVectorByName(std::string courseName) {
    int index = 0;
    for(Course* course : this->getCourses()) {
        if(toLowerCase(course->getCourseName()) == toLowerCase(courseName)) return index;
        index++;
    }
    return -1;
}

// This function creates a course. If it's done successfully, it returns true, if not, returns false
bool ProjectHandler::createCourse(std::string courseName) {
    if(courseExists(courseName)) return false;

    Course* course = new Course(courseName);
    this->getCourses().push_back(course);
    return true;
}


// This function deletes a course. If it's done successfully, it returns true, if not, return false
bool ProjectHandler::deleteCourse(std::string courseName) {
    if(!courseExists(courseName)) return false;

    int foundCourseIndex = this->findCourseIndexInVectorByName(courseName);
    if(foundCourseIndex == -1) return false;

    this->getCourses().erase(this->getCourses().begin() + foundCourseIndex);
    return true;

}