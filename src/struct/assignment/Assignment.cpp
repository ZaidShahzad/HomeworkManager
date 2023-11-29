#include "Assignment.h"

Assignment::Assignment(std::string title) {
    this->title = title;
    this->completed = false;
    this->description = "";
    this->priorityLevel = 1;
    this->preparedDescription = "";
}

// Getter for title
std::string Assignment::getTitle() {
    return this->title;
}

// Setter for title
void Assignment::setTitle(std::string newTitle) {
    this->title = newTitle;
}

// Getter for completed
bool Assignment::isCompleted() {
    return this->completed;
}

// Setter for completed
void Assignment::setCompleted(bool isCompleted) {
    this->completed = isCompleted;
}

// Getter for description
std::string Assignment::getDescription() {
    return this->description;
}

// Setter for description
void Assignment::setDescription(std::string newDescription) {
    this->description = newDescription;
}

// Getter for priorityLevel
int Assignment::getPriorityLevel() {
    return this->priorityLevel;
}

// Getter for preparationDescription
std::string Assignment::getPreparationDescription() {
    return this->preparedDescription;
}

// Setter for preparationDescription
void Assignment::setPreparationDescription(std::string newPrepDescription) {
    this->preparedDescription = newPrepDescription;
}

void Assignment::setPriorityLevel(int priorityLevel) {
    this->priorityLevel = priorityLevel;
}
std::string Assignment::getDueDate() {
    return date::format("%m-%d-%Y", this->dueDate);
}