#ifndef Card_Guardian
#define Card_Guardian

enum suit {
	diamonds, hearts, clubs, spades
};

enum type {
	Ace = 11, _2 = 2, _3 = 3, _4 = 4, _5 = 5, _6 = 6, _7 = 7, _8 = 8, _9 = 9, _10 = 10, Jack = 10, Queen = 10, King = 10
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
	void setScore(type);
};
#endif