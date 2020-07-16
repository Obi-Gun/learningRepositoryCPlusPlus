#include "Note.h"
#include <windows.h> 
#include <fstream> 
#include <iostream> 
#include <iomanip>

using namespace std;

Note::Note()
{
	_name = nullptr;
	_arrLen = 10;
	_arr = new int[_arrLen];
}

Note::Note(const char* name, int* arr, int arrLen)
{
	_name = (char*)name;
	_arr = arr;
	_arrLen = arrLen;
}

Note::~Note()
{
	delete[] _arr;
	std::cout << "\n~Note()";
}

void Note::print()
{
	cout << endl;
	for (int i = 0; i < _counter; ++i) {
		cout << _arr[i] << " ";
	}
}

void Note::saveToFile()
{
	fstream f = fstream(_name, ios::out);
	for (int i = 0; i < _arrLen; ++i) {
		f << _arr[i] << " ";
	}

	f.close();
}

void Note::readFromFile()
{
	fstream f = fstream(_name, ios::in);
	int counter = 0;
	while (!f.eof()) {
		f >> _arr[counter++];
	}
	_counter = counter - 1;
	f.close();
}

void Note::appendObj()
{
	fstream f = fstream(_name, ios::out);
	f << "name " << _name << endl;
	f << "counter " << _counter << endl;
	f << "max arr len " << _arrLen << endl;
	for (int i = 0; i < _arrLen; ++i) {
		f << _arr[i] << " ";
	}
	f.close();
}
