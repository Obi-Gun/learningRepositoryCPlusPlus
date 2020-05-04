#ifndef FractionClass
#define FractionClass

class Fraction {
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator) {
		this->numerator_ = numerator;
		this->denominator_ = denominator;
	}

	Fraction() {
		this->numerator_ = 0;
		this->denominator_ = 1;
	}

	Fraction(Fraction& fraction) {
		this->numerator_ = fraction.numerator_;
		this->denominator_ = fraction.denominator_;
	}

	void setNumerator(int numerator) {
		this->numerator_ = numerator;
	}

	void setDenominator(int denominator) {
		this->denominator_ = denominator;
	}

	void print();
	Fraction sum(Fraction fraction);
	Fraction substr(Fraction fraction);
	Fraction multiply(Fraction fraction);
	Fraction divide(Fraction fraction);
	void reduceFraction();

	~Fraction() {
		//cout << " <> Fraction has been distructed <>\n";
	}
};
#endif