#include <iostream>
#include "ComplexNum.h"//
//#include "String_SmartPointer.h"
#include "String_obi.h"//
//#include "CalcStr.h"
#include <vector>
//#include "funcs.h"
#include "Student.h"
#include <list>
#include "Student_Vector.h"
#include "DictionaryOfFrequency.h"

using namespace std;

int ComplexNum::_objCounter = 0;
int String_obi::_objCounter = 0;

int main() {
// Classwork 23.08.2020. Course: "OOP in C++". Functor
	/*for (int i = 1; i <= 10; i++)
	{
		list<int> l(10);
		generate_n(l.begin(), l.size(), AddNumberFrom(i));
		//copy(l.begin(), l.end(), ostream_iterator<int>(cout, "\t"));
		auto tmp = l.begin();
		for (int i = 1; i <= 10; i++) {
			printf("%3i ", *tmp++);
		}
		cout << endl;
	}*/

// Classwork2 23.08.2020. Course: "OOP in C++". Functor
	/*for (int i = 1; i <= 10; i++)
	{
		list<int> a(10);
		generate_n(a.begin(), a.size(), AddNumberFrom(i));
		copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		list<int> b(10);
		generate_n(b.begin(), b.size(), AddNumberFrom(i));
		copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		list<int> res(10);
		transform(a.begin(), a.end(), b.begin(), res.begin(), plus<int>());
		copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
		cout << endl << endl;
	}*/

// Classwork2 23.08.2020. Course: "OOP in C++"
	vector<int> test{ 4, 2, 6, 4, 7, 1, 8, 9 };
	copy(test.begin(), test.end(), ostream_iterator<int>(cout, " "));

	cout << endl << *(min_element(test.begin(), test.end()));

	cout << endl << *(max_element(test.begin(), test.end())) << endl;

	sort(test.begin(), test.end(), greater<int>());
	copy(test.begin(), test.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	sort(test.begin(), test.end(), less<int>());
	copy(test.begin(), test.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//generate_n(test.begin(), test.size(), AddNumber(10));
	//transform(a.begin(), a.end(), b.begin(), res.begin(), plus<int>());
	//for_each(test.begin(), test.size())
	for_each(test.begin(), test.end(), [](int& num) { num += 5; });

	copy(test.begin(), test.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}