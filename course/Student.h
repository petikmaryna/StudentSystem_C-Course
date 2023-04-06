#pragma once
#include <string>
class Student {
	int id;
	std::string name;
public:
	Student(const int& st_id, const std::string& st_name);
	int getId() const;
	std::string getName()const;
};