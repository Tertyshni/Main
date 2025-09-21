#include <iostream>
#include "Mystring.h"
using namespace std;

int main() {
	Mystring s("Hello");
	cout << s.c_str() << endl;

	s.push_back('?');
	cout << "Push back: " << s.c_str() << endl;	

	s.pop_back();
	cout << "Pop back: " << s.c_str() << endl;

	s.append(" Tree");
	cout << "Append: " << s.c_str() << endl;

	s.assign("New String");
	cout << "Assign: " << s.c_str() << endl;

	cout << "Find 'S': " << s.find('S') << endl;

	Mystring sub = s.substr(3, 5);
	cout << "Substring(3, 5) : " << sub.c_str() << endl;

	s.resize(5);
	cout << "Resize to 5: " << s.c_str() << endl;

	s.clear();
	cout << "Clear: " << s.c_str() << " size=" << s.size() << endl;

	Mystring s2("Another String");
	s = s2;
	cout << "After assignment: " << s.c_str() << endl;
	return 0;

}