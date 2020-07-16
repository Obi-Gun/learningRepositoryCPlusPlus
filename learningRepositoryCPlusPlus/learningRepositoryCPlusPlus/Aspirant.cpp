#include <iostream>
#include "Aspirant.h"

Aspirant::Aspirant()
{
	_graduationWork = " < noname >";
}

Aspirant::Aspirant(const char* name, int group, int year, const char* course, const char* graduationWork) : Student_obi(name, group, year, course)
{
	_graduationWork = graduationWork;
}

Aspirant::~Aspirant()
{
}

void Aspirant::printInfo() const
{
	std::cout << "\nInfo about ";
	_name.print();
	std::cout << "\n\tGroup number: " << _group << ", year number: " << _year;
	std::cout << "\n\tCourse: \"";
	_course.print();
	std::cout << "\"";
	std::cout << "\n\tGraduation work: \"";
	_course.print();
	std::cout << "\"";
}
