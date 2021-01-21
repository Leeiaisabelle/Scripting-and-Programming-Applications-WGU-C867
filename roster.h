#pragma once
#include "student.h"


//E: Create Roster class
class Roster {
private:
	int studentIndex;
	int rosterSize;
	//E1: Create array of pointers, classRosterArray
	Student** classRosterArray;

public:
	Roster();
	Roster(int rosterSize);

	Student* getStudentAt(int studentIndex);

	//E2a and E2b: Parse and Add strings from studentData
	void firstParseThenAdd(string studentData);
	
	//E3a: Add variables from D1
	void add(string studentID2, string firstName2, string lastName2, string emailAddress2, int ageOfStudent2, int courseOne, int courseTwo, int courseThree, DegreeProgram degree);
	
	//E3b: Remove student by student ID
	bool remove(string studentID2);

	//E3c: Print a complete list of student date
	void printAll();

	//E3d: Print student's everage days in 3 courses
	void printAverageNumDaysInCourse(string studentID2);

	//E3e: Print invalid email addresses
	void printInvalidEmails();

	//E3f: Print roster by degree program 
	void printByDegreeProgram(DegreeProgram degree2);

	

	//F5: Roster destructor
	~Roster();
};//end Roster class

