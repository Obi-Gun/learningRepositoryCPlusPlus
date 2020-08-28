#ifndef Menu_Guardian
#define Menu_Guardian
#include <iostream>
#include "Card.h"
#include "Diller.h"
#include "Player.h"
#include "Deck.h"

class Menu
{
private:
	Player* _players;
	Deck* _deck;
	Diller* _diller;

	void showRules() const;
	void showMenu();
	void showDeck() const;
	void initPlayers();
	void match();

public:
	Menu();
	~Menu();

	void start();
};
#endif // !Menu_Guardian