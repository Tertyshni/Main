#include <iostream>
#include "Fraction.h"
using namespace std;

int main() {  
	setlocale(LC_ALL, "UK_UA");
    Fraction a(2, 5);
	Fraction b(3, 5);

	Fraction result;

	result = a + 1;
    result.reduce();
    cout << "Äð³á + ×èñëî -> Result: ";
    result.print();

    
    result = a + b;
    result.reduce();
    cout << "Äð³á + Äð³á -> Result: ";
    result.print();


    result = a - 1;
    result.reduce();
    cout << "Äð³á - ×èñëî -> Result: ";
    result.print();


    result = a - b;
    result.reduce();
    cout << "Äð³á - Äð³á -> Result: ";
    result.print();


    result = a * 3;
    result.reduce();
    cout << "Äð³á * ×èñëî -> Result: ";
    result.print();

 
    result = a * b;
    result.reduce();
    cout << "Äð³á * Äð³á -> Result: ";
    result.print();

    
    result = a / 2;
    result.reduce();
    cout << "Äð³á / ×èñëî -> Result: ";
    result.print();

    
    result = a / b;
    result.reduce();
    cout << "Äð³á / Äð³á -> Result: ";
    result.print();

    
    cout << "×è ïðàâèëüíèé äð³á a? " << (a.isProper() ? "Òàê" : "Í³") << endl;


}