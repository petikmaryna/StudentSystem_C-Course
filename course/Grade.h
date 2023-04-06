#pragma once
class Grade {
	int student_id;
	int course_id;
	char grade;
public:
	Grade(const int& st_id, const int& c_id, const char& gr);
	int getStudentId()const;
	int getCourseId()const;
	char getGrade()const;
};