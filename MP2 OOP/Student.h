#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
    char id[20];
    char name[50];
    char address[100];
    char phoneNumber[15];

public:
    Student();
    Student(const char* id, const char* name, const char* address, const char* phoneNumber);

    // Getter methods
    const char* getId() const;
    const char* getName() const;
    const char* getAddress() const;
    const char* getPhoneNumber() const;

    // Setter methods
    void setId(const char* newId);
    void setName(const char* newName);
    void setAddress(const char* newAddress);
    void setPhoneNumber(const char* newPhoneNumber);

    // Display method
    void display() const;
};

#endif
