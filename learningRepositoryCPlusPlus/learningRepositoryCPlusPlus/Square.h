#ifndef Square_Class
#define Square_Class
#include "Point.h"

class Square : public Point
{
protected:
	Point _startPoint;
	int _width;

public:
	Square();
	Square(int x, int y, int width);
	Square(Square& obj);
	~Square();

	int getX() const;
	int getY() const;
	int getWidth() const;
};
#endif