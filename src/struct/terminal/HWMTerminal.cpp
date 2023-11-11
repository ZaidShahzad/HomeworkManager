#include "HWMTerminal.h"
#include <iostream>

HWMTerminal::HWMTerminal(ProjectInfo* projectInfo) {
    this->projectInfo = projectInfo;
    this->currentPage = MAIN_MENU;
}

// This will return the page the user is on
Page HWMTerminal::getCurrentPage() {
    return this->currentPage;
}

// This will allow you to set the page the user is on
Page HWMTerminal::setCurrentPage(Page page) {
    this->currentPage = page;
}

// This function will get a response from the user and return a vector as the user's response
// EX: If the user typed "create Biology", it will return a vector like ["create", "Biology"]
std::vector<std::string> HWMTerminal::getResponseFromUser() {
    std::string response;
    std::vector<std::string> args;
    std::getline(std::cin, response);

    std::string word = "";
    for(int i = 0; i < response.size(); i++) {
        if(response[i] == ' ') {
            args.push_back(word);
            word = "";
        }
        else {
            word += response[i];
        }
    }

    if(word != "") args.push_back(word);

    return args;
}

void HWMTerminal::printMainPage() {
    std::cout << "\n";
    std::cout << "-*- Homework Manager (" << this->projectInfo->getVersion() << ") | Main Page -*-\n";
    std::cout << "\n";
    std::cout << "Your Courses\n";
    std::cout << "...\n";
    std::cout << "\n";
    std::cout << "Enter 'create <className>' or 'delete <numberOfClass>' to add or remove a class\n";
    std::cout << "\n";
    std::cout << "Please type in a command to continue.\n";
    std::cout << "\n";
    std::cout << "";
}

// This function will send the user to the Main Menu and wait for a response. When the response is given,
// it will do the necessary actions depending on the response.
void HWMTerminal::gotoMainMenu() {
    this->setCurrentPage(MAIN_MENU);
    this->printMainPage();

    std::vector<std::string> response = getResponseFromUser();

    std::string command = response[0];

    if(command == "create") {
        std::string className = response[1];
        // Handle creation of class
    }
    else if(command == "delete") {
        std::string numberOfClass = response[1];
        // Handle deletion of class
    }
}