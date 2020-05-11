#include "Arr_Reservoir.h"
#include "funcs.h"

void Arr_Reservoir::setLength(int length) {
	if (length < 0) {
		this->length_ = 0;
	}
	this->length_ = length;
}
void Arr_Reservoir::reCreateArr(int length) {
	Reservoir** tmp = new Reservoir * [length];
	for (int i = 0; i < length && i < this->getLength(); ++i) {
		tmp[i] = this->arr_[i];
	}
	delete[] this->arr_;
	this->arr_ = tmp;
	this->setLength(length);
}
void Arr_Reservoir::addObj(Reservoir& reservoir) {
	this->reCreateArr(this->getLength() + 1);
	this->arr_[this->getLength() - 1] = new Reservoir(reservoir);
}
void Arr_Reservoir::removeObj(int index) {
	if (index >= 0 && this->getLength()) {
		this->arr_[index]->~Reservoir();
		for (int i = index; i < this->getLength() - 1; ++i) {
			this->arr_[i] = this->arr_[i + 1];
		}
		this->reCreateArr(this->getLength() - 1);
	}
}

Arr_Reservoir::Arr_Reservoir() {
	this->setLength(0);
	this->arr_ = new Reservoir * [this->getLength()];
}
Arr_Reservoir::Arr_Reservoir(Reservoir** arr, int length) {
	this->setLength(length);
	this->arr_ = new Reservoir * [this->getLength()];
	for (int i = 0; i < this->getLength(); ++i) {
		this->arr_[i] = new Reservoir(*(arr[i]));
	}
}
Arr_Reservoir::Arr_Reservoir(Arr_Reservoir& input) {
	this->setLength(input.getLength());
	this->arr_ = new Reservoir * [this->getLength()];
	for (int i = 0; i < this->getLength(); ++i) {
		this->arr_[i] = new Reservoir(*(input.arr_[i]));
	}
}
Arr_Reservoir::~Arr_Reservoir() {
	delete[] this->arr_;
	//cout << "\n\t~Arr_Reservoir()";
}

int Arr_Reservoir::getLength() const {
	return this->length_;
}
void Arr_Reservoir::menu() {
	do {
		cout << "\n___________Menu:\n 0 -> For exit programm\n 1 -> For add object\n 2 -> For remove object\n 3 -> For show all objects";
		cout << "\nEnter the number of opertion you want to do ---> ";
		int i;
		cin >> i;
		switch (i)
		{
		case 0:
			cout << "\n___________<EXIT Programm...>";
			return;
			break;
		case 1:
			cout << "\n___________<add object...>";
			this->addObj();
			break;
		case 2:
			cout << "\n___________<removing object...>";
			this->removeObj();
			break;
		case 3:
			cout << "\n___________<showing all objects...>";
			this->print();
			break;
		default:
			cout << "\n___________<You have entered the wrong menu number. Please try again.>";
			break;
		}
	} while (true);
}
void Arr_Reservoir::print() {
	cout << "\n_________List of reservoirs:";
	for (int i = 0; i < this->getLength(); ++i) {
		cout << "\n___<item index " << i << " >___";
		this->arr_[i]->print();

	}
}
void Arr_Reservoir::addObj() {
	char* name = new char[100];
	std::cout << "\n__________<Creating new item>\nEnter the name - > ";
	cin.getline(name, 100);
	cin.getline(name, 100);
	int length;
	std::cout << "Length - > ";
	cin >> length;
	int width;
	std::cout << "Width - > ";
	cin >> width;
	int depth;
	std::cout << "Depth - > ";
	cin >> depth;
	reservoirType type = nonselected;
	Reservoir tmp(name, length, width, depth, type);
	this->addObj(tmp);
	delete[] name;
}
void Arr_Reservoir::removeObj() {
	int index;
	std::cout << "\n__________<Removing item>\nEnter the index of item - > ";
	cin >> index;
	while (index < 0 || index > this->getLength()) {
		std::cout << "__<You`ve entered the wrong number. Please enter the correct item index - > ";
		cin >> index;
	}
	this->removeObj(index);
}