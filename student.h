#pragma once
#include <string>
#include "degree.h"

//D1: Create a Student class
class Student {
public:
	const static int numDaysArraySize = 3;//Size of array of number of days to complete course
	
protected:
	//D1: Create Student class with each of the following variables
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int ageOfStudent;
	int numDaysInCourse [ 3 ];
	DegreeProgram degree;

public:
	//D2a: Accessors
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAgeOfStudent();
	int* getNumDaysInCourse();
	virtual DegreeProgram getDegree();

	//D2b: Mutators
	void setStudentID(string studentID2);
	void setFirstName(string firstName2);
	void setLastName(string lastName2);
	void setEmailAddress(string emailAddress2);
	void setAgeOfStudent(int ageOfStudent2);
	void setNumDaysInCourse(int numDaysInCourse2[]);
	void setDegree(DegreeProgram degree2);

	//D2d: Constructors
	Student();
	Student(
		string studentID2,
		string firstName2,
		string lastName2,
		string emailAddress2,
		int ageOfStudent2,
		int numDaysCourse2[],
	DegreeProgram degree2);


	//D2e: Print the roster
	void print();

	~Student();
};//end Student class
