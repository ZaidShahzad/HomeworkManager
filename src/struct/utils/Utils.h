//
// Created by Zaid on 11/15/2023.
//

#ifndef HOMEWORKMANAGER_UTILS_H
#define HOMEWORKMANAGER_UTILS_H

#include "../handler/ProjectHandler.h"
#include "../utils/termcolor.hpp"

#include <filesystem>
namespace fs = std::filesystem;

// Singleton Class to make it easier to access to all files that require this class

class Utils {

private:
    static Utils* INSTANCE;
    ProjectHandler* handler;

public:
    Utils();

    // Get the instance of this class
    static Utils* getInstance();

    ProjectHandler getProjectHandler();
    std::string toLowerCase(std::string string);
    std::string getDesktopPath();

};


#endif //HOMEWORKMANAGER_UTILS_H