#ifndef AspirantClass
#define AspirantClass
#include "String_obi.h"
#include "Student.h"

class Aspirant : public Student
{
private:
	String_obi _graduationWork;

public:
	Aspirant();
	Aspirant(const char* name, int group, int year, const char* course, const char* graduationWork);
	~Aspirant();

	void printInfo() const;


};
#endif // !AspirantClass