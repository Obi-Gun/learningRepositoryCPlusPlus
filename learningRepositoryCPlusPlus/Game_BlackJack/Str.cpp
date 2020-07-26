#include <iostream>
#include "Str.h"

Str::Str() {
	this->setCurrentMaxStrLen();
	this->_string = new char[this->getCurrentMaxStrLen() + 1];
	this->_string[0] = '\0';
	recalcStrLen();
	//++_objCounter;
}

Str::Str(int maxStringLength) {
	this->setCurrentMaxStrLen(maxStringLength);
	this->_string = new char[this->getCurrentMaxStrLen() + 1];
	this->_string[0] = '\0';
	recalcStrLen();
	//++_objCounter;
}

Str::Str(const char* string) {
	this->setCurrentMaxStrLen(strlen(string));
	this->_string = new char[this->getCurrentMaxStrLen() + 1];
	strcpy_s(this->_string, this->getCurrentMaxStrLen() + 1, string);
	recalcStrLen();
	//++_objCounter;
}

Str::Str(Str& string_obi) {
	this->setCurrentMaxStrLen(string_obi.getStrLen());
	this->_string = new char[this->getCurrentMaxStrLen() + 1];
	strcpy_s(this->_string, this->getCurrentMaxStrLen() + 1, string_obi._string);
	recalcStrLen();
	//++_objCounter;
}

Str::Str(const Str& string_obi) {
	this->setCurrentMaxStrLen(string_obi.getStrLen());
	this->_string = new char[this->getCurrentMaxStrLen() + 1];
	strcpy_s(this->_string, this->getCurrentMaxStrLen() + 1, string_obi._string);
	recalcStrLen();
	//++_objCounter;
}

Str::~Str() {
	delete[] this->_string;
	//std::cout << "\n~String_obi()";
	//--_objCounter;
}

void Str::setCurrentMaxStrLen(int maxStringLength) {
	if (maxStringLength < this->_MIN_ARR_LEN) {
		this->_currentMaxStrLen = this->_MIN_ARR_LEN - 1;
	}
	else if (maxStringLength > this->_MAX_ARR_LEN - 1) {
		this->_currentMaxStrLen = this->_MAX_ARR_LEN - 1;
	}
	else {
		this->_currentMaxStrLen = maxStringLength;
	}
}

int Str::getCurrentMaxStrLen() const {
	return this->_currentMaxStrLen;
}

int Str::getStrLen() const {
	return this->_strLen;
}

const char* Str::getCharArr() const
{
	return this->_string;
}

/*int Str::getObjCounter()
{
	return Str::_objCounter;
}*/

Str Str::operator*(const Str& string) {
	Str result(strlen(this->_string) + strlen(string._string));
	int i = 0;
	char* str = this->_string;
	while (str = strpbrk(str, string._string)) {
		char* tmp = strchr(result._string, *str);
		if (!tmp) {
			result._string[i++] = *str;
		}
		++str;
	}
	result._string[i] = '\0';
	result.recalcStrLen();
	return result;
}

Str Str::operator=(const Str& str) {
	if (this->getCurrentMaxStrLen() < str.getStrLen()) {
		delete[] this->_string;
		this->setCurrentMaxStrLen(str.getStrLen());
		this->_string = new char[this->getCurrentMaxStrLen() + 1];
	}
	strcpy_s(this->_string, this->getCurrentMaxStrLen() + 1, str._string);
	recalcStrLen();
	return *this;
}

Str Str::operator+(const Str& str) {
	Str tmp(this->getStrLen() + str.getStrLen());
	strcpy_s(tmp._string, tmp.getCurrentMaxStrLen() + 1, this->_string);
	strcat_s(tmp._string, tmp.getCurrentMaxStrLen() + 1, str._string);
	tmp.recalcStrLen();
	return tmp;
}

char Str::operator[](int index)
{
	if (index < 0 || index > _strLen) {
		return '\0';
	}
	return _string[index];
}

int Str::operator()(char el)
{
	int index = -1;
	char* tmp;
	if (tmp = strchr(_string, el)) {
		index = tmp - _string;
	}
	return index;
}

Str::operator int()
{
	return _strLen;
}

Str& Str::operator++()
{
	if (this->_strLen < this->_currentMaxStrLen) {
		_string[_strLen] = ' ';
		_string[_strLen + 1] = '\0';
		recalcStrLen();
		return *this;
	}
	Str* tmp = new Str(this->getStrLen() + _NEW_EMPTY_SPACE);
	strcpy_s(tmp->_string, tmp->getCurrentMaxStrLen() + 1, this->_string);
	strcat_s(tmp->_string, tmp->getCurrentMaxStrLen() + 1, " ");
	tmp->recalcStrLen();
	*this = *tmp;
	return *this;
}

Str& Str::operator++(int)
{
	Str* tmp2 = new Str;
	*tmp2 = *this;
	if (this->_strLen < this->_currentMaxStrLen) {

		_string[_strLen] = ' ';
		_string[_strLen + 1] = '\0';
		recalcStrLen();
		return *tmp2;
	}
	Str* tmp = new Str(this->getStrLen() + _NEW_EMPTY_SPACE);
	strcpy_s(tmp->_string, tmp->getCurrentMaxStrLen() + 1, this->_string);
	strcat_s(tmp->_string, tmp->getCurrentMaxStrLen() + 1, " ");
	tmp->recalcStrLen();
	*this = *tmp;
	return *tmp2;
}

Str& Str::operator--()
{
	if (this->_strLen <= this->_MIN_ARR_LEN) {
		return *this;
	}
	_string[_strLen - 1] = '\0';
	recalcStrLen();
	return *this;
}

Str& Str::operator--(int)
{
	if (this->_strLen <= this->_MIN_ARR_LEN) {
		return *this;
	}
	Str* tmp = new Str;
	*tmp = *this;
	_string[_strLen - 1] = '\0';
	recalcStrLen();
	return *tmp;
}

void* Str::operator new(size_t size)
{
	void* ptr = malloc(size);
	/*if (ptr) {
		std::cout << " <" << size << "_bytes_were_allocated_> ";
	}
	else {
		std::cout << " <_memory_wasn`t_allocated_> ";
	}*/
	return ptr;
}

void* Str::operator new[](size_t size)
{
	void* ptr = malloc(size);
	return ptr;
}

void Str::operator delete(void* ptr)
{
	~Str();
	//free(ptr);
	//std::cout << " <" << sizeof(String_obi) << "_bytes_were_released_> ";
}

void Str::operator delete[](void* ptr)
{
	~Str();
	//free(ptr);
}

void Str::print() const {
	std::cout << this->_string;
}

void Str::recalcStrLen() {
	this->_strLen = strlen(this->_string);
}

std::ostream& operator << (std::ostream& out, Str& obj) {
	for (int i = 0; i < obj.getStrLen(); ++i) {
		out << obj.getCharArr()[i];
	}
	return out;
}

std::istream& operator >> (std::istream& in, Str& obj) {
	const int lenTmp = 256;
	char tmp[lenTmp];
	in >> tmp;
	Str* newStr = new Str(tmp);
	obj = *newStr;
	return in;
}