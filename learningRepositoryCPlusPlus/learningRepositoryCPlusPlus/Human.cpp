#include <iostream>
#include "Human.h"

Human::Human() {
	this->name_ = "Name";
}
Human::Human(const char* name) {
	this->name_ = name;
}
Human::Human(Human& human) {
	this->name_ = human.name_;
}
Human::~Human() {
	//this->name_.~String_obi();
	//std::cout << "\n~Human()";
}

void Human::setName(const char* name) {
	this->name_ = name;
}
String_obi Human::getName() const {
	return this->name_;
}

void Human::print() {
	this->name_.print();
}