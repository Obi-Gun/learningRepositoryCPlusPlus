#include <iostream>
#include "funcs.h"
using namespace std;

struct rectangle
{
	int x;
	int y;
	int length;
	int height;
	/*void Print()
	{
		cout << x << " " << y << endl;
	}*/
};

struct point
{
	double x;
	double y;
};

struct fraction
{
	int numerator;
	int denominator;
};

fraction sum(fraction A, fraction B)
{
	if (A.denominator != B.denominator) {
		int tmp = A.denominator * B.denominator;
		A.numerator *= (tmp / A.denominator);
		A.denominator = tmp;
		B.numerator *= (tmp / B.denominator);
		B.denominator = tmp;
	}
	fraction res = { A.numerator + B.numerator, A.denominator };
	return res;
}

fraction substr(fraction A, fraction B)
{
	if (A.denominator != B.denominator) {
		int tmp = A.denominator * B.denominator;
		A.numerator *= (tmp / A.denominator);
		A.denominator = tmp;
		B.numerator *= (tmp / B.denominator);
		B.denominator = tmp;
	}
	fraction res = { A.numerator - B.numerator, A.denominator };
	return res;
}

fraction multipy(fraction A, fraction B)
{
	fraction res = { A.numerator * B.numerator, A.denominator * B.denominator};
	return res;
}

fraction divide(fraction A, fraction B)
{
	fraction res = { A.numerator * B.denominator, A.denominator * B.numerator };
	return res;
}

void reduceFraction(fraction& A)
{
	for (int i = minValue(&A.numerator, &A.denominator); i > 0; --i) {
		if (isDivisor(A.numerator, i) && isDivisor(A.denominator, i)) {
			A.numerator /= i;
			A.denominator /= i;
			break;
		}
	}
}

void printFraction(fraction A)
{
	cout << A.numerator << endl;
	cout << "---" << endl;
	cout << A.denominator << endl;
}

double distance(point A, point B)
{
	return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}

void moveFig(rectangle& fig, int moveX, int moveY)
{
	fig.x += moveX;
	fig.y += moveY;
}

void scaleHeight(rectangle& fig, double multiplier)
{
	fig.height *= multiplier;
}

void scaleLength(rectangle& fig, double multiplier)
{
	fig.length *= multiplier;
}

void drawFig(rectangle fig)
{
	char lu = 201, ld = 200;
	char ru = 187, rd = 188;
	char hor = 205;
	char vert = 186;
	fig.length *= 1.4; // it is for correct drawing in console
	// TOP
	cout << lu;
	for (int j = 0; j < fig.length; ++j) {
		cout << hor;
	}
	cout << ru << endl;
	// MIDDLE
	for (int i = 1; i < fig.height - 1; ++i) {
		cout << vert;
		for (int j = 0; j < fig.length; ++j) {
			cout << ' ';
		}
		cout << vert << endl;
	}
	// BOTTOM
	cout << ld;
	for (int j = 0; j < fig.length; ++j) {
		cout << hor;
	}
	cout << rd << endl;
}

void printFig(rectangle fig)
{
	cout << " coordinate x = " << fig.x << endl;
	cout << " coordinate y = " << fig.y << endl;
	cout << " height = " << fig.height << endl;
	cout << " length = " << fig.length << endl;
}

void main() {
	srand(time(NULL));

// Course: "Basics of programming in C++". Week 18. ClassWork 2.1
	/*rectangle fig1 = { 50, 50, 5, 5 };
	printFig(fig1);
	moveFig(fig1, 300, 700);
	printFig(fig1);
	drawFig(fig1);
	scaleHeight(fig1, 1.5);
	scaleLength(fig1, 0.5);
	printFig(fig1);
	drawFig(fig1);*/

// Course: "Basics of programming in C++". Week 18. ClassWork 2.2
	/*point a = { 0,0 };
	point b = { 1,1 };
	cout << distance(a, b);*/

// Course: "Basics of programming in C++". Week 18. ClassWork 2.3
	//fraction a = { 1, 10 };
	//fraction b = { 1, 20 };
	//fraction res1 = sum(a, b);
	//printFraction(res1);
	//fraction res2 = substr(a, b);
	//printFraction(res2);
	//printFraction(multipy(a, b));
	//fraction res = divide(a, b);
	fraction b = { 50, 700 };
	printFraction(b);
	reduceFraction(b);
	printFraction(b);
}