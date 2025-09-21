#pragma once
class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction(int num = 0, int denom = 1);
	int getNumerator() const;
	int getDenominator() const;
	Fraction operator+(const Fraction& other) const;
	Fraction operator-(const Fraction& other) const;
	Fraction operator*(const Fraction& other) const;
	Fraction operator/(const Fraction& other) const;

	Fraction operator+(int value) const;
	Fraction operator-(int value) const;
	Fraction operator*(int value) const;
	Fraction operator/(int value) const;
};

