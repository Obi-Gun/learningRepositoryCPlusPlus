#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class minValue {
private:
	vector<int>::iterator _start;
	vector<int>::iterator _end;

	vector<int>::iterator findMinVal() {

	}

public:
	minValue(vector<int>::iterator start, vector<int>::iterator end) : _start(start), _end(end) 
	{ 
		findMinVal(); 
	};


};

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

// Hometask 2 Course: "OOP in C++"
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