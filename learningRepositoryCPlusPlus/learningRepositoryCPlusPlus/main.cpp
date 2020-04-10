#include <iostream>
#include "funcs.h"
using namespace std;

/*
int removeLastStr(const char* filepath)
{
	int strCounter = countStringsInFile((char*)filepath);
	FILE* file;
	if (fopen_s(&file, filepath, "r+")) {
		cout << "Unable to open file";
		return -1;
	}
	const int maxStringSize = 1024;
	char** arr;
	reserveArr(strCounter, maxStringSize, arr);
	int i = 0;
	int strWithoutSpacesIndex;
	while (fgets(arr[i], maxStringSize, file)) {
		if (!strchr(arr[i], ' ')) {
			strWithoutSpacesIndex = i;
		}
		++i;
	}

	//fseek(file, 0, 0);

	for (int j = 0; j < (strCounter - 1); ++j) {
		fputs(arr[j], file);
	}

	printArr(arr, strCounter);
	removeArr(arr);
	if (fclose(file)) {
		cout << "Unable to close file";
		return -2;
	}
	return 0;
}

void showMismatchedStrings(const char* filepath1, const char* filepath2) {
	char** arr1, ** arr2;
	int rows1, rows2;
	copyStringsFromFileToArr(filepath1, arr1, rows1);
	copyStringsFromFileToArr(filepath2, arr2, rows2);
	cout << "________different lines:\n";
	for (int i = 0; i < rows1 && rows2; ++i) {
		if (strcmp(arr1[i], arr2[i])) {
			cout << "____mismatched lines number " << i + 1 << ":" << endl << arr1[i] << arr2[i];
		}
	}
	removeArr(arr1, rows1);
	removeArr(arr2, rows2);
}
*/

bool isUniqStr(char** arr, int rows, char* searchedValue) { // FIXME
	for (int i = 0; i < rows; ++i) {
		if (searchedValue == arr[i]) { // FIXME
			return false;
		}
	}
	return true;
}

void addValue(char**& arr, int& rows, char* newStr) 
{
	if (rows == 0) {
		reserveArr(rows, arr);
	}
	char** arrNew;
	reserveArr(rows + 1, arrNew);
	copyArray(arr, rows, arrNew);
	arrNew[rows] = newStr;
	++rows;
	removeArr(arr);
	arr = arrNew;
}

void addValue(char**& arr, int& rows, const char* newStr)
{
	if (rows == 0) {
		reserveArr(rows, arr);
	}
	char** arrNew;
	reserveArr(rows + 1, arrNew);
	copyArray(arr, rows, arrNew);
	char* str;
	int len = strlen(newStr) + 1;
	reserveArr(len, str);
	copyArray((char*)newStr, len, str);
	arrNew[rows] = str;
	++rows;
	removeArr(arr);
	arr = arrNew;
}

void copyUniqArrValues(char** arr, int rows, char**& destArr, int& rowsDestArr) // FIXME. Add isNullCheck
{
	if (rowsDestArr == 0) { // FIXME. Add isNullCheck
		reserveArr(rowsDestArr, destArr);
	}
	for (int i = 0; i < rows; ++i) {
		if (isUniqStr(destArr, rowsDestArr, arr[i])) {
			addValue(destArr, rowsDestArr, arr[i]);
		}
	}
}

void copyUniqArrValues(char** arr, int rows, char** arr2, int rows2, char**& destArr, int& rowsDestArr)
{
	copyUniqArrValues(arr, rows, destArr, rowsDestArr);
	copyUniqArrValues(arr2, rows2, destArr, rowsDestArr);
}

void printString(char** arr, int row) // FIXME
{
	/*if (row < this.rows) { // FIXME
		cout << arr[row];
		return;
	}*/
	cout << "Error: row is out of arr length";
}

void printChar(char** arr, int row, int column)
{
	if (column < strlen(arr[row])) {
		cout << arr[row][column];
	}
	else {
		cout << "Column is out of string length";
	}
}

