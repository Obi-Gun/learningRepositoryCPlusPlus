#include "Deck.h"

int Deck::getNumbOfDecks() const
{
	return _numberOfDecks;
}

void Deck::initializeDeck()
{
	_length = _CARDS_IN_DECK * _numberOfDecks;
	_deckOfCards = new int[_length];
	for (int i = 0; i < _length; ++i) {
		_deckOfCards[i] = 0;
	}
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
