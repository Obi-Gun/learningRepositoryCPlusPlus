#include "funcs.h"
//#include <iostream>
//#include <cmath>
//#include <time.h>
//#include <string.h>
//using namespace std;

//   ===================================================
//   |            My own small library                 |
//   |    I`ve tryed to follow this codeStyle          |
//   |      https://habr.com/ru/post/172091/           |
//   ===================================================


bool isEqualsChar(char el, char el2)
{
	return el == el2;
}

int countDigits(char* source)
{
	return countSymbolsInArr1isFromArr2(source, "0123456789");
}

int countLetters(char* source)
{
	return countSymbolsInArr1isFromArr2(source, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

int countWords(char* sourceArr)
{
	int counter = 0;
	char* context;
	char* p = strtok_s(sourceArr, " ", &context);
	if (p != 0) {
		++counter;
	}
	while (p = strtok_s(NULL, " ", &context)) {
		++counter;
	}
	return counter;
}

int countSymbolsInArr1isFromArr2(char* source, const char* symbolsToFind)
{
	char* currentPointer = source;
	int counter = 0;
	while (char* c = strpbrk(currentPointer, symbolsToFind)) {
		++counter;
		currentPointer = c + 1;
	}
	return counter;
}

void fillRandomValuesToTheArray(int** arr, int lenRow, int lenCol, int minValue, int maxValue)
{
	if (maxValue < minValue) {
		swap(maxValue, minValue);
	}
	for (int i = 0; i < lenRow; ++i) {
		for (int j = 0; j < lenCol; ++j) {
			arr[i][j] = minValue + rand() % (maxValue + 1 - minValue);
		}
	}
}

void fillRandomValuesToTheArray(int** arr, int lenRow, int lenCol)
{
	for (int i = 0; i < lenRow; ++i) {
		for (int j = 0; j < lenCol; ++j) {
			arr[i][j] = rand();
		}
	}
}

void printArr(int** arr, int rows, int columns, int setMinimumWidth, bool showIndexes)
{
	setMinimumWidth = setMinimumWidth < 0 ? 0 : setMinimumWidth;
	cout << "\nArray values:" << endl;
	for (int i = 0; i < rows; ++i) {
		cout << " ";
		for (int j = 0; j < columns; ++j) {
			if (showIndexes) {
				cout << "   arr[" << i << "][" << j << "]= " << setw(setMinimumWidth) << arr[i][j];
			}
			else {
				cout << setw(setMinimumWidth) << arr[i][j] << "  ";
			}
		}
		cout << endl << endl;
	}
}

void printArr(char*** arr, int rows, int columns, int strLength, int setMinimumWidth, bool showIndexes)
{
	setMinimumWidth = setMinimumWidth < 0 ? 0 : setMinimumWidth;
	cout << "\nPhonebook:" << endl;
	for (int i = 0; i < columns; ++i) {
		cout << " ";
		for (int j = 0; j < rows; ++j) {
			if (showIndexes) {
				cout << "   arr[" << j << "][" << i << "]= " << setw(setMinimumWidth) << arr[j][i];
			}
			else {
				cout << setw(setMinimumWidth) << arr[j][i] << "  ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

template <typename T> T sumArrValues(T arr[], int curPos, int LEN)
{
	if (curPos == LEN) {
		return 0;
	}
	return arr[curPos] + sumArrValues(arr, (curPos + 1), LEN);
}

template <typename T> T sumArrValues(T* curEl, T* endEl)
{
	if (curEl == endEl) {
		return *endEl;
	}
	return *curEl + sumArrValues((curEl + 1), endEl);
}

void inserionSort(int arr[], int LEN)
{
	for (int i = 0; i < (LEN - 1); ++i) {
		int x = arr[i + 1];
		int j = i + 1;
		while (arr[j] < arr[j - 1] && j > 0) {
			//SWAP(arr, i, j);
			int tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
			j--;
		}
		arr[j] = x;
	}
}

void bobbleSort(int arr[], int length)
{
	for (int i = 0; i < length; ++i) {
		for (int j = (length - 1); j > i; --j) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
		}
	}
}

int maxValue(int* pa, int* pd)
{
	return *pa < *pd ? *pd : *pa;
}

void maxValArrInd(int* arr, int N, int& maxVal, int& indexMaxVal)
{
	maxVal = *arr;
	indexMaxVal = 0;
	for (int i = 1; i < N; ++i) {
		if (maxVal < *(arr + i)) {
			maxVal = *(arr + i);
			indexMaxVal = i;
		}
	}
}

int* reserveArr(int length) // _old   (delete later)
{
	return new int[length];
}

void reserveArr(int length, int*& arr) // _new
{
	arr = new int[length];
}

char* reserveArrChar(int length)
{
	return new char[length];
}

void reserveArr(int length, int**& arr)
{
	arr = new int* [length];
}

void reserveArr(int rows, int columns, int**& arr)
{
	arr = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		arr[i] = reserveArr(columns);
	}
}

void reserveArr(int length, char*& arr)
{
	arr = new char[length];
}

void reserveArr(int length, char**& arr)
{
	arr = new char* [length];
}

void reserveArr(int length, char***& arr)
{
	arr = new char** [length];
}

void reserveArr(int rows, int columns, char**& arr)
{
	reserveArr(rows, arr);
	for (int i = 0; i < rows; ++i) {
		reserveArr(columns, arr[i]);
	}
}

void reserveArr(int rows, int columns, int strLen, char***& arr)
{
	reserveArr(rows, arr);
	for (int i = 0; i < rows; ++i) {
		reserveArr(rows, columns, arr[i]);
	}
}


/*void addElToArr(int*& arr, int& length, int newEl)
{
	int* newArr = reserveArr(++length);
	copyArray(arr, length - 1, newArr);
	*(newArr + length - 1) = newEl;
	delete[] arr;
	arr = newArr;
}*/

void addElToArr(int*& arr, int& length, int newEl, int indexNewEl)
{
	int* newArr = reserveArr(++length);
	copyArray(arr, indexNewEl, newArr);
	*(newArr + indexNewEl) = newEl;
	copyArray(arr + indexNewEl, length - indexNewEl - 1, newArr + indexNewEl + 1);
	deleteArr(arr);
	arr = newArr;
}

/*void addElToArrToSpecialPlace(int*& arr, int& length, int newEl, int indexNewEl)
{
	addElToArr(arr, length, newEl);
	moveArrElRight(arr, indexNewEl, length - 1);
}*/

void addElToArrToSpecialPlace(char*& arr, int length, char newEl, int indexNewEl)
{
	char* newArr = reserveArrChar(length);
	copyArray(arr, indexNewEl, newArr);
	*(newArr + indexNewEl) = newEl;
	copyArray(arr + indexNewEl, length - indexNewEl - 1, newArr + indexNewEl + 1);
	*(newArr + length - 1) = '\0';
	deleteArr(arr);
	arr = newArr;
}

void addColumnToArr(int**& arr, int rows, int& columns, int* newColumn, int indexNewColumn)
{
	for (int i = 0; i < rows; ++i) {
		int length = columns;
		addElToArr(arr[i], length, newColumn[i], indexNewColumn);
	}
	++columns;
}

void removeElFromArr(int*& arr, int& length, int indexRemEl)
{
	int* newArr = reserveArr(--length);
	copyArray(arr, indexRemEl, newArr);
	copyArray(arr + indexRemEl + 1, length - indexRemEl, newArr + indexRemEl);
	delete[] arr;
	arr = newArr;
}

void removeColumnFromArr(int**& arr, int rows, int& columns, int indexRemColumn)
{
	for (int i = 0; i < rows; ++i) {
		removeElFromArr(arr[i], columns, indexRemColumn);
		++columns;
	}
	--columns;
}

void deleteLastElFromArr(int*& arr, int& length)
{
	int* newArr = reserveArr(--length);
	copyArray(arr, length, newArr);
	delete[] arr;
	arr = newArr;
}

void deleteLastElFromArr(char*& arr, int& length)
{
	char* newArr = reserveArrChar(--length);
	copyArray(arr, length, newArr);
	delete[] arr;
	arr = newArr;
}

void removeArr(int* arr)
{
	delete[] arr;
}

void removeArr(int** arr)
{
	delete[] arr;
}

void removeMatrix(int** arr, int lengthRows)
{
	while (lengthRows > 0) {
		removeArr(arr[--lengthRows]);
	}
	removeArr(arr);
}

void removeArr(char* arr)
{
	delete[] arr;
}

/*void deleteSpecificElFromArr(int*& arr, int& length, int indexOfDelEl)
{
	moveArrElLeft(arr, indexOfDelEl, length - 1);
	deleteLastElFromArr(arr, length);
}*/

int** multiplyMatrix(int** arrA, int** arrB, int aM, int K, int bN)
{
	//int** multiplyMatrix(int** arrA, int aRow, int aCol, int** arrb, int bRow, int bCol)
	int** newArr;
	reserveArr(aM, bN, newArr);
	for (int i = 0; i < aM; ++i) {
		for (int j = 0; j < bN; ++j) {
			newArr[i][j] = 0;
			for (int k = 0; k < K; ++k) {
				newArr[i][j] += arrA[i][k] * arrB[k][j];
			}
		}
	}
	return newArr;
}

int* deletePrimeNumbers(int* arr, int length, int& lengthNewArr)
{
	lengthNewArr = length; // non-prime numbers counter
	int* tmpArr = reserveArr(length);
	copyArray(arr, length, tmpArr);
	for (int i = 0; i < lengthNewArr; ++i) {
		if (isPrimeNumber(*(tmpArr + i)) == true) {
			shiftArrElLeft_old(tmpArr, i--, --lengthNewArr);
		}
	}
	int* newArr = reserveArr(lengthNewArr);
	copyArray(tmpArr, lengthNewArr, newArr);
	deleteArr(tmpArr);
	return newArr;
}

//int** sumMatrix(int** arrA, int aRow, int aCol, int** arrB, int bRow, int bCol)
/*{
	int** arrC;
	int cRow = aRow > bRow ? aRow : bRow;
	int cCol = aCol > bCol ? aCol : bCol;
	reserveArr(cRow, cCol, arrC);
	for (int i = 0; i < cRow; ++i) {
		for (int j = 0; j < cCol; ++j) {
			if ()
			arrC[i][j] = arrA[i][j] + arrB[i][j];
		}
	}
	return arrC;
}*/

void transposeMatrix(int**& arrSource, int& rows, int& columns)
{
	int** arrNew;
	int rowsNew = columns;
	int columnsNew = rows;
	reserveArr(rowsNew, columnsNew, arrNew);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			arrNew[j][i] = arrSource[i][j];
		}
	}
	rows = rowsNew;
	columns = columnsNew;
	removeArr(arrSource);// rewrite delete
	arrSource = arrNew;
}

void shiftArrElRight_old(int* arr, int indexOfFirstElement, int indexOfSecondElement)
{
	for (int i = indexOfSecondElement; i != indexOfFirstElement; --i) {
		swap((arr + i - 1), (arr + i));
	}
}
/*
void moveArrElRight (char* arr, int indexOfFirstElement, int indexOfSecondElement)
{
	for (int i = indexOfSecondElement; i != indexOfFirstElement; --i) {
		swap((arr + i - 1), (arr + i));
	}
}
*/
void shiftArrElLeft_old(int* arr, int indexOfFirstElement, int indexOfSecondElement)
{
	for (int i = indexOfFirstElement; i != indexOfSecondElement; ++i) {
		swap((arr + i), (arr + i + 1));
	}
}

void shiftArrElLeft(int*& arr, int length, int times)
{
	int* newArr = reserveArr(length);
	copyArray(arr + times, length - times, newArr);
	copyArray(arr, times, newArr + length - times);
	delete[] arr;
	arr = newArr;
}

void shiftArrElRight(int*& arr, int length, int times)
{
	int* newArr = reserveArr(length);
	copyArray(arr, length - times, newArr + times);
	copyArray(arr + length - times, times, newArr);
	delete[] arr;
	arr = newArr;
}

void shiftColumnsLeft(int** arr, int rows, int columns, int times)
{
	for (int i = 0; i < rows; ++i) {
		shiftArrElLeft(arr[i], columns, times);
	}
}

void shiftColumnsRight(int** arr, int rows, int columns, int times)
{
	for (int i = 0; i < rows; ++i) {
		shiftArrElRight(arr[i], columns, times);
	}
}

void shiftArrRowsUp(int**& arr, int length, int times)
{
	int** newArr;
	reserveArr(length, newArr);
	copyArray(arr + times, length - times, newArr);
	copyArray(arr, times, newArr + length - times);
	delete[] arr;
	arr = newArr;
}

void shiftArrRowsDown(int**& arr, int length, int times)
{
	int** newArr;
	reserveArr(length, newArr);
	copyArray(arr, length - times, newArr + times);
	copyArray(arr + length - times, times, newArr);
	delete[] arr;
	arr = newArr;
}

void shiftArrValues(int**& arr, int rows, int columns, bool shiftHigher, int verticalSteps, bool shiftRight, int horizontalSteps)
{
	verticalSteps = verticalSteps < 0 ? 0 : verticalSteps;
	horizontalSteps = horizontalSteps < 0 ? 0 : horizontalSteps;

	verticalSteps = verticalSteps >= rows ? (verticalSteps % rows) : verticalSteps;
	horizontalSteps = horizontalSteps >= columns ? (horizontalSteps % columns) : horizontalSteps;

	shiftHigher ? shiftArrRowsUp(arr, rows, verticalSteps) : shiftArrRowsDown(arr, rows, verticalSteps);
	shiftRight ? shiftColumnsRight(arr, rows, columns, horizontalSteps) : shiftColumnsLeft(arr, rows, columns, horizontalSteps);
}

void copyArray(int* arr, int lengthOfShortestArray, int* arrCopy)
{
	for (int i = 0; i < lengthOfShortestArray; ++i) {
		*(arrCopy + i) = *(arr + i);
	}
}

void copyArray(int** arr, int lengthOfShortestArray, int** arrCopy)
{
	for (int i = 0; i < lengthOfShortestArray; ++i) {
		arrCopy[i] = arr[i];
	}
}

void copyArray(char* arrSource, int length, char* arrDest)
{
	for (int i = 0; i < length; ++i) {
		*(arrDest + i) = *(arrSource + i);
	}
}

void separateArrValues(int* arr, int length, int*& arrNeg, int& lenNeg, int*& arrZero, int& lenZero, int*& arrPos, int& lenPos)
{
	for (int i = 0; i < length; ++i) {
		if (*(arr + i) > 0) {
			addElToArr(arrPos, lenPos, *(arr + i));
		}
		else if (*(arr + i) < 0) {
			addElToArr(arrNeg, lenNeg, *(arr + i));
		}
		else {
			addElToArr(arrZero, lenZero, *(arr + i));
		}
	}
}

void separateUniqElFromArr1ExceptArr2ElToNewArr(int* arr, int length, int* excludeArr, int lengthExclude, int*& arrNew, int& lengthNew)
{
	for (int i = 0; i < length; ++i) {
		if (isUniqNumber(*(arr + i), excludeArr, lengthExclude) && isUniqNumber(*(arr + i), arrNew, lengthNew)) {
			addElToArr(arrNew, lengthNew, *(arr + i));
		}
	}
}

template <typename T> long long int mathPow(T a, T b)
{
	if (b < 0) {
		return 1 / mathPow(a, -b);
	}
	else if (b == 0) {
		return 1;
	}
	else if (b == 1) {
		return a;
	}
	else {
		return a * mathPow(a, b - 1);
	}
}

int mathSumValFromRange(int a, int b)
{
	if (a > b) {
		swap(a, b);
	}
	int sum = 0;
	for (int i = a + 1; i < b; ++i) {
		sum += i;
	}
	return sum;
}

int* findPerfectNumbersFromRange(int firstIndex, int lastIndex, int& length)
{
	int* arr = reserveArr(length);
	for (int i = firstIndex; i <= lastIndex; ++i) {
		if (isPerfectNumber(i) == true) {
			addElToArr(arr, length, i);
		}
	}
	return arr;
}

bool isUniqNumber(int number, int* arr, int length)
{
	for (int i = 0; i < length; ++i) {
		if (number == *(arr + i)) {
			return false;
		}
	}
	return true;
}

bool isPerfectNumber(int a)
{
	if (a < 0) {
		a *= -1;
	}
	int sum = 0;
	for (int i = 1; i < a; ++i) {
		if (isDivisor(a, i) == true) {
			sum += i;
		}
	}
	return sum == a;
}

bool isDivisor(int a, int divisor)
{
	return a % divisor == 0;
}

bool isNumberHappy(int number)
{
	if (number <= 1000000 && number >= 100000) {
		int d1 = number % 1000000 / 100000;
		int d2 = number % 100000 / 10000;
		int d3 = number % 10000 / 1000;
		int d4 = number % 1000 / 100;
		int d5 = number % 100 / 10;
		int d6 = number % 10 / 1;
		if ((d1 + d2 + d3) == (d4 + d5 + d6)) {
			return true;
		}
	}
	else {
		cout << "U have entered not 6-digit number. Please, try again.\n";
	}
	return false;
}

bool isPrimeNumber(int number)
{
	if (number < 2) {
		return false;
	}
	for (int i = 2; i < number; ++i) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

int searchIndexOfKeyEl(int* arr, int length, int searchedEl)
{ // linear search
	for (int i = 0; i < length; ++i) {
		if (*(arr + i) == searchedEl) {
			return i;
		}
	}
	return -1;
}

int searchIndexOfKeyElBinar(int* arr, int length, int searchedEl)
{ // binar search
	if (searchedEl >= *(arr) && searchedEl <= *(arr + length - 1)) {
		int lBorderInd = 0;          // array`s left border index
		int rBorderInd = length;     // array`s right border index
		int mid;                     // array`s middle element index
		for (int i = 0; i < length; ++i) {
			mid = lBorderInd + (rBorderInd - lBorderInd) / 2;
			if (searchedEl == *(arr + mid)) {
				return mid;
			}
			else if (searchedEl < *(arr + mid)) {
				rBorderInd = mid;
			}
			else if (searchedEl > * (arr + mid)) {
				lBorderInd = mid;
			}
		}
	}
	return -1;
}

int convertBinarySystemNumberToDecimal(int input)
{
	if (input == 0) {
		return 0;
	}
	int digitCounter = 10;
	int* arr;
	for (int i = 1000000000; i > 0; i /= 10) {
		if (input / i != 0) {
			arr = reserveArr(digitCounter);
			for (int i = 0; i < digitCounter; ++i) {
				*(arr + i) = input % (int)mathPow(10, digitCounter - i) / (int)mathPow(10, digitCounter - i - 1);
			}
			int rslt = 0;
			for (int i = 0; i < digitCounter; ++i) {
				rslt += *(arr + i) * mathPow(2, digitCounter - 1 - i);
			}
			return rslt;
		}
		else {
			digitCounter--;
		}
	}
	return -1;
}

int convertBinarySystemNumberToDecimal(long long int input) {
	if (input == 0) {
		return 0;
	}
	int digitCounter = 19;
	int* arr;
	for (long long int i = 1000000000000000000; i > 0; i /= 10) {
		if (input / i != 0) {
			arr = reserveArr(digitCounter);
			for (int j = 0; j < digitCounter; ++j) {
				int tmp = input % mathPow(10, digitCounter - j) / mathPow(10, digitCounter - j - 1);
				*(arr + j) = tmp;
			}
			int rslt = 0;
			for (int k = 0; k < digitCounter; ++k) {
				rslt += *(arr + k) * mathPow(2, digitCounter - 1 - k);
			}
			return rslt;
		}
		else {
			digitCounter--;
		}
	}
	return -1;
}

void findName(char*** arr, int columns, char* strName, int setMinimumWidth)
{
	const int rowName = 0; // name row
	const int rowPNum = 1; // phone number row
	cout << setw(setMinimumWidth) << "Names" << setw(setMinimumWidth) << "Phone numbers" << endl;
	for (int i = 0; i < columns; ++i) {
		if (strstr(arr[rowName][i], strName)) {
			cout << setw(setMinimumWidth) << arr[rowName][i] << setw(setMinimumWidth) << arr[rowPNum][i] << endl;
		}
	}
	cout << "The end of search results\n\n";
}

void findPhone(char*** arr, int columns, char* strPhoneNumber, int setMinimumWidth)
{
	const int rowName = 0; // name row
	const int rowPNum = 1; // phone number row
	cout << setw(setMinimumWidth) << "Names" << setw(setMinimumWidth) << "Phone numbers" << endl;
	for (int i = 0; i < columns; ++i) {
		if (strstr(arr[rowPNum][i], strPhoneNumber)) {
			cout << setw(setMinimumWidth) << arr[rowPNum][i] << setw(setMinimumWidth) << arr[rowName][i] << endl;
		}
	}
	cout << "The end of search results\n\n";
}

void enterStr(char*** arr, int row, int column, int strLength)
{
	cin.getline(arr[row][column], strLength);
}

void addContact(char*** arr, int column, int strLength)
{
	const int rowName = 0; // name row
	const int rowPNum = 1; // phone number row
	cout << "Enter the name, please: --> ";
	enterStr(arr, rowName, column, strLength);
	cout << "Enter the phone number, please: --> ";
	enterStr(arr, rowPNum, column, strLength);
}

void addContact(char*** arr, int column, int strLength, char* name, char* pNumber)
{
	if (strlen(name) > strLength) {
		char* nameNew;
		reserveArr(strLength, nameNew);
		copyArray(name, strLength, nameNew);
		name = nameNew;
	}
	if (strlen(pNumber) > strLength) {
		char* pNumberNew;
		reserveArr(strLength, pNumberNew);
		copyArray(pNumber, strLength, pNumberNew);
		pNumber = pNumberNew;
	}
	const int rowName = 0; // name row
	const int rowPNum = 1; // phone number row
	arr[rowName][column] = name;
	arr[rowPNum][column] = pNumber;

}