void concatinateStr(char* source, char*& dest) // FIXME memory leak
{
	char* str;
	int length = strlen(source) + strlen(dest);
	reserveArr(length, str);
	strcpy_s(str, length, dest);
	strcpy_s(str + strlen(str), length, source);
	// removeArr(dest);
	dest = str;
}

void concatinateStrInArr(char** source, int rows, char**& destArr, int& rowsDestArr)
{
	if (rowsDestArr == 0) {
		char** arrNew;
		int rowsArrNew = 0;
		reserveArr(rowsArrNew, arrNew);
		for (int i = 0; i < rows; ++i) {
			addValue(arrNew, rowsArrNew, " \0");
		}
		removeArr(destArr, rowsDestArr);
		destArr = arrNew;
		rowsDestArr = rowsArrNew;
	}
	for (int i = 0; i < rows && i < rowsDestArr; ++i) {
		concatinateStr(source[i], destArr[i]);
	}
}

void concatinateStrInArr(char** source, int rows, char** source2, int rows2, char**& destArr, int& rowsDestArr)
{
	concatinateStrInArr(source, rows, destArr, rowsDestArr);
	concatinateStrInArr(source2, rows2, destArr, rowsDestArr);
}

int main() {
	//srand(time(NULL));
	//setlocale(LC_ALL, "Russian");
	

// test void addValue(char**& arr, int& rows, char* newStr)
	/*char** arr;
	int rows = 2;
	int len = 20;
	reserveArr(rows, len, arr);

	arr[0] = (char*)"Lola";
	arr[1] = (char*)"Ivan";
	printArr(arr, 2);

	char** arrNew;
	int rows2 = 3;
	int len2 = 0;
	
	reserveArr(rows2, arrNew);
	arrNew[2] = (char*)"Kate";
	addValue(arrNew, rows2, (char*)"Igor");
	copyArray(arr, rows, arrNew);
	printArr(arrNew, rows2);*/

// test void copyUniqArrValues(char** arr, int rows, char** destArr, int& rowsDestArr)
	char** nameList;
	int rowsNameList = 3;
	reserveArr(rowsNameList, nameList);
	nameList[0] = (char*)"Lola";
	nameList[1] = (char*)"Tolik";
	nameList[2] = (char*)"Ebonit";
	printArr(nameList, rowsNameList);
	cout << endl;

	char** nameList3;
	int rowsNameList3 = 3;
	reserveArr(rowsNameList3, nameList3);
	nameList3[0] = (char*)"Igor";
	nameList3[1] = (char*)"Tolik";
	nameList3[2] = (char*)"Juju";
	printArr(nameList3, rowsNameList3);
	cout << endl;

	char** nameList2;
	int rowsNameList2 = 0;
	copyUniqArrValues(nameList, rowsNameList, nameList3, rowsNameList3, nameList2, rowsNameList2);
	printArr(nameList2, rowsNameList2);

// test void concatinateStrInArr(char** source, int rows, char**& destArr, int& rowsDestArr)
	/*char** nameList;
	int rowsNameList = 0;
	addValue(nameList, rowsNameList, "Lola");
	addValue(nameList, rowsNameList, "Tolik");
	addValue(nameList, rowsNameList, "Ebonit");
	printArr(nameList, rowsNameList);
	cout << endl;

	char** nameList3;
	int rowsNameList3 = 0;
	addValue(nameList3, rowsNameList3, "Igorevsky");
	addValue(nameList3, rowsNameList3, "Jujuvsky");
	addValue(nameList3, rowsNameList3, "Tolikancky");
	printArr(nameList3, rowsNameList3);
	cout << endl;

	char** nameListResult;
	int rowsNameListResult = 0;
	reserveArr(rowsNameListResult, nameListResult);
	concatinateStrInArr(nameList, rowsNameList, nameList3, rowsNameList3, nameListResult, rowsNameListResult);
	printArr(nameListResult, rowsNameListResult);*/

// test void addValue(char**& arr, int& rows, const char* newStr)
	/*char** arr;
	int rows = 0;
	reserveArr(rows, arr);
	addValue(arr, rows, "Igor");
	printArr(arr, rows);*/



}