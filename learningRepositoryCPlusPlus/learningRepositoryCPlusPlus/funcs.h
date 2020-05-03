#ifndef funcsClass
#define funcsClass

#include <iostream>
#include <cmath>
#include <time.h>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <io.h>
#include <direct.h>

#include "Fraction.h"
#include "Contact.h"
#include "PhoneBook.h"

//   |            My own small libraries               |
//   |    I`ve tryed to follow this codeStyle          |
//   |      https://habr.com/ru/post/172091/           |

	//srand(time(NULL));
	//setlocale(LC_ALL, "Russian");
using namespace std; //bad practice to use it out of funcs
enum carColor { red, blue };
enum carTransmissionType { mechanic, automatic };
enum carField { carLength = 1, clearance = 2, engineVolume = 3, enginePower = 4, wheelsDiameter = 5, color = 6, transmissionType = 7 };

//
//
//
//
//
//   ===================================================
//   |            library "obi.arrays.h"               |
//   ===================================================
template <typename T> void fillRandomValuesToTheArray(T arr[], int LEN)
{
	for (int i = 0; i < LEN; ++i) {
		arr[i] = rand();
	}
}
template <typename T> void fillRandomValuesToTheArray(T arr[], int LEN, int minValue, int maxValue)
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
void fillRandomValuesToTheArray(double** arr, int lenRow, int lenCol);
void fillRandomValuesToTheArray(char** arr, int lenRow, int lenCol, char minValue, char maxValue);
int fillRandomValue(int minValue, int maxValue);
int fillRandom4DigitValue();

void shakeValuesInArr(int* arr, int length);

template <typename T> void printArr(T arr[], int LEN)
{
	cout << "\nArray values:" << endl;
	for (int i = 0; i < LEN; ++i) {
		printf("arr[%i] = ", i);
		cout << *(arr + i) << endl;
	}
}
void printArr(int** arr, int rows, int columns, int setMinimumWidth = 0, bool showIndexes = false);
void printArr(double** arr, int rows, int columns, int setMinimumWidth = 0, bool showIndexes = false);
void printArr(char** arr, int rows, int columns, int setMinimumWidth = 0, bool showIndexes = false);
void printArr(char** arr, int rows, bool showOnNewLine = true);
void printArr(char*** arr, int rows, int columns, int strLength, int setMinimumWidth = 2, bool showIndexes = false);

void reserveArr(int length, int*& arr);
void reserveArr(int length, int**& arr);
void reserveArr(int rows, int columns, int**& arr);
void reserveArr(int length, double*& arr);
void reserveArr(int rows, int columns, double**& arr);
void reserveArr(int length, char*& arr);
void reserveArr(int length, char**& arr);
void reserveArr(int length, char***& arr);
void reserveArr(int rows, int columns, char**& arr);
void reserveArr(int rows, int columns, int strLen, char***& arr);

void addElToArr(int*& arr, int& length, int newEl, int indexNewEl = 0);
void addElToArrToSpecialPlace(char*& arr, int length, char newEl, int indexNewEl);
void addColumnToArr(int**& arr, int rows, int& columns, int* newColumn, int indexNewColumn = 0);
void removeElFromArr(int*& arr, int& length, int indexRemEl = 0);
void removeColumnFromArr(int**& arr, int rows, int& columns, int indexRemColumn = 0);
void deleteLastElFromArr(int*& arr, int& length);

void removeArr(int* arr);
void removeArr(int** arr);
void removeArr(int** arr, int lengthRows);
void removeArr(char* arr);
void removeArr(char** arr);
void removeArr(char** arr, int lengthRows);

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
void copyArray(char* arrSource, int length, char* arrDest); // add arrLen parameter + check isOutOfArray
//void copyArray2(char* arrSource, int length, char*& arrDest); //
void copyArray(char** arrSource, int rows, char** arrDest);
void copyArray(int* arrSource, int length, char* arrDest);

