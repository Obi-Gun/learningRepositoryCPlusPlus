#include "Circle.h"

Circle::Circle()
{
	_radius = 0;
}

Circle::Circle(int x, int y, int radius) : Point(x, y)
{
	_radius = radius;
}

Circle::Circle(Circle& obj)
{
	_x = obj._x;
	_y = obj._y;
	_radius = obj._radius;
}

Circle::~Circle()
{
}

int Circle::calcSquare()
{
	return 3,14 * _radius * _radius;
}

int Circle::getX() const
{
	return _x;
}

int Circle::getY() const
{
	return _y;
}

int Circle::getRadius() const
{
	return _radius;
}
