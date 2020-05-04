#include <iostream>
#include "String_obi.h"
#include "funcs.h"

String_obi::String_obi() {
	this->string_ = new char[1];
	this->string_[0] = '\0';
}
String_obi::String_obi(int length) {
	this->string_ = new char[length];
	this->string_[0] = '\0';
}
String_obi::String_obi(const char* string) {
	this->string_ = new char[strlen(string) + 1];
	strcpy_s(this->string_, strlen(string) + 1, string);
}
String_obi::String_obi(String_obi& string_obi) {
	int len = strlen(string_obi.string_);
	this->string_ = new char[len + 1];
	strcpy_s(this->string_, len + 1, string_obi.string_);
}
String_obi::~String_obi() {
	delete[] this->string_;
	std::cout << "\n~String_obi()";
}


String_obi String_obi::operator*(const String_obi& string) {
	int len = strlen(this->string_) > strlen(string.string_) ? strlen(this->string_) : strlen(string.string_);
	String_obi result(len + 1);
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
	return result;
}

void String_obi::print() const {
	std::cout << this->string_;
}