void maxValArrInd(int* arr, int length, int& maxVal, int& indexMaxVal);
void maxValArrInd(double* arr, int length, double& maxVal, int& indexMaxVal);
void maxValArrInd(char* arr, int length, char& maxVal, int& indexMaxVal);
void minValArrInd(int* arr, int length, int& minVal, int& indexMinVal);
void minValArrInd(double* arr, int length, double& minVal, int& indexMinVal);
void minValArrInd(char* arr, int length, char& minVal, int& indexMinVal);

//void deleteSpecificElFromArr(int*& arr, int& length, int indexOfDelEl);
//int** multiplyMatrix(int** arrA, int** arrB, int aM, int K, int bN);
//int** sumMatrix(int** arrA, int aRow, int aCol, int** arrB, int bRow, int bCol);
void transposeMatrix(int**& arrSource, int& rows, int& columns);

int maxValueDiagonal(int** squareMatrix, int length);
char maxValueDiagonal(char** squareMatrix, int length);
double maxValueDiagonal(double** squareMatrix, int length);
int minValueDiagonal(int** squareMatrix, int length);
char minValueDiagonal(char** squareMatrix, int length);
double minValueDiagonal(double** squareMatrix, int length);

int sumArrValues(int* curEl, int* endEl);
double calcAverage(int* arr, int length);

int countPairsWithEqualValuesInArr(int* arr1, int length, int* arr2);
int countPairsWithEqualValuesInArr(char* arr1, char* arr2);

void createArr(int**& arr, int& rows, int& columns, int minVal, int maxVal, const char* arrShowingName);
//
//
//
//
//
//   ===================================================
//   |            library "obi.sort.h"                 |
//   ===================================================
void insertionSort(int arr[], int LEN);
void insertionSort(int** arr, int rows, int columns);
void insertionSort(double arr[], int LEN);
void insertionSort(double** arr, int rows, int columns);
void insertionSort(char arr[], int LEN);
void insertionSort(char** arr, int rows, int columns);

void bobbleSort(int arr[], int LEN);

template <typename T> void quickSort(T* arr, int lastElementIndex)
{
	int i = 0, j = lastElementIndex;
	T p = arr[lastElementIndex / 2];
	do {
		while (arr[i] < p) {
			++i;
		}
		while (arr[j] > p) {
			--j;
		}
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		quickSort(arr, j);
	}
	if (i < lastElementIndex) {
		quickSort(arr + i, lastElementIndex - i);
	}
}
template <typename T> void quickSortDescendingOrder(T* arr, int lastElementIndex)
{
	int i = 0, j = lastElementIndex;
	T p = arr[lastElementIndex / 2];
	do {
		while (arr[i] > p) ++i;
		while (arr[j] < p) --j;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)				  quickSortDescendingOrder(arr, j);
	if (i < lastElementIndex) quickSortDescendingOrder(arr + i, lastElementIndex - i);
}

void sortArr(int* arr, int length, bool isInAscendingOrder = 1);
void bobbleSortStr(char** arr, int rows, int iSL);
void sortStr(char** arr, int rows, int iSL);
//
//
//
//
//
//   ===================================================
//   |            library "obi.funcs.h"                |
//   ===================================================
int maxValue(int* pa, int* pd);
int minValue(int* pa, int* pd);
int minValue(int a, int b);
int maxCommonDivisor(int A, int B);
int mathSumValFromRange(int a, int b);
int* deletePrimeNumbers(int* arr, int length, int& lengthNewArr);
int countDigits(int inp);
void separateDigitsFromNumberToArrValues(int inp, int*& output, int& length);

void calcNumbers(int* arr, int length, int& negCounter, int& zerosCounter, int& posCounter);
void separateArrValues(int* arr, int length, int*& arrNeg, int& lenNeg, int*& arrZero, int& lenZero, int*& arrPos, int& lenPos);
void separateArrValuesNegative(int* arr, int length, int*& arrNeg, int& lenNeg);
void separateUniqElFromArr1ExceptArr2ElToNewArr(int* arr, int length, int* arr2, int length2, int*& arrNew, int& lengthNew);
void separateUniqElFromArr1ExceptArr2ElToNewArr(int** source, int sRows, int sColumns, int** excludeArr, int eRows, int eColumns, int*& arrNew, int& lengthNew);
void separateUniqElFromArr1ExceptArr2ElToNewArr(int** source, int sRows, int sColumns, int* excludeArr, int elength, int*& arrNew, int& lengthNew);
void separateCommonElFromArr1AndArr2ToNewArr(int* arr, int length, int* arr2, int length2, int*& arrNew, int& lengthNew);
void separateCommonElFromArr1AndArr2ToNewArr(int** source, int sRows, int sColumns, int** arr2, int arr2Rows, int arr2Columns, int*& arrNew, int& lengthNew);

