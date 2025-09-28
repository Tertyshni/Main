#include <iostream>
#include "String.h"
using namespace std;

int main() {
	String a("Micrasoft");
	String b("Windows");

	String c = a * b;
	c.show();

	String d = a / b;
	d.show();
	return 0;
}