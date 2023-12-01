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
    bool completed;
    std::string description;
    int priorityLevel;
    std::string preparedDescription;
    sys_days dueDate;
    std::string parentCourseName;
    std::string assignmentID;



public:

// Constructor
    Assignment(std::string title, std::string parentCourse);

//Public member functions for accessing and modifying private members

//Getters for the title
    std::string getTitle();

//setter for the title
    void setTitle(std::string newTitle);

//getter for the completion status
    bool isCompleted();

//setter for the completion status
    void setCompleted(bool isCompleted);

//getter for the description
    std::string getDescription();

//setter for the description
    void setDescription(std::string newDescription);

//getter for the priority level
    int getPriorityLevel();

//getter for the prepared description
    std::string getPreparationDescription();

//setter for the prepared description
    void setPreparationDescription(std::string newPrepDescription);

    void setPriorityLevel(int priorityLevel);

    std::string getFormattedDueDate();
    void setDueDate(sys_days dueDate);

// getter for time left until due date
    std::string getTimeLeft();
    std::string getAssignmentID();
    std::string getParentCourseName();
};

#endif 