#ifndef HOMEWORKMANAGER_COURSE_H
#define HOMEWORKMANAGER_COURSE_H

#include <iostream>
#include <vector>
#include <string>



class Course {
private: 
    std::string courseName;
    std::vector<std::string*> assignments; //vector of pointers


public:
    //getter for courseName
    std::string getCourseName(); 

    //setter for courseName
    void setCourseName(std::string name);

    //getter for assignments
    std::vector<std::string*> getAssignments(); 


};

#endif