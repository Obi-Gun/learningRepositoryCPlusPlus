#ifndef Human_Guardian
#define Human_Guardian

#include "String_obi.h"

class Human
{
private:
	String_obi _name;

public:
	Human();
	Human(const char* name);
	Human(Human& human);
	~Human();

	void setName(const char* name);
	String_obi getName() const;

	void print();

};
#endif