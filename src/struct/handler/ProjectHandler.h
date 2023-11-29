#ifndef HOMEWORKMANAGER_PROJECTHANDLER_H
#define HOMEWORKMANAGER_PROJECTHANDLER_H

#include "../terminal/HWMTerminal.h"
#include "../projectInfo/ProjectInfo.h"
#include "../assignment/Assignment.h"
#include "../course/Course.h"

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
    std::string toLowerCase(std::string string);


public:
    ProjectHandler();
    ProjectInfo getProjectInfo();
    HWMTerminal getTerminal();

    std::vector<Course*>& getCourses();
    bool createCourse(std::string courseName);
    bool deleteCourse(std::string courseName);

    bool createAssignment(std::string className, std::string assignmentName, std::string priorityLevel);

    bool courseExists(std::string courseName);
    Course* findCourseByName(std::string courseName);
    int findCourseIndexInVectorByName(std::string courseName);

};


#endif
