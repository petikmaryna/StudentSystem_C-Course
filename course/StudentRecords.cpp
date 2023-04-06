#include "StudentRecords.h"
#include <iostream>
#include <fstream>

void StudentRecords::addStudent(const int& id, const std::string& name) {
	students.push_back(Student(id, name));
}
void StudentRecords::addCourse(const int& cid, const std::string& cname, const int8_t& credits) {
	courses.push_back(Course(cid, cname, credits));
}
void StudentRecords::addGrade(const int& sid, const int& cid, const char& grade) {
	grades.push_back(Grade(sid, cid, grade));
}

int StudentRecords::getNumberStudents() {
	return students.size();
}

void StudentRecords::printReportCard(const int& stId) const {
	std::string studentName = getStudentName(stId);
	float GPA = getGPA(stId);
	std::cout << "Report card for " << getStudentName(stId) << '\n';
	for (const auto& grade : grades) {
		if (grade.getStudentId() == stId) {
			std::cout << getCouseName(grade.getCourseId()) << ": " << grade.getGrade() << '\n';
		}
	}
	std::cout << "GPA: " << GPA << '\n';

}
void StudentRecords::printReportCard(const int& stId, std::ostream& stream) const {
	std::string studentName = getStudentName(stId);
	float GPA = getGPA(stId);
	stream << "Report card for " << getStudentName(stId) << '\n';
	for (const auto& grade : grades) {
		if (grade.getStudentId() == stId) {
			stream << getCouseName(grade.getCourseId()) << ": " << grade.getGrade() << '\n';
		}
	}
	stream << "GPA: " << GPA << '\n';
}
void StudentRecords::reportCardFile(std::ofstream& outFile) {
	int sid;
	outFile.open("report.txt");
	if (outFile.fail()) {
		std::cout << "Could not open report file.";
	}
	else {
		outFile << "=======================================" << '\n';
		for (const auto& student : students) {
			sid = student.getId();
			printReportCard(sid, outFile);
			outFile << "=======================================" << '\n';
		}
		outFile.close();
	}
	
}
float StudentRecords::getNumGrade(const char& grade)const {
	float numGrade = 0.0f;
	switch (grade) {
	case 'A': numGrade = 4.0f;
		break;
	case 'B': numGrade = 3.0f;
		break;
	case 'C': numGrade = 2.0f;
		break;
	case 'D': numGrade = 1.0f;
		break;
	case 'F': numGrade = 0.0f;
		break;
	};
	return numGrade;
}

std::string StudentRecords::getStudentName(const int& sid) const{
	int i = 0;
	while (i < students.size() && students[i].getId() != sid)
		i++;
	return students[i].getName();
}

std::string StudentRecords::getCouseName(const int& courseId) const{
	int j = 0;
	while (j < courses.size() && courses[j].getId() != courseId)
		j++;
	return courses[j].getName();
}
unsigned char StudentRecords::getCourseCredits(const int& cid)const {
	int j = 0;
	while (j < courses.size() && courses[j].getId() != cid) {
		j++;
	}
	return courses[j].getCredits();
}
float StudentRecords::getGPA(const int& sid) const {

	float totalPoints = 0.0f;
	float totalCredits = 0.0f;
	for (const auto& grade : grades) {
		if (grade.getStudentId() == sid) {
			unsigned char currentCredits = getCourseCredits(grade.getCourseId());
			totalCredits += currentCredits;
			totalPoints += getNumGrade(grade.getGrade()) * currentCredits;
		}
	}
	return totalPoints / totalCredits;
}