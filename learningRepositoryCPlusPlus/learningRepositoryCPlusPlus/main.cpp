#include <iostream>
#include "funcs.h"
using namespace std;

int maxStringLengthInFile(const char* filepath)
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
	char* trash;
	reserveArr(strlen(str) + 1, trash);
	copyArray(str, strlen(str) + 1, trash);
	char* context;
	char* bufferLexemme = strtok_s(trash, " ", &context);
	char* tmpStr;
	reserveArr(lengthOfNewString, tmpStr);
	char* descriptorTmp = tmpStr;
	while (bufferLexemme) {
		int counterCharsBeforeBuffer = (strstr(descriptorStr, bufferLexemme) - descriptorStr);
		copyArray(descriptorStr, counterCharsBeforeBuffer, descriptorTmp);
		descriptorTmp += counterCharsBeforeBuffer;
		descriptorStr += counterCharsBeforeBuffer;
		if (!strcmp(bufferLexemme, wordToBeRemoved)) {
			copyArray(wordNew, strlen(wordNew), descriptorTmp);
			descriptorTmp += strlen(wordNew);
		}
		else {
			copyArray(bufferLexemme, strlen(bufferLexemme), descriptorTmp);
			descriptorTmp += strlen(bufferLexemme);
		}
		descriptorStr += strlen(bufferLexemme);
		bufferLexemme = strtok_s(NULL, " ", &context);
	}
	// end of the line
	int counterlastSymbolsFromStr = strlen(str) - (descriptorStr - str);
	copyArray(descriptorStr, counterlastSymbolsFromStr, descriptorTmp);
	descriptorTmp += counterlastSymbolsFromStr;
	descriptorStr += counterlastSymbolsFromStr;
	*descriptorTmp = '\0';
	removeArr(str);
	removeArr(trash);
	str = tmpStr;
}

void changeSpecialWordsInArr2(char* wordToBeRemoved, char* wordNew, char*& str, int lengthOfNewString = 1024)
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
			//charCounter = minValue(&charCounter, &symbolsLeft);
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

		// add end of the string
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

void changeSpecialWordsInFile(const char* filepath, char* wordToBeRemoved, char* wordNew)
{
	char** text;
	int rows = 0;
	readStringsFromFileToArr(filepath, text, rows);
	changeSpecialWordsInArr(wordToBeRemoved, wordNew, text, rows);
	writeStringsToFile(filepath, text, rows, false);
	removeArr(text, rows);
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
	//changeSpecialWordsInFile("C:\\Users\\Alexandr\\Desktop\\test.txt", (char*)"_", (char*)"go");
	changeSpecialWordsInFile("C:\\Users\\Alexandr\\Desktop\\test.txt", (char*)"go", (char*)"_");
}