#include "Date_obi.h"
#include "funcs.h"

bool Date_obi::isLeapYear(int year) const
{
	if (year % 400 == 0) return true;
	if (year % 100 == 0) return false;
	if (year % 4 == 0)   return true;
	return false;
}

int Date_obi::getDays() const
{
	int daysInMonth[] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
	int daysCounter = this->day_ + daysInMonth[this->month_] + (this->month_ > 2 ? isLeapYear(this->year_) : 0);

	for (int i = 0; i < this->year_; ++i) {
		daysCounter += 365 + isLeapYear(i);
	}
	return daysCounter;
}

/*Date_obi Date_obi::getDate(int days) const {
	Date_obi date;
	int daysInMonth[] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
	int daysInYear = 365;
	while()

	return date;
}*/

int Date_obi::operator-(const Date_obi& date) {
	if (this == &date) {
		return 0;
	}
	return this->getDays() - date.daysAC_;
}

Date_obi Date_obi::operator+(const int& days) {
	Date_obi date;

	return date;
}

Date_obi::Date_obi() {

}
Date_obi::Date_obi(int day, int month, int year) {
	this->day_ = day;
	this->month_ = month;
	this->year_ = year;
	this->daysAC_ = this->getDays();
}
Date_obi::~Date_obi() {

}


/*int calcDays(int day1, int month1, int year1, int day2, int month2, int year2)
{
	if (year1 > year2) {
		swap(day1, day2);
		swap(month1, month2);
		swap(year1, year2);
	}
	int daysInMonth[] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
	int daysCounter1 = day1 + daysInMonth[month1] + (month1 > 2 ? isLeapYear(year1) : 0);

	int daysCounter2 = day2 + daysInMonth[month2] + (month2 > 2 ? isLeapYear(year2) : 0);
	for (int i = year1; i < year2; ++i) {
		daysCounter2 += 365 + isLeapYear(i);
	}
	return daysCounter2 - daysCounter1;
}*/