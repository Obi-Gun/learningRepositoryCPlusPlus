#ifndef Worker_Class
#define Worker_Class
#include "Employer.h"
class Worker :
	public Employer
{
private:
	char* _str;
	int _len;

public:
	Worker(const char* str);
	virtual ~Worker();

	void print();
};
#endif