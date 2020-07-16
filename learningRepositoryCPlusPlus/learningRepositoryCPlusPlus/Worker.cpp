#include <iostream>
#include "Worker.h"

Worker::Worker(const char* str)
{
	_len = strlen(str) + 1;
	_str = new char[_len];
	strcpy_s(_str, strlen(str) + 1, str);
}

Worker::~Worker()
{
	std::cout << "~Worker()" << std::endl;
	delete[] _str;
}

void Worker::print()
{
	std::cout << _str << std::endl;
}
