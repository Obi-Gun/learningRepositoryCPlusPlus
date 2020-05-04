#include "Contact.h"
#include "funcs.h"

Contact::Contact() {
	this->makeDefaultString(this->name_);
	this->makeDefaultString(this->surname_);
	this->makeDefaultString(this->middleName_);
	this->makeDefaultString(this->phoneNumber_home_);
	this->makeDefaultString(this->phoneNumber_work_);
	this->makeDefaultString(this->phoneNumber_mobile_);
	this->makeDefaultString(this->otherInfo_);
}
Contact::Contact(const char* name) {
	reserveArr(strlen(name) + 1, this->name_);
	strcpy_s(this->name_, strlen(name) + 1, name);
	this->makeDefaultString(this->surname_);
	this->makeDefaultString(this->middleName_);
	this->makeDefaultString(this->phoneNumber_home_);
	this->makeDefaultString(this->phoneNumber_work_);
	this->makeDefaultString(this->phoneNumber_mobile_);
	this->makeDefaultString(this->otherInfo_);
}
Contact::Contact(const Contact& contact) {
	reserveArr(strlen(contact.name_) + 1, this->name_);
	reserveArr(strlen(contact.surname_) + 1, this->surname_);
	reserveArr(strlen(contact.middleName_) + 1, this->middleName_);
	reserveArr(strlen(contact.phoneNumber_home_) + 1, this->phoneNumber_home_);
	reserveArr(strlen(contact.phoneNumber_work_) + 1, this->phoneNumber_work_);
	reserveArr(strlen(contact.phoneNumber_mobile_) + 1, this->phoneNumber_mobile_);
	reserveArr(strlen(contact.otherInfo_) + 1, this->otherInfo_);
	strcpy_s(this->name_, strlen(contact.name_) + 1, contact.name_);
	strcpy_s(this->surname_, strlen(contact.surname_) + 1, contact.surname_);
	strcpy_s(this->middleName_, strlen(contact.middleName_) + 1, contact.middleName_);
	strcpy_s(this->phoneNumber_home_, strlen(contact.phoneNumber_home_) + 1, contact.phoneNumber_home_);
	strcpy_s(this->phoneNumber_work_, strlen(contact.phoneNumber_work_) + 1, contact.phoneNumber_work_);
	strcpy_s(this->phoneNumber_mobile_, strlen(contact.phoneNumber_mobile_) + 1, contact.phoneNumber_mobile_);
	strcpy_s(this->otherInfo_, strlen(contact.otherInfo_) + 1, contact.otherInfo_);
}

void Contact::makeDefaultString(char*& pointer) {
	reserveArr(1, pointer);
	pointer[0] = '\0';
}

void Contact::setStringField(char*& fieldPointer, const char* newValueForString) {
	delete[] fieldPointer;
	reserveArr(strlen(newValueForString) + 1, fieldPointer);
	strcpy_s(fieldPointer, strlen(newValueForString) + 1, newValueForString);
}
void Contact::setName(const char* newName) {
	this->setStringField(this->name_, newName);
}
void Contact::setSurname(const char* newSurname) {
	this->setStringField(this->surname_, newSurname);
}
void Contact::setMiddleName(const char* newMiddleName) {
	this->setStringField(this->middleName_, newMiddleName);
}
void Contact::setPhoneNumber_home(const char* newPhoneNumber_home) {
	this->setStringField(this->phoneNumber_home_, newPhoneNumber_home);
}
void Contact::setPhoneNumber_work(const char* newPhoneNumber_work) {
	this->setStringField(this->phoneNumber_work_, newPhoneNumber_work);
}
void Contact::setPhoneNumber_mobile(const char* newPhoneNumber_mobile) {
	this->setStringField(this->phoneNumber_mobile_, newPhoneNumber_mobile);
}
void Contact::setOtherInfo(const char* newOtherInfo) {
	this->setStringField(this->otherInfo_, newOtherInfo);
}

const char* Contact::getName() {
	return this->name_;
}
const char* Contact::getSurname() {
	return this->surname_;
}
const char* Contact::getMiddleName() {
	return this->middleName_;
}

void Contact::cinAllFields() {
	char crutch;
	std::cout << "\nEnter the name: ";
	cin.getline(this->name_, 100);							// FIXME later (fix crutch)
	cin.getline(this->name_, 100);
	std::cout << "Enter the surname: ";
	cin.getline(this->surname_, 100);
	std::cout << "Enter the middleName: ";
	cin.getline(this->middleName_, 100);
	std::cout << "Enter the home phoneNumber: ";
	cin.getline(this->phoneNumber_home_, 15);
	std::cout << "Enter the work phoneNumber: ";
	cin.getline(this->phoneNumber_work_, 15);
	std::cout << "Enter the mobile phoneNumber: ";
	cin.getline(this->phoneNumber_mobile_, 15);
	std::cout << "Enter the other information: ";
	cin.getline(this->otherInfo_, 250);
}

Contact::~Contact() {
	delete[] this->name_;
	delete[] this->surname_;
	delete[] this->middleName_;
	delete[] this->phoneNumber_home_;
	delete[] this->phoneNumber_work_;
	delete[] this->phoneNumber_mobile_;
	delete[] this->otherInfo_;
	std::cout << "\n~Contact()";
}