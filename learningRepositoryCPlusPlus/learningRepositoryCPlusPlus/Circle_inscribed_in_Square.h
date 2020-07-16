#ifndef Circle_inscribed_in_Square_Class
#define Circle_inscribed_in_Square_Class
#include "Circle.h"
#include "Square.h"

class Circle_inscribed_in_Square : public Circle, public Square
{
private:
	Circle _circle;
	Square _square;

public:
	Circle_inscribed_in_Square();
	Circle_inscribed_in_Square(int xCircle, int yCircle, int rCircle, int xSquare, int ySquare, int widthSquare);
	Circle_inscribed_in_Square(Circle circle, Square square);
	~Circle_inscribed_in_Square();

	bool isCircleInscribedInSquare(int xCircle, int yCircle, int rCircle, int xSquare, int ySquare, int widthSquare);

};
#endif