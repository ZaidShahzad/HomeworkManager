cmake_minimum_required(VERSION 3.24)
project(HomeworkManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(src main.cpp struct/terminal/HWMTerminal.cpp struct/projectinfo/ProjectInfo.cpp struct/handler/ProjectHandler.cpp struct/course/Course.cpp struct/assignment/Assignment.cpp struct/utils/Utils.cpp)
