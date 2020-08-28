#ifndef Person_Guardian
#define Person_Guardian
#include "Card.h"
#include <vector>
using namespace std;
class Person
{
protected:
	vector<Card*> _hand;
	int _bet;

	Person();

public:

	virtual ~Person() = 0;
	
	virtual void bringCard(Card*);
	int calcScore();

	// only if two first cards have 21 score. Like Ace + King/Queen/Jack/Ten
	bool isBlackJack(); 
	bool isScoreMoreThen21();

};
#endif