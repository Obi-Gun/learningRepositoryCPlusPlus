#include <iostream>
#include <cmath>
#include <time.h>
#include <string.h>
#include <iomanip>
using namespace std;
// headers
#ifndef funcs

template <typename T> void fillRandomValuesToTheArray(T arr[], int LEN)
{
	for (int i = 0; i < LEN; ++i) {
		arr[i] = rand();
	}
}
template <typename T> void fillRandomValuesToTheArray(T arr[], int LEN, T minValue, T maxValue)
{
	if (maxValue < minValue) {
		swap(maxValue, minValue);
	}
	for (int i = 0; i < LEN; ++i) {
		arr[i] = minValue + rand() % (maxValue + 1 - minValue);
	}
}
void fillRandomValuesToTheArray(int** arr, int lenRow, int lenCol, int minValue, int maxValue);
void fillRandomValuesToTheArray(int** arr, int lenRow, int lenCol);

template <typename T> void printArr(T arr[], int LEN)
{
	cout << "\nArray values:" << endl;
	for (int i = 0; i < LEN; ++i) {
		printf("arr[%i] = ", i);
		cout << *(arr + i) << endl;
	}
}
void printArr(int** arr, int rows, int columns, int setMinimumWidth = 0, bool showIndexes = false);
void printArr(char*** arr, int rows, int columns, int strLength, int setMinimumWidth = 2, bool showIndexes = false);

template <typename T> void swap(T* pFirst, T* pSecond)
{
	T tmp = *pFirst;
	*pFirst = *pSecond;
	*pSecond = tmp;
}

void inserionSort(int arr[], int LEN);
void bobbleSort(int arr[], int LEN);

int* reserveArr(int length); // _old   (delete later)
char* reserveArrChar(int length); // _old   (delete later)

void reserveArr(int length, int*& arr);
void reserveArr(int length, int**& arr);
void reserveArr(int rows, int columns, int**& arr);
void reserveArr(int length, char*& arr);
void reserveArr(int length, char**& arr);
void reserveArr(int length, char***& arr);
void reserveArr(int rows, int columns, char**& arr);
void reserveArr(int rows, int columns, int strLen, char***& arr);

//void addElToArr(int*& arr, int& length, int newEl);
void addElToArr(int*& arr, int& length, int newEl, int indexNewEl = 0);
//void addElToArrToSpecialPlace(int*& arr, int& length, int newEl, int indexNewEl);
void addElToArrToSpecialPlace(char*& arr, int length, char newEl, int indexNewEl);
void addColumnToArr(int**& arr, int rows, int& columns, int* newColumn, int indexNewColumn = 0);

void removeElFromArr(int*& arr, int& length, int indexRemEl = 0);
void removeColumnFromArr(int**& arr, int rows, int& columns, int indexRemColumn = 0);
void deleteLastElFromArr(int*& arr, int& length);
template <typename T> void deleteArr(T* arr) //delete later
{
	delete[] arr;
} //delete later
void removeArr(int* arr);
void removeArr(int** arr);
void removeMatrix(int** arr, int lengthRows);
void removeArr(char* arr);

//void deleteSpecificElFromArr(int*& arr, int& length, int indexOfDelEl);
//int** multiplyMatrix(int** arrA, int** arrB, int aM, int K, int bN);
//int** sumMatrix(int** arrA, int aRow, int aCol, int** arrB, int bRow, int bCol);
void transposeMatrix(int**& arrSource, int& rows, int& columns);

void shiftArrElRight_old(int* arr, int indexOfFirstElement, int indexOfSecondElement); // _old   (delete later)
void shiftArrElLeft_old(int* arr, int indexOfFirstElement, int indexOfSecondElement); // _old   (delete later)
void shiftArrElLeft(int*& arr, int length, int times);
void shiftArrElRight(int*& arr, int length, int times);
void shiftColumnsLeft(int** arr, int rows, int columns, int times = 1);
void shiftColumnsRight(int** arr, int rows, int columns, int times = 1);
void shiftArrRowsUp(int**& arr, int length, int times);
void shiftArrRowsDown(int**& arr, int length, int times);
void shiftArrValues(int**& arr, int rows, int columns, bool shiftHigher, int verticalSteps, bool shiftRight, int horizontalSteps);

void copyArray(int* arr, int lengthOfShortestArray, int* arrCopy);
void copyArray(int** arr, int lengthOfShortestArray, int** arrCopy);
void copyArray(char* arrSource, int length, char* arrDest);

template <typename T> T sumArrValues(T arr[], int curPos, int LEN);
template <typename T> T sumArrValues(T* curEl, T* endEl);
int maxValue(int* pa, int* pd);
void maxValArrInd(int* arr, int N, int& maxVal, int& indexMaxVal);
int* deletePrimeNumbers(int* arr, int length, int& lengthNewArr);
void separateArrValues(int* arr, int length, int*& arrNeg, int& lenNeg, int*& arrZero, int& lenZero, int*& arrPos, int& lenPos);
void separateUniqElFromArr1ExceptArr2ElToNewArr(int* arr, int length, int* arr2, int length2, int*& arrNew, int& lengthNew);
template <typename T> long long int mathPow(T a, T b);
int mathSumValFromRange(int a, int b);

bool isUniqNumber(int number, int* arr, int length);
bool isPerfectNumber(int a);
bool isDivisor(int a, int divisor);
bool isNumberHappy(int number);
bool isPrimeNumber(int number);
bool isEqualsChar(char el, char el2);

int countDigits(char* source);
int countLetters(char* source);
int countWords(char* sourceArr);
int countSymbolsInArr1isFromArr2(char* source, const char* symbolsToFind);

int searchIndexOfKeyEl(int* arr, int length, int searchedEl);
int searchIndexOfKeyElBinar(int* arr, int length, int searchedEl);
int* findPerfectNumbersFromRange(int first, int last, int& length);

int convertBinarySystemNumberToDecimal(int input);
int convertBinarySystemNumberToDecimal(long long int input);

void findName(char*** arr, int columns, char* strName, int setMinimumWidth = 16);
void findPhone(char*** arr, int columns, char* strPhoneNumber, int setMinimumWidth = 16);
void enterStr(char*** arr, int row, int column, int strLength);
void addContact(char*** arr, int column, int strLength);
void addContact(char*** arr, int column, int strLength, char* name, char* pNumber);

#define funcs
#endif // !funcs