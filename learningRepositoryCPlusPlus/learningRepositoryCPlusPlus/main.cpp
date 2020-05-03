#include <iostream>
#include "funcs.h"

using namespace std;

int main() {
// Homework 1.1. Course: "OOP in C++".
	/*Fraction A(1, 2);
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
	A.print();*/

// Homework 1.2. Course: "OOP in C++".
	PhoneBook phonebook;

	Contact* i0 = new Contact("Ivan");
	Contact* i1 = new Contact(*i0);
	i1->setName("Igor");
	Contact* i2 = new Contact("Ivar");
	Contact* i3 = new Contact("Lola");
	Contact* i4 = new Contact("Kola");
	Contact* i5 = new Contact("Juju");
	Contact* i6 = new Contact("Goga");
	Contact* i7 = new Contact("Pepe");
	Contact* i8 = new Contact("Lili");
	Contact* i9 = new Contact("Vova");
	Contact* i10 = new Contact("Revu");
	Contact* i11 = new Contact("Opel");

	phonebook.addContact(i0);
	phonebook.addContact(i1);
	phonebook.addContact(i2);
	phonebook.addContact(i3);
	phonebook.addContact(i4);
	phonebook.addContact(i5);
	phonebook.addContact(i6);
	phonebook.addContact(i7);
	phonebook.addContact(i8);
	phonebook.addContact(i9);
	phonebook.addContact(i10);
	phonebook.addContact(i11);

	phonebook.menu();


}