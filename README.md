# Course Management System

## Project Description

This project is a command-line interface (CLI) application for managing university courses and student enrollments. It provides a simple menu-driven interface for users to perform various administrative tasks.

Core functionalities include:

- **Course Management:** Create new courses with a name and code, remove existing courses, and list all available courses along with their student rosters.
- **Student Enrollment:** Enroll students into a specific course by providing their name, ID, and classification.
- **Roster Management:** Remove students from a course roster.
- **Dynamic Memory:** The student roster for each course dynamically expands as more students are added, preventing fixed-size limitations.

The application is built using object-oriented principles in C++, with distinct classes for `Course`, `Roster`, and `Student` to logically separate concerns.

## Technologies Used

- **Language:** C++
- **Core Libraries:** `iostream`, `string`
- **Frameworks:** None
- **Tools:** g++ (or any standard C++ compiler)

## How to Run

Follow these steps to compile and run the project on a system with a C++ compiler.

1.  **Prerequisites**

    - A C++ compiler, such as g++, must be installed on your system.

2.  **Compilation**
    Navigate to the project's root directory in your terminal and run the following command to compile the source files into an executable named `course_manager`.

    ```bash
    g++ driver.cpp class.cpp -o course_manager
    ```

3.  **Execution**
    Run the compiled program with the following command:
    ```bash
    ./course_manager
    ```
    The application will start, and you can interact with it through the command-line menu.

## Project Output

Here is an example of the application's workflow:

```text
Welcome to course maker! please select the following options

   Course Options
a: Create a course 
r: Remove a course 
l: List all courses

   Enrollment Options
e: Enroll a student in a course 
s: Remove a student from a course

OUT (o)

< a
What course would you like to create? Intro to C++
What is the class code? CS101
   Course Options
a: Create a course 
r: Remove a course 
l: List all courses

   Enrollment Options
e: Enroll a student in a course 
s: Remove a student from a course

OUT (o)

< e
What course would you like the student to be added to: 
1) Intro to C++
Intro to C++
What is the students name: John Doe
Enter the students ID: 12345
Enter the classification of the student: F
   Course Options
a: Create a course 
r: Remove a course 
l: List all courses

   Enrollment Options
e: Enroll a student in a course 
s: Remove a student from a course

OUT (o)

< l
Course Name: Intro to C++
Course Code: CS101
Class size: 1
Roster capacity: 5

Student #1
   Name: John Doe
   ID: 12345
   Classification: F

   Course Options
a: Create a course 
r: Remove a course 
l: List all courses

   Enrollment Options
e: Enroll a student in a course 
s: Remove a student from a course

OUT (o)

< o
```
