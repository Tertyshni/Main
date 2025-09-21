#include "Mystring.h"
#include <iostream>
#include <cstring>
using namespace std;
Mystring::Mystring()
{
	data = nullptr;
	length = 0;
}

Mystring::Mystring(const char* str)
{
	if (str)
	{
		length = strlen(str);
		data = new char[length + 1];
		strcpy_s(data, length + 1, str);
	}
	else
	{
		data = nullptr;
		length = 0;
	}
}

Mystring::Mystring(const Mystring& other)
{
	if (other.data)
	{
		length = other.length;
		data = new char[length + 1];
		strcpy_s(data, length + 1, other.data);
	}
	else
	{
		data = nullptr;
		length = 0;
	}
}

Mystring::~Mystring()
{
	delete[] data;


}

int Mystring::size() const
{
	return length;
}

bool Mystring::empty() const
{
	return length == 0;
}

const char* Mystring::c_str() const
{
	return data;
}

char* Mystring::at(int index) const
{
	return data + index;
}

void Mystring::push_back(char c)
{
	char* newData = new char[length + 2];
	strcpy(newData, data);
	newData[length] = c;
	newData[length + 1] = '\0';
	delete[] data;
	data = newData;
	length++;

}

void Mystring::pop_back()
{
	if (length > 0)
	{
		data[length - 1] = '\0';
		length--;
	}
}

void Mystring::clear()
{
	delete[] data;
	data = nullptr;
	length = 0;
}

void Mystring::append(const char* str)
{
	int addLen = strlen(str);
	char* newData = new char[length + addLen + 1];
	strcpy(newData, data);
	strcat(newData, str);
	delete[] data;
	data = newData;
	length += addLen;
}

void Mystring::assign(const char* str)
{
	delete[] data;
	if (str)
	{
		length = strlen(str);
		data = new char[length + 1];
		strcpy_s(data, length + 1, str);
	}
	else
	{
		data = nullptr;
		length = 0;
	}
}

int Mystring::find(char c)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == c)
			return i;

	}
	return -1;
}

Mystring Mystring::substr(size_t pos, size_t count) const
{
	if (pos >= length)
		return Mystring();
	if (pos + count > length)
		count = length - pos;
	char* subData = new char[count + 1];
	strncpy_s(subData, count + 1, data + pos, count);
	subData[count] = '\0';
	Mystring subStr(subData);
	delete[] subData;
	return subStr;
}

Mystring& Mystring::operator=(const Mystring& other)
{
	delete[] data;
	length = other.length;
	data = new char[length + 1];
	strcpy_s(data, length + 1, other.data);
	return *this;
}

void Mystring::resize(int newSize)
{
	char* newData = new char[newSize + 1];
	if (newSize < length)
	{
		strncpy_s(newData, newSize + 1, data, newSize);
		newData[newSize] = '\0';
	}
	else
	{
		strcpy_s(newData, newSize + 1, data);
		for (int i = length; i < newSize; i++)
			newData[i] = '\0';
		newData[newSize] = '\0';
	}
	delete[] data;
	data = newData;
	length = newSize;

}
