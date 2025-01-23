#include <string>
#include "degree.h"
#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string email;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;
public:
    Student(
        std::string studentID,
        std::string firstName,
        std::string lastName,
        std::string email,
        int age,
        int daysInCourse[],
        DegreeProgram degreeProgram
    );

    // Getters
    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    int getDaysInCourse() const;
    DegreeProgram getDegreeProgram() const;

    // Setters
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string email);
    void setAge(int age);
    void setDaysInCourse(int daysInCOurse[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    //Print
    void print() const;
};

#endif
