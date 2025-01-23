#include "roster.h"
#include <iostream>
#include <sstream> 

// Constructor
Roster::Roster() {
    lastIndex = -1; // Initialize the index tracker
    for (int i = 0; i < 5; i++) {
        classRosterArray[i] = nullptr; // Set all pointers to nullptr
    }
}

// Add a student to class roster
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string email,
                 int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    lastIndex++; // Increment the index
    int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeProgram);
}

// Remove student by ID
void Roster::remove(std::string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i]; // Free memory
            classRosterArray[i] = nullptr; // Set the pointer to nullptr
            found = true;
            std::cout << "Student with ID " << studentID << " has been removed.\n";
            return;
        }
    }
    if (!found) {
        std::cout << "Error: Student with ID " << studentID << " not found.\n";
    }
}

// Print all students in class roster
void Roster::printAll() const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}

// Print average days in course for a student by ID
void Roster::printAverageDaysInCourse(std::string studentID) const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            const int* days = classRosterArray[i]->getDaysInCourse();
            int average = (days[0] + days[1] + days[2]) / 3;
            std::cout << "Student ID: " << studentID << ", Average Days in Course: " << average << "\n";
            return;
        }
    }
    std::cout << "Error: Student with ID " << studentID << " not found.\n";
}

// Print invalid email addresses
void Roster::printInvalidEmails() const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] != nullptr) {
            std::string email = classRosterArray[i]->getemail();
            // Check for '@' and '.' in email and absence of space
            if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos) {
                std::cout << "Invalid Email: " << email << "\n";
            }
        }
    }
}

// Print students by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

// Populate the roster from student data
void Roster::populateRoster(const std::string studentData[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        std::string data = studentData[i];
        std::string parsedValues[9]; // Array to store the parsed tokens
        int index = 0; // Tracks the current token

        for (size_t j = 0; j < data.length(); j++) {
            if (data[j] == ',') {
                index++;
            } else {
                parsedValues[index] += data[j];
            }
        }

        // Extract individual attributes
        std::string studentID = parsedValues[0];
        std::string firstName = parsedValues[1];
        std::string lastName = parsedValues[2];
        std::string email = parsedValues[3];
        int age = std::stoi(parsedValues[4]);
        int daysInCourse1 = std::stoi(parsedValues[5]);
        int daysInCourse2 = std::stoi(parsedValues[6]);
        int daysInCourse3 = std::stoi(parsedValues[7]);

        DegreeProgram degreeProgram;
        if (parsedValues[8] == "SECURITY") {
            degreeProgram = SECURITY;
        } else if (parsedValues[8] == "NETWORK") {
            degreeProgram = NETWORK;
        } else {
            degreeProgram = SOFTWARE;
        }

        // Add student to roster
        add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }

// Destructor
Roster::~Roster() {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }
}
}
