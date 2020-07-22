#ifndef Flat_Guardian
#define Flat_Guardian

#include "String_obi.h"
#include "Human.h"

class Flat
{
private:
	String_obi _familySurname;
	int _floorNumber;
	int _flatNumber;
	Human** _tenants;
	int _arrLen;
	int _area;

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
	void setArea(int area);

	String_obi getFamilySurname() const;
	int getFloorNumber() const;
	int getFlatNumber() const;
	Human** getTenants() const;
	int getArrLen() const;
	int getArea() const;

	void addTenant(Human human);
	void print() const;
	void printCompact() const;

	bool operator== (const Flat& obj);
	void operator= (const Flat& flat);
	bool operator> (const Flat& obj);
	bool operator< (const Flat& obj);
};
#endif