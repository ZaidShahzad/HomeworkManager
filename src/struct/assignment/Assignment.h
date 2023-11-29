#ifndef HOMEWORKMANAGER_ASSIGNMENT_H
#define HOMEWORKMANAGER_ASSIGNMENT_H

#include <iostream>
#include <vector>
#include <string>



class Assignment {
//Private member variables
private: 
   std::string title;                 
   bool completed;                    
   std::string description;
   int priorityLevel;
   std::string preparedDescription;

public:

// Constructor
   Assignment(std::string title);

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

};

#endif 