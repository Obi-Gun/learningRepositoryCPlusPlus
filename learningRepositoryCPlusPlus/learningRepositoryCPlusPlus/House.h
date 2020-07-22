#ifndef House_Guardian
#define House_Guardian

#include <iostream>
#include "String_obi.h"
#include "Flat.h"

class House
{
private:
	int arrLen_;
	Flat** flats_;
	int floorsInHouse_;
	String_obi adress_;

public:
	House();
	House(const String_obi adress);
	House(const char* adress);
	House(Flat** flats, int arrLen, int floorsInHouse, String_obi adress);
	House(House& house);
	~House();

	void setFlats(Flat** flats, int arrLen);
	void setFloorsInHouse(int floorsInHouse);
	void setAdress(String_obi adress);
	void setAdress(char* adress);

	Flat** getFlats() const;
	int getFloorsInHouse() const;
	String_obi getAdress() const;

	void print() const;
};
#endif