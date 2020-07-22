#include "Time_obi.h"

Time_obi::Time_obi(int hour, int minute, int second) {
	this->setHour(hour);
	this->setMinute(minute);
	this->setSecond(second);
}
Time_obi::~Time_obi() {
	std::cout << "\n~Time_obi()";
}

/*Time_obi* Time_obi::getReference() {
	return pointer_;
}*/
void Time_obi::setHour(int hour) {
	this->hour_ = hour % 24;
}
void Time_obi::setMinute(int minute) {
	this->minute_ = minute % 60;
}
void Time_obi::setSecond(int second) {
	this->second_ = second % 60;
}
void Time_obi::operator() (int hour, int minute, int second) {
	this->setHour(hour);
	this->setMinute(minute);
	this->setSecond(second);
}
int Time_obi::getHour() const {
	return this->hour_;
}
int Time_obi::getMinute() const {
	return this->minute_;
}
int Time_obi::getSecond() const {
	return this->second_;
}

std::istream& operator>> (std::istream& is, Time_obi* obj) {
	int tmp;
	std::cout << "\nEnter hour: ";
	std::cin >> tmp;
	obj->setHour(tmp);
	std::cout << "Enter minute: ";
	std::cin >> tmp;
	obj->setMinute(tmp);
	std::cout << "Enter second: ";
	std::cin >> tmp;
	obj->setSecond(tmp);
	return is;
}
std::ostream& operator<< (std::ostream& os, const Time_obi* obj) {
	std::cout << "\ntime: " << obj->getHour() << ":" << obj->getMinute() << "." << obj->getSecond();
	return os;
}