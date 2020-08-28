#ifndef Player_Guardian
#define Player_Guardian
#include "Person.h"

class Player : public Person
{
private:
	vector<Card*> _secondHand;
	int _secondHandBet;

public:
	Player();
	~Player();

	void initSecondHand();
	void relocateOneCardFromFirstHandToSecondHand();
	void mirrorTheBetToSecondHand();

	void bringCard(Card*);

	bool isItSplit(); // if both first and second card have the same Score

	bool wouldUlikeToPlayDouble();
	bool wouldUlikeToTakeOneMoreCard();
	bool wouldUlikeToSplit(); //MakeSecondHand


	// BETS
	bool makeABet();
	bool toDoubleTheBet();	
	bool playDouble();
	void split(); //MakeSecondHand
	void makeSecondHand();
};
#endif