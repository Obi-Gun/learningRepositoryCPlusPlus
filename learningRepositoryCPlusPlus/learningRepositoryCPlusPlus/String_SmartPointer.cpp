#include <iostream>
#include "String_SmartPointer.h"

String_SmartPointer::String_SmartPointer(String_obi* pointer) {
	this->_ptr = pointer;
	this->_counterCopies = 0;
}

String_SmartPointer::String_SmartPointer(String_SmartPointer& obj)
{
	this->_ptr = obj._ptr;
	this->_counterCopies++;
}

String_SmartPointer::~String_SmartPointer()
{
	if (this->_counterCopies == 0 && this->_ptr != nullptr) {
		delete this->_ptr;
		std::cout << "\t<> ~String_SmartPointer()\n";
	}
	else {
		this->_counterCopies--;
		std::cout << "\t<> decrement smartpointer copies counter\n";
	}
}

String_SmartPointer::operator String_obi* ()
{
	return this->_ptr;
}

String_obi* String_SmartPointer::operator->()
{
	return this->_ptr;
}

String_SmartPointer String_SmartPointer::operator++()
{
	this->_ptr++;
	return *this;
}

String_SmartPointer String_SmartPointer::operator++(int)
{
	this->_ptr++;
	return *this;
}

String_SmartPointer String_SmartPointer::operator=(const String_SmartPointer& obj)
{
	this->_ptr = obj._ptr;
	this->_counterCopies++;
	return *this;
}




