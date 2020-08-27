#include <iostream>
#include "StringBuilder.h"

StringBuilder::StringBuilder() {
	this->setCurrentMaxStrLen();
	this->_string = new char[this->getCurrentMaxStrLen() + 1];
	this->_string[0] = '\0';
	recalcStrLen();
	//++_objCounter;
}

StringBuilder::StringBuilder(int maxStringLength) {
	this->setCurrentMaxStrLen(maxStringLength);
	this->_string = new char[this->getCurrentMaxStrLen() + 1];
	this->_string[0] = '\0';
	recalcStrLen();
	//++_objCounter;
}

StringBuilder::StringBuilder(const char* string) {
	this->setCurrentMaxStrLen(strlen(string));
	this->_string = new char[this->getCurrentMaxStrLen() + 1];
	strcpy_s(this->_string, this->getCurrentMaxStrLen() + 1, string);
	recalcStrLen();
	//++_objCounter;
}

StringBuilder::StringBuilder(StringBuilder& string_obi) {
	this->setCurrentMaxStrLen(string_obi.getStrLen());
	this->_string = new char[this->getCurrentMaxStrLen() + 1];
	strcpy_s(this->_string, this->getCurrentMaxStrLen() + 1, string_obi._string);
	recalcStrLen();
	//++_objCounter;
}

StringBuilder::StringBuilder(const StringBuilder& string_obi) {
	this->setCurrentMaxStrLen(string_obi.getStrLen());
	this->_string = new char[this->getCurrentMaxStrLen() + 1];
	strcpy_s(this->_string, this->getCurrentMaxStrLen() + 1, string_obi._string);
	recalcStrLen();
	//++_objCounter;
}

StringBuilder::~StringBuilder() {
	delete[] this->_string;
	std::cout << "\n~String_obi()";
	//--_objCounter;
}

void StringBuilder::setCurrentMaxStrLen(int maxStringLength) {
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

int StringBuilder::getCurrentMaxStrLen() const {
	return this->_currentMaxStrLen;
}

int StringBuilder::getStrLen() const {
	return this->_strLen;
}

const char* StringBuilder::getCharArr() const
{
	return this->_string;
}

//int String_obi::getObjCounter()
//{
//	return String_obi::_objCounter;
//}

StringBuilder StringBuilder::operator*(const StringBuilder& string) {
	StringBuilder result(strlen(this->_string) + strlen(string._string));
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

StringBuilder StringBuilder::operator=(const StringBuilder& str) {
	if (this->getCurrentMaxStrLen() < str.getStrLen()) {
		delete[] this->_string;
		this->setCurrentMaxStrLen(str.getStrLen());
		this->_string = new char[this->getCurrentMaxStrLen() + 1];
	}
	strcpy_s(this->_string, this->getCurrentMaxStrLen() + 1, str._string);
	recalcStrLen();
	return *this;
}

StringBuilder StringBuilder::operator+(const StringBuilder& str) {
	StringBuilder tmp(this->getStrLen() + str.getStrLen());
	strcpy_s(tmp._string, tmp.getCurrentMaxStrLen() + 1, this->_string);
	strcat_s(tmp._string, tmp.getCurrentMaxStrLen() + 1, str._string);
	tmp.recalcStrLen();
	return tmp;
}

char StringBuilder::operator[](int index)
{
	if (index < 0 || index > _strLen) {
		return '\0';
	}
	return _string[index];
}

int StringBuilder::operator()(char el)
{
	int index = -1;
	char* tmp;
	if (tmp = strchr(_string, el)) {
		index = tmp - _string;
	}
	return index;
}

StringBuilder::operator int()
{
	return _strLen;
}

StringBuilder& StringBuilder::operator++()
{
	if (this->_strLen < this->_currentMaxStrLen) {
		_string[_strLen] = ' ';
		_string[_strLen + 1] = '\0';
		recalcStrLen();
		return *this;
	}
	StringBuilder* tmp = new StringBuilder(this->getStrLen() + _NEW_EMPTY_SPACE);
	strcpy_s(tmp->_string, tmp->getCurrentMaxStrLen() + 1, this->_string);
	strcat_s(tmp->_string, tmp->getCurrentMaxStrLen() + 1, " ");
	tmp->recalcStrLen();
	*this = *tmp;
	return *this;
}

StringBuilder& StringBuilder::operator++(int)
{
	StringBuilder* tmp2 = new StringBuilder;
	*tmp2 = *this;
	if (this->_strLen < this->_currentMaxStrLen) {

		_string[_strLen] = ' ';
		_string[_strLen + 1] = '\0';
		recalcStrLen();
		return *tmp2;
	}
	StringBuilder* tmp = new StringBuilder(this->getStrLen() + _NEW_EMPTY_SPACE);
	strcpy_s(tmp->_string, tmp->getCurrentMaxStrLen() + 1, this->_string);
	strcat_s(tmp->_string, tmp->getCurrentMaxStrLen() + 1, " ");
	tmp->recalcStrLen();
	*this = *tmp;
	return *tmp2;
}

StringBuilder& StringBuilder::operator--()
{
	if (this->_strLen <= this->_MIN_ARR_LEN) {
		return *this;
	}
	_string[_strLen - 1] = '\0';
	recalcStrLen();
	return *this;
}

StringBuilder& StringBuilder::operator--(int)
{
	if (this->_strLen <= this->_MIN_ARR_LEN) {
		return *this;
	}
	StringBuilder* tmp = new StringBuilder;
	*tmp = *this;
	_string[_strLen - 1] = '\0';
	recalcStrLen();
	return *tmp;
}

void* StringBuilder::operator new(size_t size)
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

void* StringBuilder::operator new[](size_t size)
{
	void* ptr = malloc(size);
	return ptr;
}

void StringBuilder::operator delete(void* ptr)
{
	~StringBuilder();
	//free(ptr);
	//std::cout << " <" << sizeof(String_obi) << "_bytes_were_released_> ";
}

void StringBuilder::operator delete[](void* ptr)
{
	~StringBuilder();
	//free(ptr);
}

void StringBuilder::print() const {
	std::cout << this->_string;
}

void StringBuilder::recalcStrLen() {
	this->_strLen = strlen(this->_string);
}

std::ostream& operator << (std::ostream& out, StringBuilder& obj) {
	for (int i = 0; i < obj.getStrLen(); ++i) {
		out << obj.getCharArr()[i];
	}
	return out;
}

std::istream& operator >> (std::istream& in, StringBuilder& obj) {
	const int lenTmp = 256;
	char tmp[lenTmp];
	in >> tmp;
	StringBuilder* newStr = new StringBuilder(tmp);
	obj = *newStr;
	return in;
}