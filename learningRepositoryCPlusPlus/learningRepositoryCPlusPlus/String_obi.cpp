#include <iostream>
#include "String_obi.h"

String_obi::String_obi() {
	this->setCurrentMaxStrLen();
	this->_string = new char[this->getCurrentMaxStrLen() + 1];
	this->_string[0] = '\0';
	recalcStrLen();
	++_objCounter;
}

String_obi::String_obi(int maxStringLength) {
	this->setCurrentMaxStrLen(maxStringLength);
	this->_string = new char[this->getCurrentMaxStrLen() + 1];
	this->_string[0] = '\0';
	recalcStrLen();
	++_objCounter;
}

String_obi::String_obi(const char* string) {
	this->setCurrentMaxStrLen(strlen(string));
	this->_string = new char[this->getCurrentMaxStrLen() + 1];
	strcpy_s(this->_string, this->getCurrentMaxStrLen() + 1, string);
	recalcStrLen();
	++_objCounter;
}

String_obi::String_obi(String_obi& string_obi) {
	this->setCurrentMaxStrLen(string_obi.getStrLen());
	this->_string = new char[this->getCurrentMaxStrLen() + 1];
	strcpy_s(this->_string, this->getCurrentMaxStrLen() + 1, string_obi._string);
	recalcStrLen();
	++_objCounter;
}

String_obi::String_obi(const String_obi& string_obi) {
	this->setCurrentMaxStrLen(string_obi.getStrLen());
	this->_string = new char[this->getCurrentMaxStrLen() + 1];
	strcpy_s(this->_string, this->getCurrentMaxStrLen() + 1, string_obi._string);
	recalcStrLen();
	++_objCounter;
}

String_obi::~String_obi() {
	delete[] this->_string;
	//std::cout << "\n~String_obi()";
	--_objCounter;
}

void String_obi::setCurrentMaxStrLen(int maxStringLength) {
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

int String_obi::getCurrentMaxStrLen() const {
	return this->_currentMaxStrLen;
}

int String_obi::getStrLen() const {
	return this->_strLen;
}

const char* String_obi::getCharArr() const
{
	return this->_string;
}

int String_obi::getObjCounter()
{
	return String_obi::_objCounter;
}

String_obi String_obi::operator*(const String_obi& string) {
	String_obi result(strlen(this->_string) + strlen(string._string));
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

String_obi String_obi::operator=(const String_obi& str) {
	if (this->getCurrentMaxStrLen() < str.getStrLen()) {
		delete[] this->_string;
		this->setCurrentMaxStrLen(str.getStrLen());
		this->_string = new char[this->getCurrentMaxStrLen() + 1];
	}
	strcpy_s(this->_string, this->getCurrentMaxStrLen() + 1, str._string);
	recalcStrLen();
	return *this;
}

String_obi String_obi::operator+(const String_obi& str) {
	String_obi tmp(this->getStrLen() + str.getStrLen());
	strcpy_s(tmp._string, tmp.getCurrentMaxStrLen() + 1, this->_string);
	strcat_s(tmp._string, tmp.getCurrentMaxStrLen() + 1, str._string);
	tmp.recalcStrLen();
	return tmp;
}

char String_obi::operator[](int index)
{
	if (index < 0 || index > _strLen) {
		return '\0';
	}
	return _string[index];
}

int String_obi::operator()(char el)
{
	int index = -1;
	char* tmp;
	if (tmp = strchr(_string, el)) {
		index = tmp - _string;
	}
	return index;
}

String_obi::operator int()
{
	return _strLen;
}

String_obi& String_obi::operator++()
{
	if (this->_strLen < this->_currentMaxStrLen) {
		_string[_strLen] = ' ';
		_string[_strLen + 1] = '\0';
		recalcStrLen();
		return *this;
	}
	String_obi* tmp = new String_obi(this->getStrLen() + _NEW_EMPTY_SPACE);
	strcpy_s(tmp->_string, tmp->getCurrentMaxStrLen() + 1, this->_string);
	strcat_s(tmp->_string, tmp->getCurrentMaxStrLen() + 1, " ");
	tmp->recalcStrLen();
	*this = *tmp;
	return *this;
}

String_obi& String_obi::operator++(int)
{
	String_obi* tmp2 = new String_obi;
	*tmp2 = *this;
	if (this->_strLen < this->_currentMaxStrLen) {

		_string[_strLen] = ' ';
		_string[_strLen + 1] = '\0';
		recalcStrLen();
		return *tmp2;
	}
	String_obi* tmp = new String_obi(this->getStrLen() + _NEW_EMPTY_SPACE);
	strcpy_s(tmp->_string, tmp->getCurrentMaxStrLen() + 1, this->_string);
	strcat_s(tmp->_string, tmp->getCurrentMaxStrLen() + 1, " ");
	tmp->recalcStrLen();
	*this = *tmp;
	return *tmp2;
}

String_obi& String_obi::operator--()
{
	if (this->_strLen <= this->_MIN_ARR_LEN) {
		return *this;
	}
	_string[_strLen - 1] = '\0';
	recalcStrLen();
	return *this;
}

String_obi& String_obi::operator--(int)
{
	if (this->_strLen <= this->_MIN_ARR_LEN) {
		return *this;
	}
	String_obi* tmp = new String_obi;
	*tmp = *this;
	_string[_strLen - 1] = '\0';
	recalcStrLen();
	return *tmp;
}

void* String_obi::operator new(size_t size)
{
	void* ptr = malloc(size);
	if (ptr) {
		std::cout << " <" << size << "_bytes_were_allocated_> ";
	}
	else {
		std::cout << " <_memory_wasn`t_allocated_> ";
	}
	return ptr;
}

void* String_obi::operator new[](size_t size)
{
	void* ptr = malloc(size);
	return ptr;
}

void String_obi::operator delete(void* ptr)
{
	~String_obi();
	//free(ptr);
	std::cout << " <" << sizeof(String_obi) << "_bytes_were_released_> ";
}

void String_obi::operator delete[](void* ptr)
{
	~String_obi();
	//free(ptr);
}

void String_obi::print() const {
	std::cout << this->_string;
}

void String_obi::recalcStrLen() {
	this->_strLen = strlen(this->_string);
}

std::ostream& operator << (std::ostream& out, String_obi& obj) {
	for (int i = 0; i < obj.getStrLen(); ++i) {
		out << obj.getCharArr()[i];
	}
	return out;
}

std::istream& operator >> (std::istream& in, String_obi& obj) {
	const int lenTmp = 256;
	char tmp[lenTmp];
	in >> tmp;
	String_obi* newStr = new String_obi(tmp);
	obj = *newStr;
	return in;
}