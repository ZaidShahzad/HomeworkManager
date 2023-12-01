#include "Assignment.h"
#include <chrono>
#include <sstream>

Assignment::Assignment(std::string title, std::string parentCourse) {
    this->title = title;
    this->parentCourseName = parentCourse;
    this->completed = false;
    this->description = "";
    this->priorityLevel = 1;
    this->preparedDescription = "";
    this->assignmentID = parentCourse + "-" + title;
}

Assignment::Assignment(Assignment* assignmentToCopyFrom) {
    this->title = assignmentToCopyFrom->title;
    this->parentCourseName = assignmentToCopyFrom->parentCourseName;
    this->completed = assignmentToCopyFrom->completed;
    this->description = assignmentToCopyFrom->description;
    this->priorityLevel = assignmentToCopyFrom->priorityLevel;
    this->preparedDescription = assignmentToCopyFrom->preparedDescription;
    this->assignmentID = assignmentToCopyFrom->assignmentID;
}

// Getter for title
std::string Assignment::getTitle() {
    return this->title;
}

// Setter for title
void Assignment::setTitle(std::string newTitle) {
    this->title = newTitle;
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

std::string Assignment::getAssignmentID() {
    return this->assignmentID;
}

std::string Assignment::getParentCourseName() {
    return this->parentCourseName;
}

std::string Assignment::getTimeLeft() {

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

    // Gets remaining hours of the day
    auto hoursLeft = duration_cast<hours>(exactTimeDiff) % 24;
    // Gets remaining minutes of the hour
    auto minutesLeft = duration_cast<minutes>(exactTimeDiff) % 60;

    // Output
    std::stringstream ss;
    ss << daysDiff.count() << " days " << hoursLeft.count() << " hrs "
       << minutesLeft.count() << " min left";
    return ss.str();
}

