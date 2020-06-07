#include <iostream>
#include "Human.h"
#include "Flat.h"
#include "House.h"
#include "Reservoir.h"
#include "Arr_Reservoir.h"
#include "String_obi.h"
#include "Arr_int.h"
#include "Time_obi.h"
#include "String_SmartPointer.h"
#include "QueuePriority.h"
#include "List.h"
#include "ListBiDirectional.h"

using namespace std;

Time_obi* Time_obi::pointer_ = new Time_obi(666, 666, 666);

void str(int first, ...) {
	int* p = &first;
	for (int i = 0; i < 6; ++i) {
		cout << (char)*p++;

	}
}

int main() {
// Classwork override operator [] 1. Course: "OOP in C++".
	/*Arr_int arr(5);
	arr[0] = 88;
	arr[1] = 77;
	arr[2] = 66;
	arr[3] = 55;
	arr[4] = 44;

	Arr_int arr2;
	arr2 = arr;
	++arr2;
	cout << arr2;*/

// Classwork singletone pattern and override operator(). Course: "OOP in C++".
	/*Time_obi* time = Time_obi::getReference();
	cout << time;*/

// Classwork. Smartpointers. Course: "OOP in C++".
	/*String_obi* str = new String_obi("Lola");

	String_SmartPointer smartP(str);

	String_obi* tmp = smartP;

	String_SmartPointer tmpSP = smartP;

	smartP->print();

	++smartP;
	smartP++;*/

// Classwork. Functions with custom quantityand type arguments. Course: "OOP in C++".
	//str('1', '2', '3', '4', '5', '6');

// Classwork. New dataStructures. Queues. Course: "OOP in C++".
	/*QueuePriority queue(10);

	queue.add(666, 6);
	queue.add(777, 7);
	queue.add(666, 6);
	queue.print();
	queue.extract();
	queue.print();*/

// Homework 3.1. Course: "OOP in C++". Class Fraction
// Homework 3.2. Course: "OOP in C++". Class ComplexNumber
// Homework 3.3. Course: "OOP in C++". Class Overcoat
// Homework 3.4. Course: "OOP in C++". Class Flat

// Classwork. List. Queues. Course: "OOP in C++".
	/*List* list = new List("Hello");
	list->print();
	list->add(", ");
	list->add("Lola");
	list->print();*/

// Classwork. ListBiDirectional. Queues. Course: "OOP in C++".
	ListBiDirectional<char>* list = new ListBiDirectional<char>((char*)"1");
	list->addTail((char*)"2");
	list->addTail((char*)"3");
	list->addHead((char*)"0");
	list->print();
	list->insert((char*)"F", 1);
	list->print();
	list->~ListBiDirectional();
	//cout << list->getEl(3)->str_;
	//list->printReverse();
}