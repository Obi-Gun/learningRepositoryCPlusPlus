#ifndef HumanClass
#define HumanClass

#include "String_obi.h"

class Human
{
private:
	String_obi name_;

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