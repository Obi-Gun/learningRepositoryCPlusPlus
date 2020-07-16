#ifndef Manager_Class
#define Manager_Class
#include "Employer.h"
class Manager :
	public Employer
{
private:
	char* _str;
	int _len;

public:
	Manager(const char* str);
	virtual ~Manager();

	void print();
};
#endif