#include "roster.h"
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

    // Print course information
    cout << "Course Title: Scripting and Programming Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 012126141" << endl;
    cout << "Name: Rezart Xeka" << endl << endl;

    // Student data table
    const string studentData[] = {
       "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
       "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
       "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
       "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
       "A5,Rezart,Xeka,reyxeka@gmail.com,27,20,35,15,SOFTWARE"
    };

    // Create class roster
    Roster* classRoster = new Roster(5);

    // Populate roster with students
    for (int i = 0; i < 5; ++i) {
        classRoster->add(studentData[i]);
    };

    //Print roster
    classRoster->printAll();

    // Print invalid emails
    classRoster->printInvalidEmails();

    for (int i = 0; i < 5; ++i) {

       classRoster->printAverageDaysInCourse(classRoster->getStudentID(i));
    }
   cout << endl;

   // Print students in software program
   classRoster->printByDegreeProgram(SOFTWARE);
   cout << endl;

   // Remove student ID
   classRoster->remove("A3");
   cout << endl;

   // Print new roster
   classRoster->printAll();
   cout << endl;

   // Test error
   classRoster->remove("A3");
   cout << endl;

   //Destructor
   classRoster->~Roster();
   delete classRoster;


    return 0;
}
