#include <iostream>
#include "funcs.h"
using namespace std;




int main() {


// Classwork 1.1. Course: "OOP in C++".
	/*Counter counter(1, 50);
	counter.setCurrentValue(100);
	counter.print();
	counter.increment();
	counter.print();*/

// Classwork 1.2. Course: "OOP in C++".
	/*Group group1(5);
	Group group2;
	Student Kolia("Kolia");*/

// Classwork 2.1. Course: "OOP in C++".
	/*Person Egor((char*)"Egor", 40, male, (char*)"+79990001111");
	Egor.print();
	Person Ivan = Egor;
	Ivan.print();
	Person Juju(Ivan);
	Ivan.print();
	Person* pIgor = &Egor;
	pIgor->print();
	pIgor->setName((char*)"Igor");
	pIgor->setAge(33);
	pIgor->setGender(female);
	pIgor->setPhoneNumber((char*)"+7666000666");
	Egor.print();*/

// Homework 1.1. Course: "OOP in C++".
	Fraction A(1, 2);
	Fraction B(2, 3);

	cout << "Sum (";
	A.print();
	cout << ") + (";
	B.print();
	cout << ") = ";
	A.sum(B).print();

	cout << "\nSubstr (";
	A.print();
	cout << ") - (";
	B.print();
	cout << ") = ";
	A.substr(B).print();

	cout << "\nMultiply (";
	A.print();
	cout << ") * (";
	B.print();
	cout << ") = ";
	A.multiply(B).print();

	cout << "\nDivide (";
	A.print();
	cout << ") / (";
	A.print();
	cout << ") = ";
	A = A.divide(A);
	A.print();

	cout << "\nReduced fraction = ";
	A.reduceFraction();
	A.print();

// Homework 1.2. Course: "OOP in C++".

}