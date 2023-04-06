#pragma once
#include <string>
#include <cstdint>
class Course {
	int id;
	std::string name;
	int8_t credits;
public:
	Course(const int& c_id, const std::string& c_name, const int8_t& c_credits);
	int getId()const;
	std::string getName()const;
	int8_t getCredits()const;
};