#ifndef Student_Class
#define Student_Class
#include <iostream>

using namespace std;

class Student
{
protected:
	string _name;
	string _surname;
	int _group;
	int _year;
	string _course;

public:
	Student();
	Student(const char* name, int group, int year, const char* course);
	Student(const char* name, const char* surname, int year);
	Student(string name, string surname, int year);
	~Student();


	string getName() const;
	string getSurname() const;
	int getYear() const;
	void printInfo() const;
};

std::ostream& operator << (std::ostream& out, Student& obj);
#endif