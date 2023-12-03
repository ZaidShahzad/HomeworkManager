#include "ProjectHandler.h"
#include "../utils/Utils.h"

ProjectHandler::ProjectHandler() {
    this->loadData();
}

void ProjectHandler::saveData() {
    std::string path;
    #ifdef _WIN32
        path = Utils::getInstance()->getDesktopPath() + "\\HomeworkManagerData.txt";
    #else
        path = Utils::getInstance()->getDesktopPath() + "/HomeworkManagerData.txt";
    #endif
    std::ofstream file(path);
    file << "Courses:\n";
    for(Course* course : this->getCourses()) {
        for(Assignment* assignment : course->getAssignments()) {
            std::string courseName = course->getCourseName();
            std::string assignmentName = assignment->getTitle();
            int priorityLevel = assignment->getPriorityLevel();
            std::string dueDate = assignment->getFormattedDueDate();
            file << "/ca " << courseName << " " << assignmentName << " " << priorityLevel << " " << dueDate << "\n";
        }
    }
    file << "Completed Assignments:\n";
    for(Assignment* assignment : this->getCompletedAssignmentsHistory()) {
        std::string courseName = assignment->getParentCourseName();
        std::string assignmentName = assignment->getTitle();
        int priorityLevel = assignment->getPriorityLevel();
        std::string dueDate = assignment->getFormattedDueDate();
        file << "/ca " << courseName << " " << assignmentName << " " << priorityLevel << " " << dueDate << " completed\n";
    }

    file.close();
}

void ProjectHandler::loadData() {
    std::string path;
    #ifdef _WIN32
        path = Utils::getInstance()->getDesktopPath() + "\\HomeworkManagerData.txt";
    #else
        path = Utils::getInstance()->getDesktopPath() + "/HomeworkManagerData.txt";
    #endif
    std::ifstream file(path);
    std::string line;
    while(std::getline(file, line)) {
        std::istringstream iss(line);
        std::string command;
        iss >> command;
        if(command == "/ca") {
            std::string courseName;
            std::string assignmentName;
            int priorityLevel;
            std::string dueDate;
            std::string completed;
            iss >> courseName >> assignmentName >> priorityLevel >> dueDate >> completed;
            if(completed == "completed") {
                this->createAssignment(courseName, assignmentName, priorityLevel, dueDate);
                this->completeAssignment(courseName + "-" + assignmentName);
            } else {
                this->createAssignment(courseName, assignmentName, priorityLevel, dueDate);
            }
        }
    }
    file.close();
}
ProjectInfo ProjectHandler::getProjectInfo() {
    return this->projectInfo;
}

HWMTerminal ProjectHandler::getTerminal() {
    return this->terminal;
}

std::vector<Course*>& ProjectHandler::getCourses() {
    return this->courses;
}

std::vector<Assignment*>& ProjectHandler::getCompletedAssignmentsHistory() {
    std::sort(this->completedAssignmentsHistory.begin(), this->completedAssignmentsHistory.end(), [](Assignment* a, Assignment* b) {
        return a->getDaysLeft() < b->getDaysLeft();
    });
    return this->completedAssignmentsHistory;
}

bool ProjectHandler::isValidDateFormat(std::string string) {
    std::istringstream dateStream(string);
    date::sys_days parsedData;
    dateStream >> date::parse("%m-%d-%Y", parsedData);
    return !dateStream.fail();

}

// This function will check if a course exists (if does, returns true, if not, returns false)
bool ProjectHandler::courseExists(std::string courseName) {
    for(Course* course : this->getCourses()) {
        if(Utils::getInstance()->toLowerCase(course->getCourseName()) == Utils::getInstance()->toLowerCase((courseName))) return true;
    }
    return false;
}

// This function will return a course if it's found by the name passed it, if not, it will return nullptr
Course *ProjectHandler::findCourseByName(std::string courseName) {
    for(Course* course : this->getCourses()) {
        if(Utils::getInstance()->toLowerCase((course->getCourseName())) == Utils::getInstance()->toLowerCase((courseName))) return course;
    }
    return nullptr;
}

Assignment* ProjectHandler::findAssignmentByID(std::string id) {
    for(Course* course : this->getCourses()) {
        for(Assignment* assignment : course->getAssignments()) {
            if(Utils::getInstance()->toLowerCase(assignment->getAssignmentID()) == Utils::getInstance()->toLowerCase(id)) return assignment;
        }
    }
    return nullptr;
}

// This function will return a course index if it's found by the name passed it, if not, it will return -1
int ProjectHandler::findCourseIndexInVectorByName(std::string courseName) {
    int index = 0;
    for(Course* course : this->getCourses()) {
        if(Utils::getInstance()->toLowerCase((course->getCourseName())) == Utils::getInstance()->toLowerCase((courseName))) return index;
        index++;
    }
    return -1;
}

int ProjectHandler::findAssignmentIndexInVectorByID(std::string assignmentID) {
    int index = 0;
    Assignment* toFindAssignment = this->findAssignmentByID(assignmentID);
    Course* course = this->findCourseByName(toFindAssignment->getParentCourseName());
    for(Assignment* assignment : course->getAssignments()) {
        if(Utils::getInstance()->toLowerCase(assignment->getAssignmentID()) == Utils::getInstance()->toLowerCase(assignmentID)) return index;
        index++;
    }
    return -1;
}

