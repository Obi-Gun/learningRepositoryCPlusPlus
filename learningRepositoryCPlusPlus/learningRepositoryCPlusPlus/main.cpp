#include <iostream>
#include "funcs.h"
using namespace std;

template <typename T> void quickSort(T* arr, int N) //N - index of last element
{
	int i = 0, j = N;
	T p = arr[N / 2]; // опорный элемент
	do {
		while (arr[i] <= p) {
			++i;
		}
		while (arr[j] >= p) {
			--j;
		}
		if (i < j) {
			swap(arr[i], arr[j]);
		}
	} while (i < j);
	if (j > 0) {
		quickSort(arr, j);
	}
	if (j < N) {
		quickSort(arr + j, N - j);
	}
}

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
	/*int arr[] = { -1, -1, -555, 0, 1, 1, 555, 0, 0 };
	int negCounter = 0, zerosCounter = 0, posCounter = 0;
	calcNumbers(arr, 9, negCounter, zerosCounter, posCounter);
	cout << "negative = " << negCounter << ", zeros = " << zerosCounter << ", positive = " << posCounter;*/

// HomeWork 12.2.1. Course: "Basics of programming in C++".
	/*int len = 5;

	char** arr1;
	reserveArr(len, len, arr1);
	fillRandomValuesToTheArray(arr1, len, len, 1, 100);
	printArr(arr1, len, len);
	cout << "max value on diagonal = " << maxValueDiagonal(arr1, len) << endl;
	cout << "min value on diagonal = " << minValueDiagonal(arr1, len) << endl;
	insertionSort(arr1, len, len);
	printArr(arr1, len, len);

	int** arr2;
	reserveArr(len, len, arr2);
	fillRandomValuesToTheArray(arr2, len, len, 0, 9);
	printArr(arr2, len, len);
	cout << "max value on diagonal = " << maxValueDiagonal(arr2, len) << endl;
	cout << "min value on diagonal = " << minValueDiagonal(arr2, len) << endl;
	insertionSort(arr2, len, len);
	printArr(arr2, len, len);

	double** arr3;
	reserveArr(len, len, arr3);
	fillRandomValuesToTheArray(arr3, len, len);
	arr3[3][3] = 3.3333;
	printArr(arr3, len, len);
	cout << "max value on diagonal = " << maxValueDiagonal(arr3, len) << endl;
	cout << "min value on diagonal = " << minValueDiagonal(arr3, len) << endl;
	insertionSort(arr3, len, len);
	printArr(arr3, len, len);*/
	
// HomeWork 12.2.2. Course: "Basics of programming in C++".
	/*cout << maxCommonDivisor(159, 646) << endl;
	cout << maxCommonDivisor(100, 1000) << endl;
	cout << maxCommonDivisor(666, 777) << endl;*/

// HomeWork 12.2.3. Course: "Basics of programming in C++".
	//game_BullsAndCows();

// ClassWork QuickSort. Course: "Basics of programming in C++". 25.03.2020
	int length = 10;
	int* arr;
	reserveArr(length, arr);
	fillRandomValuesToTheArray(arr, length, 0, 10);
	printArr(arr, length);
	quickSort(arr, 9);
	printArr(arr, length);
}