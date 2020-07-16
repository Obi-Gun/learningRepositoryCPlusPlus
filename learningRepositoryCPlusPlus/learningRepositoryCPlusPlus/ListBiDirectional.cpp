#include "ListBiDirectional.h"
#include <iostream>
#include "String_obi.h"

template elementBD<int>::elementBD(elementBD<int>* previous, int* field, elementBD<int>* next);
template elementBD<double>::elementBD(elementBD<double>* previous, double* field, elementBD<double>* next);
template elementBD<char>::elementBD(elementBD<char>* previous, char* field, elementBD<char>* next);
template elementBD<String_obi>::elementBD(elementBD<String_obi>* previous, String_obi* field, elementBD<String_obi>* next);
template<class T>
elementBD<T>::elementBD(elementBD<T>* previous, T* field, elementBD<T>* next)
{
	prev_ = previous;
	str_ = field;
	next_ = next;
}

template ListBiDirectional<int>::ListBiDirectional();
template ListBiDirectional<char>::ListBiDirectional();
template ListBiDirectional<String_obi>::ListBiDirectional();
template<class T>
ListBiDirectional<T>::ListBiDirectional()
{
	phead_ = nullptr;
	ptail_ = nullptr;
	counter_ = 0;
}

template ListBiDirectional<int>::ListBiDirectional(int* str);
template ListBiDirectional<char>::ListBiDirectional(char* str);
template ListBiDirectional<String_obi>::ListBiDirectional(String_obi* str);
template<class T>
ListBiDirectional<T>::ListBiDirectional(T* str)
{
	phead_ = new elementBD<T>(nullptr, str, nullptr);
	ptail_ = phead_;
	counter_ = 1;
}

template ListBiDirectional<char>::~ListBiDirectional();
template ListBiDirectional<String_obi>::~ListBiDirectional();
template<class T>
ListBiDirectional<T>::~ListBiDirectional()
{
	std::cout << "~ListBiDirectional()\n";
	deleteAllElements();

}

template void ListBiDirectional<char>::print() const;
template<class T> 
void ListBiDirectional<T>::print() const
{
	elementBD<T>* tmp = phead_;
	while (tmp != nullptr) {
		std::cout << tmp->str_;
		tmp = tmp->next_;
	}
	std::cout << std::endl;
}

void ListBiDirectional<String_obi>::print() const
{
	elementBD<String_obi>* tmp = phead_;
	while (tmp != nullptr) {
		std::cout << std::endl;
		tmp->str_->print();
		tmp = tmp->next_;
	}
	std::cout << std::endl;
}

template void ListBiDirectional<char>::print(int index) const;
template <class T>
void ListBiDirectional<T>::print(int index) const
{
	elementBD<T>* tmp;
	if (index < counter_ / 2 - 1) {
		int counter = 1;
		tmp = phead_;
		while (counter - 1 != index) {
			tmp = tmp->next_;
			++counter;
		}
	}
	else {
		int counter = counter_;
		tmp = ptail_;
		while (counter - 1 != index) {
			tmp = tmp->prev_;
			--counter;
		}
	}
	std::cout << std::endl << tmp->str_ << std::endl;
}

void ListBiDirectional<String_obi>::print(int index) const
{
	elementBD<String_obi>* tmp;
	if (index < counter_ / 2 - 1) {
		int counter = 1;
		tmp = phead_;
		while (counter - 1 != index) {
			tmp = tmp->next_;
			++counter;
		}
	}
	else {
		int counter = counter_;
		tmp = ptail_;
		while (counter - 1 != index) {
			tmp = tmp->prev_;
			--counter;
		}
	}
	std::cout << std::endl;
	tmp->str_->print();
}

template void ListBiDirectional<char>::printReverse() const;
template <class T>
void ListBiDirectional<T>::printReverse() const
{
	elementBD<T>* tmp = ptail_;
	while (tmp != nullptr) {
		std::cout << tmp->str_;
		tmp = tmp->prev_;
	}
	std::cout << std::endl;
}

template void ListBiDirectional<char>::addHead(char* str);
template void ListBiDirectional<String_obi>::addHead(String_obi* str);
template <class T>
void ListBiDirectional<T>::addHead(T* str)
{
	elementBD<T>* tmp = tmp = new elementBD<T>(nullptr, str, phead_);
	if (phead_ != nullptr) {
		phead_->prev_ = tmp;
	}
	phead_ = tmp;
	if (ptail_ == nullptr) {
		ptail_ = tmp;
	}
	++counter_;
}

template void ListBiDirectional<char>::addTail(char* str);
template void ListBiDirectional<String_obi>::addTail(String_obi* str);
template <class T>
void ListBiDirectional<T>::addTail(T* str)
{
	elementBD<T>* tmp = new elementBD<T>(ptail_, str, nullptr);
	if (ptail_ != nullptr) {
		ptail_->next_ = tmp;
	}
	ptail_ = tmp;
	if (phead_ == nullptr) {
		phead_ = tmp;
	}
	++counter_;
}

template void ListBiDirectional<char>::insert(char* str, int index);
template void ListBiDirectional<String_obi>::insert(String_obi* str, int index);
template <class T>
void ListBiDirectional<T>::insert(T* str, int index)
{
	elementBD<T>* tmp = nullptr, *prev = nullptr, *next = nullptr;
	next = getEl(index);
	prev = next->prev_;
	tmp = new elementBD<T>(prev, str, next);
	prev->next_ = tmp;
	next->prev_ = tmp;
	++counter_;
}

template void ListBiDirectional<char>::deleteAllElements();
template void ListBiDirectional<String_obi>::deleteAllElements();
template <class T>
void ListBiDirectional<T>::deleteAllElements()
{
	elementBD<T>* tmp = phead_, * next;
	while (tmp != nullptr) {
		next = tmp->next_;
		delete tmp;
		tmp = next;
	}
}

template int ListBiDirectional<char>::getCount() const;
template int ListBiDirectional<String_obi>::getCount() const;
template <class T>
int ListBiDirectional<T>::getCount() const
{
	return counter_;
}

template elementBD<char>* ListBiDirectional<char>::getEl(int index);
template elementBD<String_obi>* ListBiDirectional<String_obi>::getEl(int index);
template <class T>
elementBD<T>* ListBiDirectional<T>::getEl(int index)
{
	elementBD<T>* tmp = nullptr;
	if (index + 1 < counter_ / 2) {
		int counter = 1;
		tmp = phead_;
		while (counter != index + 1) {
			tmp = tmp->next_;
			++counter;
		}
	}
	else {
		int counter = counter_;
		tmp = ptail_;
		while (counter != index + 1) {
			tmp = tmp->prev_;
			--counter;
		}
	}
	return tmp;
}