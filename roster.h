#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include <array>
#include "degree.h"
#include "student.h"

using namespace std;

class Student;
class Roster {

Student* classRosterArray[5];

public:

    Roster(int classSize);
    string getStudentID(int index);
    void add(string studentData);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(degreeProgram degree);
    int classSize;
    int index;
    ~Roster();
};

#endif
