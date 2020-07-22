#include <iostream>
#include "Circle_inscribed_in_Square.h"

Circle_inscribed_in_Square::Circle_inscribed_in_Square()
{
}

Circle_inscribed_in_Square::Circle_inscribed_in_Square(int xCircle, int yCircle, int rCircle, int xSquare, int ySquare, int widthSquare)
	: Circle(xCircle, yCircle, rCircle), Square(xSquare, ySquare, widthSquare)
{
	this->isCircleInscribedInSquare(xCircle, yCircle, rCircle, xSquare, ySquare, widthSquare);
}

Circle_inscribed_in_Square::Circle_inscribed_in_Square(Circle circle, Square square)
	: Circle(circle), Square(square)
{
	this->isCircleInscribedInSquare(circle.getX(), circle.getY(), circle.getRadius(), square.getX(), square.getY(), square.getWidth());
}

Circle_inscribed_in_Square::~Circle_inscribed_in_Square()
{
}

bool Circle_inscribed_in_Square::isCircleInscribedInSquare(int xCircle, int yCircle, int rCircle, int xSquare, int ySquare, int widthSquare)
{
	if (widthSquare / 2 != rCircle && xSquare != xCircle - rCircle && ySquare != yCircle - rCircle) {
		std::cout << "\n\t <ERROR> Circle is not inscribed in square! <ERROR>";
		return false;
	}
	std::cout << "\n\t <Note> Circle has been inscribed in square! <Note>";
	return true;
}
