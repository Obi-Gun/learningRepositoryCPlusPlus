#include <iostream>
#include "Flat.h"

Flat::Flat() {
	this->familySurname_ = " <empty> ";
	this->floorNumber_ = 0;
	this->flatNumber_ = 0;
	this->tenants_ = new Human*[0];
	this->arrLen_ = 0;
}
Flat::Flat(int flatNumber) {
	this->familySurname_ = " <empty> ";
	this->floorNumber_ = 0;
	this->flatNumber_ = flatNumber;
	this->tenants_ = new Human*[0];
	this->arrLen_ = 0;
}
Flat::Flat(const char* familySurname, int floorNumber, int flatNumber, Human** tenants, int arrLen) {
	this->familySurname_ = familySurname;
	this->floorNumber_ = floorNumber;
	this->flatNumber_ = flatNumber;
	this->tenants_ = tenants;
	this->arrLen_ = arrLen;
}
Flat::Flat(String_obi familySurname, int floorNumber, int flatNumber, Human** tenants, int arrLen) {
	this->familySurname_ = familySurname;
	this->floorNumber_ = floorNumber;
	this->flatNumber_ = flatNumber;
	this->tenants_ = tenants;
	this->arrLen_ = arrLen;
}
Flat::Flat(Flat& flat) {
	this->familySurname_ = flat.familySurname_;
	this->floorNumber_ = flat.floorNumber_;
	this->flatNumber_ = flat.flatNumber_;
	this->tenants_ = new Human*[flat.arrLen_];
	for (int i = 0; i < flat.arrLen_; ++i) {
		this->tenants_[i] = new Human(*(flat.tenants_[i]));
	}
	this->arrLen_ = flat.arrLen_;
}
Flat::~Flat() {
	delete[] this->tenants_;
	//std::cout << "~Flat()";
}

void Flat::setFamilySurname(const char* familySurname) {
	this->familySurname_ = familySurname;
}
void Flat::setFamilySurname(const String_obi familySurname) {
	this->familySurname_ = familySurname;
}
void Flat::setFloorNumber(int floorNumber) {
	this->floorNumber_ = floorNumber;
}
void Flat::setFlatNumber(int flatNumber) {
	this->flatNumber_ = flatNumber;
}
void Flat::setTenants(Human** tenants, int length) {
	Human** tmp = new Human * [length];
	for (int i = 0; i < length; ++i) {
		tmp[i] = new Human(*(tenants[i]));
	}
	this->arrLen_ = length;
	delete[] this->tenants_;
	this->tenants_ = tmp;
}

String_obi Flat::getFamilySurname() const {
	return this->familySurname_;
}
int Flat::getFloorNumber() const {
	return this->flatNumber_;
}
int Flat::getFlatNumber() const {
	return this->flatNumber_;
}
Human** Flat::getTenants() const {
	return this->tenants_;
}
int Flat::getArrLen() const {
	return this->arrLen_;
}

void Flat::addTenant(Human human) {
	Human* tmp = new Human(human);
	Human** tmp2 = new Human * [this->arrLen_ + 1];
	for (int i = 0; i < this->arrLen_; ++i) {
		tmp2[i] = this->tenants_[i];
	}
	tmp2[arrLen_] = tmp;
	++this->arrLen_;
	delete[] this->tenants_;
	this->tenants_ = tmp2;
}
void Flat::print() const {
	std::cout << "\nFamily surname: ";
	this->familySurname_.print();
	std::cout << "\nFloor   number: " << this->floorNumber_;
	std::cout << "\nFlat    number: " << this->flatNumber_;
	std::cout << "\nTentnants list: ";
	for (int i = 0; i < this->arrLen_; ++i) {
		this->tenants_[i]->print();
		std::cout << "\n\t\t";
	}
}
void Flat::printCompact() const {
	std::cout << "\n - Floor " << this->floorNumber_;
	std::cout << " Flat " << this->flatNumber_;
	std::cout << " Family ";
	this->familySurname_.print();
	std::cout << "\n   Tentnants: ";
	for (int i = 0; i < this->arrLen_; ++i) {
		this->tenants_[i]->print();
		std::cout << "\n              ";
	}
}