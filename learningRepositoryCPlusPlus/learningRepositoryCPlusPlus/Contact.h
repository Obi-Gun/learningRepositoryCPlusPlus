#ifndef ContactClass
#define ContactClass

#include "funcs.h"

class Contact
{
private:
	char* name_;
	char* surname_;
	char* middleName_; // patronymic (like Filimonovich)
	char* phoneNumber_home_;
	char* phoneNumber_work_;
	char* phoneNumber_mobile_;
	char* otherInfo_;

	void makeDefaultString(char*& pointer);
	void setStringField(char*& fieldPointer, const char* newValueForString);

public:
	Contact();
	Contact(const char* name);
	Contact(const Contact& contact);

	void setName(const char* newName);
	void setSurname(const char* newSurname);
	void setMiddleName(const char* newMiddleName);
	void setPhoneNumber_home(const char* newPhoneNumber_home);
	void setPhoneNumber_work(const char* newPhoneNumber_work);
	void setPhoneNumber_mobile(const char* newPhoneNumber_mobile);
	void setOtherInfo(const char* newOtherInfo);

	void cinAllFields(); // FIXME later (fix crutch)

	inline void print() {
		std::cout << "\nContact info:";
		std::cout << "\n1\tName: " << this->name_;
		std::cout << "\n2\tSurname: " << this->surname_;
		std::cout << "\n3\tMiddleName: " << this->middleName_;
		std::cout << "\n4\tHome phoneNumber: " << this->phoneNumber_home_;
		std::cout << "\n5\tWork phoneNumber: " << this->phoneNumber_work_;
		std::cout << "\n6\tMobile phoneNumber: " << this->phoneNumber_mobile_;
		std::cout << "\n7\tOther information: " << this->otherInfo_;
	}
	inline void printCompact() {
		std::cout << " Contact:";
		std::cout << " " << this->name_;
		std::cout << " " << this->middleName_;
		std::cout << " " << this->surname_;
		std::cout << "\nPhone numbers: home: " << this->phoneNumber_home_;
		std::cout << "\n               work: " << this->phoneNumber_work_;
		std::cout << "\n             mobile: " << this->phoneNumber_mobile_;
		std::cout << "\nOther: " << this->otherInfo_;
	}

	~Contact();
};
#endif