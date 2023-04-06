#include "Grade.h"

Grade::Grade(const int& st_id, const int& c_id, const char& gr) {
	student_id = st_id;
	course_id = c_id;
	grade = gr;
}
int Grade::getStudentId() const {
	return student_id;
}
int Grade::getCourseId() const {
	return course_id;
}
char Grade::getGrade() const {
	return grade;
}
