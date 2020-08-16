#include "Student_Vector.h"

Student_Vector::Student_Vector()
{
}

Student_Vector::~Student_Vector()
{
}

void Student_Vector::add(string name, string surname, int year)
{
	_students.push_back(Student(name, surname, year));
}

void Student_Vector::sortByName(int startIndex, int finishIndex)
{
	checkIndexesAreNotOutOfBounds(startIndex, finishIndex);
	for (int i = startIndex; i < finishIndex - 1; ++i) {
		for (int j = startIndex; j < finishIndex - 1 - i; ++j) {
			for (int k = 0; k < _students[j].getName().length() && k < _students[j].getName().length(); ++k) {
				char charFirstWord = _students[j].getName().c_str()[k];
				char charSecondWord = _students[j + 1].getName().c_str()[k];
				if (charFirstWord == charSecondWord) {
					continue;
				}
				if (charFirstWord < charSecondWord) {
					break;
				}
				if (charFirstWord > charSecondWord) {
					auto tmp = _students[j];
					_students[j] = _students[j + 1];
					_students[j + 1] = tmp;
					break;
				}
			}
		}
	}
}

void Student_Vector::sortBySurname(int startIndex, int finishIndex)
{
	checkIndexesAreNotOutOfBounds(startIndex, finishIndex);
	for (int i = startIndex; i < finishIndex - 1; ++i) {
		for (int j = startIndex; j < finishIndex - 1 - i; ++j) {
			for (int k = 0; k < _students[j].getSurname().length() && k < _students[j].getSurname().length(); ++k) {
				char charFirstWord = _students[j].getSurname().c_str()[k];
				char charSecondWord = _students[j + 1].getSurname().c_str()[k];
				if (charFirstWord == charSecondWord) {
					continue;
				}
				if (charFirstWord < charSecondWord) {
					break;
				}
				if (charFirstWord > charSecondWord) {
					auto tmp = _students[j];
					_students[j] = _students[j + 1];
					_students[j + 1] = tmp;
					break;
				}
			}
		}
	}
}

void Student_Vector::sortByYear(int startIndex, int finishIndex)
{
	checkIndexesAreNotOutOfBounds(startIndex, finishIndex);
	for (int i = startIndex; i < finishIndex - 1; ++i) {
		for (int j = startIndex; j < finishIndex - 1 - i; ++j) {
			if (_students[j].getYear() > _students[j + 1].getYear()) {
				auto tmp = _students[j];
				_students[j] = _students[j + 1];
				_students[j + 1] = tmp;
			}
		}
	}
}

void Student_Vector::checkIndexesAreNotOutOfBounds(int& startIndex, int& finishIndex)
{
	if (startIndex < 0 || startIndex >= _students.size()) {
		startIndex = 0;
	}
	if (finishIndex < 0 || finishIndex >= _students.size()) {
		finishIndex = _students.size();
	}
	if (startIndex > finishIndex) {
		auto tmp = startIndex;
		startIndex = finishIndex;
		finishIndex = tmp;
	}
}



std::ostream& operator<<(std::ostream& out, Student_Vector& obj)
{
	printf("%10s \t%10s   %s\n", "Name: ", "Surname: ", "Year: ");
	for (auto student = obj._students.begin(); student != obj._students.end(); ++student)
	{
		cout << *student << endl;
	}
	return out;
}
