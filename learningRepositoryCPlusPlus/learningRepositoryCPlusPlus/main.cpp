#include <iostream>
#include "funcs.h"

using namespace std;

int main() {
	srand(time(NULL));

	/*FILE* file;
	if (fopen_s(&file, filepath, "r")) {
		cout << "Unable to open file";
		return -1;
	}

    cout << _access_s("C:\\Users\\Alexandr\\Desktop\\123.txt", 06); // access to file

	int handle = _fileno(file);
	cout << _filelength(handle) << endl; // length

	const int maxStringSize = 1024;
	char str[maxStringSize];
	while (fgets(str, maxStringSize, file)) { //to print the file
		cout << str << endl;
	}

	fseek(file, 0, 0); // change pointer to start position
	while (fgets(str, maxStringSize, file)) { 
		cout << str << endl;
	}

	fputs(str, file); // to write to file

	fread_s(str, maxStringSize, sizeof(char), maxStringSize, file);
	cout << str;*/

// Classwork 21.2.5 Course: "Basics of programming in C++".
	/*char* path = (char*)"C:\\Users\\Alexandr\\Desktop\\123.txt";
	cout << " strCounter = " << countStringsInFile(path);*/

// Classwork 21.2.4 Course: "Basics of programming in C++".
	/*char* path = (char*)"C:\\Users\\Alexandr\\Desktop\\123.txt";
	cout << " charsCounter = " << countCharsInFile(path);*/

// Classwork 21.2.3 Course: "Basics of programming in C++".
	/*const int length = 5;
	const char* arrChar[length] = {"123", "456", "789", "123", "456" };
	writeStringsToFile("C:\\Users\\Alexandr\\Desktop\\1234.txt", arrChar, length);*/

// Classwork 21.2.2 Course: "Basics of programming in C++".
	//changeCharInFile("C:\\Users\\Alexandr\\Desktop\\1111.txt", "C:\\Users\\Alexandr\\Desktop\\0000.txt", '1', '0');
	
// Classwork 21.2.1 Course: "Basics of programming in C++".
	/*cout << "Enter a char => ";
	char inp;
	cin >> inp;
	cout << "There are " << countWords("C:\\Users\\Alexandr\\Desktop\\1111.txt", inp) << " words start with " << inp;*/
	
}