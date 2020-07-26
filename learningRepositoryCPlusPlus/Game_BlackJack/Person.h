#ifndef Person_Guardian
#define Person_Guardian
#include "Card.h"
#include "Str.h"

class Person
{
private:
	Card** _hand;
	int _cardsCounter;
	Str _name;

	Person();

public:
	virtual ~Person() = 0;
	
	virtual void bringCard(Card*);
	int calcScore();

	bool isBlackJack(); // only if two first cards have 21 score. Like Ace + King/Queen/Jack/Ten
	bool isScoreMoreThen21();

};
#endif