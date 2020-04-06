#include <iostream>
#include "funcs.h"
using namespace std;



int main() {
	srand(time(NULL));

// Homework 18.1.1 Course: "Basics of programming in C++".
	/*int length = 10;
	int rows = 20;
	char** arr;
	reserveArr(rows, length, arr);
	arr[0] = (char*)"33335";
	arr[1] = (char*)"33325";
	arr[2] = (char*)"33315";
	arr[3] = (char*)"20";
	arr[4] = (char*)"33235";
	arr[5] = (char*)"330";
	arr[6] = (char*)"23315";
	arr[7] = (char*)"33015";
	arr[8] = (char*)"33455";
	arr[9] = (char*)"1008";
	arr[10] = (char*)"Masha";
	arr[11] = (char*)"Ivan";
	arr[12] = (char*)"Misha";
	arr[13] = (char*)"Alex";
	arr[14] = (char*)"Mashunia";
	arr[15] = (char*)"Alexa";
	arr[16] = (char*)"Kolia";
	arr[17] = (char*)"Maria";
	arr[18] = (char*)"Mashia";
	arr[19] = (char*)"Mashen`ka";
	sortStr(arr, rows, 0);
	printArr(arr, rows);*/

// Homework 18.1.2 Course: "Basics of programming in C++".
	int minVal = -20, maxVal = 20;
	int** A, aRows = 4, aColumns = 4;
	int** B, bRows = 4, bColumns = 4;
	int** C, cRows = 4, cColumns = 4;
	createArr(A, aRows, aColumns, minVal, maxVal, "arr A");
	createArr(B, bRows, bColumns, minVal, maxVal, "arr B");
	createArr(C, cRows, cColumns, minVal, maxVal, "arr C");

	// Task 3
	int* commonValFromAC, lenAC = 0;
	separateCommonElFromArr1AndArr2ToNewArr(A, aRows, aColumns, C, cRows, cColumns, commonValFromAC, lenAC);
	cout << "There are common values from arrays A and C";
	printArr(commonValFromAC, lenAC);

	// Task 1
	int* commonValFromAB, lenAB = 0;
	separateCommonElFromArr1AndArr2ToNewArr(A, aRows, aColumns, B, bRows, bColumns, commonValFromAB, lenAB);
	int* commonValFromABC, lenABC = 0;
	separateCommonElFromArr1AndArr2ToNewArr(commonValFromAB, lenAB, commonValFromAC, lenAC, commonValFromABC, lenABC);
	cout << "\nThere are common values from arrays A, B and C";
	printArr(commonValFromABC, lenABC);

	// Task 2
	int* uniqValABC, lenABCuniq = 0;
	separateUniqElFromArr1ExceptArr2ElToNewArr(A, aRows, aColumns, commonValFromABC, lenABC, uniqValABC, lenABCuniq);
	separateUniqElFromArr1ExceptArr2ElToNewArr(B, bRows, bColumns, commonValFromABC, lenABC, uniqValABC, lenABCuniq);
	separateUniqElFromArr1ExceptArr2ElToNewArr(C, cRows, cColumns, commonValFromABC, lenABC, uniqValABC, lenABCuniq);
	cout << "\nThere are uniq values from arrays A, B and C";
	printArr(uniqValABC, lenABCuniq);

	// Task 4
	int* negativeVal, lenNeg = 0;
	separateArrValuesNegative(uniqValABC, lenABCuniq, negativeVal, lenNeg);
	separateArrValuesNegative(commonValFromABC, lenABC, negativeVal, lenNeg);
	cout << "\nThere are negative values from arrays A, B and C";
	printArr(negativeVal, lenNeg);

	removeArr(A, aRows);
	removeArr(B, bRows);
	removeArr(C, cRows);
	removeArr(commonValFromAC);
	removeArr(commonValFromAB);
	removeArr(commonValFromABC);
	removeArr(uniqValABC);
	removeArr(negativeVal);
	
// Homework 18.2.1 Course: "Basics of programming in C++".
	/*complexNumber A { 3, 3 };
	complexNumber B { 4, 4 };
	A.print();
	addComplexNumber(A, B).print();
	subComplexNumber(A, B).print();
	multComplexNumber(A, B).print();
	divComplexNumber(A, B).print();*/

// Homework 18.2.2 Course: "Basics of programming in C++".
	/*car A{ "Audi", 1, 2, 3, 4, 5, red, automatic };
	car B{ "BMW", 2, 3, 4, 5, 6, blue, mechanic };
	car arr[2];
	arr[0] = A;
	arr[1] = B;
	car searchedCar;
	int length = 2, indexOfSearchedElement;
	if (trySearchIndexOfKeyEl(arr, length, carLength, 2, searchedCar, indexOfSearchedElement)) {
		searchedCar.print();
	}
	if (trySearchIndexOfKeyEl(arr, length, red, searchedCar, indexOfSearchedElement)) {
		searchedCar.print();
	}
	if (trySearchIndexOfKeyEl(arr, length, mechanic, searchedCar, indexOfSearchedElement)) {
		searchedCar.print();
	}*/
}