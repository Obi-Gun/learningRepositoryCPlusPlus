#include <iostream>
#include "funcs.h"
using namespace std;

void main() {
	srand(time(NULL));

// Course: "Basics of programming in C++". Week 18. HomeWork 1.1 


// Course: "Basics of programming in C++". Week 18. ClassWork 2.3
	//fraction a = { 1, 10 };
	//fraction b = { 1, 20 };
	//fraction res1 = sum(a, b);
	//printFraction(res1);
	//fraction res2 = substr(a, b);
	//printFraction(res2);
	//printFraction(multipy(a, b));
	//fraction res = divide(a, b);
	fraction b = { 50, 700 };
	printFraction(b);
	reduceFraction(b);
	printFraction(b);

}