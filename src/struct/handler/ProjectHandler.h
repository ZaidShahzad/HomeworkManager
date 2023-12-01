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
    std::vector<Assignment*> completedAssignmentsHistory;


public:
    ProjectHandler();
    ProjectInfo getProjectInfo();
    HWMTerminal getTerminal();

    std::vector<Course*>& getCourses();
    std::vector<Assignment*>& getCompletedAssignmentsHistory();
    bool createCourse(std::string courseName);
    bool deleteCourse(std::string courseName);

    bool createAssignment(std::string className, std::string assignmentName, int priorityLevel, std::string dueDate);
    bool deleteAssignment(std::string assignmentID);

    bool courseExists(std::string courseName);
    bool completeAssignment(std::string assignmentID);

    Course* findCourseByName(std::string courseName);
    Assignment* findAssignmentByID(std::string id);
    int findCourseIndexInVectorByName(std::string courseName);
    int findAssignmentIndexInVectorByID(std::string assignmentID);
    bool isValidDateFormat(std::string string);

};


#endif