#include <iostream>
#include "funcs.h"
using namespace std;
#define CHAR

void process()
{
	int length = 20;

#if defined(INTEGER)
	int* arr;
	int minVal, minValInd, maxVal, maxValInd;
#elif defined(DOUBLE)
	double* arr;
	double minVal, maxVal;
	int maxValInd, minValInd;
#elif defined(CHAR)
	char* arr;
	char minVal, maxVal;
	int maxValInd, minValInd;
#endif

	reserveArr(length, arr);
	fillRandomValuesToTheArray(arr, length);
	printArr(arr, length);
	quickSort(arr, length - 1);
	minValArrInd(arr, length, minVal, minValInd);
	maxValArrInd(arr, length, maxVal, maxValInd);
	printArr(arr, length);
	cout << "minVal = " << minVal;
}


void main() {
	srand(time(NULL));
// ClassWork. Course: "Basics of programming in C++". 25.03.2020


// ClassWork. Preprocessors. Course: "Basics of programming in C++". 27.03.2020
	process();

}