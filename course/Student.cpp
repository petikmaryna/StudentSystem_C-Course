#include "Student.h"

Student::Student(const int& st_id, const std::string& st_name) {
	id = st_id;
	name = st_name;
}
int Student::getId() const {
	return id;
}
std::string Student::getName() const {
	return name;
}
