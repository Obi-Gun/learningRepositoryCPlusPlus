#include <iostream>
#include "funcs.h"
using namespace std;

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


int main() {
	//srand(time(NULL));
	//setlocale(LC_ALL, "Russian");
	
// Homework 21.1.1 Course: "Basics of programming in C++".
	//showMismatchedStrings("C:\\Users\\Alexandr\\Desktop\\criptos_data.txt", "C:\\Users\\Alexandr\\Desktop\\criptos_data - Copy.txt");

// Homework 21.1.2 Course: "Basics of programming in C++".
	writeInfoAboutFileToNewFile("C:\\Users\\Alexandr\\Desktop\\2.txt", "C:\\Users\\Alexandr\\Desktop\\3.txt");

// Homework 21.1.3 Course: "Basics of programming in C++".


// Homework 21.2.1 Course: "Basics of programming in C++".
	//cout << countStringsInFile((char*)"C:\\Users\\Alexandr\\Desktop\\Classwork21.1.2.txt");
	//removeLastStr("C:\\Users\\Alexandr\\Desktop\\Classwork21.1.2.txt");
	/*int arr2[10];
	int arr3[15];
	int* arr[2];
	arr[0] = arr2;
	arr[1] = arr3;*/

// Homework 21.2.2 Course: "Basics of programming in C++".
// Homework 21.2.3 Course: "Basics of programming in C++".
// Homework 21.2.4 Course: "Basics of programming in C++".

// Kryptos task
	// Test copyStringsFromFileToArr
	/*char** arr;
	int len;
	copyStringsFromFileToArr("C:\\Users\\Alexandr\\Desktop\\criptos_data.txt", arr, len);
	printArr(arr, len, 5, 0, true);
	char* destArr;
	int length;
	copyStringsFromFileToArr("C:\\Users\\Alexandr\\Desktop\\criptos_data.txt", destArr, length);
	cout << endl << endl;
	copyStringsFromFileToArr("C:\\Users\\Alexandr\\Desktop\\criptos_data.txt", destArr, length, false);*/




}