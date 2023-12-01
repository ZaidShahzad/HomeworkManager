#ifndef HOMEWORKMANAGER_PROJECTHANDLER_H
#define HOMEWORKMANAGER_PROJECTHANDLER_H

#include "../terminal/HWMTerminal.h"
#include "../projectInfo/ProjectInfo.h"
#include "../assignment/Assignment.h"
#include "../course/Course.h"
#include "../utils/date.h"
using namespace date;
#include <vector>


/*
 *
 * This class will handle everything and anything related to the project
 *
 */
class ProjectHandler {

private:
    ProjectInfo projectInfo;
    HWMTerminal terminal;

    std::vector<Course*> courses;


public:
    ProjectHandler();
    ProjectInfo getProjectInfo();
    HWMTerminal getTerminal();

    std::vector<Course*>& getCourses();
    bool createCourse(std::string courseName);
    bool deleteCourse(std::string courseName);

    bool createAssignment(std::string className, std::string assignmentName, int priorityLevel, std::string dueDate);

    bool courseExists(std::string courseName);

    Course* findCourseByName(std::string courseName);
    Assignment* findAssignmentByID(std::string id);
    int findCourseIndexInVectorByName(std::string courseName);
    bool isValidDateFormat(std::string string);

};


#endif