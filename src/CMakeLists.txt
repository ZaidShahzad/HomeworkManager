cmake_minimum_required(VERSION 3.24)
project(HomeworkManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(src main.cpp struct/terminal/HWMTerminal.cpp struct/projectinfo/ProjectInfo.cpp struct/manager/ProjectHandler.cpp)
