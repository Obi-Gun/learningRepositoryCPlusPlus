#ifndef Diller_Guardian
#define Diller_Guardian
#include "Person.h"

class Diller : public Person
{
private:


public:
	Diller();
	~Diller();

	bool isScoreMoreThen16(); // if true then Diller can`t take more cards
						 // if false then Diller have to take one more card

	void bringCard(Card*);

	void showSecondCard();

	// BETS
	bool payMoney();
	bool earnMoney();
};
#endif