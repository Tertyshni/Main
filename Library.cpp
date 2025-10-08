#include "Library.h"
#include <iostream>
using namespace std;
Library::Library()
{
	size = 0;
	books = nullptr;
}

Library::~Library()
{
	delete[] books;
}

void Library::addBook(const Book& book)
{
	Book* newBooks = new Book[size + 1];
	for (int i = 0; i < size; i++)
	{
		newBooks[i] = books[i];
	}
	newBooks[size] = book;
	delete[] books;
	books = newBooks;
	size++;
}

void Library::removeBook(const char* name)
{
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(books[i].getName(), name) == 0)
		{
			index = i;
			break;
		}
	}
	Book* newBooks = new Book[size - 1];
	for (int i = 0, j = 0; i < size; i++)
	{
		if (i != index)
		{
			newBooks[j++] = books[i];
		}
	}
	delete[] books;
	books = newBooks;
	size--;
}

Book* Library::findBook(const char* name) const
{
	for (int i = 0; i < size; i++){
		if (strcmp(books[i].getName(), name) == 0){
			if (books[i].isOnHand()) {
				return &books[i];
			}
			else {
				cout << "The book is currently borrowed by " << books[i].getBorrower() << endl;
				return nullptr;
			}
		}
	}
	return nullptr;
}

void Library::listAvailableBooks() const
{
	for (int i = 0; i < size; i++)
	{
		if (books[i].isOnHand())
		{
			books[i].printInfo();
			cout << "------------------------" << endl;
		}
	}
}

void Library::listBorrowedBooks() const
{
	for (int i = 0; i < size; i++)
	{
		if (!books[i].isOnHand())
		{
			books[i].printInfo();
			cout << "------------------------" << endl;
		}
	}
}