// This function creates a course. If it's done successfully, it returns true, if not, returns false
bool ProjectHandler::createCourse(std::string courseName) {
    if(courseExists(courseName)) return false;

    Course* course = new Course(courseName);
    this->getCourses().push_back(course);
    return true;
}


// This function deletes a course. If it's done successfully, it returns true, if not, return false
bool ProjectHandler::deleteCourse(std::string courseName) {
    if(!courseExists(courseName)) return false;

    int foundCourseIndex = this->findCourseIndexInVectorByName(courseName);
    if(foundCourseIndex == -1) return false;

    Course* course = this->findCourseByName(courseName);
    this->getCourses().erase(this->getCourses().begin() + foundCourseIndex);
    delete course;
    return true;

}

bool ProjectHandler::createAssignment(std::string className, std::string assignmentName, int priorityLevel, std::string dueDate) {
    if(!this->courseExists(className)) {
        this->createCourse(className);
    }
    Course* course = findCourseByName(className);
    // Check if an assignment already exists (check's by name)
    if(course->assignmentExists(assignmentName)) return false;
    if(!this->isValidDateFormat(dueDate)){
        std::cout << "Your due date was invalid.\n";
        return false;
    }

    Assignment* assignment = new Assignment(assignmentName, course->getCourseName());

    sys_days sysDueDate;
    std::istringstream dateStream(dueDate);
    dateStream >> date::parse("%m-%d-%Y", sysDueDate);
    assignment->setDueDate(sysDueDate);

    assignment->setPriorityLevel(priorityLevel);
    assignment->setParentCourseName(course->getCourseName());
    course->getAssignments().push_back(assignment);
    return true;
}

bool ProjectHandler::deleteAssignment(std::string assignmentID) {
    Assignment* assignment = this->findAssignmentByID(assignmentID);
    if(assignment == nullptr) {
        std::cout << "That assignment ID was invalid!\n";
        return false;
    }
    Course* course = this->findCourseByName(assignment->getParentCourseName());
    int foundAssignmentIndex = this->findAssignmentIndexInVectorByID(assignmentID);
    if(foundAssignmentIndex == -1) return false;

    course->getAssignments().erase(course->getAssignments().begin() + foundAssignmentIndex);
    delete assignment;
    return true;
}

bool ProjectHandler::completeAssignment(std::string assignmentID) {
    Assignment* assignment = this->findAssignmentByID(assignmentID);
    if(assignment == nullptr) {
        std::cout << "That assignment ID was invalid!\n";
        return false;
    }
    Assignment* completedAssignment = new Assignment(assignment);
    this->getCompletedAssignmentsHistory().push_back(completedAssignment);

    this->deleteAssignment(assignmentID);
    return true;
}

bool ProjectHandler::rabinKarpSearch(std::string text, std::string pattern) {
    if (text.length() < pattern.length()) {
        return false;
    }

    const int base = 256;
    const int prime = 101;

    int patternHash = 0;
    int textHash = 0;
    int h = 1;

    for (int i = 0; i < pattern.length(); ++i) {
        patternHash = (base * patternHash + pattern[i]) % prime;
        textHash = (base * textHash + text[i]) % prime;
        if (i < pattern.length() - 1) {
            h = (h * base) % prime;
        }
    }

    for (int i = 0; i <= text.length() - pattern.length(); ++i) {
        if (patternHash == textHash) {
            int j;
            for (j = 0; j < pattern.length(); ++j) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == pattern.length()) {
                return true;
            }
        }

        if (i < text.length() - pattern.length()) {
            textHash = (base * (textHash - text[i] * h) + text[i + pattern.length()]) % prime;
            if (textHash < 0) {
                textHash += prime;
            }
        }
    }

    return false;
}

std::vector<Assignment*> ProjectHandler::findAssignmentsByPattern(std::string pattern) {
    std::vector<Assignment*> assignments;
    for(Course* course : this->getCourses()) {
        for(Assignment* assignment : course->getAssignments()) {
            if (this->rabinKarpSearch(Utils::getInstance()->toLowerCase(assignment->getTitle()), pattern)) {
                assignments.push_back(assignment);
            }
        }
    }
    std::sort(assignments.begin(), assignments.end(), [](Assignment* a, Assignment* b) {
        return a->getDaysLeft() < b->getDaysLeft();
    });
    return assignments;
}

bool ProjectHandler::boyerMooreSearch(std::string text, std::string pattern) {
    if (text.length() < pattern.length()) {
        return false;
    }

    std::unordered_map<char, int> last;
    for (int i = 0; i < pattern.length(); ++i) {
        last[pattern[i]] = i;
    }

    int i = pattern.length() - 1;
    int j = pattern.length() - 1;

    while (i < text.length()) {
        if (text[i] == pattern[j]) {
            if (j == 0) {
                return true;
            }
            --i;
            --j;
        } else {
            int l = last[text[i]];
            i = i + pattern.length() - std::min(j, l + 1);
            j = pattern.length() - 1;
        }
    }

    return false;
}

std::vector<Assignment*> ProjectHandler::findAssignmentsInHistoryByPattern(std::string pattern) {
    std::vector<Assignment*> assignments;
    for(Assignment* assignment : this->getCompletedAssignmentsHistory()) {
        if (this->boyerMooreSearch(Utils::getInstance()->toLowerCase(assignment->getTitle()), pattern)) {
            assignments.push_back(assignment);
        }
    }
    std::sort(assignments.begin(), assignments.end(), [](Assignment* a, Assignment* b) {
        return a->getDaysLeft() < b->getDaysLeft();
    });
    return assignments;
}

