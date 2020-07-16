#include <iostream>
#include "President.h"

President::President(const char* str)
{
	_len = strlen(str) + 1;
	_str = new char[_len];
	strcpy_s(_str, strlen(str) + 1, str);
}

President::~President()
{
	std::cout << "~President()" << std::endl;
	delete[] _str;
}

void President::print()
{
	std::cout << this->_str << std::endl;
}
