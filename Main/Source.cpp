#include <iostream>
#include <fstream>
#include <cstring>
#include "Phone.h"
using namespace std;
int main() {
	int choice;
	Phone p;
	do {
		cout << "1. Add Contact" << endl;
		cout << "2. Delete Contact" << endl;
		cout << "3. Search by Name" << endl;
		cout << "4. Show All Contacts" << endl;
		cout << "5. Save to File" << endl;
		cout << "6. Load from File" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1: {
			char name[100];
			int homeNumber, workNumber, mobileNumber;
			char job[100];
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
			p.addContact(newContact);
			break;
		}
		case 2:
			p.deleteContact();
			break;
		case 3: {
			char name[100];
			cout << "Enter Name to Search: ";
			cin.getline(name, 100);
			p.searchByName(name);
			break;
		}
		case 4:
			p.showAllContacts();
			break;
		case 5: {
			string filename;
			cout << "Enter filename to save: ";
			cin >> filename;
			p.saveToFile(filename);
			break;
		}
		case 6: {
			string filename;
			cout << "Enter filename to load: ";
			cin >> filename;
			p.loadFromFile(filename);
			break;
		}
		case 0:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice! Please try again." << endl;
		}
	} while (choice != 0);
	
}