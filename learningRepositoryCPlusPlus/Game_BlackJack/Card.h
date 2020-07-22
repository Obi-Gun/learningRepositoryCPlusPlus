#ifndef Card_Guardian
#define Card_Guardian

enum suit {
	diamonds, hearts, clubs, spades
};

enum type {
	Ace, _2, _3, _4, _5, _6, _7, _8, _9, _10, Jack, Queen, King
};

class Card
{
private:
	suit _suit;
	type _type;
	int _score;

public:
	Card(suit, type, int score);
	~Card();
	
	suit getSuit() const;
	type getType() const;
	int getScore() const;

	void setScore(int);
};
#endif