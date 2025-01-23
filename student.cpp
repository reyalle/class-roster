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
