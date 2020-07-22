#ifndef Menu_Guardian
#define Menu_Guardian
#include <iostream>
#include "Card.h"

class Menu
{
private:
	int* _deckOfCards;
	int _numberOfDecks;
	int _length;
	const int _CARDS_IN_DECK = 52; 
	const int _MIN_NUMB_OF_DECKS = 1;
	const int _MAX_NUMB_OF_DECKS = 8;

	int getNumbOfDecks() const;
	bool setNumberOfDecks(int);

	void showRules() const;
	void showMenu();
	void showDeck() const;

	void initialize();

public:
	Menu();
	~Menu();

	void start();
};
#endif // !Menu_Guardian