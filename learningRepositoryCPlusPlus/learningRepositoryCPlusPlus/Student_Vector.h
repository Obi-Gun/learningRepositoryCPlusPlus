#ifndef Student_Vector_Class
#define Student_Vector_Class
#include <vector>
#include <iostream>
#include "Student.h"

using namespace std;

class Student_Vector
{
private:
	vector<Student> _students;
	friend std::ostream& operator << (std::ostream& out, Student_Vector& obj);
public:
	Student_Vector();
	~Student_Vector();

	void add(string name, string surname, int year);
	void sortByName(int startIndex = 0, int finishIndex = -1);
	void sortBySurname(int startIndex = 0, int finishIndex = -1);
	void sortByYear(int startIndex = 0, int finishIndex = -1);
	void checkIndexesAreNotOutOfBounds(int& startIndex, int& finishIndex);
	void swap();
};

std::ostream& operator << (std::ostream& out, Student_Vector& obj);
#endif