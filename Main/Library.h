#pragma once
#include<iostream>
#include"Book.h"
class Library
{
private:
	Book* books;
	int size;
public:
	Library();
	~Library();
	void addBook(const Book& book);
	void removeBook(const char* name);
	Book* findBook(const char* name) const;
	void listAvailableBooks() const;
	void listBorrowedBooks() const;
};

