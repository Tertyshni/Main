#pragma once
class String
{
	char* str;
	int length;
public:
	String();
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	String& operator=(const String& other);
	String& operator=(String&& other);
	String operator*(const String& other) const;
	String operator/(const String& other) const;

	void show() const;
};

