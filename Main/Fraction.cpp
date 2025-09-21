#include "Fraction.h"
#include <iostream>

using namespace std;

Fraction::Fraction(int num, int denom)
{
	numerator = num;
	denominator = denom;
}


int Fraction::getNumerator() const
{
	return numerator;
}

int Fraction::getDenominator() const
{
	return denominator;
}


Fraction Fraction::operator+(const Fraction& other) const
{
	return Fraction(numerator * other.denominator + other.numerator * denominator);
}

Fraction Fraction::operator-(const Fraction& other) const
{
	return Fraction(numerator * other.denominator-other.numerator * denominator);
}

Fraction Fraction::operator*(const Fraction& other) const
{
	return Fraction(numerator * other.numerator);
}

Fraction Fraction::operator/(const Fraction& other) const
{
	return Fraction(numerator * other.denominator);
}

Fraction Fraction::operator+(int value) const
{
	return Fraction(numerator + value * denominator);
}

Fraction Fraction::operator-(int value) const
{
	return Fraction(numerator - value * denominator);
}

Fraction Fraction::operator*(int value) const
{
	return Fraction(numerator * value);
}

Fraction Fraction::operator/(int value) const
{
	return Fraction(numerator / value);
}
