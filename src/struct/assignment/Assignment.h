#ifndef HOMEWORKMANAGER_ASSIGNMENT_H
#define HOMEWORKMANAGER_ASSIGNMENT_H

#include <iostream>
#include <vector>
#include <string>



class Assignment {
private: 
   std::string title;
   bool completed;
   std::string description;
   int priorityLevel;
   std::string preparedDescription;

public:
   std::string getTitle();

   void setTitle(std::string newTitle);

   bool isCompleted();

   void setCompleted(bool isCompleted);

   std::string getDescription();

   void setDescription(std::string newDescription);

   int getPriorityLevel();

   std::string getPreparationDescription();

   void setPreparationDescription(std::string newPrepDescription);

};

#endif