//
// Created by Zaid on 11/15/2023.
//

#include "Utils.h"
// Set INSTANCE to the class itsself
Utils::Utils() {
    INSTANCE = this;
    this->handler = new ProjectHandler();
}

// get the instance of the class
Utils* Utils::getInstance() {
    if(INSTANCE == nullptr) return new Utils;
    return INSTANCE;
}

ProjectHandler Utils::getProjectHandler() {
    return *this->handler;
}

std::string Utils::toLowerCase(std::string string) {
    for(int i = 0; i < string.length(); i++) {
        string[i] = tolower(string[i]);
    }
    return string;
}

std::string Utils::getDesktopPath() {
    fs::path desktopPath;
    #ifdef _WIN32
    desktopPath = fs::path(getenv("USERPROFILE")) / "Desktop";
    #else
    desktopPath = fs::path(getenv("HOME")) / "Desktop";
    #endif
    return desktopPath.string();
}