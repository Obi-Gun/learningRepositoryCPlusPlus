#ifndef FlatClass
#define FlatClass

#include "String_obi.h"
#include "Human.h"

class Flat
{
private:
	String_obi familySurname_;
	int floorNumber_;
	int flatNumber_;
	Human** tenants_;
	int arrLen_;

public:
	Flat();
	Flat(int flatNumber);
	Flat(const char* familySurname, int floorNumber, int flatNumber, Human** tenants, int arrLen);
	Flat(String_obi familySurname, int floorNumber, int flatNumber, Human** tenants, int arrLen);
	Flat(Flat& flat);
	~Flat();

	void setFamilySurname(const char* familySurname);
	void setFamilySurname(const String_obi familySurname);
	void setFloorNumber(int floorNumber);
	void setFlatNumber(int flatNumber);
	void setTenants(Human** tenants, int length);

	String_obi getFamilySurname() const;
	int getFloorNumber() const;
	int getFlatNumber() const;
	Human** getTenants() const;
	int getArrLen() const;

	void addTenant(Human human);
	void print() const;
	void printCompact() const;
};
#endif