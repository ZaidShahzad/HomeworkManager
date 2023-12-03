#ifndef HOMEWORKMANAGER_ASSIGNMENT_H
#define HOMEWORKMANAGER_ASSIGNMENT_H

#include <iostream>
#include <vector>
#include <string>
#include "../utils/date.h"
#include <chrono> // to calculate remaining time until assignment is due
using namespace date;
using namespace std::chrono;



class Assignment {
//Private member variables
private:
    std::string title;
    int priorityLevel;
    sys_days dueDate;
    std::string parentCourseName;
    std::string assignmentID;



public:

// Constructor
    Assignment(std::string title, std::string parentCourse);
// Copy constructor
    Assignment(Assignment* assignmentToCopyFrom);

//Public member functions for accessing and modifying private members

//Getters for the title
    std::string getTitle();

//setter for the title
    void setTitle(std::string newTitle);

//getter for the priority level
    int getPriorityLevel();

    void setPriorityLevel(int priorityLevel);

    std::string getFormattedDueDate();
    void setDueDate(sys_days dueDate);

// getter for time left until due date
    std::string getTimeLeft();
    int getDaysLeft();
    std::string getAssignmentID();
    std::string getParentCourseName();
    void setParentCourseName(std::string parentCourseName);
    bool isDueToday();
};

#endif 