#include "ListBiDirectional.h"
#include <iostream>

/*template <class T>
void ListBiDirectional<T>::print() const
{
	elementBD* tmp = phead_;
	while (tmp != nullptr) {
		std::cout << tmp->str_;
		tmp = tmp->next_;
	}
	std::cout << std::endl;
}*/

template <class T>
void ListBiDirectional<T>::print(int index) const
{
	elementBD* tmp;
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
template void ListBiDirectional<char>::print(int index) const;

/*template <class T>
void ListBiDirectional<T>::printReverse() const
{
	elementBD* tmp = ptail_;
	while (tmp != nullptr) {
		std::cout << tmp->str_;
		tmp = tmp->prev_;
	}
	std::cout << std::endl;
}

template <class T>
void ListBiDirectional<T>::addHead(T* str)
{
	elementBD* tmp = tmp = new elementBD(nullptr, str, phead_);
	phead_->prev_ = tmp;
	phead_ = tmp;
	++counter_;
}

template <class T>
void ListBiDirectional<T>::addTail(T* str)
{
	elementBD* tmp = new elementBD(ptail_, str, nullptr);
	ptail_->next_ = tmp;
	ptail_ = tmp;
	++counter_;
}

template <class T>
void ListBiDirectional<T>::insert(T* str, int index)
{
	elementBD* tmp = nullptr, *prev = nullptr, *next = nullptr;
	next = getEl(index);
	prev = next->prev_;
	tmp = new elementBD(prev, str, next);
	prev->next_ = tmp;
	next->prev_ = tmp;
	++counter_;
}

template <class T>
void ListBiDirectional<T>::deleteAllElements()
{
	elementBD* tmp = phead_, * next;
	while (tmp != nullptr) {
		next = tmp->next_;
		delete tmp;
		tmp = next;
	}
}

template <class T>
int ListBiDirectional<T>::getCount() const
{
	return counter_;
}

template <class T>
elementBD<T>* ListBiDirectional<T>::getEl(int index)
{
	elementBD* tmp = nullptr;
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
}*/