#include "DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray()
{
	int size = 0;
	int capacity = 10;
	data = new int[capacity];

}

DynamicArray::DynamicArray(int capacity)
{
	int size = 0;
	int capacity = capacity;
	data = new int[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& other)
{
    int size = other.size;
	int capacity = other.capacity;
	data = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

DynamicArray::~DynamicArray()
{
	delete[] data;
}

void DynamicArray::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

void DynamicArray::add(int value)
{
	if (size >= capacity){
		capacity *= 2;
		int* newData = new int[capacity];
		for (int i = 0; i < size; i++){
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		
	}
}

void DynamicArray::remove(int index)
{
	if (index < 0 || index >= size) {
		cout << "Error! " << endl;
		return;
	}
	for (int i = index; i < size - 1; i++) {
		data[i] = data[i + 1];
	}
	size--;
}

int DynamicArray::get(int index)
{
	if (index < 0 || index >= size) {
		cout << "Error! " << endl;
		return -1;
	}
	return data[index];
}

int DynamicArray::size()
{
	return size;
}

int DynamicArray::capacity()
{
	return capacity;
}

int DynamicArray::operator[](int index)
{
	if (index < 0 || index >= size) {
		cout << "Error! " << endl;
		return -1;
	}
	return data[index];
}

DynamicArray& DynamicArray::operator+(const DynamicArray& other)
{
	DynamicArray* newArray = new DynamicArray(size + other.size);
	for (int i = 0; i < size; i++) {
		newArray->add(data[i]);
	}
	for (int i = 0; i < other.size; i++) {
		newArray->add(other.data[i]);
	}
	return *newArray;
	
}

DynamicArray& DynamicArray::operator+=(const DynamicArray& other)
{
	for (int i = 0; i < other.size; i++) {
		add(other.data[i]);
	}
	return *this;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
	if (this != &other) {
		delete[] data;
		size = other.size;
		capacity = other.capacity;
		data = new int[capacity];
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}
	return *this;
}

bool DynamicArray::operator==(const DynamicArray& other)
{
	if (size != other.size) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (data[i] != other.data[i]) {
			return false;
		}
	}
	return true;
}
