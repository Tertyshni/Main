#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {
	Fraction f1(2, 4);
	Fraction f2(3, 5);
	
	Fraction result1 = f1 + f2;
	Fraction result2 = f1 - f2;
	Fraction result3 = f1 * f2;
	Fraction result4 = f1 / f2;
	Fraction result5 = f1 + 2;
	Fraction result6 = f1 - 2;
	Fraction result7 = f1 * 2;
	Fraction result8 = f1 / 2;

	cout << "result1: " << result1.getNumerator() << "/" << result1.getDenominator() << endl;
	cout << "result2: " << result2.getNumerator() << "/" << result2.getDenominator() << endl;
	cout << "result3: " << result3.getNumerator() << "/" << result3.getDenominator() << endl;
	cout << "result4: " << result4.getNumerator() << "/" << result4.getDenominator() << endl;
	cout << "result5: " << result5.getNumerator() << "/" << result5.getDenominator() << endl;
	cout << "result6: " << result6.getNumerator() << "/" << result6.getDenominator() << endl;
	cout << "result7: " << result7.getNumerator() << "/" << result7.getDenominator() << endl;
	cout << "result8: " << result8.getNumerator() << "/" << result8.getDenominator() << endl;
	return 0;
}