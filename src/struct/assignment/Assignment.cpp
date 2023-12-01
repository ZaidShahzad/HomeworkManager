#include "Assignment.h"
#include <chrono>
#include <sstream>

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

std::string Assignment::getFormattedDueDate() {
    return date::format("%m-%d-%Y", this->dueDate);
}

void Assignment::setDueDate(sys_days dueDate) {
    this->dueDate = dueDate;
}

std::string Assignment::getTimeLeft() const {
    using namespace std::chrono;
    using namespace date;

    // Get the current time and date
    auto now = system_clock::now();
    // Current date in days
    auto nowDays = floor<days>(now);

    // Calculate the difference in days
    auto daysDiff = dueDate - nowDays;

    if (daysDiff.count() < 0) {
        return "Overdue";
    }

    // Calculates exact time difference
    auto exactTimeDiff = dueDate - now;

    // convert to hours and minutes
    auto hoursLeft = duration_cast<hours>(exactTimeDiff) % 24; // Modulo 24 to get remaining hours of the day
    auto minutesLeft = duration_cast<minutes>(exactTimeDiff) % 60; // Modulo 60 to get remaining minutes of the hour

    // output
    std::stringstream ss;
    ss << daysDiff.count() << " days " << hoursLeft.count() << " hrs "
       << minutesLeft.count() << " min left";
    return ss.str();
}

