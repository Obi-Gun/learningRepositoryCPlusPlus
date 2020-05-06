#include <iostream>
#include "House.h"

House::House() {
	this->arrLen_ = 0;
	this->flats_ = new Flat * [this->arrLen_];
	this->floorsInHouse_ = 0;
	this->adress_ = " <empty> ";
}
House::House(const String_obi adress) {
	this->arrLen_ = 0;
	this->flats_ = new Flat * [this->arrLen_];
	this->floorsInHouse_ = 0;
	this->adress_ = adress;
}
House::House(const char* adress) {
	this->arrLen_ = 0;
	this->flats_ = new Flat * [this->arrLen_];
	this->floorsInHouse_ = 0;
	this->adress_ = adress;
}
House::House(Flat** flats, int arrLen, int floorsInHouse, String_obi adress) {
	this->arrLen_ = arrLen;
	this->flats_ = new Flat * [arrLen];
	for (int i = 0; i < arrLen; ++i) {
		this->flats_[i] = new Flat(*(flats[i]));
	}
	this->floorsInHouse_ = floorsInHouse;
	this->adress_ = adress;
}
House::House(House& house) {
	this->arrLen_ = house.arrLen_;
	this->flats_ = new Flat * [this->arrLen_];
	for (int i = 0; i < this->arrLen_; ++i) {
		this->flats_[i] = new Flat(*(house.flats_[i]));
	}
	this->floorsInHouse_ = house.floorsInHouse_;
	this->adress_ = house.adress_;
}
House::~House() {
	delete this->flats_;
}

void House::setFlats(Flat** flats, int arrLen) {
	delete[] this->flats_;
	this->arrLen_ = arrLen;
	this->flats_ = new Flat * [arrLen];
	for (int i = 0; i < arrLen; ++i) {
		this->flats_[i] = new Flat(*(flats[i]));
	}
}
void House::setFloorsInHouse(int floorsInHouse) {
	this->floorsInHouse_ = floorsInHouse;
}
void House::setAdress(String_obi adress) {
	this->adress_ = adress;
}
void House::setAdress(char* adress) {
	this->adress_ = adress;
}

Flat** House::getFlats() const {
	return this->flats_;
}
int House::getFloorsInHouse() const {
	return this->floorsInHouse_;
}
String_obi House::getAdress() const {
	return this->adress_;
}

void House::print() const {
	std::cout << "\nHouse adress ";
	this->adress_.print();
	std::cout << "\nThere are " << this->floorsInHouse_ << " floors";
	std::cout << "\nFlats list: ";
	for (int i = 0; i < this->arrLen_; ++i) {
		this->flats_[i]->printCompact();
		std::cout << "\n\t\t";
	}
}