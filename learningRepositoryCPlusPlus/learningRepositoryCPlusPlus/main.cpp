#include <iostream>
#include "funcs.h"
using namespace std;

class Counter {
	int min;
	int max;
	int currentValue;
	
public:
	Counter() {
		min = 0;
		max = 100;
		currentValue = min;
	}
	Counter(int minValue, int maxValue) {
		min = minValue;
		max = maxValue;
		currentValue = min;
	}
	Counter(int minValue, int maxValue, int currentValue) {
		min = minValue;
		max = maxValue;
		currentValue = currentValue;
	}

	void increment() {
		if (currentValue < max) {
			currentValue++;
		}
		else {
			currentValue = min;
		}
	}

	int getCurrentValue() {
		return currentValue;
	}

	void setCurrentValue(int value) {
		if (value < min) {
			currentValue = min;
		}
		else if (value > max){
			currentValue = max;
		}
		else {
			currentValue = value;
		}
	}

	void print() {
		cout << currentValue << endl;
	}

	~Counter() {
		cout << "conter has been destructed\n";
	}
};

class Student {
	int height;
	char name[16];

public:
	Student() {
	}
	Student(const char* name) {
		name = name;
	}

	~Student() {
		cout << "Student has been destructed\n";
	}
};

class Group {
	Student* group;

public:
	Group() {
		group = new Student[0];
	}
	Group(int studentsInGroup) {
		group = new Student[studentsInGroup];
	}
		
	~Group() {
		cout << "Group has been destructed\n";
		delete[] group;
	}
};

enum gender {male, female};

class Person {
	char* _name;
	int _age;
	gender _gender;
	char* _phoneNumber;

public:
	Person(char* name, int age, gender _gender, char* phoneNumber) {
		reserveArr(strlen(name) + 1, this->_name);
		copyArray(name , strlen(name) + 1, this->_name);
		this->_age = age;
		this->_gender = _gender;
		reserveArr(strlen(phoneNumber) + 1, this->_phoneNumber);
		copyArray(phoneNumber , strlen(phoneNumber) + 1, this->_phoneNumber);
		}

	Person(Person& person) {
		reserveArr(strlen(person._name) + 1, this->_name);
		copyArray(person._name, strlen(person._name) + 1, this->_name);
		this->_age = person._age;
		this->_gender = person._gender;
		reserveArr(strlen(person._phoneNumber) + 1, this->_phoneNumber);
		copyArray(person._phoneNumber, strlen(person._phoneNumber) + 1, this->_phoneNumber);
	}

	~Person() {
		delete[] this->_name;
		delete[] this->_phoneNumber;
		cout << " <> Person has been distructed <>\n";
	}

	void print() {
		cout << "\nInfo about person:\n";
		cout << "name of person: " << this->_name << endl;
		cout << "age of person: " << this->_age << endl;
		if (this->_gender) {
			cout << "gender of person: female" << endl;
		}
		else {
			cout << "gender of person: male" << endl;
		}
		cout << "phoneNumber of person: " << this->_phoneNumber << endl;
	}

	void setName(char* newName) {
		delete[] this->_name;
		reserveArr(strlen(newName) + 1, this->_name);
		copyArray(newName, strlen(newName) + 1, this->_name);
	}

	void setAge(int newAge) {
		this->_age = newAge;
	}

	void setGender(gender newGender) {
		this->_gender = newGender;
	}

	void setPhoneNumber(char* newPhoneNumber) {
		delete[] this->_phoneNumber;
		reserveArr(strlen(newPhoneNumber) + 1, this->_phoneNumber);
		copyArray(newPhoneNumber, strlen(newPhoneNumber) + 1, this->_phoneNumber);
	}
};

int main() {
	//srand(time(NULL));
	//setlocale(LC_ALL, "Russian");
	
// Homework 21.1.1 Course: "Basics of programming in C++".
	//showMismatchedStringsFromFile("C:\\Users\\Alexandr\\Desktop\\criptos_data.txt", "C:\\Users\\Alexandr\\Desktop\\criptos_data - Copy.txt");

// Homework 21.1.2 Course: "Basics of programming in C++".
	//writeInfoAboutFileToNewFile("C:\\Users\\Alexandr\\Desktop\\2.txt", "C:\\Users\\Alexandr\\Desktop\\3.txt");

// Homework 21.1.3 Course: "Basics of programming in C++".
	/*int encryptionKey = -26;
	encryptTextFromFileAnd_WriteToNewFile("C:\\Users\\Alexandr\\Desktop\\criptos_data.txt", "C:\\Users\\Alexandr\\Desktop\\criptos_data_encrypted.txt", encryptionKey);*/

// Homework 21.2.1 Course: "Basics of programming in C++".
	//removeLastStrInFile("C:\\Users\\Alexandr\\Desktop\\criptos_data - Copy.txt");

// Homework 21.2.2 Course: "Basics of programming in C++".
	//cout << maxStringLength("C:\\Users\\Alexandr\\Desktop\\criptos_data.txt");

// Homework 21.2.3 Course: "Basics of programming in C++".
	//cout << countSpecialWordInFile("C:\\Users\\Alexandr\\Desktop\\test.txt", "test");

// Homework 21.2.4 Course: "Basics of programming in C++".
	changeSpecialWordsInFile("C:\\Users\\Alexandr\\Desktop\\test.txt", (char*)"go", (char*)"ty");

// Classwork OOP.1.1. Course: "Basics of programming in C++".
	/*Counter counter(1, 50);
	counter.setCurrentValue(100);
	counter.print();
	counter.increment();
	counter.print();*/

// Classwork OOP.1.2. Course: "Basics of programming in C++".
	/*Group group1(5);
	Group group2;
	Student Kolia("Kolia");*/

// Classwork OOP.2.1. Course: "Basics of programming in C++".
	/*Person Egor((char*)"Egor", 40, male, (char*)"+79990001111");
	Egor.print();
	Person Ivan = Egor;
	Ivan.print();
	Person Juju(Ivan);
	Ivan.print();
	Person* pIgor = &Egor;
	pIgor->print();
	pIgor->setName((char*)"Igor");
	pIgor->setAge(33);
	pIgor->setGender(female);
	pIgor->setPhoneNumber((char*)"+7666000666");
	Egor.print();*/


}