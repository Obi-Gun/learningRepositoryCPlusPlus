#include "List.h"
#include <iostream>

List::List()
{
	phead_ = nullptr;
	ptail_ = nullptr;
}

List::List(const char* str)
{
	this->phead_ = new element(str, nullptr);
	this->ptail_ = this->phead_;
}

void List::add(const char* str)
{
	element* tmp = this->phead_;
	while (tmp != nullptr) {
		tmp = tmp->next_;
	}
	tmp = new element(str, nullptr);
	this->ptail_->next_ = tmp;
	this->ptail_ = tmp;
}

void List::print() const
{
	element* tmp = this->phead_;
	while (tmp != nullptr) {
		std::cout << tmp->str_;
		tmp = tmp->next_;
	}
	std::cout << std::endl;
}




