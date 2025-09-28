#pragma once
class DynamicArray
{
	int* data;
	int size;
	int capacity;
public:
	DynamicArray();
	DynamicArray(int capacity);
	DynamicArray(const DynamicArray& other);
	~DynamicArray();

	void  print();

	void add(int value);
	void remove(int index);
	int get(int index);
	int size();
	int capacity();

	int operator[](int index);
	DynamicArray& operator+(const DynamicArray& other);
	DynamicArray& operator+=(const DynamicArray& other);
	DynamicArray& operator=(const DynamicArray& other);
	bool operator==(const DynamicArray& other);
};

