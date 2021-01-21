#include <string>
#include <iostream>
#include <iomanip>
#include "roster.h"
#include "student.h"
#include "degree.h"

Roster::Roster() {
	this->rosterSize = 0;
	this->studentIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int rosterSize) {
	this->rosterSize = rosterSize;
	this->studentIndex = -1;
	this->classRosterArray = new Student* [rosterSize];
}

Student* Roster::getStudentAt(int studentIndex) {
	return classRosterArray[studentIndex];
}

void Roster::firstParseThenAdd(string row) {
	if (studentIndex < rosterSize) {
		studentIndex++;
	}
		//Parse student ID
		int rightSide = row.find(",");
		string localStudentID = row.substr(0, rightSide);

		//Parse first name
		int leftSide = rightSide + 1;
		rightSide = row.find(",", leftSide);
		string localFirstName = row.substr(leftSide, rightSide - leftSide);

		//Parse lastname
		leftSide = rightSide + 1;
		rightSide = row.find(",", leftSide);
		string localLastName = row.substr(leftSide, rightSide - leftSide);

		//Parse email address
		leftSide = rightSide + 1;
		rightSide = row.find(",", leftSide);
		string localEmail = row.substr(leftSide, rightSide - leftSide);

		//Parse age
		leftSide = rightSide + 1;
		rightSide = row.find(",", leftSide);
		int localAge = stoi(row.substr(leftSide, rightSide - leftSide));

		//Parse course 1
		leftSide = rightSide + 1;
		rightSide = row.find(",", leftSide);
		int localCourse1 = stoi(row.substr(leftSide, rightSide - leftSide));

		//Parse course 2
		leftSide = rightSide + 1;
		rightSide = row.find(",", leftSide);
		int localCourse2 = stoi(row.substr(leftSide, rightSide - leftSide));

		//Parse course 3
		leftSide = rightSide + 1;
		rightSide = row.find(",", leftSide);
		int localCourse3 = stoi(row.substr(leftSide, rightSide - leftSide));
		
		//Parse degree program
		leftSide = rightSide + 1;
		rightSide = row.find(",", leftSide);
		DegreeProgram localDegree0;
		string localDegree1 = row.substr(leftSide, rightSide - leftSide);
		if (localDegree1 == "SOFTWARE") {
			localDegree0 = DegreeProgram::SOFTWARE;
		}
		else if (localDegree1 == "SECURITY") {
			localDegree0 = DegreeProgram::SECURITY;
		}
		else if (localDegree1 == "NETWORK") {
			localDegree0 = DegreeProgram::NETWORK;
		}
		else {
			cerr << "MAJOR NOT FOUND.\nPLEASE ENSURE ALL STUDENTS HAVE A MAJOR AND TRY AGAIN." << endl;
			exit(-1);
		}

		//Add parsed data back to array
		add(localStudentID, localFirstName, localLastName, localEmail, localAge, localCourse1, localCourse2, localCourse3, localDegree0);
	
}// end firstParseThenAdd

//E3a: Add variables from D1
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int ageOfStudent, int courseOne, int courseTwo, int courseThree, DegreeProgram degree) {
	int courseDays[Student::numDaysArraySize];

	courseDays[0] = courseOne;
	courseDays[1] = courseTwo;
	courseDays[2] = courseThree;

	classRosterArray[studentIndex] = new Student(studentID, firstName, lastName, emailAddress, ageOfStudent, courseDays, degree);
}

//E3b: Remove student by student ID
bool Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i <= studentIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[studentIndex]; //moves last student to empty slot
			studentIndex--;
		}
	}
	return found;
}

//E3c: Print a complete list of student data
void Roster::printAll() {
	for (int i = 0; i <= this->studentIndex; i++) (this->classRosterArray)[i]->print();
}

void Roster::printInvalidEmails() {
	
	for (int i = 0; i < 5; ++i) {
		string localStudentID = classRosterArray[i]->getStudentID();
		string localEmail = classRosterArray[i]->getEmailAddress();
		if ((localEmail.find("@") == string::npos || localEmail.find(".") == string::npos) || (localEmail.find(" ") != string::npos)) {
			cout << "Student " << localStudentID << ": " << localEmail << endl;
		}
	}

}

//E3f: Print roster by degree program
void Roster::printByDegreeProgram(DegreeProgram degree2) {
	for (int i = 0; i < 5; ++i) {
		DegreeProgram localDegree = classRosterArray[i]->getDegree();
		if (localDegree == degree2) {
			classRosterArray[i]->print();
		}
	}
}

//E3d: Print average number of days in courses for each student
void Roster::printAverageNumDaysInCourse(string studentID2) {
	int average = 0;

	for (int i = 0; i < 5; ++i) {
		string localStudentID = classRosterArray[i]->getStudentID();
		if (localStudentID == studentID2) {
			average = ((classRosterArray[i]->getNumDaysInCourse()[0] + classRosterArray[i]->getNumDaysInCourse()[1] + classRosterArray[i]->getNumDaysInCourse()[2]) / 3);
			cout << "Student " << localStudentID << "'s average time in each class: " << average << endl;
		}
	}
}

//F5: Roster destructor
Roster::~Roster() {
	for (int i = 0; i < 5; ++i) {
		delete classRosterArray[i];
	}
	delete classRosterArray;
}