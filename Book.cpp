#include "Book.h"
#include <iostream>
#include <cstring>
using namespace std;
Book::Book()
{
	onHand = true;
	borrower[0] = '\0';
	name[0] = '\0';
	author[0] = '\0';
	genre[0] = '\0';
}

Book::~Book()
{
	delete[] name;
	delete[] author;
	delete[] genre;
	delete[] borrower;
}

void Book::setName(const char* name)
{
	strcpy_s(this->name, name);
}

const char* Book::getName() const
{
	return name;
}

void Book::setAuthor(const char* author)
{
	strcpy_s(this->author, author);
}

const char* Book::getAuthor() const
{
	return author;
}

void Book::setGenre(const char* genre)
{
	strcpy_s(this->genre, genre);
}

const char* Book::getGenre() const
{
	return genre;
}

bool Book::isOnHand() const
{
	return false;
}

void Book::borrowBook(const char* borrower)
{
	onHand = false;
	strcpy_s(this->borrower, borrower);
}

void Book::returnBook()
{
	onHand = true;
	borrower[0] = '\0';
}

const char* Book::getBorrower() const
{
	return borrower;
}

void Book::printInfo() const
{
	cout << "Name: " << name << endl;
	cout << "Author: " << author << endl;
	cout << "Genre: " << genre << endl;
	cout << "On Hand: " << (onHand ? "Yes" : "No") << endl;
	if (!onHand)
	{
		cout << "Borrower: " << borrower << endl;
	}
}
