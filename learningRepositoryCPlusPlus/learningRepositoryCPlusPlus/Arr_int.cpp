#include "Arr_int.h"

Arr_int::Arr_int() {
	this->length_ = 0;
	this->arr_ = new int[this->length_];
}

Arr_int::Arr_int(int length) {
	this->length_ = length;
	this->arr_ = new int[length];
	for (int i = 0; i < length; ++i) {
		this->arr_[i] = 0;
	}
}

Arr_int::Arr_int(Arr_int& obj) {
	this->length_ = obj.length_;
	this->arr_ = new int[this->length_];
	for (int i = 0; i < this->length_; ++i) {
		(*this)[i] = obj[i];
	}
}
Arr_int::~Arr_int() {
	delete[] this->arr_;
}

int Arr_int::getLength() const {
	return this->length_;
}
int& Arr_int::operator[] (int i) const {
	if (i < 0) {
		return this->arr_[0];
	}
	if (i >= this->getLength()) {
		return this->arr_[this->getLength() - 1];
	}
	return this->arr_[i];
}
Arr_int& Arr_int::operator++ () {
	int* tmp = new int[this->length_ + 1];
	for (int i = 0; i < this->length_; ++i) {
		tmp[i] = this->arr_[i];
	}
	tmp[this->length_] = 0;
	delete[] this->arr_;
	this->arr_ = tmp;
	++this->length_;
	return *this;
}
Arr_int& Arr_int::operator++ (int) {
	int* tmp = new int[this->length_ + 1];
	for (int i = 0; i < this->length_; ++i) {
		tmp[i] = this->arr_[i];
	}
	tmp[this->length_] = 0;
	delete[] this->arr_;
	this->arr_ = tmp;
	++this->length_;
	return *this;
}
/*Arr_int Arr_int::operator+ (const int& number) {
	
}*/
/*Arr_int& Arr_int::operator+ (const Arr_int& secondArr) {
	Arr_int tmp()
	return ;
}*/
Arr_int Arr_int::operator= (const Arr_int& obj) {
	if (this->getLength() != obj.getLength()) {
		delete[] this->arr_;
		this->arr_ = new int[obj.getLength()];
		this->length_ = obj.getLength();
	}
	for (int i = 0; i < obj.getLength(); ++i) {
		this->arr_[i] = obj.arr_[i];
	}
	return *this;
}
void Arr_int::print() const {
	std::cout << std::endl;
	for (int i = 0; i < this->length_; ++i) {
		std::cout << this->arr_[i] << " ";
	}
}

std::ostream& operator << (std::ostream& out, Arr_int& obj) {
	for (int i = 0; i < obj.getLength(); ++i) {
		out << obj[i] << " ";
	}
	out << std::endl;
	return out;
}

std::istream& operator >> (std::istream& in, Arr_int& obj) {
	std::cout << "\n_________Enter the value:\n";
	for (int i = 0; i < obj.getLength(); ++i) {
		std::cout << "ind " << i << " = ";
		in >> obj[i];
	}
	std::cout << std::endl;
	return in;
}