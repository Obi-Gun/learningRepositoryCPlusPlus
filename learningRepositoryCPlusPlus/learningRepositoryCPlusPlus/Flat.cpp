#include <iostream>
#include "Flat.h"

Flat::Flat() {
	this->_familySurname = " <empty> ";
	this->_floorNumber = 0;
	this->_flatNumber = 0;
	this->_tenants = new Human*[0];
	this->_arrLen = 0;
	this->_area = 0;
}
Flat::Flat(int flatNumber) {
	this->_familySurname = " <empty> ";
	this->_floorNumber = 0;
	this->_flatNumber = flatNumber;
	this->_tenants = new Human*[0];
	this->_arrLen = 0;
	this->_area = 0;
}
Flat::Flat(const char* familySurname, int floorNumber, int flatNumber, Human** tenants, int arrLen) {
	this->_familySurname = familySurname;
	this->_floorNumber = floorNumber;
	this->_flatNumber = flatNumber;
	this->_tenants = tenants;
	this->_arrLen = arrLen;
	this->_area = 0;
}
Flat::Flat(String_obi familySurname, int floorNumber, int flatNumber, Human** tenants, int arrLen) {
	this->_familySurname = familySurname;
	this->_floorNumber = floorNumber;
	this->_flatNumber = flatNumber;
	this->_tenants = tenants;
	this->_arrLen = arrLen;
	this->_area = 0;
}
Flat::Flat(Flat& flat) {
	this->_familySurname = flat._familySurname;
	this->_floorNumber = flat._floorNumber;
	this->_flatNumber = flat._flatNumber;
	this->_tenants = new Human*[flat._arrLen];
	for (int i = 0; i < flat._arrLen; ++i) {
		this->_tenants[i] = new Human(*(flat._tenants[i]));
	}
	this->_arrLen = flat._arrLen;
	this->_area = flat._area;
}
Flat::~Flat() {
	delete[] this->_tenants;
	//std::cout << "~Flat()";
}

void Flat::setFamilySurname(const char* familySurname) {
	this->_familySurname = familySurname;
}
void Flat::setFamilySurname(const String_obi familySurname) {
	this->_familySurname = familySurname;
}
void Flat::setFloorNumber(int floorNumber) {
	this->_floorNumber = floorNumber;
}
void Flat::setFlatNumber(int flatNumber) {
	this->_flatNumber = flatNumber;
}
void Flat::setTenants(Human** tenants, int length) {
	Human** tmp = new Human * [length];
	for (int i = 0; i < length; ++i) {
		tmp[i] = new Human(*(tenants[i]));
	}
	this->_arrLen = length;
	delete[] this->_tenants;
	this->_tenants = tmp;
}

void Flat::setArea(int area)
{
	this->_area = area;
}

String_obi Flat::getFamilySurname() const {
	return this->_familySurname;
}
int Flat::getFloorNumber() const {
	return this->_flatNumber;
}
int Flat::getFlatNumber() const {
	return this->_flatNumber;
}
Human** Flat::getTenants() const {
	return this->_tenants;
}
int Flat::getArrLen() const {
	return this->_arrLen;
}

int Flat::getArea() const
{
	return this->_area;
}

void Flat::addTenant(Human human) {
	Human* tmp = new Human(human);
	Human** tmp2 = new Human * [this->_arrLen + 1];
	for (int i = 0; i < this->_arrLen; ++i) {
		tmp2[i] = this->_tenants[i];
	}
	tmp2[_arrLen] = tmp;
	++this->_arrLen;
	delete[] this->_tenants;
	this->_tenants = tmp2;
}
void Flat::print() const {
	std::cout << "\nFamily surname: ";
	this->_familySurname.print();
	std::cout << "\nFloor   number: " << this->_floorNumber;
	std::cout << "\nFlat    number: " << this->_flatNumber;
	std::cout << "\nTentnants list: ";
	for (int i = 0; i < this->_arrLen; ++i) {
		this->_tenants[i]->print();
		std::cout << "\n\t\t";
	}
}
void Flat::printCompact() const {
	std::cout << "\n - Floor " << this->_floorNumber;
	std::cout << " Flat " << this->_flatNumber;
	std::cout << " Family ";
	this->_familySurname.print();
	std::cout << "\n   Tentnants: ";
	for (int i = 0; i < this->_arrLen; ++i) {
		this->_tenants[i]->print();
		std::cout << "\n              ";
	}
}

bool Flat::operator==(const Flat& obj)
{
	if (this->_area == obj._area) {
		return true;
	}
	return false;
}

void Flat::operator=(const Flat& flat)
{
	this->_familySurname = flat._familySurname;
	this->_floorNumber = flat._floorNumber;
	this->_flatNumber = flat._flatNumber;
	this->_tenants = new Human * [flat._arrLen];
	for (int i = 0; i < flat._arrLen; ++i) {
		this->_tenants[i] = new Human(*(flat._tenants[i]));
	}
	this->_arrLen = flat._arrLen;
	this->_area = flat._area;
}

bool Flat::operator>(const Flat& obj)
{
	if (this->_area > obj._area) {
		return true;
	}
	return false;
}

bool Flat::operator<(const Flat& obj)
{
	if (this->_area < obj._area) {
		return true;
	}
	return false;
}
