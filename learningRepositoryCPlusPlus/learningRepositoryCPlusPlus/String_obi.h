#ifndef String_obiClass
#define String_obiClass
#include <iostream>

class String_obi
{
private:
	char* string_;
	int currentMaxStrLen_;
	int strlen_;
	static const int MIN_ARR_LEN_ = 1;				// min arrLen in chars
	static const int MAX_ARR_LEN_ = 1000;			// max arrLen in chars
	static const int DEFAULT_ARR_LEN_ = 81;			// default arrLen in chars = 81 (task requirement)

	void setCurrentMaxStrLen(int maxStringLength = DEFAULT_ARR_LEN_ - 1);
	void recalcStrLen();

public:
	String_obi();
	String_obi(int length);
	String_obi(const char* string);
	String_obi(String_obi& string_obi);
	String_obi(const String_obi& string_obi);
	~String_obi();

	int getCurrentMaxStrLen() const;
	int getStrLen() const;
	const char* getCharArr() const;

	String_obi operator*(const String_obi& str);
	String_obi operator=(const String_obi& str);
	String_obi operator+(const String_obi& str);

	void print() const;
};

std::ostream& operator << (std::ostream& out, String_obi& obj);
std::istream& operator >> (std::istream& in, String_obi& obj);

#endif