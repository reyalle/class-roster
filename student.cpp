#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->daysInCourse[0] = 0;
    this->daysInCourse[1] = 0;
    this->daysInCourse[2] = 0;
    this->degree = SECURITY;

}

// Setters
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
}

void Student::setDegreeProgram(degreeProgram degree) {
    this->degree = degree;
}

// Getters
string Student::getStudentID() {
    return studentID;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmailAddress() {
    return emailAddress;
}

int Student::getAge() {
    return age;
}

int Student::getDaysInCourse1() {
    return daysInCourse[0];
}

int Student::getDaysInCourse2() {
    return daysInCourse[1];
}

int Student::getDaysInCourse3() {
    return daysInCourse[2];
}

degreeProgram Student::getDegreeProgram() {
    return degree;
}

// Print function
void Student::printStudentInfo() {
    cout << studentID << "\t";
    cout << firstName << "\t" << lastName << "\t";
    cout << emailAddress << "\t";
    cout << age << "\t";
    cout << "{ " << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << " }\t";
    string degreeStrings[] = {"SECURITY", "NETWORK", "SOFTWARE"};
    cout << degreeStrings[degree] << endl;
}
