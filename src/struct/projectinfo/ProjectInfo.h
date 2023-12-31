#ifndef HOMEWORKMANAGER_PROJECTINFO_H
#define HOMEWORKMANAGER_PROJECTINFO_H

#include <iostream>
#include <vector>


/*
 *
 * This class is to show information about the project
 *
 */
class ProjectInfo {

private:
    std::string VERSION = "1.0 - STABLE";
    std::vector<std::string> AUTHORS = {"Diego Romero", "Zaid Shahzad", "Essam Abdulraouf", "Adam Mesiya"};

public:
    std::string getVersion();
    std::vector<std::string>& getAuthors();

};


#endif