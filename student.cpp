#include "student.h"
#include <iostream>

//Constuctor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string email,
                int age, int daysInCourse[], DegreeProgram degreeProgram) {
    this-> studentID = studentID;
    this-> firstName = firstName;
    this-> lastName = lastName;
    this->email = email;
    this->age = age;
    for(int i = 0; i < 3; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    };
    this->degreeProgram = degreeProgram;
}

// Getters (Accessors)
std::string Student::getStudentID() const { return studentID; }
std::string Student::getFirstName() const { return firstName; }
std::string Student::getLastName() const { return lastName; }
std::string Student::getEmailAddress() const { return email; }
int Student::getAge() const { return age; }
int* Student::getDaysInCourse() const { return daysInCourse[]; }
DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }

// Setters (Mutators)
void Student::setStudentID(std::string studentID) { this->studentID = studentID; }
void Student::setFirstName(std::string firstName) { this->firstName = firstName; }
void Student::setLastName(std::string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(std::string emailAddress) { this->email = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse[]) {
    for (int i = 0; i < 3; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }


