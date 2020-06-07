#ifndef Time_obiClass
#define Time_obiClass
#include <iostream>

class Time_obi
{
private:
	static Time_obi* pointer_;
	int hour_;
	int minute_;
	int second_;

	Time_obi(int hour, int minute, int second);

public:
	
	~Time_obi();
	static Time_obi* getReference();

	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);
	void operator() (int hour, int minute, int second);
	int getHour() const;
	int getMinute() const;
	int getSecond() const;

	void operator+ (int seconds);
	friend void operator+ (Time_obi time);
};

std::istream& operator>> (std::istream& is, Time_obi* obj);
std::ostream& operator<< (std::ostream& os, const Time_obi* obj);

#endif // !Time_obiClass