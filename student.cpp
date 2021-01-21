#include <iostream>
#include <iomanip>
#include "degree.h"
#include "student.h"
using namespace std;

//D2d: Constructors
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->ageOfStudent = 0;
	for (int i = 0; i < numDaysArraySize; i++) {
		this->numDaysInCourse[i] = 0;
	}
}

Student::Student(string studentID2, string firstName2, string lastName2, string emailAddress2, int ageOfStudent2, int numDaysInCourse2[], DegreeProgram degree2) {
	this->studentID = studentID2;
	this->firstName = firstName2;
	this->lastName = lastName2;
	this->emailAddress = emailAddress2;
	this->ageOfStudent = ageOfStudent2;
	for (int i = 0; i < numDaysArraySize; i++) {
		this->numDaysInCourse[i] = numDaysInCourse2[i];
	}
	this->degree = degree2;
}//end Constructors

//D2a: Accessors
string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAgeOfStudent() {
	return ageOfStudent;
}

int* Student::getNumDaysInCourse() {
	return numDaysInCourse;
}
DegreeProgram Student::getDegree() {
	return degree;
}
//end of Accessors

//D2b: Mutators
void Student::setStudentID(string studentID2) {
	this->studentID = studentID2;
}

void Student::setFirstName(string firstName2) {
	this->firstName = firstName2;
}

void Student::setLastName(string lastName2) {
	this->lastName = lastName2;
}

void Student::setEmailAddress(string emailAddress2) {
	this->emailAddress = emailAddress2;
}

void Student::setAgeOfStudent(int ageOfStudent2) {
	this->ageOfStudent = ageOfStudent2;
}

void Student::setNumDaysInCourse(int numDaysInCourse2[]) {
	for (int i = 0; i < numDaysArraySize; i++)
		this->numDaysInCourse[i] = numDaysInCourse[i];
}

void Student::setDegree(DegreeProgram degree2) {
	this->degree = degree2;
}//end of mutators

//D2e: Print the roster
void Student::print() {
	std::cout << getStudentID() << "\t" << getFirstName() << "\t" << getLastName() << "\t" << getEmailAddress() << "\t" << getAgeOfStudent() << "\t";
	int* localNumDaysInCourse = getNumDaysInCourse();
	cout << localNumDaysInCourse[0] << "\t" << localNumDaysInCourse[1] << "\t" << localNumDaysInCourse[2] << "\t";
	cout << degreeStrings[(int)getDegree()] << endl;
}

//Destructor
Student::~Student() {
}