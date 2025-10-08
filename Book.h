#pragma once
class Book
{
private:
	char name[50];
	char author[50];
	char genre[50];
	bool onHand;
	char borrower[50];
public:
	Book();
	~Book();
	void setName(const char* name);
	const char* getName() const;
	void setAuthor(const char* author);
	const char* getAuthor() const;
	void setGenre(const char* genre);
	const char* getGenre() const;
	bool isOnHand() const;
	void borrowBook(const char* borrower);
	void returnBook();
	const char* getBorrower() const;
	void printInfo() const;
};

