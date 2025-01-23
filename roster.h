#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <string>

class Roster {
private:
    Student* classRosterArray[5];
    int lastIndex; // Keeps track of the last index

public:
    Roster();  // Default constructor
    ~Roster(); // Destructor to release allocated memory

    // Roster functions
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
             int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(std::string studentID);
    void printAll() const;
    void printAverageDaysInCourse(std::string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;

    // Populate roster with student data
    void populateRoster(const std::string studentData[], int numStudents);
};

#endif
