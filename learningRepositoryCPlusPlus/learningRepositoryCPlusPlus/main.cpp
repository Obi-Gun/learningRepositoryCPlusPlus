#include <iostream>
#include "funcs.h"
using namespace std;

int maxStringLength(const char* filepath)
{
	char** text;
	int rows = 0;
	readStringsFromFileToArr(filepath, text, rows);
	int maxLen = strlen(text[0]);
	for (int i = 1; i < rows; ++i) {
		if (strlen(text[i]) > maxLen) {
			maxLen = strlen(text[i]);
		}
	}
	removeArr(text, rows);
	return maxLen;
}

int countSpecialWordInFile(const char* filepath, const char* word) // add ignore upper/lowercase
{
	char** text;
	int rows = 0;
	readStringsFromFileToArr(filepath, text, rows, true);
	int wordCounter = 0;
	for (int i = 0; i < rows; ++i) {
		char* p = strstr(text[i], word);
		if (p) {
			do {
				++wordCounter;
				p += strlen(word);
			} while (p = strstr(p, word));
		}
	}
	removeArr(text, rows);
	return wordCounter;
}

void changeSpecialWordsInArr(char* wordToBeRemoved, char* wordNew, char*& str, int lengthOfNewString = 1024)
{
	char* descriptorStr = str;
	char* pFrst = strstr(descriptorStr, wordToBeRemoved);
	if (pFrst) {
		int lengthWordNew = strlen(wordNew);
		int lengthwordToBeRemoved = strlen(wordToBeRemoved);
		int symbolsLeft = lengthOfNewString - 1;
		char* tmp;
		reserveArr(lengthOfNewString, tmp);
		char* descriptorTmp = tmp;
		do {
			int charCounter = pFrst - descriptorStr;
			if (charCounter > symbolsLeft) {
				charCounter = symbolsLeft;
			}
			symbolsLeft -= charCounter;
			copyArray(descriptorStr, charCounter, descriptorTmp);
			descriptorTmp += charCounter;
			if (lengthWordNew > symbolsLeft) {
				lengthWordNew = symbolsLeft;
			}
			symbolsLeft -= lengthWordNew;
			copyArray(wordNew, lengthWordNew, descriptorTmp);
			descriptorTmp += lengthWordNew;
			descriptorStr = pFrst + lengthwordToBeRemoved;
			pFrst = strstr(descriptorStr, wordToBeRemoved);
		} while (pFrst && symbolsLeft > 0);
		int counterlastSymbolsFromStr = strlen(str) - (descriptorStr - str);
		if (counterlastSymbolsFromStr > symbolsLeft) {
			counterlastSymbolsFromStr = symbolsLeft;
		}
		copyArray(descriptorStr, counterlastSymbolsFromStr, descriptorTmp);
		descriptorTmp += counterlastSymbolsFromStr;
		tmp[descriptorTmp - tmp] = '\0';
		removeArr(str);
		str = tmp;
	}
}

void changeSpecialWordsInArr(char* wordToBeRemoved, char* wordNew, char** text, int rows, int lengthOfNewString = 1024)
{
	for (int i = 0; i < rows; ++i) {
		changeSpecialWordsInArr(wordToBeRemoved, wordNew, text[i], lengthOfNewString);
	}
}

void changeSpecialWordsInFile()
{

}

int main() {
	//srand(time(NULL));
	//setlocale(LC_ALL, "Russian");
	
// Homework 21.1.1 Course: "Basics of programming in C++".
	//showMismatchedStringsFromFile("C:\\Users\\Alexandr\\Desktop\\criptos_data.txt", "C:\\Users\\Alexandr\\Desktop\\criptos_data - Copy.txt");

// Homework 21.1.2 Course: "Basics of programming in C++".
	//writeInfoAboutFileToNewFile("C:\\Users\\Alexandr\\Desktop\\2.txt", "C:\\Users\\Alexandr\\Desktop\\3.txt");

// Homework 21.1.3 Course: "Basics of programming in C++".
	/*int encryptionKey = -26;
	encryptTextFromFileAnd_WriteToNewFile("C:\\Users\\Alexandr\\Desktop\\criptos_data.txt", "C:\\Users\\Alexandr\\Desktop\\criptos_data_encrypted.txt", encryptionKey);*/

// Homework 21.2.1 Course: "Basics of programming in C++".
	//removeLastStrInFile("C:\\Users\\Alexandr\\Desktop\\criptos_data - Copy.txt");

// Homework 21.2.2 Course: "Basics of programming in C++".
	//cout << maxStringLength("C:\\Users\\Alexandr\\Desktop\\criptos_data.txt");

// Homework 21.2.3 Course: "Basics of programming in C++".
	//cout << countSpecialWordInFile("C:\\Users\\Alexandr\\Desktop\\test.txt", "test");

// Homework 21.2.4 Course: "Basics of programming in C++".
	char** text;
	int rows = 0;
	readStringsFromFileToArr("C:\\Users\\Alexandr\\Desktop\\test.txt", text, rows);
	printArr(text, rows);
	changeSpecialWordsInArr((char*)"_", (char*)"go", text, rows, 50);
	printArr(text, rows);
	
}