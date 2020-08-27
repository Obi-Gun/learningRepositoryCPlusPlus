#include <iostream>
#include "ComplexNum.h"//
//#include "String_SmartPointer.h"
#include "String_obi.h"//
//#include "CalcStr.h"
#include <vector>
//#include "funcs.h"
#include "Student.h"
#include <list>
#include "Student_Vector.h"
#include "DictionaryOfFrequency.h"
#include <fcntl.h>
#include <io.h>

using namespace std;

int ComplexNum::_objCounter = 0;
int String_obi::_objCounter = 0;

int main() {
// Homework 6.1. Course: "OOP in C++". 



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
	/*cout << "\nThere are " << String_obi::getObjCounter() << " String_obi objects right now";

	String_obi* str = new String_obi("Hello there!");
	cout << "\nThere are " << String_obi::getObjCounter() << " String_obi objects right now";

	String_SmartPointer obj(str);
	cout << "\nThere are " << String_obi::getObjCounter() << " String_obi objects right now";

	String_SmartPointer copy1;
	cout << "\nThere are " << String_obi::getObjCounter() << " String_obi objects right now";
	copy1 = obj;
	cout << "\nThere are " << String_obi::getObjCounter() << " String_obi objects right now";

	String_SmartPointer* copy2 = new String_SmartPointer(obj);
	cout << "\nThere are " << String_obi::getObjCounter() << " String_obi objects right now";

	delete copy2;
	cout << "\nThere are " << String_obi::getObjCounter() << " String_obi objects right now";

	copy2 = new String_SmartPointer(obj);
	cout << "\nThere are " << String_obi::getObjCounter() << " String_obi objects right now";

	copy2->~String_SmartPointer() ;
	cout << "\nThere are " << String_obi::getObjCounter() << " String_obi objects right now";

	String_SmartPointer copy3 = copy1;
	cout << "\nThere are " << String_obi::getObjCounter() << " String_obi objects right now";

	// Here we can see that there is only one example of class String_obi has been created. Thats why we used a smartpointer.
	*/
}