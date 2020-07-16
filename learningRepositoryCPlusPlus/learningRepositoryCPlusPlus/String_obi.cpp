#include <iostream>
#include "String_obi.h"

String_obi::String_obi() {
	this->setCurrentMaxStrLen();
	this->string_ = new char[this->getCurrentMaxStrLen() + 1];
	this->string_[0] = '\0';
	recalcStrLen();
}

String_obi::String_obi(int maxStringLength) {
	this->setCurrentMaxStrLen(maxStringLength);
	this->string_ = new char[this->getCurrentMaxStrLen() + 1];
	this->string_[0] = '\0';
	recalcStrLen();
}

String_obi::String_obi(const char* string) {
	this->setCurrentMaxStrLen(strlen(string));
	this->string_ = new char[this->getCurrentMaxStrLen() + 1];
	strcpy_s(this->string_, this->getCurrentMaxStrLen() + 1, string);
	recalcStrLen();
}

String_obi::String_obi(String_obi& string_obi) {
	this->setCurrentMaxStrLen(string_obi.getStrLen());
	this->string_ = new char[this->getCurrentMaxStrLen() + 1];
	strcpy_s(this->string_, this->getCurrentMaxStrLen() + 1, string_obi.string_);
	recalcStrLen();
}

String_obi::String_obi(const String_obi& string_obi) {
	this->setCurrentMaxStrLen(string_obi.getStrLen());
	this->string_ = new char[this->getCurrentMaxStrLen() + 1];
	strcpy_s(this->string_, this->getCurrentMaxStrLen() + 1, string_obi.string_);
	recalcStrLen();
}

String_obi::~String_obi() {
	delete[] this->string_;
	//std::cout << "\n~String_obi()";
}

void String_obi::setCurrentMaxStrLen(int maxStringLength) {
	if (maxStringLength < this->MIN_ARR_LEN_) {
		this->currentMaxStrLen_ = this->MIN_ARR_LEN_ - 1;
	}
	else if (maxStringLength > this->MAX_ARR_LEN_ - 1) {
		this->currentMaxStrLen_ = this->MAX_ARR_LEN_ - 1;
	}
	else {
		this->currentMaxStrLen_ = maxStringLength;
	}
}

int String_obi::getCurrentMaxStrLen() const {
	return this->currentMaxStrLen_;
}

int String_obi::getStrLen() const {
	return this->strlen_;
}

const char* String_obi::getCharArr() const
{
	return this->string_;
}

String_obi String_obi::operator*(const String_obi& string) {
	String_obi result(strlen(this->string_) + strlen(string.string_));
	int i = 0;
	char* str = this->string_;
	while (str = strpbrk(str, string.string_)) {
		char* tmp = strchr(result.string_, *str);
		if (!tmp) {
			result.string_[i++] = *str;
		}
		++str;
	}
	result.string_[i] = '\0';
	result.recalcStrLen();
	return result;
}

String_obi String_obi::operator=(const String_obi& str) {
	if (this->getCurrentMaxStrLen() < str.getStrLen()) {
		delete[] this->string_;
		this->setCurrentMaxStrLen(str.getStrLen());
		this->string_ = new char[this->getCurrentMaxStrLen() + 1];
	}
	strcpy_s(this->string_, this->getCurrentMaxStrLen() + 1, str.string_);
	recalcStrLen();
	return *this;
}

String_obi String_obi::operator+(const String_obi& str) {
	String_obi tmp(this->getStrLen() + str.getStrLen());
	strcpy_s(tmp.string_, tmp.getCurrentMaxStrLen() + 1, this->string_);
	strcat_s(tmp.string_, tmp.getCurrentMaxStrLen() + 1, str.string_);
	tmp.recalcStrLen();
	return tmp;
}

void String_obi::print() const {
	std::cout << this->string_;
}

void String_obi::recalcStrLen() {
	this->strlen_ = strlen(this->string_);
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