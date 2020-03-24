#include <iostream>
#include "funcs.h"
using namespace std;



void main() {
	srand(time(NULL));

// HomeWork 12.1.1. Course: "Basics of programming in C++".
	/*cout << calcDays(1, 1, 2001, 02, 03, 2020) << endl;
	cout << calcDays(1, 1, 2001, 01, 03, 2020) << endl;
	cout << calcDays(1, 1, 2001, 29, 02, 2020) << endl;
	cout << calcDays(1, 1, 2001, 28, 02, 2020) << endl;*/

// HomeWork 12.1.2. Course: "Basics of programming in C++".
	/*int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	cout << sumArrValues(arr, arr + 11) << endl;
	cout << calcAverage(arr, 12);*/

// HomeWork 12.1.3. Course: "Basics of programming in C++".
	int arr[] = { -1, -1, -555, 0, 1, 1, 555, 0, 0 };
	int negCounter = 0, zerosCounter = 0, posCounter = 0;
	calcNumbers(arr, 9, negCounter, zerosCounter, posCounter);
	cout << "negative = " << negCounter << ", zeros = " << zerosCounter << ", positive = " << posCounter;

// HomeWork 12.2.1. Course: "Basics of programming in C++".
// HomeWork 12.2.2. Course: "Basics of programming in C++".
// HomeWork 12.2.3. Course: "Basics of programming in C++".

}