template <typename T> void swap(T* pFirst, T* pSecond)
{
	T tmp = *pFirst;
	*pFirst = *pSecond;
	*pSecond = tmp;
}
void swapArr(char*& pFirst, char*& pSecond);

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

bool isUniqNumber(int number, int* arr, int length);
bool isUniqNumber(int number, int** arr, int rows, int columns);
bool isPerfectNumber(int a);
bool isDivisor(int a, int divisor);
bool isNumberHappy(int number);
bool isPrimeNumber(int number);
bool isEqualsChar(char el, char el2);

int searchIndexOfKeyEl(int* arr, int length, int searchedEl);
int searchIndexOfKeyElBinar(int* arr, int length, int searchedEl);
int* findPerfectNumbersFromRange(int first, int last, int& length);

int convertBinarySystemNumberToDecimal(int input);
int convertBinarySystemNumberToDecimal(long long int input);

bool isLeapYear(int year);
int calcDays(int day1, int month1, int year1, int day2, int month2, int year2);

void game_BullsAndCows();
void processExamplePreprocessorsDefined();
//
//
//
//
//
//   ===================================================
//   |            library "obi.strings.h"              |
//   ===================================================
int countDigits(char* source);
int countLetters(char* source);
int countWords(char* sourceArr);
int countVowelLettersInStr(char* str);
int countConsonantLettersInStr(char* str);
int countSymbolsInArr1isFromArr2(char* source, const char* symbolsToFind);

int minStrLength(char** arr, int rows);

void findName(char*** arr, int columns, char* strName, int setMinimumWidth = 16);
void findPhone(char*** arr, int columns, char* strPhoneNumber, int setMinimumWidth = 16);
void enterStr(char*** arr, int row, int column, int strLength);
void addContact(char*** arr, int column, int strLength);
void addContact(char*** arr, int column, int strLength, char* name, char* pNumber);

char* convertIntToCharArr(int number);

// funcs for list class in future
bool isUniqStr(char** arr, int rows, char* searchedValue);// FIXME
void addStrToArr(char**& arr, int& rows, char* newStr);
void addStrToArr(char**& arr, int& rows, const char* newStr);
void copyUniqArrValues(char** arr, int rows, char**& destArr, int& rowsDestArr); // FIXME. Add isNullCheck
void copyUniqArrValues(char** arr, int rows, char** arr2, int rows2, char**& destArr, int& rowsDestArr);
void printString(char** arr, int row); // FIXME
void printChar(char** arr, int row, int column);
void concatinateStr(char* source, char*& dest); // FIXME memory leak
void concatinateStrInArr(char** source, int rows, char**& destArr, int& rowsDestArr);
void concatinateStrInArr(char** source, int rows, char** source2, int rows2, char**& destArr, int& rowsDestArr);

void encryptLettersInString(char* str, int encryptionKey);
void encryptText(char** arr, int rows, int encryptionKey);

void changeSpecialWordsInArr(char* wordToBeRemoved, char* wordNew, char*& str, int lengthOfNewString = 1024);
void changeSpecialWordsInArr(char* wordToBeRemoved, char* wordNew, char** text, int rows, int lengthOfNewString = 1024);
void changeSpecialWordsInFile(const char* filepath, char* wordToBeRemoved, char* wordNew);
//
//
//
//
//
//   ===================================================
//   |            library "obi.structures.h"           |
//   ===================================================
struct rectangle
{
	int x;
	int y;
	int length;
	int height;
	/*void Print()
	{
		cout << x << " " << y << endl;
	}*/
};
void moveFig(rectangle& fig, int moveX, int moveY);
void scaleHeight(rectangle& fig, double multiplier);
void scaleLength(rectangle& fig, double multiplier);
void drawFig(rectangle fig);
void printFig(rectangle fig);

