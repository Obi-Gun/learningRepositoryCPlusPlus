#include "PhoneBook.h"

PhoneBook::PhoneBook() {
	this->addSlots();
}

PhoneBook::PhoneBook(const PhoneBook& phoneBook) {
	this->currentPosition_ = phoneBook.currentPosition_;
	this->phoneBookArrLength_ = phoneBook.phoneBookArrLength_;
	this->phoneBook_ = new Contact * [this->phoneBookArrLength_];
	for (int i = 0; i < phoneBook.currentPosition_; ++i) {
		Contact* contact = new Contact(*(phoneBook.phoneBook_[i]));
		this->phoneBook_[i] = contact;
	}
}

void PhoneBook::addSlots(int howManyAddSlot) {
	this->phoneBookArrLength_ += howManyAddSlot;
	class Contact** tmp;
	tmp = new Contact* [this->phoneBookArrLength_];
	copyContactPointers(tmp, this->currentPosition_, this->phoneBook_);
	delete[] this->phoneBook_;
	this->phoneBook_ = tmp;
}

void PhoneBook::copyContactPointers(class Contact** dest, int length, class Contact** source) {
	for (int i = 0; i < length; ++i) {
		dest[i] = source[i];
	}
}

void PhoneBook::menu() {
	char input;
	do {
		this->printMenu();
		cin >> input;
		switch (input)
		{
		case '0': // for EXIT programm
			break;
		case '1': // for add contact
			this->addContact();
			break;
		case '2': // for print all contacts
			this->print();
			break;
		case '3': // for search contact

			break;
		case '4': // for remove contact
			this->removeContact();
			break;
		default:
			std::cout << "You have entered the wrong number. Please try gain";
			break;
		}
	} while (input != '0');
}

void PhoneBook::printMenu() {
	std::cout << "\nEnter menu number:";
	std::cout << "\n0 for EXIT programm";
	std::cout << "\n1 for add contact";
	std::cout << "\n2 for print all contacts";
	std::cout << "\n3 for search contact";
	std::cout << "\n4 for remove contact";
	std::cout << "\n---> ";
}

void PhoneBook::print() {
	for (int i = 0; i < this->currentPosition_; ++i) {
		std::cout << "\nID #" << i;
		this->phoneBook_[i]->printCompact();
	}
}

void PhoneBook::removeContact() {
	std::cout << "Enter ID ---> ";
	int input2;
	cin >> input2;
	this->removeContact(input2);
}

void PhoneBook::removeContact(int index) {
	// index = indexOfContactToBeRemoved
	delete this->phoneBook_[index];
	this->copyContactPointers(this->phoneBook_ + index, this->currentPosition_ - index - 1, this->phoneBook_ + index + 1);
	--this->currentPosition_;
}

void PhoneBook::addContact() {
	if (this->currentPosition_ > this->phoneBookArrLength_) {
		std::cout << "\n\n\tError \tvoid PhoneBook::addContact()\n\tcurrentPosition > phoneBookArrLength";
		return;
	}
	else if (this->currentPosition_ == this->phoneBookArrLength_) {
		addSlots();
	}
	this->addContact(this->createContact());
}

void PhoneBook::addContact(class Contact* contact) {
	if (this->currentPosition_ > this->phoneBookArrLength_) {
		std::cout << "\n\n\tError \tvoid PhoneBook::addContact()\n\tcurrentPosition > phoneBookArrLength";
		return;
	}
	else if (this->currentPosition_ == this->phoneBookArrLength_) {
		addSlots();
	}
	this->phoneBook_[this->currentPosition_] = contact;
	currentPosition_++;
}

Contact* PhoneBook::createContact() {
	Contact* contact = new Contact;
	contact->cinAllFields();
	return contact;
}

PhoneBook::~PhoneBook() {
	delete[] this->phoneBook_;
	std::cout << "\n~PhoneBook()";
}