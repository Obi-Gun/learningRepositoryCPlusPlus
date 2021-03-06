#include "Menu.h"
using namespace std;

void Menu::showRules() const
{
	cout << "\nWould you like to read rules? (Y / N) ";
	char tmp;
	cin >> tmp;
	if (tmp == 'N' || tmp == 'n') {
		return;
	}
	cout << "\n\n =========================================== ";
	cout << "\n ================== RULES ================== ";
	cout << "\n ===============https://youtu.be/j7IcPS4YQBI ";
	cout << "\n ================== RULES ================== ";
	cout << "\n ================== RULES ================== ";
}

void Menu::showMenu()
{
	cout << "\n\n =========================================== ";
	cout << "\n ================== MENU =================== ";
	cout << "\nEnter how many decks you would like to play with, please: (1-8 decks could be) ";
	int decks;
	cin >> decks;
	if (!_deck->setNumberOfDecks(decks)) {
		cout << "You have entered the wrong number of decks (it should be between 1 and 8).";
		cout << "\nThere are " << _deck->getNumbOfDecks() << " decks will be in this match! Good game for you!";
	}
}

void Menu::showDeck() const
{
	cout << "\n\n =========================================== ";
	cout << "\n ================== DESK =================== ";
}

void Menu::initPlayers()
{
	_players = new Player * [1];
	_players[0] = new Player;
}

void Menu::match()
{
	//makeABet();
	//int cardNum = randVal();
	//while (!isCardInDeck(cardNum)) {
	//	cardNum = randVal();
	//}

}

Menu::Menu()
{
	_deck = new Deck;
	_diller = new Diller;
}

Menu::~Menu()
{
	if (_players) {
		delete[] _players;
	}
	if (_deck) {
		delete _deck;
	}
	if (_diller) {
		delete _diller;
	}
}

void Menu::start()
{
	cout << "\n Nice to meet you Player";
	showRules();
	showMenu();
	initPlayers();
	match();
}