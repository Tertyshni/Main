#include "Phone.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
	int choice;
	Phone p;
	do {
		cout << "\nMenu:\n";
		cout << "1. Add Contact\n";
		cout << "2. Delete Contact\n";
		cout << "3. Search by Name\n";
		cout << "4. Show All Contacts\n";
		cout << "5. Save to File\n";
		cout << "6. Load from File\n";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1: {
			char name[100], job[100];
			int homeNumber, workNumber, mobileNumber;
			cout << "Enter Name: ";
			cin.getline(name, 100);
			cout << "Enter Home Number: ";
			cin >> homeNumber;
			cout << "Enter Work Number: ";
			cin >> workNumber;
			cout << "Enter Mobile Number: ";
			cin >> mobileNumber;
			cin.ignore();
			cout << "Enter Job: ";
			cin.getline(job, 100);
			Phone newContact(name, homeNumber, workNumber, mobileNumber, job);
			Phone::addContact(newContact);
			break;
		}
		case 2:
			Phone::deleteContact();
			break;

		case 3: {
			char name[100];
			cout << "Enter Name to Search: ";
			cin.ignore();
			cin.getline(name, 100);
			Phone::searchByName(name);
			break;
		}
		case 4:
			Phone::showAllContacts();
			break;
		case 5: {
			Phone::saveToFile("contacts.txt");
			break;
		}
		case 6: {
			Phone::loadFromFile("contacts.txt");
			break;
		}
		}
	} while (choice != 0);
	return 0;
}
