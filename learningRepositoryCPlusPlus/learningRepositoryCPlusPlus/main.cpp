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
	if (A.denominator != B.denominator) {
		int tmp = A.denominator * B.denominator;
		A.numerator *= (tmp / A.denominator);
		A.denominator = tmp;
		B.numerator *= (tmp / B.denominator);
		B.denominator = tmp;
	}
	fraction res = { A.numerator * B.numerator, A.denominator };
	return res;
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
	/*// Course: "Basics of programming in C++". Week 17. HomeWork 2.2
		char*** arr;
		int rows = 2, columns = 6, strLen = 16;
		reserveArr(rows, columns, strLen, arr);
		addContact(arr, 0, strLen, (char*)"Ivan Smirnov", (char*)"+79999999999");
		addContact(arr, 1, strLen, (char*)"Petr Smirnov", (char*)"+71234567890");
		addContact(arr, 2, strLen, (char*)"Oleg Efimov", (char*)"+71565151515");
		addContact(arr, 3, strLen, (char*)"Petr Long", (char*)"+712345454545");
		addContact(arr, 4, strLen, (char*)"Evgeny Petrov", (char*)"+79999889999");
		addContact(arr, 5, strLen, (char*)"Petr Ivanov", (char*)"+71234566890");
		printArr(arr, rows, columns, strLen, strLen);
		findName(arr, columns, (char*)"Petr", strLen);
		findPhone(arr, columns, (char*)"712345454545", strLen);
	// There is something wrong with input. Every time i tried "cin" name to 3rd or larger column the program crashed.
	// fail
		//addContact(arr, 6, strLen);
	// fail
		while (true) {
		cout << "Enter the name, please: --> ";
		enterStr(arr, 0, 6, strLen);
		}
	// fail
		for (int i = 0; i < columns; ++i) {
		cout << "Enter the name, please: --> ";
		cin.getline(arr[0][i], strLen);
		}
	// fail
		for (int i = 0; i < columns; ++i) {
		cout << "Enter the name, please: --> ";
		cin >> arr[0][i];
		}*/

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
	fraction a = { 1, 2 };
	fraction b = { 1, 3 };
	//fraction res1 = sum(a, b);
	//printFraction(res1);
	//fraction res2 = substr(a, b);
	//printFraction(res2);
	printFraction(multipy(a, b));
}