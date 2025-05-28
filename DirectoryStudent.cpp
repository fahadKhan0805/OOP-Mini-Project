#include "DirectoryStudent.h"
#include <iostream>

DirectoryStudent::DirectoryStudent() : count(0) {}

void DirectoryStudent::mainMenu() {
    while (true) {
        std::cout << "*************************************" << std::endl;
        std::cout << "Telephone Directory: Main Menu" << std::endl;
        std::cout << "*************************************" << std::endl;
        std::cout << "1. Insert a new student" << std::endl;
        std::cout << "2. Update an existing student" << std::endl;
        std::cout << "3. Delete a record" << std::endl;
        std::cout << "4. Search for a student (using name or ID)" << std::endl;
        std::cout << "5. List directory" << std::endl;
        std::cout << "Select Option [1, 2, 3, 4 or 5]: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            insertMenu();
            break;
        case 2:
            updateMenu();
            break;
        case 3:
            deleteMenu();
            break;
        case 4:
            searchMenu();
            break;
        case 5:
            listDirectory();
            break;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
}

void DirectoryStudent::insertMenu() {
    while (true) {
        std::cout << "*************************************" << std::endl;
        std::cout << "Telephone Directory: Insert Menu" << std::endl;
        std::cout << "*************************************" << std::endl;

        char id[20], name[50], address[100], phoneNumber[15];
        std::cout << "Enter ID: ";
        std::cin >> id;

        // Check if ID already exists
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (strcmp(students[i].getId(), id) == 0) {
                std::cout << "ID already exists. Cannot insert." << std::endl;
                found = true;
                break;
            }
        }

        if (found)
            continue;

        std::cout << "Enter Name: ";
        std::cin.ignore();
        std::cin.getline(name, sizeof(name));

        std::cout << "Enter Address: ";
        std::cin.getline(address, sizeof(address));

        std::cout << "Enter Phone Number: ";
        std::cin.getline(phoneNumber, sizeof(phoneNumber));

        students[count++] = Student(id, name, address, phoneNumber);

        std::cout << "Record saved successfully." << std::endl;

        char choice;
        std::cout << "Want to insert another record? [y/n]: ";
        std::cin >> choice;

        if (choice != 'y')
            break;
    }
}

void DirectoryStudent::updateMenu() {
    while (true) {
        std::cout << "*************************************" << std::endl;
        std::cout << "Telephone Directory: Update Menu" << std::endl;
        std::cout << "*************************************" << std::endl;

        char query[50];
        std::cout << "Enter ID or Name: ";
        std::cin >> query;

        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (strcmp(students[i].getId(), query) == 0 || strcmp(students[i].getName(), query) == 0) {
                found = true;
                std::cout << "Current Information is: " << std::endl;
                students[i].display();
                std::cout << "Do you want to update [y/n]? ";
                char choice;
                std::cin >> choice;
                if (choice == 'y') {
                    char id[20], name[50], address[100], phoneNumber[15];

                    std::cout << "Enter New Information:" << std::endl;
                    std::cout << "Enter ID: ";
                    std::cin >> id;

                    std::cout << "Enter Name: ";
                    std::cin.ignore();
                    std::cin.getline(name, sizeof(name));

                    std::cout << "Enter Address: ";
                    std::cin.getline(address, sizeof(address));

                    std::cout << "Enter Phone Number: ";
                    std::cin.getline(phoneNumber, sizeof(phoneNumber));

                    students[i] = Student(id, name, address, phoneNumber);
                    std::cout << "Record updated successfully." << std::endl;
                }
                break;
            }
        }

        if (!found)
            std::cout << "Student not found." << std::endl;

        char choice;
        std::cout << "Do you want to update another record? [y/n]: ";
        std::cin >> choice;

        if (choice != 'y')
            break;
    }
}

void DirectoryStudent::deleteMenu() {
    while (true) {
        std::cout << "*************************************" << std::endl;
        std::cout << "Telephone Directory: Delete Menu" << std::endl;
        std::cout << "*************************************" << std::endl;

        char id[20];
        std::cout << "Enter ID: ";
        std::cin >> id;

        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (strcmp(students[i].getId(), id) == 0) {
                found = true;
                std::cout << "Current Information is: " << std::endl;
                students[i].display();
                std::cout << "Do you want to delete this record [y/n]? ";
                char choice;
                std::cin >> choice;
                if (choice == 'y') {
                    for (int j = i; j < count - 1; ++j) {
                        students[j] = students[j + 1];
                    }
                    --count;
                    std::cout << "Record deleted successfully." << std::endl;
                }
                break;
            }
        }

        if (!found)
            std::cout << "Student not found." << std::endl;

        char choice;
        std::cout << "Do you want to delete another record? [y/n]: ";
        std::cin >> choice;

        if (choice != 'y')
            break;
    }
}

void DirectoryStudent::searchMenu() {
    while (true) {
        std::cout << "*************************************" << std::endl;
        std::cout << "Telephone Directory: Search Menu" << std::endl;
        std::cout << "*************************************" << std::endl;

        char query[50];
        std::cout << "Enter ID or Name: ";
        std::cin >> query;

        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (strcmp(students[i].getId(), query) == 0 || strcmp(students[i].getName(), query) == 0) {
                found = true;
                std::cout << "Record Found:" << std::endl;
                students[i].display();
                break;
            }
        }

        if (!found)
            std::cout << "Student not found." << std::endl;

        char choice;
        std::cout << "Do you want to search another record? [y/n]: ";
        std::cin >> choice;

        if (choice != 'y')
            break;
    }
}

void DirectoryStudent::listDirectory() {
    std::cout << "*************************************" << std::endl;
    std::cout << "Telephone Directory Members" << std::endl;
    std::cout << "*************************************" << std::endl;
    std::cout << "Showing All Members:" << std::endl;

    for (int i = 0; i < count; ++i) {
        std::cout << "Record " << i + 1 << ":" << std::endl;
        students[i].display();
    }
    std::cout << "Total " << count << " records shown successfully." << std::endl;

    char choice;
    std::cout << "Press 'm' to go to Main Menu: ";
    std::cin >> choice;
}
