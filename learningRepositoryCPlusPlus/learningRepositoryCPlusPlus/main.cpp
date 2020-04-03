#include <iostream>
#include "funcs.h"
using namespace std;

bool isWordInArr(char** arr, int rows, char* word)
{
	for (int i = 0; i < rows; ++i) {
		if (!strcmp(word, arr[i])) {
			return true;
		}
	}
	return false;
}

void fillArr2(const char* specialWordsFilePath)
{
	int counterWords = countWordsFile(specialWordsFilePath);
	FILE* sWFile;
	if (fopen_s(&sWFile, specialWordsFilePath, "r")) {
		cout << "Unable to open file";
		return;
	}
	const int maxStringSize = 1024;
	char str[maxStringSize];
	char** arrBadWords;
	reserveArr(counterWords, maxStringSize, arrBadWords);
	int i = 0;
	while (fgets(str, maxStringSize, sWFile)) {
		char* context;
		arrBadWords[i++] = strtok_s(str, " ", &context);
		cout << arrBadWords[i - 1] << endl;
		while (char* word = strtok_s(NULL, " ", &context)) {
			strcpy_s(arrBadWords[i++], strlen(word) + 1, word);
			//arrBadWords[i++] = word;
			cout << word << endl;
		}
	}
	printArr(arrBadWords, counterWords);
	if (fclose(sWFile)) {
		cout << "Unable to close file";
		return;
	}
}

int replaceTextToFileExceptSpecialWords(const char* filepath, const char* destFilepath, const char* specialWordsFilePath)
{
	int counterWords = countWordsFile(specialWordsFilePath);
	FILE* file;
	if (fopen_s(&file, filepath, "r")) {
		cout << "Unable to open file";
		return -1;
	}
	FILE* destFile;
	if (fopen_s(&destFile, destFilepath, "w")) {
		cout << "Unable to open file";
		return -1;
	}
	FILE* sWFile;
	if (fopen_s(&sWFile, specialWordsFilePath, "r")) {
		cout << "Unable to open file";
		return -1;
	}
	const int maxStringSize = 1024;
	char str[maxStringSize];
	char** arrBadWords;
	reserveArr(counterWords, maxStringSize, arrBadWords);
	int i = 0;
	while (fgets(str, maxStringSize, sWFile)) {
		char* context;
		arrBadWords[i++] = strtok_s(str, " ", &context);
		while (char* word = strtok_s(NULL, " ", &context)) {
			arrBadWords[i++] = word;
			cout << word << endl;
		}
	}
	printArr(arrBadWords, counterWords);

	while (fgets(str, maxStringSize, file)) {
		char* context;
		char* word = strtok_s(str, " ", &context);
		while (word) {
			
			if (isWordInArr(arrBadWords, counterWords, word)) {
				fputs(word, destFile);
				fputs("\n", destFile);
			}
			word = strtok_s(NULL, " ", &context);
		}
	}
	if (fclose(file)) {
		cout << "Unable to close file";
		return -2;
	}
	if (fclose(destFile)) {
		cout << "Unable to close file";
		return -2;
	}
	if (fclose(sWFile)) {
		cout << "Unable to close file";
		return -2;
	}
	return 0;
}

int main() {
	srand(time(NULL));

// Classwork "Work with files3.". Course: "Basics of programming in C++".
	// FILE* file;
	// cout << countWordsFile("C:\\Users\\Alexandr\\Desktop\\ClassworkBadWords.txt");
	fillArr2("C:\\Users\\Alexandr\\Desktop\\ClassworkBadWords.txt");
	//replaceTextToFileExceptSpecialWords("C:\\Users\\Alexandr\\Desktop\\1.txt", "C:\\Users\\Alexandr\\Desktop\\2.txt", "C:\\Users\\Alexandr\\Desktop\\ClassworkBadWords.txt");
}