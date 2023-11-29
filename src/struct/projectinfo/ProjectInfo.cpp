#include "ProjectInfo.h"
#include "../utils/Utils.h"

std::string ProjectInfo::getVersion() {
    return this->VERSION;
}
std::vector<std::string>& ProjectInfo::getAuthors() {
    return this->AUTHORS;

}