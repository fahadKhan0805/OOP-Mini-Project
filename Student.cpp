#include "Student.h"
#include <iostream>

Student::Student() {}

Student::Student(const char* id, const char* name, const char* address, const char* phoneNumber) {
    // Set ID
    int i = 0;
    while (id[i] != '\0' && i < 19) {
        this->id[i] = id[i];
        ++i;
    }
    this->id[i] = '\0';

    // Set Name
    i = 0;
    while (name[i] != '\0' && i < 49) {
        this->name[i] = name[i];
        ++i;
    }
    this->name[i] = '\0';

    // Set Address
    i = 0;
    while (address[i] != '\0' && i < 99) {
        this->address[i] = address[i];
        ++i;
    }
    this->address[i] = '\0';

    // Set Phone Number
    i = 0;
    while (phoneNumber[i] != '\0' && i < 14) {
        this->phoneNumber[i] = phoneNumber[i];
        ++i;
    }
    this->phoneNumber[i] = '\0';
}

const char* Student::getId() const {
    return id;
}

const char* Student::getName() const {
    return name;
}

const char* Student::getAddress() const {
    return address;
}

const char* Student::getPhoneNumber() const {
    return phoneNumber;
}

void Student::setId(const char* newId) {
    int i = 0;
    while (newId[i] != '\0' && i < 19) {
        id[i] = newId[i];
        ++i;
    }
    id[i] = '\0';
}

void Student::setName(const char* newName) {
    int i = 0;
    while (newName[i] != '\0' && i < 49) {
        name[i] = newName[i];
        ++i;
    }
    name[i] = '\0';
}

void Student::setAddress(const char* newAddress) {
    int i = 0;
    while (newAddress[i] != '\0' && i < 99) {
        address[i] = newAddress[i];
        ++i;
    }
    address[i] = '\0';
}

void Student::setPhoneNumber(const char* newPhoneNumber) {
    int i = 0;
    while (newPhoneNumber[i] != '\0' && i < 14) {
        phoneNumber[i] = newPhoneNumber[i];
        ++i;
    }
    phoneNumber[i] = '\0';
}

void Student::display() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
}
