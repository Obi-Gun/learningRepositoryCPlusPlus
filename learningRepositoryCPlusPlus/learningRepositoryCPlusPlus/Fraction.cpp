#include "Fraction.h"
#include "funcs.h"

Fraction::Fraction(int numerator, int denominator)
{
	this->_numerator = numerator;
	this->_denominator = denominator;
}

Fraction::Fraction()
{
	this->_numerator = 0;
	this->_denominator = 1;
}

Fraction::Fraction(Fraction& fraction)
{
	this->_numerator = fraction._numerator;
	this->_denominator = fraction._denominator;
}

void Fraction::setNumerator(int numerator)
{
	this->_numerator = numerator;
}

void Fraction::setDenominator(int denominator)
{
	this->_denominator = denominator;
}

void Fraction::print() {
	cout << this->_numerator;
	if (this->_denominator != 1) {
		cout << " / ";
		cout << this->_denominator;
	}
	//cout << endl;
}

Fraction Fraction::sum(Fraction fraction)
{
	Fraction result;
	if (this->_denominator != fraction._denominator) {
		result.setNumerator((this->_numerator * fraction._denominator) + (fraction._numerator * this->_denominator));
		result.setDenominator(this->_denominator * fraction._denominator);
		return result;
	}
	result.setNumerator(this->_numerator + fraction._numerator);
	result.setDenominator(this->_denominator);
	return result;
}

Fraction Fraction::substr(Fraction fraction)
{
	Fraction result;
	if (this->_denominator != fraction._denominator) {
		result.setNumerator((this->_numerator * fraction._denominator) - (fraction._numerator * this->_denominator));
		result.setDenominator(this->_denominator * fraction._denominator);
		return result;
	}
	result.setNumerator(this->_numerator - fraction._numerator);
	result.setDenominator(this->_denominator);
	return result;
}

Fraction Fraction::multiply(Fraction fraction)
{
	Fraction result(this->_numerator * fraction._numerator, this->_denominator * fraction._denominator);
	return result;
}

Fraction Fraction::divide(Fraction fraction)
{
	Fraction result(this->_numerator * fraction._denominator, this->_denominator * fraction._numerator);
	return result;
}

Fraction Fraction::operator+(const Fraction& fraction)
{
	Fraction result;
	if (this->_denominator != fraction._denominator) {
		result.setNumerator((this->_numerator * fraction._denominator) + (fraction._numerator * this->_denominator));
		result.setDenominator(this->_denominator * fraction._denominator);
		return result;
	}
	result.setNumerator(this->_numerator + fraction._numerator);
	result.setDenominator(this->_denominator);
	return result;
}

Fraction Fraction::operator-(const Fraction& fraction)
{
	Fraction result;
	if (this->_denominator != fraction._denominator) {
		result.setNumerator((this->_numerator * fraction._denominator) - (fraction._numerator * this->_denominator));
		result.setDenominator(this->_denominator * fraction._denominator);
		return result;
	}
	result.setNumerator(this->_numerator - fraction._numerator);
	result.setDenominator(this->_denominator);
	return result;
}

Fraction Fraction::operator*(const Fraction& fraction)
{
	Fraction result(this->_numerator * fraction._numerator, this->_denominator * fraction._denominator);
	return result;
}

Fraction Fraction::operator/(const Fraction& fraction)
{
	Fraction result(this->_numerator * fraction._denominator, this->_denominator * fraction._numerator);
	return result;
}

void Fraction::reduceFraction()
{
	for (int i = minValue(this->_numerator, this->_denominator); i > 0; --i) {
		if (isDivisor(this->_numerator, i) && isDivisor(this->_denominator, i)) {
			this->_numerator /= i;
			this->_denominator /= i;
			break;
		}
	}
}