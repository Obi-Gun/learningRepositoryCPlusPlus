#ifndef String_obiClass
#define String_obiClass
#include <iostream>

class String_obi
{
private:
	char* _string;
	int _currentMaxStrLen;					// max string length (how many symbols could be inscribed)
	int _strLen;							// current string length (how many symbols have already inscribed)
	static const int _MIN_ARR_LEN = 1;				// min arrLen in chars
	static const int _MAX_ARR_LEN = 1000;			// max arrLen in chars
	static const int _DEFAULT_ARR_LEN = 81;			// default arrLen in chars = 81 (task requirement)
	static const int _NEW_EMPTY_SPACE = 20;         // minimum space will be added if there is no space for cancatinate new string
	static int _objCounter;

	void setCurrentMaxStrLen(int maxStringLength = _DEFAULT_ARR_LEN - 1);
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
	static int getObjCounter();


	String_obi operator*(const String_obi& str);
	String_obi operator=(const String_obi& str);
	String_obi operator+(const String_obi& str);
	char operator[] (int);
	int operator() (char);
	operator int();
	String_obi& operator++();
	String_obi& operator--();
	String_obi& operator++(int);
	String_obi& operator--(int);
	void* operator new (size_t);
	void* operator new[] (size_t);
	void operator delete (void*);
	void operator delete[] (void*);

	void print() const;
};
//int String_obi::_objCounter = 0;

std::ostream& operator << (std::ostream& out, String_obi& obj);
std::istream& operator >> (std::istream& in, String_obi& obj);

#endif