# Homework Manager

A program that allows you to manage your homework assignments in an efficient way.

## Table of Contents
- [Overview](#overview)
- [Dependencies](#dependencies)
- [Usage](#usage)
- [Commands](#commands)
- [Authors](#authors)

## Overview
Homework Manager is a C++ program designed to streamline your homework assignment organization. It provides a structured approach to managing courses, projects, and assignments in a user-friendly manner.

## Dependencies
Before you begin, ensure you have the following dependencies installed on your system:
- CMake (version 3.24 or higher)
- C++ Compiler with C++17 support
- Visual Studios Build Tools (Windows Only - if you're using Visual Studio Code)

## Usage
To use Homework Manager, follow these simple steps:

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/your-username/HomeworkManager.git
   cd HomeworkManager
   ```
### Using CLion
If you're using CLion, follow these steps:

1. Open CLion and choose "Open Project" or "File > Open...".
2. Navigate to the HomeworkManager directory and select it.
3. CLion will automatically load the CMake configuration (If not, right click the CMAKE file and click load). Then, click "Run" or use the `Shift + F10` shortcut to build and run the executable.

### Using Visual Studio Code
If you prefer Visual Studio Code, you can compile and run the program using the terminal:

1. Open a terminal in the HomeworkManager directory.

2. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```
3. Generate the build files using CMake:
   ```bash
    cmake ../src
    cmake --build .
    ```
4. Run the executable:
    ```bash
    ..\Debug\src.exe (wherever the executable location is)
    ```

## Commands
- /cc (course name) - `Create a course`
- /dc (course name) - `Delete a course`
- /ca (course name) (assignment name) (priority level (1-5)) (due date (mm-dd-yyyy)) - `Create an assignment`
- /d (assignment ID) - `Delete an assignment`
- /cm (assignment ID) - `Complete an assignment`
- /sa (query) - `Search for an assignment`
- /sh (query) - `Search for an assignment in history`
- /history - `View completed assignments history`
- /today - `View assignments due today`
- /all - `View all assignments`
- /view (course name) - `View assignments for a course`
- /todolist - `View auto todo list`
- /generate (# of courses) (# of assignments in courses) - `Generate assignments & courses to test benchmarking`
- /main - `Go back to the main menu`

## Authors
1. [Zaid Shahzad](https://github.com/ZaidShahzad)
2. [Diegotyb](https://github.com/Diegotyb)
3. [Essamabd03](https://github.com/essamabd03)
4. [AdamMesiya](https://github.com/AdamMesiya)

## Conclusion
Thank you for checking out our project! We hope you find it useful and easy to use.
