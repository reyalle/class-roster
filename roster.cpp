#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"
#include <array>
#include <string>
using namespace std;

// Constructor
Roster::Roster(int classSize) {
    this->classSize = classSize;
    this->index = 0;
    for (int i = 0; i < classSize; ++i) {
        this->classRosterArray[i] = new Student;
    }
    return;
}
//Get student ID
string Roster::getStudentID(int index) {

    string id = classRosterArray[index]->getStudentID();
    return id;
}
//Create Student objects in Roster
void Roster::add(string studentData) {
    string id, firstName, lastName, email;
    int age, daysInCourse1, daysInCourse2, daysInCourse3;

    if (index < classSize) {
        classRosterArray[index] = new Student();

        std::string::size_type i = studentData.find(",");
        id = studentData.substr(0, i);
        classRosterArray[index]->setStudentID(id);

        std::string::size_type j = i + 1;
        i = studentData.find(",", j);
        firstName = studentData.substr(j, i - j);
        classRosterArray[index]->setFirstName(firstName);

        j = i + 1;
        i = studentData.find(",", j);
        lastName = studentData.substr(j, i - j);
        classRosterArray[index]->setLastName(lastName);

        j = i + 1;
        i = studentData.find(",", j);
        email = studentData.substr(j, i - j);
        classRosterArray[index]->setEmailAddress(email);

        j = i + 1;
        i = studentData.find(",", j);
        age = stoi(studentData.substr(j, i - j));
        classRosterArray[index]->setAge(age);

        j = i + 1;
        i = studentData.find(",", j);
        daysInCourse1 = stoi(studentData.substr(j, i - j));

        j = i + 1;
        i = studentData.find(",", j);
        daysInCourse2 = stoi(studentData.substr(j, i - j));

        j = i + 1;
        i = studentData.find(",", j);
        daysInCourse3 = stoi(studentData.substr(j, i - j));
        classRosterArray[index]->setDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);

        j = i + 1;
        string type = studentData.substr(j);

        if (type == "SECURITY") {
            classRosterArray[index]->setDegreeProgram(SECURITY);
        } else if (type == "NETWORK") {
            classRosterArray[index]->setDegreeProgram(NETWORK);
        } else if (type == "SOFTWARE") {
            classRosterArray[index]->setDegreeProgram(SOFTWARE);
        } else {
            cout << "Unknown Degree." << endl;
        }
        ++index;
    }
    return;
}

// Remove student from the roster
void Roster::remove(string id) {

    bool foundStudent = false;
    for (int i = 0; i < classSize; ++i) {
        if (classRosterArray[i] == nullptr) {
            continue;
        }
        else if (id == classRosterArray[i]->getStudentID()) {
            classRosterArray[i] = nullptr;
            foundStudent = true;
            break;
        }
    }
    if (foundStudent == false) {
            cout << "Error: Student " << id <<" Not Found." << endl;
    }
    else if (foundStudent == true) {
            cout << "Student " << id << " removed." << endl;
    }
    return;
}

// Print all students in roster
void Roster::printAll() {
    cout << "All current students: " << endl;
    for (int i = 0; i < classSize; ++i) {
        if (classRosterArray[i] == nullptr)
        {
            continue;
        }
        else {
            classRosterArray[i]->printStudentInfo();
        }
    }
    cout << endl;
    return;
}
// Print average number of days in course
void Roster::printAverageDaysInCourse(string id) {
    for (int i = 0; i < classSize; ++i) {
        if (id == classRosterArray[i]->getStudentID()) {
            int temparray[3] = { classRosterArray[i]->getDaysInCourse1(), classRosterArray[i]->getDaysInCourse2(), classRosterArray[i]->getDaysInCourse3() };
            double averageDays = (static_cast<double>(temparray[0]) + static_cast<double>(temparray[1]) + static_cast<double>(temparray[2])) / 3.0;
            cout << id << "'s Average Days In Course: " << averageDays << endl;;
        }
    }
    return;
}
// Print invalid emails
void Roster::printInvalidEmails() {
    for (int i = 0; i < classSize; ++i) {
        string email = classRosterArray[i]->getEmailAddress();
        if ((email.find(' ') != string::npos) || (email.find('.') == string::npos) || (email.find('@') == string::npos)) {
            cout << classRosterArray[i]->getStudentID() << "'s email address " << email << " is invalid." << endl;
        }
    }
    cout << endl;
    return;
}
// Print students within program
void Roster::printByDegreeProgram(degreeProgram degree) {
    string degreeString;
    if (degree == SECURITY) {
        degreeString = "SECURITY";
    }
    else if (degree == NETWORK) {
        degreeString = "NETWORK";
    }
    else if (degree == SOFTWARE) {
        degreeString = "SOFTWARE";
    }
    else {
        degreeString = "ERROR";
    }
    cout << "Students in degree program: " << degreeString << endl;
    int numStudents = 0;
    for (int i = 0; i < classSize; ++i) {
        if (classRosterArray[i]->getDegreeProgram() == degree) {
            classRosterArray[i]->printStudentInfo();
            ++numStudents;
        }
    }
    if (numStudents == 0) {
        cout << "No students with this degree found." << endl;
    }
    return;
}
// Destructor
Roster::~Roster() {

    return;
}
