#ifndef HOMEWORKMANAGER_COURSE_H
#define HOMEWORKMANAGER_COURSE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../Assignment/Assignment.h"

class Course {
private:
    std::string courseName;
    std::vector<Assignment*> assignments; //vector of pointers


public:
    Course(std::string courseName);
    //getter for courseName
    std::string getCourseName();

    //setter for courseName
    void setCourseName(std::string name);

    // Check if a assignment exists (by it's name)
    bool assignmentExists(std::string assignmentName);

    //getter for assignments
    std::vector<Assignment*>& getAssignments();


};

#endif