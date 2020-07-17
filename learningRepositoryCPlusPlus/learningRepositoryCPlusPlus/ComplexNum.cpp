#include <iostream>
#include "ComplexNum.h"

ComplexNum::ComplexNum()
{
	_a = 0;
	_b = 0;
}

ComplexNum::ComplexNum(double a, double b)
{
	_a = a;
	_b = b;
}

ComplexNum::ComplexNum(ComplexNum& obj)
{
	_a = obj._a;
	_b = obj._b;
}

ComplexNum ComplexNum::operator+(const ComplexNum obj)
{
	ComplexNum num;
	num._a = this->_a + obj._a;
	num._b = this->_a + obj._b;
	return num;
}

ComplexNum ComplexNum::operator-(const ComplexNum obj)
{
	ComplexNum num;
	num._a = this->_a - obj._a;
	num._b = this->_a - obj._b;
	return num;
}

ComplexNum ComplexNum::operator*(const ComplexNum obj)
{
	ComplexNum num;
	num._a = this->_a * obj._a - this->_b * obj._b;
	num._b = this->_b * obj._a - this->_a * obj._b;
	return num;
}

ComplexNum ComplexNum::operator/(const ComplexNum obj)
{
	ComplexNum num;
	num._a = (this->_a * obj._a + this->_b * obj._b) / (pow(obj._a, 2) + pow(obj._b, 2));
	num._b = (this->_b * obj._a - this->_a * obj._b) / (pow(obj._a, 2) + pow(obj._b, 2));
	return num;
}

void ComplexNum::operator=(ComplexNum obj)
{
	_a = obj._a;
	_b = obj._b;
}

void ComplexNum::print()
{
	std::cout << this->_a << " + " << this->_b << i << std::endl;
}
