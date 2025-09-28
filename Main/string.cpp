#include "String.h"
#include<iostream>
using namespace std;

String::String()
{
	str = nullptr;
	length = 0;
}

String::String(const char* str)
{
	if (str)
	{
		length = 0;
		while (str[length] != '\0')
			length++;
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
			this->str[i] = str[i];
		this->str[length] = '\0';
	}
	else
	{
		this->str = nullptr;
		length = 0;
	}
}

String::String(const String& other)
{
	length = other.length;
	str = new char[length + 1];
	strcpy(str, other.str);
}

String::String(String&& other)
{
	str = other.str;
	length = other.length;
	other.str = nullptr;
	other.length = 0;
}

String::~String()
{
	delete[] str;
}

String& String::operator=(const String& other)
{
	delete[] str;
	length = other.length;
	str = new char[length + 1];
	strcpy(str, other.str);
	return *this;
}

String& String::operator=(String&& other)
{
	delete[] str;
	str = other.str;
	length = other.length;
	other.str = nullptr;
	other.length = 0;
	return *this;
}

String String::operator*(const String& other) const
{
	String result;
	delete[] result.str;
	result.length = 0;
	result.str = new char[result.length + 1];
	for (int i = 0; i < length; i++) {
		result.str[result.length] = str[i];
	}
	result.length++;
	result.str[result.length] = '\0';
	return result;
}

String String::operator/(const String& other) const
{
	String result;
	delete[] result.str;
	result.length = 0;
	result.str = new char[result.length + 1];
	for (int i = 0; i < length; i++) {
		result.str[result.length] = str[i];
	}
	result.length++;
	result.str[result.length] = '\0';
	return result;
}

void String::show() const
{
	cout << str << endl;
}