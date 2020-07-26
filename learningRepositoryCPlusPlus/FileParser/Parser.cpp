#include "Parser.h"

int Parser::countStringsInFile(char* filepth)
{
	FILE* file;
	if (fopen_s(&file, filepth, "r")) {
		std::cout << "Unable to open file";
		return -1;
	}
	const int maxStringSize = 1024;
	char str[maxStringSize];
	int strCounter = 0;
	while (fgets(str, maxStringSize, file)) {
		++strCounter;
	}
	if (fclose(file)) {
		std::cout << "Unable to close file";
		return -2;
	}
	return strCounter;
}

void Parser::read(const char* sourceFilepath)
{
	_rows = countStringsInFile((char*)sourceFilepath);
	FILE* sourceFile;
	if (fopen_s(&sourceFile, sourceFilepath, "r")) {
		std::cout << "Unable to open file";
		return;
	}
	const int maxStringSize = 1024;
	reserveArr(_rows, maxStringSize, _buffer);
	int i = 0;

	while (i < _rows && fgets(_buffer[i], maxStringSize - 1, sourceFile)) {
		_buffer[i][maxStringSize - 1] = '/0';
		i++;
	}
	if (fclose(sourceFile)) {
		std::cout << "Unable to close file";
		return;
	}
}

void Parser::filterStrWith(const char* key)
{
	char* tmp;
	char** tmp2;
	int lenTmp2 = _rows;
	int currentIndex = 0;
	reserveArr(lenTmp2, tmp2);
	for (int i = 0; i < _rows; ++i) {
		if (strstr(_buffer[i], key)) {
			tmp2[currentIndex++] = _buffer[i];
			_buffer[i] = nullptr;
		}
		else {
			delete _buffer[i];
		}
	}
	delete _buffer;
	_buffer = tmp2;
	_rows = currentIndex;
}

void Parser::print()
{
	for (int i = 0; i < _rows; ++i) {
		std::cout << _buffer[i];
	}
}

void Parser::write(const char* destFilepath, bool everyElOnNewStr)
{
	FILE* file;
	if (fopen_s(&file, destFilepath, "w")) {
		std::cout << "Unable to open file";
		return;
	}

	for (int i = 0; i < _rows; ++i) {
		fputs(_buffer[i], file);
		if (everyElOnNewStr) {
			fputs("\n", file);
		}
	}

	if (fclose(file)) {
		std::cout << "Unable to close file";
		return;
	}
}

void Parser::reserveArr(int length, char*& arr)
{
	arr = new char[length];
}

void Parser::reserveArr(int length, char**& arr)
{
	arr = new char* [length];
}

void Parser::reserveArr(int rows, int columns, char**& arr)
{
	reserveArr(rows, arr);
	for (int i = 0; i < rows; ++i) {
		reserveArr(columns, arr[i]);
	}
}

Parser::Parser()
{
}

Parser::~Parser()
{
}

Parser* Parser::getReferance()
{
    return _ptr;
}