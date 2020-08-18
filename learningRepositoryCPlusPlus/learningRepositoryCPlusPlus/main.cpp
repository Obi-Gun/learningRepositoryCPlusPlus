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

// Classwork 16.08.2020 Vector task 1
	/*vector<int> testVector;
	for (int i = 0; i < 10; ++i) {
		testVector.push_back(mathPow(i + 1, 2));
		cout << testVector[i] << " ";
	}
	cout << endl;
	for (auto i = testVector.begin(); i != testVector.end(); ++i) {
		cout << *i << " ";
	}*/

// Classwork 16.08.2020 two-dimensional Vector task 2
	/*vector<vector<int>> testVector;
	for (int i = 0; i < 10; ++i) {
		testVector.push_back(vector<int>());
		for (int j = 0; j < 10; ++j) {
			testVector[i].push_back((i + 1) * (j + 1));
		}
	}
	for (auto i = testVector.begin(); i != testVector.end(); ++i) {
		for (auto j = i->begin(); j != i->end(); ++j) {
			printf("%3i ", *j);
		}
		cout << endl << endl;
	}*/

// Classwork 16.08.2020 list
	/*list<list<int>> testList;
	for (int i = 0; i < 10; ++i) {
		list<int> tmp;
		for (int j = 0; j < 10; ++j) {
			tmp.push_back((i + 1) * (j + 1));
		}
		testList.push_back(tmp);
	}
	for (auto i = testList.begin(); i != testList.end(); ++i) {
		for (auto j = i->begin(); j != i->end(); ++j) {
			printf("%3i ", *j);
		}
		cout << endl << endl;
	}*/

// Homework 14.1. Course: "OOP in C++".
	/*Student_Vector arr;
	arr.add("Ivan2", "Ivanov", 1);
	arr.add("Egor2", "Gagarin", 2);
	arr.add("Oleg2", "Ivanov", 3);
	arr.add("Gregory2", "Kim", 4);
	arr.add("Ugine2", "Tompson", 1);
	arr.add("Bobr1", "Klimov", 2);
	arr.add("Ul1", "Erundov", 3);
	arr.add("Epistafiy1", "Corabelov", 4);
	arr.add("Lenin1", "Ter", 1);
	arr.add("Yuri1", "Tompson", 2);

	arr.add("Ivan1", "Ivanisov", 1);
	arr.add("Egor1", "Tatarin", 2);
	arr.add("Oleg1", "Pivanov", 3);
	arr.add("Gregory1", "Uim", 4);
	arr.add("Ugine1", "Tompson", 1);
	arr.add("Bobr2", "Klimov", 2);
	arr.add("Ul2", "Terundov", 3);
	arr.add("Epistafiy2", "Morabelov", 4);
	arr.add("Lenin2", "Meller", 1);
	arr.add("Yuri2", "Tomson", 2);

	arr.sortByName();
	cout << "_______SortByName" << endl << arr << endl;

	arr.sortBySurname();
	cout << "_______SortBySurname" << endl << arr << endl;

	arr.sortByYear();
	cout << "_______SortByYear" << endl << arr << endl;

	arr.sortByName(0, 3);
	arr.sortByName(3);
	cout << "_______SortByFirst 1-3 and 4-20" << endl << arr << endl;*/

// Homework 14.2. Course: "OOP in C++".
	DictionaryOfFrequency dict;
	//dict.readFileAndFillDictionary("C:\\Users\\Alexandr\\Desktop\\New Text Document.txt");
	dict.readFileAndFillDictionary("C:\\Users\\Alexandr\\Desktop\\War and Peace.txt");
	cout << dict;
}