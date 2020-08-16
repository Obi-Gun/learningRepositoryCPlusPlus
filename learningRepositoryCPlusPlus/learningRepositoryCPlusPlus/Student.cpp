#include <iostream>
#include "Student.h"

Student::Student()
{
	_name = " < noname >";
	_group = 0;
	_year = 0;
	_course = " < noname >";
}

Student::Student(const char* name, int group, int year, const char* course)
{
	_name = name;
	_group = group;
	_year = year;
	_course = course;
}

Student::Student(const char* name, const char* surname, int year)
{
	_name = name;
	_surname = surname;
	_year = year;
}

Student::Student(string name, string surname, int year)
{
	_name = name;
	_surname = surname;
	_year = year;
}

Student::~Student()
{
}

string Student::getName() const
{
	return _name;
}

string Student::getSurname() const
{
	return _surname;
}

int Student::getYear() const
{
	return _year;
}

void Student::printInfo() const
{
	std::cout << "\nInfo about ";
	//_name.print();
	//std::cout << "\n\tGroup number: " <<_group << ", year number: " << _year;
	//std::cout << "\n\tCourse: \"";
	//_course.print();
	//std::cout << "\"";
}

std::ostream& operator<<(std::ostream& out, Student& obj)
{
	printf("%10s \t%10s \t%3i", obj.getName().c_str(), obj.getSurname().c_str(), obj.getYear());
	return out;
}
