#include "Fraction.h"

void Fraction::print() {
	cout << this->numerator_;
	if (this->denominator_ != 1) {
		cout << " / ";
		cout << this->denominator_;
	}
	//cout << endl;
}

Fraction Fraction::sum(Fraction fraction)
{
	Fraction result;
	if (this->denominator_ != fraction.denominator_) {
		result.setNumerator((this->numerator_ * fraction.denominator_) + (fraction.numerator_ * this->denominator_));
		result.setDenominator(this->denominator_ * fraction.denominator_);
		return result;
	}
	result.setNumerator(this->numerator_ + fraction.numerator_);
	result.setDenominator(this->denominator_);
	return result;
}

Fraction Fraction::substr(Fraction fraction)
{
	Fraction result;
	if (this->denominator_ != fraction.denominator_) {
		result.setNumerator((this->numerator_ * fraction.denominator_) - (fraction.numerator_ * this->denominator_));
		result.setDenominator(this->denominator_ * fraction.denominator_);
		return result;
	}
	result.setNumerator(this->numerator_ - fraction.numerator_);
	result.setDenominator(this->denominator_);
	return result;
}

Fraction Fraction::multiply(Fraction fraction)
{
	Fraction result(this->numerator_ * fraction.numerator_, this->denominator_ * fraction.denominator_);
	return result;
}

Fraction Fraction::divide(Fraction fraction)
{
	Fraction result(this->numerator_ * fraction.denominator_, this->denominator_ * fraction.numerator_);
	return result;
}

void Fraction::reduceFraction()
{
	for (int i = minValue(this->numerator_, this->denominator_); i > 0; --i) {
		if (isDivisor(this->numerator_, i) && isDivisor(this->denominator_, i)) {
			this->numerator_ /= i;
			this->denominator_ /= i;
			break;
		}
	}
}