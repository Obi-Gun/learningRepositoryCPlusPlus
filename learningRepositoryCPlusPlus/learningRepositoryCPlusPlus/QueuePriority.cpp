#include <iostream>
#include "QueuePriority.h"

using namespace std;

QueuePriority::QueuePriority(int maxLen)
{
	this->maxLength_ = maxLen;
	this->cells_ = new int[maxLen];
	this->priorityMarkers_ = new int[maxLen];
	this->currentLength_ = 0;
}

QueuePriority::~QueuePriority()
{
	delete[] this->cells_;
	delete[] this->priorityMarkers_;
}

void QueuePriority::add(int obj, int priority)
{
	this->currentLength_++;
	this->cells_[currentLength_ - 1] = obj;
	this->priorityMarkers_[currentLength_ - 1] = priority;
}

int QueuePriority::extract()
{
	int indexMaxPriority = 0;
	for (int i = 1; i < this->currentLength_ - 1; ++i) {
		if (this->priorityMarkers_[indexMaxPriority] < this->priorityMarkers_[i]) {
			this->priorityMarkers_[indexMaxPriority] = this->priorityMarkers_[i];
		}
	}
	int tmpCell = this->cells_[indexMaxPriority];
	this->cells_[indexMaxPriority] = this->cells_[currentLength_ - 1];
	this->priorityMarkers_[indexMaxPriority] = this->cells_[currentLength_ - 1];
	--this->currentLength_;
	return tmpCell;
}

void QueuePriority::print() const
{
	cout << "\nQueuePriority:";
	for (int i = 0; i < this->currentLength_; ++i) {
		cout << "\n\t" << i + 1 << " element = " << this->cells_[i];
	}
}
