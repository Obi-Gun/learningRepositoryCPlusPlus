#include <iostream>
#include "Student_obi.h"

Student_obi::Student_obi()
{
	_name = " < noname >";
	_group = 0;
	_year = 0;
	_course = " < noname >";
}

Student_obi::Student_obi(const char* name, int group, int year, const char* course)
{
	_name = name;
	_group = group;
	_year = year;
	_course = course;
}

Student_obi::~Student_obi()
{
}

void Student_obi::printInfo() const
{
	std::cout << "\nInfo about ";
	_name.print();
	std::cout << "\n\tGroup number: " <<_group << ", year number: " << _year;
	std::cout << "\n\tCourse: \"";
	_course.print();
	std::cout << "\"";
}
