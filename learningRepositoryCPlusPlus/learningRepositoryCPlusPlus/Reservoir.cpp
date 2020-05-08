#include <iostream>
#include "Reservoir.h"

Reservoir::Reservoir() {
	this->name_ = " <empty field> ";
	this->length_ = 0;
	this->width_ = 0;
	this->depth_ = 0;
	this->type_ = nonselected;
}
Reservoir::Reservoir(String_obi name) {
	this->name_ = name;
	this->length_ = 0;
	this->width_ = 0;
	this->depth_ = 0;
	this->type_ = nonselected;
}
Reservoir::Reservoir(const char* name) {
	this->name_ = name;
	this->length_ = 0;
	this->width_ = 0;
	this->depth_ = 0;
	this->type_ = nonselected;
}
Reservoir::Reservoir(int length, int width, int depth) {
	this->name_ = " <empty field> ";
	this->length_ = length;
	this->width_ = width;
	this->depth_ = depth;
	this->type_ = nonselected;
}
Reservoir::Reservoir(const char* name, int length, int width, int depth, reservoirType type) {
	this->name_ = name;
	this->length_ = length;
	this->width_ = width;
	this->depth_ = depth;
	this->type_ = type;
}
Reservoir::Reservoir(String_obi name, int length, int width, int depth, reservoirType type) {
	this->name_ = name;
	this->length_ = length;
	this->width_ = width;
	this->depth_ = depth;
	this->type_ = type;
}
Reservoir::Reservoir(Reservoir& reservoir) {
	this->name_ = reservoir.name_;
	this->length_ = reservoir.length_;
	this->width_ = reservoir.width_;
	this->depth_ = reservoir.depth_;
	this->type_ = reservoir.type_;
}
Reservoir::~Reservoir() {
}

void Reservoir::setName(String_obi name) {
	this->name_ = name;
}
void Reservoir::setName(const char* name) {
	this->name_ = name;
}
void Reservoir::setLength(int length) {
	this->length_ = length;
}
void Reservoir::setWidth(int width) {
	this->width_ = width;
}
void Reservoir::setDepth(int depth) {
	this->depth_ = depth;
}
void Reservoir::setReservoirType(reservoirType type) {
	this->type_ = type;
}

String_obi Reservoir::getName() const {
	return this->name_;
}
int Reservoir::getLength() const {
	return this->length_;
}
int Reservoir::getWidth() const {
	return this->width_;
}
int Reservoir::getDepth() const {
	return this->depth_;
}
String_obi Reservoir::getReservoirType() const {
	String_obi tmp;
	switch (this->type_)
	{
	case nonselected:
		tmp = " <nonselected> ";
		break;
	case ocean:
		tmp = "ocean";
		break;
	case sea:
		tmp = "sea";
		break;
	case swimmingPool:
		tmp = "swimmingPool";
		break;
	case pond:
		tmp = "pond";
		break;
	default:
		break;
	}
	return tmp;
}

void Reservoir::print() const {
	std::cout << "\nReservoir: ";
	this->getName().print();
	std::cout << " ";
	this->getReservoirType().print();
	std::cout << "\nlength " << this->getLength() << " m, width " << this->getWidth() << " m, depth " << this->getDepth();
	std::cout << " m\nVolume " << this->calcVolume() << " m3, Square area " << this->calcAreaOfWaterSurface() << " m2\n";
}
int Reservoir::calcVolume() const {
	return length_ * width_ * depth_;
}
int Reservoir::calcAreaOfWaterSurface() const {
	return length_ * width_;
}
bool Reservoir::isEqualsReservoirTypes(const Reservoir& reservoir) const {
	return 0;
}
int Reservoir::compareReservoirAreaOfWaterSurface(const Reservoir& reservoir) const {
	return 0;
}