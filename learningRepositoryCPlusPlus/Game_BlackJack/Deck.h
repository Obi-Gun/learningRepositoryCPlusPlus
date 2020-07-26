#ifndef Deck_Guardian
#define Deck_Guardian
#include "Card.h"

class Deck
{
private:
	static Deck* _ptr;
	int* _deckOfCards;
	int _numberOfDecks;
	int _length;
	const int _CARDS_IN_DECK = 52;
	const int _MIN_NUMB_OF_DECKS = 1;
	const int _DEFAULT_NUMB_OF_DECKS = 6;
	const int _MAX_NUMB_OF_DECKS = 8;

	Deck();

	int getNumbOfDecks() const;

	void initializeDeck();
	
	int randVal() const;

	Card* giveACard() const;

	Card* createCard(int);
	bool isCardInDeck(int) const; //check card haven`t already been played in this match.



public:
	~Deck();
	static Deck* getReferance();
	bool setNumberOfDecks(int);
};
#endif // !Menu_Guardian