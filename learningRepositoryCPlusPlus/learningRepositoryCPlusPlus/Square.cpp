#include "Square.h"

Square::Square()
{
}

Square::Square(int x, int y, int width) : Point (x, y)
{
	_width = width;
}

Square::Square(Square& obj)
{
	_x = obj._x;
	_y = obj._y;
	_width = obj._width;
}

Square::~Square()
{
}

int Square::getX() const
{
	return _x;
}

int Square::getY() const
{
	return _y;
}

int Square::getWidth() const
{
	return _width;
}
