#ifndef FractionClass
#define FractionClass

class Fraction {
	int _numerator;
	int _denominator;

public:
	Fraction(int numerator, int denominator);
	Fraction();
	Fraction(Fraction& fraction);

	void setNumerator(int numerator);
	void setDenominator(int denominator);

	void print();

	Fraction sum(Fraction fraction);
	Fraction substr(Fraction fraction);
	Fraction multiply(Fraction fraction);
	Fraction divide(Fraction fraction);

	Fraction operator+ (const Fraction& fraction);
	Fraction operator- (const Fraction& fraction);
	Fraction operator* (const Fraction& fraction);
	Fraction operator/ (const Fraction& fraction);

	void reduceFraction();

	~Fraction() {
		//cout << " <> Fraction has been distructed <>\n";
	}
};
#endif