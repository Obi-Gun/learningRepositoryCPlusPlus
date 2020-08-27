#include <algorithm> 

class AddNumberFrom
{
private:
	int _delta;
	int _current;

public:
	AddNumberFrom(int number, int from = 0) : _delta(number), _current(from) 
	{}

	int operator()()
	{
		return _current += _delta;
	}
};

class AddNumber
{
private:
	int _delta;

public:
	AddNumber(int delta) : _delta(delta)
	{}

	int operator()()
	{
		return _delta;
	}
};