#ifndef Circle_Class
#define Circle_Class
#include "Point.h"
#include "Figure.h"

class Circle : public Point , public Figure
{
protected:
	Point _center;
	int _radius;

public:
	Circle();
	Circle(int x, int y, int radius);
	Circle(Circle& obj);
	~Circle();

	int calcSquare();

	int getX() const;
	int getY() const;
	int getRadius() const;
};
#endif