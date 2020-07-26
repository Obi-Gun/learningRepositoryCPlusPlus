#ifndef String_obiClass
#define String_obiClass
#include <iostream>

class Str
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
	Str();
	Str(int length);
	Str(const char* string);
	Str(Str& string_obi);
	Str(const Str& string_obi);
	~Str();

	int getCurrentMaxStrLen() const;
	int getStrLen() const;
	const char* getCharArr() const;
	//static int getObjCounter();


	Str operator*(const Str& str);
	Str operator=(const Str& str);
	Str operator+(const Str& str);
	char operator[] (int);
	int operator() (char);
	operator int();
	Str& operator++();
	Str& operator--();
	Str& operator++(int);
	Str& operator--(int);
	void* operator new (size_t);
	void* operator new[](size_t);
	void operator delete (void*);
	void operator delete[](void*);

	void print() const;
};

std::ostream& operator << (std::ostream& out, Str& obj);
std::istream& operator >> (std::istream& in, Str& obj);

#endif