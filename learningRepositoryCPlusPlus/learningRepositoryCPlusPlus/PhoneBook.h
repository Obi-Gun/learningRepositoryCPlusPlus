#ifndef PhoneBookClass
#define PhoneBookClass

class PhoneBook
{
private:
	int phoneBookArrLength_ = 0;
	int currentPosition_ = 0;
	class Contact** phoneBook_;

	void addSlots(int howManyAddSlot = 10);
	void copyContactPointers(class Contact** dest, int length, class Contact** source);
	class Contact* createContact();
	void addContact();
	void printMenu();
	void print();
	void removeContact();
	void removeContact(int indexOfContactToBeRemoved);
	void searchByName();                                       // FIXME later (fix crutch)
	void searchByName(const char* str);

public:
	PhoneBook();
	PhoneBook(const PhoneBook& phoneBook); // FIXME

	void addContact(class Contact* contact);
	void menu();
		
	~PhoneBook();
};
#endif