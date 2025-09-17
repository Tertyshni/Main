#include <iostream>
#include "String.h"
using namespace std;

int main() {
	String s1("Hello");
	String s2 = s1;
	s1.print();
	s2.print();
	return 0;
}