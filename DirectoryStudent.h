#ifndef DIRECTORYSTUDENT_H
#define DIRECTORYSTUDENT_H

#include "Student.h"

class DirectoryStudent {
private:
    static const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int count;

public:
    DirectoryStudent();

    // Menu methods
    void mainMenu();
    void insertMenu();
    void updateMenu();
    void deleteMenu();
    void searchMenu();
    void listDirectory();

    // Operation methods
    void insertStudent();
    void updateStudent();
    void deleteStudent();
    void searchStudent();
};

#endif
