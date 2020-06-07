#include <iostream>
#include "String_SmartPointer.h"

String_SmartPointer::String_SmartPointer(String_obi* pointer) {
	this->p_ = pointer;
	this->counterCopies_ = 0;
}

String_SmartPointer::String_SmartPointer(String_SmartPointer& obj)
{
	this->p_ = obj.p_;
	this->counterCopies_++;
}

String_SmartPointer::~String_SmartPointer()
{
	if (this->counterCopies_ == 0 && this->p_ != nullptr) {
		delete this->p_;
		std::cout << "\t<> ~String_SmartPointer()\n";
	}
	else {
		this->counterCopies_--;
		std::cout << "\t<> decrement smartpointer copies counter\n";
	}
}

String_SmartPointer::operator String_obi* ()
{
	return this->p_;
}

String_obi* String_SmartPointer::operator->()
{
	return this->p_;
}

String_SmartPointer String_SmartPointer::operator++()
{
	this->p_++;
	return *this;
}

String_SmartPointer String_SmartPointer::operator++(int)
{
	this->p_++;
	return *this;
}

String_SmartPointer String_SmartPointer::operator=(const String_SmartPointer& obj)
{
	this->p_ = obj.p_;
	this->counterCopies_++;
	return *this;
}




