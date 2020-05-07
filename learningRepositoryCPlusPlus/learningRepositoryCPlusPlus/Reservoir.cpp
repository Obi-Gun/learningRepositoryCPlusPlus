#include "Reservoir.h"

Reservoir::Reservoir() {

}
Reservoir::Reservoir(String_obi name) {

}
Reservoir::Reservoir(const char* name) {

}
Reservoir::Reservoir(int length, int width, int depth) {

}
Reservoir::Reservoir(const char* name, int length, int width, int depth, reservoirType type) {

}
Reservoir::Reservoir(String_obi name, int length, int width, int depth, reservoirType type) {

}
Reservoir::Reservoir(Reservoir& reservoir) {

}
Reservoir::~Reservoir() {

}

void Reservoir::setName() {

}
void Reservoir::setLength() {

}
void Reservoir::setWidth() {

}
void Reservoir::setDepth() {

}
void Reservoir::setReservoirType() {

}

String_obi Reservoir::getName() const {
	this->name_;
}
int Reservoir::getLength() const {
	this->length_;
}
int Reservoir::getWidth() const {
	this->width_;
}
int Reservoir::getDepth() const {
	this->depth_;
}
String_obi Reservoir::getReservoirType() const {
	
}

int Reservoir::calcVolume() const {

}
int Reservoir::calcAreaOfWaterSurface() const {

}
bool Reservoir::isEqualsReservoirTypes(const Reservoir& reservoir) const {

}
int Reservoir::compareReservoirAreaOfWaterSurface(const Reservoir& reservoir) const {

}