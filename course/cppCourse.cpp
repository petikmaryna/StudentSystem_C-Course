#include <iostream>
#include <fstream>
#include <vector>
#include "Student.h"
#include "Course.h"
#include "Grade.h"
#include "StudentRecords.h"

void initialize();
StudentRecords studentRecords;
int main()
{
	initialize();
	std::ofstream outFile;
	int id;
	std::cout << "Print student's id: ";
	std::cin >> id;
	if (studentRecords.getNumberStudents() < id || id < 1) {
		std::cout << "Invalid id.";
	}
	else {
		studentRecords.printReportCard(id);
		studentRecords.reportCardFile(outFile);

	}
		return 0;
}
void initialize() {
	std::string str;
	std::string name;
	int id;
	int cid;
	int8_t credits;
	char grade;
	std::ifstream inFile;
	inFile.open("students.txt");
	if (inFile.fail()) {
		std::cout << "Student file not found";
	}
	else {
		while (!inFile.eof()) {
			getline(inFile, str);
			id = stoi(str);
			getline(inFile, str);
			name = str;
			studentRecords.addStudent(id, name);
		}
		inFile.close();
	}
	inFile.open("courses.txt");
	if (inFile.fail()) {
		std::cout << "Courses file not found";
	}
	else {
		while (!inFile.eof()) {
			getline(inFile, str);
			cid = stoi(str);
			getline(inFile, str);
			name = str;
			getline(inFile, str);
			credits = stoi(str);
			studentRecords.addCourse(cid, name, credits);
		}
		inFile.close();
	}
	inFile.open("grades.txt");
	if (inFile.fail()) {
		std::cout << "Grades file not found";
	}
	else {
		while (!inFile.eof()) {
			getline(inFile, str);
			id = stoi(str);
			getline(inFile, str);
			cid = stoi(str);
			getline(inFile, str);
			grade = str[0];
			studentRecords.addGrade(id, cid, grade);
		}
		inFile.close();
	}
	
}
