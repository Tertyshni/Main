#include "String.h"
#include <iostream>
using namespace std;

String::String()
{
	data = nullptr;
	length = 0;
}

String::String(const char* str)
{
	length = strlen(str);
	data = new char[length + 1];
	strcpy_s(data, length + 1, str);
}

String::String(const String& other)
{
	length = other.length;
	data = new char[length + 1];
	strcpy_s(data, length + 1, other.data);
}

String& String::operator=(const String& other)
{
	if (this == &other)
		return *this;
	delete[] data;

	length = other.length;
	data = new char[length + 1];
	strcpy(data, other.data);
	return *this;
}

String::~String()
{
	delete[] data;
}

void String::print() const
{
	cout << data << endl;
}
