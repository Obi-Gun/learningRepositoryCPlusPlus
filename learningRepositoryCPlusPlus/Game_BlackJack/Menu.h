#ifndef Menu_Guardian
#define Menu_Guardian
#include <iostream>
#include "Card.h"
#include "Diller.h"
#include "Player.h"

class Menu
{
private:
	static Menu* _ptr;
	Person** _persons;

	Menu();

	void showRules() const;
	void showMenu();
	void showDeck() const;
	void initPersons();
	void initPlayers();
	void initDiller();
	void initDecks();
	void match();

public:
	~Menu();

	void start();

	static Menu* getReferance();
};
#endif // !Menu_Guardian