struct point
{
	double x;
	double y;
};
double distance(point A, point B);

struct fraction
{
	int numerator;
	int denominator;
};
fraction sum(fraction A, fraction B);
fraction substr(fraction A, fraction B);
fraction multipy(fraction A, fraction B);
fraction divide(fraction A, fraction B);
void reduceFraction(fraction& A);
void printFraction(fraction A);

struct complexNumber {
	double a;
	double b;
	//char sigh = '+';
	const char i = 'i';
	void print()
	{
		cout << a << " + " << b << i << endl;
	}
};
complexNumber addComplexNumber(complexNumber num1, complexNumber num2);
complexNumber subComplexNumber(complexNumber num1, complexNumber num2);
complexNumber multComplexNumber(complexNumber num1, complexNumber num2);
complexNumber divComplexNumber(complexNumber num1, complexNumber num2);

struct car {
	char name[32];
	double carLength;
	double clearance;
	double engineVolume;
	double enginePower;
	double wheelsDiameter;
	carColor color;
	carTransmissionType transmissionType;
	void setLength(double inp)
	{
		if (inp > 0) {
			carLength = inp;
		}
		else {
			cout << "Please try again: =>";
		}
	}
	void print()
	{
		cout << endl << endl;
		cout << " name = " << name;
		cout << " length = " << carLength;
		cout << "\n clearance = " << clearance;
		cout << "\n engineVolume = " << engineVolume;
		cout << "\n enginePover = " << enginePower;
		cout << "\n wheelsDiamter = " << wheelsDiameter;
		cout << "\n color = " << color;
		cout << "\n transmissionType = " << transmissionType;
	}
};
bool trySearchIndexOfKeyEl(car* arr, int len, carField field, double searchedEl, car& resultCar, int& indexOfSearchedElement);
bool trySearchIndexOfKeyEl(car* arr, int len, carColor searchedEl, car& resultCar, int& indexOfSearchedElement);
bool trySearchIndexOfKeyEl(car* arr, int len, carTransmissionType searchedEl, car& resultCar, int& indexOfSearchedElement);
//
//
//
//
//
//   ===================================================
//   |            library "obi.files.h"                |
//   ===================================================
int countCharsInFile(char* filepth);
int countWordsInFile(const char* filepath, char searchedChar);
int countWordsInFile(const char* filepath);
int countStringsInFile(char* filepth);
int countVowelLettersInFile(const char* filepth);
int countConsonantLettersInFile(const char* filepth);
int countDigitsInFile(const char* filepth);
int countSpecialWordInFile(const char* filepath, const char* word); // add ignore upper/lowercase

int maxStringLengthInFile(const char* filepath);

bool isWordInArr(char** arr, int rows, char* word);

int addStringToFile(const char* filepath);
int addStringToFile(const char* filepath, char* strNew);
void writeStringsToFile(const char* filepath, char** strings, int rows, bool everyElOnNewStr = true);
int writeInfoAboutFileToNewFile(const char* sourcefilepath, const char* destfilepath);

void replaceCharInFile(const char* sourcefilepath, const char* destfilepath, char sCh, char dCh);
int replaceWordsToFile(const char* filepath, const char* destFilepath, int wordLength);
int replaceTextToFileExceptSpecialWords(const char* filepath, const char* destFilepath, const char* specialWordsFilePath); // here is some bag here. Rewrite it later

void readWordsFromFileToArr(const char* specialWordsFilePath, char**& destArr, int& length);
void readStringsFromFileToArr(const char* sourceFilepath, char**& destArr, int& rows, bool makeAllLowerCase = false);
void readStringsFromFileToArr(const char* sourceFilepath, char*& destArr, int& length, bool copyWithLineBreakCharacters = true);

