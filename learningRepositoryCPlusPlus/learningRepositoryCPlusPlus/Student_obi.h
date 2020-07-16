#ifndef Student_obi_Class
#define Student_obi_Class
#include "String_obi.h"

class Student_obi
{
protected:
	String_obi _name;
	int _group;
	int _year;
	String_obi _course;

public:
	Student_obi();
	Student_obi(const char* name, int group, int year, const char* course);
	~Student_obi();

	void printInfo() const;
};
#endif