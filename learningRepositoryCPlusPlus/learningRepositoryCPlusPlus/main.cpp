#include <iostream>
#include "ComplexNum.h"
#include "String_SmartPointer.h"

using namespace std;

int ComplexNum::_objCounter = 0;

int main() {
// Homework 6.2. Course: "OOP in C++". Class ComplexNumber
	/*cout << "\nThere are " << ComplexNum::getObjCounter() << " ComplexNum objects right now";

	ComplexNum num1(5, 6), num2(8, 8);
	cout << "\nSum:      ";
	(num1 + num2).print();
	cout << "\nThere are " << ComplexNum::getObjCounter() << " ComplexNum objects right now";

	cout << "\nSubstr:   ";
	(num1 - num2).print();
	cout << "\nThere are " << ComplexNum::getObjCounter() << " ComplexNum objects right now";

	cout << "\nMultiply: ";
	(num1 * num2).print();
	cout << "\nThere are " << ComplexNum::getObjCounter() << " ComplexNum objects right now";

	cout << "\nDivide:   ";
	(num1 / num2).print();
	cout << "\nThere are " << ComplexNum::getObjCounter() << " ComplexNum objects right now";

	cout << "\nnum1: ";
	num1.print();
	cout << "\nnum2: ";
	num2.print();
	num1 = num2;
	cout << "\nnum1 after operation = : ";
	num1.print();
	cout << "\nThere are " << ComplexNum::getObjCounter() << " ComplexNum objects right now";*/

// Homework 6.3. Course: "OOP in C++". Class String_SmartPointer
	String_obi* str = new String_obi("Hello there!");

	String_SmartPointer obj(str);
	String_SmartPointer copy1;
	copy1 = obj;

	String_SmartPointer copy2 = obj;
	String_SmartPointer copy3 = copy2;

}