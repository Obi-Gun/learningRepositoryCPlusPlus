#ifndef President_Class
#define President_Class
#include "Employer.h"
class President :
	public Employer
{
private:
	char* _str;
	int _len;
public:
	President(const char* str);
	~President();

	void print();

};
#endif