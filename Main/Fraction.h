#pragma once
class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction();                       
	Fraction(int, int);              
	Fraction(const Fraction&);

	int getNumerator();
	int getDenominator();
	void setNumerator(int);
	void setDenominator(int);
	void print();
	void reduce();
	bool isProper();
	int gcd(int a, int b);
	Fraction operator+(int);
	Fraction operator+(const Fraction&);

	Fraction operator-(int);
	Fraction operator-(const Fraction&);

	Fraction operator*(int);
	Fraction operator*(const Fraction&);

	Fraction operator/(int);
	Fraction operator/(const Fraction&);
};

