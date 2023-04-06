#pragma once
#include <vector>
#include "Student.h"
#include "Course.h"
#include "Grade.h"

class StudentRecords {
	std::vector<Student> students;
	std::vector<Course> courses;
	std::vector<Grade> grades;
	float getNumGrade(const char& grade)const;
public:
	void addStudent(const int &id, const std::string &name);
	void addCourse(const int &cid, const std::string &cname, const int8_t &credits);
	void addGrade(const int& sid, const int& cid, const char &grade);
	std::string getCouseName(const int& courseId) const;
	int getNumberStudents();

	void printReportCard(const int& stId) const;
	void printReportCard(const int& stId, std::ostream& stream) const;
	void reportCardFile(std::ofstream& outFile);

	std::string getStudentName(const int& sid)const;
	unsigned char getCourseCredits(const int& cid)const;
	float getGPA(const int &sid)const;
};