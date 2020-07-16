#include "Rectangle.h"

Rectangle::Rectangle(int width, int height)
{
	_width = width;
	_height = height;
}

int Rectangle::calcSquare()
{
	return _height * _width;
}