void copyStringsFromFileToFile(const char* sourceFilepath, const char* destFilepath);
void copyStringsFromFileToFileReverse(const char* sourceFilepath, const char* destFilepath);

void showMismatchedStringsFromFile(const char* filepath1, const char* filepath2);

void encryptTextFromFileAnd_WriteToNewFile(const char* sourceFilepath, const char* destFilepath, int encryptionKey);

void removeLastStrInFile(const char* filepath);
//
//
//
//
//
//   ===================================================
//   |            library "obi.classes.h"                |
//   ===================================================
class Counter {
	int min;
	int max;
	int currentValue;

public:
	Counter() {
		min = 0;
		max = 100;
		currentValue = min;
	}
	Counter(int minValue, int maxValue) {
		min = minValue;
		max = maxValue;
		currentValue = min;
	}
	Counter(int minValue, int maxValue, int currentValue) {
		min = minValue;
		max = maxValue;
		currentValue = currentValue;
	}

	void increment() {
		if (currentValue < max) {
			currentValue++;
		}
		else {
			currentValue = min;
		}
	}

	int getCurrentValue() {
		return currentValue;
	}

	void setCurrentValue(int value) {
		if (value < min) {
			currentValue = min;
		}
		else if (value > max) {
			currentValue = max;
		}
		else {
			currentValue = value;
		}
	}

	void print() {
		cout << currentValue << endl;
	}

	~Counter() {
		cout << "conter has been destructed\n";
	}
};

class Student {
	int height;
	char name[16];

public:
	Student() {
	}
	Student(const char* name) {
		name = name;
	}

	~Student() {
		cout << "Student has been destructed\n";
	}
};

class Group {
	Student* group;

public:
	Group() {
		group = new Student[0];
	}
	Group(int studentsInGroup) {
		group = new Student[studentsInGroup];
	}

	~Group() {
		cout << "Group has been destructed\n";
		delete[] group;
	}
};

enum gender { male, female };

class Person {
	char* _name;
	int _age;
	gender _gender;
	char* _phoneNumber;

public:
	Person(char* name, int age, gender _gender, char* phoneNumber) {
		reserveArr(strlen(name) + 1, this->_name);
		copyArray(name, strlen(name) + 1, this->_name);
		this->_age = age;
		this->_gender = _gender;
		reserveArr(strlen(phoneNumber) + 1, this->_phoneNumber);
		copyArray(phoneNumber, strlen(phoneNumber) + 1, this->_phoneNumber);
	}

	Person(Person& person) {
		reserveArr(strlen(person._name) + 1, this->_name);
		copyArray(person._name, strlen(person._name) + 1, this->_name);
		this->_age = person._age;
		this->_gender = person._gender;
		reserveArr(strlen(person._phoneNumber) + 1, this->_phoneNumber);
		copyArray(person._phoneNumber, strlen(person._phoneNumber) + 1, this->_phoneNumber);
	}

	~Person() {
		delete[] this->_name;
		delete[] this->_phoneNumber;
		cout << " <> Person has been distructed <>\n";
	}

	void print() {
		cout << "\nInfo about person:\n";
		cout << "name of person: " << this->_name << endl;
		cout << "age of person: " << this->_age << endl;
		if (this->_gender) {
			cout << "gender of person: female" << endl;
		}
		else {
			cout << "gender of person: male" << endl;
		}
		cout << "phoneNumber of person: " << this->_phoneNumber << endl;
	}

	void setName(char* newName) {
		delete[] this->_name;
		reserveArr(strlen(newName) + 1, this->_name);
		copyArray(newName, strlen(newName) + 1, this->_name);
	}

	void setAge(int newAge) {
		this->_age = newAge;
	}

	void setGender(gender newGender) {
		this->_gender = newGender;
	}

	void setPhoneNumber(char* newPhoneNumber) {
		delete[] this->_phoneNumber;
		reserveArr(strlen(newPhoneNumber) + 1, this->_phoneNumber);
		copyArray(newPhoneNumber, strlen(newPhoneNumber) + 1, this->_phoneNumber);
	}
};

#endif //funcs// !funcs