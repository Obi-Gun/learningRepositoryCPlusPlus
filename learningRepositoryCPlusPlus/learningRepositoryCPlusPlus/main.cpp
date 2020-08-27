#include <list>
#include <list>
#include <io.h>
#include <vector>
#include "ComplexNum.h"
#include "String_obi.h"
#include "Student_Vector.h"
#include "DictionaryOfFrequency.h"
#include "Student.h"

using namespace std;

int main() {
// Homework 16.1. Course: "OOP in C++".
	/*Student_Vector arr;
	arr.add("Ivan2", "Ivanov", 1);
	arr.add("Egor2", "Gagarin", 2);
	arr.add("Oleg2", "Ivanov", 3);
	arr.add("Gregory2", "Kim", 4);
	arr.add("Ugine2", "Tompson", 1);
	arr.add("Bobr1", "Klimov", 2);
	arr.add("Ul1", "Erundov", 3);
	arr.add("Epistafiy1", "Corabelov", 4);
	arr.add("Lenin1", "Ter", 1);
	arr.add("Yuri1", "Tompson", 2);

	arr.add("Ivan1", "Ivanisov", 1);
	arr.add("Egor1", "Tatarin", 2);
	arr.add("Oleg1", "Pivanov", 3);
	arr.add("Gregory1", "Uim", 4);
	arr.add("Ugine1", "Tompson", 1);
	arr.add("Bobr2", "Klimov", 2);
	arr.add("Ul2", "Terundov", 3);
	arr.add("Epistafiy2", "Morabelov", 4);
	arr.add("Lenin2", "Meller", 1);
	arr.add("Yuri2", "Tomson", 2);

	arr.sortByName();
	cout << "_______SortByName" << endl << arr << endl;

	arr.sortBySurname();
	cout << "_______SortBySurname" << endl << arr << endl;

	arr.sortByYear();
	cout << "_______SortByYear" << endl << arr << endl;

	arr.sortByName(0, 3);
	arr.sortByName(3);
	cout << "_______SortByFirst 1-3 and 4-20" << endl << arr << endl;*/

// Homework 16.2. Course: "OOP in C++".
	DictionaryOfFrequency dict;
	dict.readFileAndFillDictionary("G:\\_Downloads\\War and Peace.txt");
	cout << dict;

}