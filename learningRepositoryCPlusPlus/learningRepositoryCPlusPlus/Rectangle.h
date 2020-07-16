#ifndef Rectangle_Class
#define Rectangle_Class
#include "Figure.h"

class Rectangle : public Figure
{
private:
	int _width;
	int _height;

public:
	Rectangle(int width, int height);
	//~Rectangle();

	int calcSquare();
};
#endif