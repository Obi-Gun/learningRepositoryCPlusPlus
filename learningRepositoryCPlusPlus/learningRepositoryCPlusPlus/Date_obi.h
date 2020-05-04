#ifndef Date_obiClass
#define Date_obiClass

class Date_obi
{
private:
	int day_;
	int month_;
	int year_;
	int daysAC_;

	bool isLeapYear(int year) const;


public:
	int getDays() const;
	//Date_obi getDate(int days) const;
	int operator-(const Date_obi& date);
	Date_obi operator+(const int& days);

	Date_obi();
	Date_obi(int day, int month, int year);
	~Date_obi();

};
#endif