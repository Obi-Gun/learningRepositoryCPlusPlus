#include <iostream>
#include "Human.h"

Human::Human() {
	this->_name = "Name";
}
Human::Human(const char* name) {
	this->_name = name;
}
Human::Human(Human& human) {
	this->_name = human._name;
}
Human::~Human() {
	//this->name_.~String_obi();
	//std::cout << "\n~Human()";
}

void Human::setName(const char* name) {
	this->_name = name;
}
String_obi Human::getName() const {
	return this->_name;
}

void Human::print() {
	this->_name.print();
}