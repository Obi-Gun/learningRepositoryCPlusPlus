#include <iostream>
#include "Time_obi.h"
#include "Fraction.h"
#include "ComplexNum.h"
#include "Overcoat.h"
#include "Flat.h"

using namespace std;
Time_obi* Time_obi::pointer_ = new Time_obi(666, 666, 666);

int main() {
// Homework 3.1. Course: "OOP in C++". Class Fraction
	/*Fraction fract1(5, 10), fract2(3, 5);
	cout << "Sum:      ";
	fract1.sum(fract2).print();
	cout << "        ";
	(fract1 + fract2).print();

	cout << "\nSubstr:   ";
	fract1.substr(fract2).print();
	cout << "        ";
	(fract1 - fract2).print();

	cout << "\nMultiply: ";
	fract1.multiply(fract2).print();
	cout << "        ";
	(fract1 * fract2).print();

	cout << "\nDivide:   ";
	fract1.divide(fract2).print();
	cout << "        ";
	(fract1 / fract2).print();*/

// Homework 3.2. Course: "OOP in C++". Class ComplexNumber
	/*ComplexNum num1(5, 6), num2(8, 8);
	cout << "Sum:      ";
	(num1 + num2).print();

	cout << "\nSubstr:   ";
	(num1 - num2).print();

	cout << "\nMultiply: ";
	(num1 * num2).print();

	cout << "\nDivide:   ";
	(num1 / num2).print();

	cout << "\n = :      ";
	num1.print();
	num2.print();
	num1 = num2;
	cout << ",  ";
	num1.print();*/

// Homework 3.3. Course: "OOP in C++". Class Overcoat
	/*bool tmp;
	Overcoat coat1, coat2(10, fur), coat3(15, fur);

	tmp = coat2 == coat3;
	cout << "\nTest operator==      Expected true      Result is: " << tmp;
	tmp = coat1 == coat2;
	cout << "\nTest operator==      Expected false     Result is: " << tmp;

	coat1 = coat2;
	tmp = coat1 == coat2;
	cout << "\nTest operator=       Expected true      Result is: " << tmp;
	
	tmp = coat2 > coat3;
	cout << "\nTest operator>       Expected false     Result is: " << tmp;
	tmp = coat3 > coat2;
	cout << "\nTest operator>       Expected true      Result is: " << tmp;
	tmp = coat2 < coat3;
	cout << "\nTest operator<       Expected true      Result is: " << tmp;
	tmp = coat3 < coat2;
	cout << "\nTest operator<       Expected false     Result is: " << tmp;*/

// Homework 3.4. Course: "OOP in C++". Class Flat
	bool tmp;
	Flat flat1, flat2, flat3;
	flat1.setArea(0);
	flat2.setArea(0);
	flat3.setArea(2);

	tmp = flat1 == flat2;
	cout << "\nTest operator==      Expected true      Result is: " << tmp;
	tmp = flat2 == flat3;
	cout << "\nTest operator==      Expected false     Result is: " << tmp;

	flat2 = flat3;
	tmp = flat2 == flat3;
	cout << "\nTest operator=       Expected true      Result is: " << tmp;

	tmp = flat1 > flat2;
	cout << "\nTest operator>       Expected false     Result is: " << tmp;
	tmp = flat2 > flat1;
	cout << "\nTest operator>       Expected true      Result is: " << tmp;
	tmp = flat1 < flat2;
	cout << "\nTest operator<       Expected true      Result is: " << tmp;
	tmp = flat2 < flat1;
	cout << "\nTest operator<       Expected false     Result is: " << tmp;
}