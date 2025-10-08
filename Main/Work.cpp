#include <iostream>
#include <cstring>
#include "Library.h"
using namespace std;

int main() {
	Library lib;
	Book book1, book2, book3;
	book1.setName("1984");
	book1.setAuthor("George Orwell");
	book1.setGenre("Dystopian");
	book2.setName("To Kill a Mockingbird");
	book2.setAuthor("Harper Lee");
	book2.setGenre("Fiction");
	book3.setName("The Great Gatsby");
	book3.setAuthor("F. Scott Fitzgerald");
	book3.setGenre("Classic");
	lib.addBook(book1);
	lib.addBook(book2);
	lib.addBook(book3);
	cout << "Available Books:" << endl;
	lib.listAvailableBooks();
	Book* foundBook = lib.findBook("1984");
	if (foundBook) {
		foundBook->borrowBook("Alice");
		cout << "Alice borrowed '1984'" << endl;
	}
	cout << "\nAvailable Books after borrowing '1984':" << endl;
	lib.listAvailableBooks();
	cout << "\nBorrowed Books:" << endl;
	lib.listBorrowedBooks();
	lib.removeBook("To Kill a Mockingbird");
	cout << "\nAvailable Books after removing 'To Kill a Mockingbird':" << endl;
	lib.listAvailableBooks();
	return 0;
}
