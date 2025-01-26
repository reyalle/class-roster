#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;


class Student {

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[3];
    degreeProgram degree;

public:

    Student();

    // Setters
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram(degreeProgram degree);

    // Getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int getDaysInCourse1();
    int getDaysInCourse2();
    int getDaysInCourse3();
    degreeProgram getDegreeProgram();

    //Print
    void printStudentInfo();
};

#endif

