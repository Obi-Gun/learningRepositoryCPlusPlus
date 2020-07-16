#include <iostream>
#include "Manager.h"

Manager::Manager(const char* str)
{
	_len = strlen(str) + 1;
	_str = new char[_len];
	strcpy_s(_str, strlen(str) + 1, str);
}

Manager::~Manager()
{
	std::cout << "~Manager()" << std::endl;
	delete[] _str;
}

void Manager::print()
{
	std::cout << _str << std::endl;
}
