//
// Created by Zaid on 11/15/2023.
//

#include "Utils.h"

// Set INSTANCE to the class itsself
Utils::Utils() {
    INSTANCE = this;
}

// get the instance of the class
Utils* Utils::getInstance() {
    if(INSTANCE == nullptr) return new Utils;
    return INSTANCE;
}

ProjectHandler Utils::getProjectHandler() {
    return this->handler;
}