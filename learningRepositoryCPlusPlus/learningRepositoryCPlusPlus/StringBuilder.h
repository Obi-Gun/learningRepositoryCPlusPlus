#ifndef String_obiClass
#define String_obiClass
#include <iostream>

class StringBuilder
{
private:
	char* _string;
	int _currentMaxStrLen;					// max string length (how many symbols could be inscribed)
	int _strLen;							// current string length (how many symbols have already inscribed)
	static const int _MIN_ARR_LEN = 1;				// min arrLen in chars
	static const int _MAX_ARR_LEN = 1000;			// max arrLen in chars
	static const int _DEFAULT_ARR_LEN = 81;			// default arrLen in chars = 81 (task requirement)
	static const int _NEW_EMPTY_SPACE = 20;         // minimum space will be added if there is no space for cancatinate new string
	//static int _objCounter;

	void setCurrentMaxStrLen(int maxStringLength = _DEFAULT_ARR_LEN - 1);
	void recalcStrLen();

public:
	StringBuilder();
	StringBuilder(int length);
	StringBuilder(const char* string);
	StringBuilder(StringBuilder& string_obi);
	StringBuilder(const StringBuilder& string_obi);
	~StringBuilder();

	int getCurrentMaxStrLen() const;
	int getStrLen() const;
	const char* getCharArr() const;
	//static int getObjCounter();


	StringBuilder operator*(const StringBuilder& str);
	StringBuilder operator=(const StringBuilder& str);
	StringBuilder operator+(const StringBuilder& str);
	char operator[] (int);
	int operator() (char);
	operator int();
	StringBuilder& operator++();
	StringBuilder& operator--();
	StringBuilder& operator++(int);
	StringBuilder& operator--(int);
	void* operator new (size_t);
	void* operator new[] (size_t);
	void operator delete (void*);
	void operator delete[] (void*);

	void print() const;
};

std::ostream& operator << (std::ostream& out, StringBuilder& obj);
std::istream& operator >> (std::istream& in, StringBuilder& obj);

#endif