#include "ProjectHandler.h"
#include "../course/Course.h"
#include "../assignment/Assignment.h"
#include "../utils/Utils.h"

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
    for(Course* course : this->getCourses()) {
        if(Utils::getInstance()->toLowerCase(course->getCourseName()) == Utils::getInstance()->toLowerCase((courseName))) return true;
    }
    return false;
}

// This function will return a course if it's found by the name passed it, if not, it will return nullptr
Course *ProjectHandler::findCourseByName(std::string courseName) {
    for(Course* course : this->getCourses()) {
        if(Utils::getInstance()->toLowerCase((course->getCourseName())) == Utils::getInstance()->toLowerCase((courseName))) return course;
    }
    return nullptr;
}

// This function will return a course index if it's found by the name passed it, if not, it will return -1
int ProjectHandler::findCourseIndexInVectorByName(std::string courseName) {
    int index = 0;
    for(Course* course : this->getCourses()) {
        if(Utils::getInstance()->toLowerCase((course->getCourseName())) == Utils::getInstance()->toLowerCase((courseName))) return index;
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

bool ProjectHandler::createAssignment(std::string className, std::string assignmentName, int priorityLevel) {
    Course* course = findCourseByName(className);

    // Check if an assignment already exists (check's by name)
    if(course->assignmentExists(assignmentName)) return false;

    Assignment* assignment = new Assignment(assignmentName);
    assignment->setPriorityLevel(priorityLevel);
    course->getAssignments().push_back(assignment);
    return true;
}