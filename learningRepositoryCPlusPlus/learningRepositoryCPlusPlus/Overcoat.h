#ifndef Overcoat_Guard
#define Overcoat_Guard

enum overcoatTypes {
	empty_field = -1, coat = 0, greatcoat = 1, outerwear = 2, fur = 3, overcoat = 4, topcoat = 5
};

class Overcoat
{
private:
	int _price;
	overcoatTypes _type;

public:
	Overcoat();
	Overcoat(int price, overcoatTypes type);
	Overcoat(Overcoat& obj);


	bool operator== (const Overcoat& obj);
	void operator= (const Overcoat& obj);
	bool operator> (const Overcoat& obj);
	bool operator< (const Overcoat& obj);
};
#endif