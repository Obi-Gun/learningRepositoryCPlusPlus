#include <iostream>
#include "Time_obi.h"
#include "String_obi.h"

using namespace std;
Time_obi* Time_obi::pointer_ = new Time_obi(666, 666, 666);
int String_obi::_objCounter = 0;


int main() {
// Homework 4.1. Course: "OOP in C++".

	String_obi str1("ho");

	cout << "\ndefault value:                 \tExpected: \"hohoho   \"\tResult is: \"";
	cout << str1 << str1 << str1 << "\"";

	cout << "\nTest operator++ (prefix)       \tExpected: \"ho ho ho \"\tResult is: \"";
	cout << ++str1 << str1 << str1 << "\"";

	cout << "\nTest operator-- (prefix)       \tExpected: \"hohoho   \"\tResult is: \"";
	cout << --str1 << str1 << str1 << "\"";

	cout << "\nTest operator++ (postfix)      \tExpected: \"hoho ho  \"\tResult is: \"";
	cout << str1++ << str1 << str1 << "\"";

	cout << "\nTest operator-- (postfix)      \tExpected: \"ho hoho  \"\tResult is: \"";
	cout << str1-- << str1 << str1 << "\"";

	cout << "\nTest operator int              \tExpected: \"2        \"\tResult is: \"";
	int len = str1;
	cout << len << "\"";

	cout << "\nTest operator() (find \'e\')   \tExpected: \"-1       \"\tResult is: \"";
	cout << str1('e') << "\"";

	cout << "\nTest operator() (find \'o\')   \tExpected: \"1        \"\tResult is: \"";
	cout << str1('o') << "\"";

	cout << "\nTest operator[] (index -5)     \tExpected: \"         \"\tResult is: \"";
	cout << str1[-5] << "\"";

	cout << "\nTest operator[] (index 100)    \tExpected: \"         \"\tResult is: \"";
	cout << str1[100] << "\"";

	cout << "\nTest operator[] (index 0)      \tExpected: \"h        \"\tResult is: \"";
	cout << str1[0] << "\"";

	cout << "\nTest operator[] (index 1)      \tExpected: \"o        \"\tResult is: \"";
	cout << str1[1] << "\"";

	cout << "\nTest operator[] (index 2)      \tExpected: \"         \"\tResult is: \"";
	cout << str1[2] << "\"";

// Homework 4.2. Course: "OOP in C++".
	cout << "\nThere are " << String_obi::getObjCounter() << " String_obi objects right now";

// Homework 4.3. Course: "OOP in C++".
	cout << endl;
	String_obi* str2 = new String_obi;
	delete str2;
}