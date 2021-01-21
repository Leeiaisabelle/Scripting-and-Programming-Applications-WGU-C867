#include <string>
#include <vector>
#include <iostream>
#include "roster.h"
#include "degree.h"
#include "student.h"
using namespace std;

//F: Add main() function
int main() {

	//F1: course title, programming language, student ID, name
	cout << "C867 - Scripting and Programming - Applications" << endl;
	cout << "`````````````````Written in C++````````````````" << endl;
	cout << "````````````````````00090592```````````````````" << endl;
	cout << "```````````````by Leeia Isabelle```````````````" << endl;
	cout << "\n";

	int numStudents = 5;
	
	//A: Modify to include my personal info
	const string studentData[5] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Leeia,Isabelle,lisabel@wgu.edu,32,20,30,40,SOFTWARE"//my info
	};//end studentData

	//F2: Create an instance of the Roster class called classRoster
	Roster* classRoster = new Roster(numStudents);

	//F3: Add each student to classRoster
	for (int i = 0; i < numStudents; i++) {
		classRoster->firstParseThenAdd(studentData[i]);
	}

	//F4a: Printing class roster
	cout << "CLASS ROSTER: " << endl;
	classRoster->printAll();
	cout << "\n";

	//F4b: Print invalid emails
	cout << "INVALID EMAIL ADDRESSES: " << endl;
	classRoster->printInvalidEmails();
	cout << "\n";

	//F4c: Print average number of days in courses for each student
	cout << "AVERAGE NUMBER OF DAYS IN COURSE: " << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster->printAverageNumDaysInCourse(classRoster->getStudentAt(i)->getStudentID());
	}
	cout << "\n";

	//F4d: Print students in SOFTWARE degree progran
	cout << "SOFTWARE STUDENTS: " << endl;
	classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << "\n";

	//F4e: Remove A3 from student roster
	cout << "REMOVING STUDENT A3 FROM ROSTER." << endl;
	if (classRoster->remove("A3")) {
		classRoster->printAll(); //F4f: Print all
		numStudents--;
	}
	cout << "\n";

	//F4g: Remove A3 again
	if (classRoster->remove("A3")) classRoster->printAll();
	else cout << "STUDENT A3 WAS NOT FOUND." << endl;
	
	system ("pause");
	return 0;

}//end main function
