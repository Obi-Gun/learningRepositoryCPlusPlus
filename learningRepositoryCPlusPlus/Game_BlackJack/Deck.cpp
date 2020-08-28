#include "Deck.h"

int Deck::getNumbOfDecks() const
{
	return _numberOfDecks;
}

void Deck::initializeDeck()
{
	_deckOfCards = new vector<bool>[_CARDS_IN_DECK * _numberOfDecks];
	_length = _CARDS_IN_DECK * _numberOfDecks;
	_deckOfCards = new int[_length];
	for (int i = 0; i < _length; ++i) {
		_deckOfCards[i] = 0;
	}
}

Card* Deck::giveACard()
{
	int cardNumber;
	do {
		cardNumber = randVal();
	} while (!isCardInDeck(cardNumber));
	_deckOfCards[cardNumber] = true;
	return createCard(cardNumber);
}

Deck::Deck()
{
}

Deck::~Deck()
{
}

bool Deck::setNumberOfDecks(int num)
{
	if (num < 1) {
		_numberOfDecks = _MIN_NUMB_OF_DECKS;
		return false;
	}
	if (num > 8) {
		_numberOfDecks = _MAX_NUMB_OF_DECKS;
		return false;
	}
	_numberOfDecks = num;
	return true;
}
