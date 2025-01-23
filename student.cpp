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

// Getters
std::string Student::getStudentID() const { return studentID; }
std::string Student::getFirstName() const { return firstName; }
std::string Student::getLastName() const { return lastName; }
std::string Student::getEmailAddress() const { return email; }
int Student::getAge() const { return age; }
int* Student::getDaysInCourse() const { return daysInCourse[]; }
DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }

// Setters
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

// Print
void Student::print() const {
    std::cout << "Student ID: " << studentID << "\t"
              << "First Name: " << firstName << "\t"
              << "Last Name: " << lastName << "\t"
              << "Email: " << email << "\t"
              << "Age: " << age << "\t"
              << "Days In Course: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\t"
              << "Degree Program: "
              << (degreeProgram == SECURITY ? "SECURITY" : degreeProgram == NETWORK ? "NETWORK" : "SOFTWARE")
              << std::endl;
}
