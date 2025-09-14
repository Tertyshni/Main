#include <iostream>
#include "Mystring.h"
using namespace std;

int main() {
	Mystring s("Hello");
	cout << "s: " << s.c_str() << " size=" << s.size() << endl;
	s.push_back('?');
	cout << "push_back('?'):" << s.c_str() << endl;
	s.pop_back();
	cout << "pop_back():" << s.c_str() << endl;
	s.append(" Tree");
	cout << "append: " << s.c_str() << endl;
	s.assign("New String");
	cout << "assign: " << s.c_str() << endl;
	cout << "find 'S': " << s.find('S') << endl;
	Mystring sub = s.substr(4, 6);
	cout << "substr(4,6): " << sub.c_str() << endl;
	s.resize(5);
	cout << "resize(5): " << s.c_str() << endl;
	s.clear();
	cout << "clear(): " << s.c_str() << " size=" << s.size() << endl;
	return 0;
}