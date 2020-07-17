#include "Overcoat.h"

Overcoat::Overcoat()
{
	_price = 0;
	_type = empty_field;
}

Overcoat::Overcoat(int price, overcoatTypes type)
{
	_price = price;
	_type = type;
}

Overcoat::Overcoat(Overcoat& obj)
{
	_price = obj._price;
	_type = obj._type;
}

bool Overcoat::operator==(const Overcoat& obj)
{
	if (this->_type == obj._type) {
		return true;
	}
	return false;
}

void Overcoat::operator=(const Overcoat& obj)
{
	this->_price = obj._price;
	this->_type = obj._type;
}

bool Overcoat::operator>(const Overcoat& obj)
{
	if (this->_price > obj._price) {
		return true;
	}
	return false;
}

bool Overcoat::operator<(const Overcoat& obj)
{
	if (this->_price < obj._price) {
		return true;
	}
	return false;
}
