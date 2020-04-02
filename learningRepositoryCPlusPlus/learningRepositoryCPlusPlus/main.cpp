#include <iostream>
#include "funcs.h"

using namespace std;



int main() {
	srand(time(NULL));

// Homework 13.1 Course: "Basics of programming in C++".
	/*int length = 50;
	int* arr;
	reserveArr(length, arr);
	fillRandomValuesToTheArray(arr, length, 0, 50);
	printArr(arr, length);
	sortArr(arr, length, 0);
	printArr(arr, length);
	removeArr(arr);*/

// Homework 13.2 Course: "Basics of programming in C++".
	/*int length = 20;
	int* arr;
	reserveArr(length, arr);
	fillRandomValuesToTheArray(arr, length, -20, 20);
	printArr(arr, length);
	int left, right, l = 0, r = length - 1;
	while (arr[l++] > 0);
	while (arr[r--] > 0);
	quickSort(arr + l, r - l);
	printArr(arr, length);
	removeArr(arr);*/

// Homework 13.3 Course: "Basics of programming in C++".
	int length = 20;
	int* arr;
	reserveArr(length, arr);
	for (int i = 0; i < length; ++i) {
		arr[i] = i + 1;
	}
	printArr(arr, length);
	// Homework 13.3.1
	shakeValuesInArr(arr, length);
	printArr(arr, length);
	// Homework 13.3.2
	int searchedNumber = fillRandomValue(1, 20);
	cout << "searchedNumber = " << searchedNumber << endl;
	int indexOfSN = searchIndexOfKeyEl(arr, length, searchedNumber);
	cout << "index of searchedNumber = " << indexOfSN << endl;
	// Homework 13.3.3
	sortArr(arr, indexOfSN, false);
	sortArr(arr + indexOfSN + 1, length - indexOfSN - 1);
	printArr(arr, length);
	removeArr(arr);
}