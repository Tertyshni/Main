#pragma once
class String
{
private:
	char* data;
	int length;
public:
	String();
	String(const char* str);
	String(const String& other);
	String& operator=(const String& other);
	~String();

	void print() const;


};

