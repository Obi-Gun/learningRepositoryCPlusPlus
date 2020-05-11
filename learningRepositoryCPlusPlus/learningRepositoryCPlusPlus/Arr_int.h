#ifndef Arr_intClass
#define Arr_intClass

#include <iostream>

class Arr_int
{
private:
	int length_;
	int* arr_;

public:
	Arr_int();
	Arr_int(int length);
	Arr_int(Arr_int& obj);
	~Arr_int();

	int getLength() const;
	int& operator[] (int i) const;
	Arr_int& operator++ ();
	Arr_int& operator++ (int);
	//Arr_int operator+ (const int& number);
	//Arr_int operator+ (const Arr_int& secondArr);
	Arr_int operator= (const Arr_int& secondArr);

	void print() const;
};

std::ostream& operator << (std::ostream& out, Arr_int& obj);
std::istream& operator >> (std::istream& in, Arr_int& obj);

#endif