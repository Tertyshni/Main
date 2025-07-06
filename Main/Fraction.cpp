#include "Fraction.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int num, int denom) {
	numerator = num;
	denominator = denom;
}

Fraction::Fraction(const Fraction& other) {
	numerator = other.numerator;
	denominator = other.denominator;
}

int Fraction::getNumerator() {
	return numerator;
}
int Fraction::getDenominator() {
	return denominator;
}

void Fraction::setNumerator(int num) {
	numerator = num;
}

void Fraction::setDenominator(int denom) {
	denominator = denom;
}

void Fraction::print() {
	cout << numerator << "/" << denominator << endl;
}
int Fraction::gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
void Fraction::reduce() {
	int g = gcd(abs(numerator), abs(denominator));
	numerator /= g;
	denominator /= g;
	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}
}
bool Fraction::isProper() {
	return abs(numerator) < abs(denominator);
}

Fraction Fraction::operator+(int value) {
	Fraction result(numerator + value * denominator, denominator);
	return result;
}

Fraction Fraction::operator-(int value) {
	Fraction result(numerator - value * denominator, denominator);
	return result;
}

Fraction Fraction::operator*(int value) {
	Fraction result(numerator * value, denominator);
	return result;
}
Fraction Fraction::operator/(int value) {
	Fraction result(numerator, denominator * value);
	return result;
}

Fraction Fraction::operator+(const Fraction& other) {
	Fraction result(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
	result.reduce();
	return result;
}
Fraction Fraction::operator-(const Fraction& other) {
	Fraction result(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
	result.reduce();
	return result;
}

Fraction Fraction::operator*(const Fraction& other) {
	Fraction result(numerator * other.numerator, denominator * other.denominator);
	result.reduce();
	return result;
}

Fraction Fraction::operator/(const Fraction& other) {
	Fraction result(numerator * other.denominator, denominator * other.numerator);
	result.reduce();
	return result;
}