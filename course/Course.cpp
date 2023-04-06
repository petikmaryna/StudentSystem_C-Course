#include "Course.h"

Course::Course(const int& c_id, const std::string& c_name, const int8_t& c_credits) {
	id = c_id;
	name = c_name;
	credits = c_credits;
}
int Course::getId() const {
	return id;
}
std::string Course::getName() const {
	return name;
}
int8_t Course::getCredits() const {
	return credits;
}