#pragma once
class Mystring
{
private:
	char* data;
	int length;
public:
	Mystring();
	Mystring(const char* str);
	Mystring(const Mystring& other);
	~Mystring();

	int size() const;
	bool empty() const;
	const char* c_str() const;
	char* at(int index) const;

	void push_back(char c);
	void pop_back();
	void clear();
	void append(const char* str);
	void assign(const char* str);
	int find(char c);
	Mystring substr(size_t pos, size_t count) const;
	Mystring& operator=(const Mystring& other);
	void resize(int newSize);
};
