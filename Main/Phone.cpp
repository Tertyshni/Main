#include <iostream>
#include <fstream>
#include <cstring>
#include "Phone.h"
using namespace std;

Phone* Phone::contacts = nullptr;
int Phone::size = 0;

Phone::Phone()
{
	name = new char[100];
	job = new char[100];
	strcpy_s(name, 100, "name");
	homeNumber = 0;
	workNumber = 0;
	mobileNumber = 0;
	strcpy_s(job, 100, "job");
}

Phone::Phone(const char* n, int hn, int wn, int mn, const char* j)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
	homeNumber = hn;
	workNumber = wn;
	mobileNumber = mn;
	job = new char[strlen(j) + 1];
	strcpy_s(job, strlen(j) + 1, j);
}

Phone::Phone(const Phone& p)
{
	name = new char[strlen(p.name) + 1];
	strcpy_s(name, strlen(p.name) + 1, p.name);
	homeNumber = p.homeNumber;
	workNumber = p.workNumber;
	mobileNumber = p.mobileNumber;
	job = new char[strlen(p.job) + 1];
	strcpy_s(job, strlen(p.job) + 1, p.job);
}

void Phone::PrintPhone() const
{
	cout << "Name: " << name << endl;
	cout << "Home Number: " << homeNumber << endl;
	cout << "Work Number: " << workNumber << endl;
	cout << "Mobile Number: " << mobileNumber << endl;
	cout << "Job: " << job << endl;
}

char* Phone::getName()
{
	return name;
}

int Phone::getHomeNumber() const
{
	return homeNumber;
}

int Phone::getWorkNumber() const
{
	return workNumber;
}

int Phone::getMobileNumber() const
{
	return mobileNumber;
}

char* Phone::getJob()
{
	return job;
}

void Phone::setName(const char* value)
{
	if (strlen(value) < 1) {
		std::cout << "ERROR! Name length must be greater than 0";
		return;
	}
	strcpy_s(name, 100, value);

}

void Phone::setHomeNumber(int value)
{
	if (value < 0) {
		std::cout << "ERROR! Value must be greater than 0";
		return;
	}
	homeNumber = value;
}

void Phone::setWorkNumber(int value)
{
	if (value < 0) {
		std::cout << "ERROR! Value must be greater than 0";
		return;
	}
	workNumber = value;
}

void Phone::setMobileNumber(int value)
{
	if (value < 0) {
		std::cout << "ERROR! Value must be greater than 0";
		return;
	}
	mobileNumber = value;
}

void Phone::setJob(const char* value)
{
	if (strlen(value) < 1) {
		std::cout << "ERROR! Job length must be greater than 0";
		return;
	}
	strcpy_s(job, 100, value);
}

void Phone::show() const
{
	cout << "Name: " << name << endl;
	cout << "Home Number: " << homeNumber << endl;
	cout << "Work Number: " << workNumber << endl;
	cout << "Mobile Number: " << mobileNumber << endl;
	cout << "Job: " << job << endl;
}

void Phone::save(ofstream& fout) const
{
	fout << name << endl;
	fout << homeNumber << endl;
	fout << workNumber << endl;
	fout << mobileNumber << endl;
	fout << job << endl;
}



void Phone::load(ifstream& fin)
{
	fin.getline(name, 100);
	fin >> homeNumber;
	fin >> workNumber;
	fin >> mobileNumber;
	fin.ignore();
	fin.getline(job, 100);
}

void Phone::addContact(const Phone& c)
{
	Phone* newContacts = new Phone[size + 1];
	for (int i = 0; i < size; i++) {
		newContacts[i] = contacts[i];
	}
	newContacts[size] = c;
	delete[] contacts;
	contacts = newContacts;
	size++;
}

void Phone::deleteContact()
{
	if (size == 0) {
		cout << "No contacts to delete!" << endl;
		return;
	}
	size--;
	Phone* newContacts = new Phone[size];
	for (int i = 0; i < size; i++) {
		newContacts[i] = contacts[i];
	}
	delete[] contacts;
	contacts = newContacts;
}




void Phone::searchByName(const char* n)
{
	for (int i = 0; i < size; i++) {
		if (strcmp(contacts[i].getName(), n) == 0) {
			contacts[i].show();
			return;
		}
	}

}

void Phone::showAllContacts()
{
	for (int i = 0; i < size; i++) {
		contacts[i].show();
	}
}

void Phone::saveToFile(const char* file)
{
	ofstream fout(file);
	if (!fout.is_open()) {
		cout << "Error opening file for writing!" << endl;
		return;
	}
	fout << size << endl;
	for (int i = 0; i < size; i++) {
		contacts[i].save(fout);
	}
	fout.close();
}

void Phone::loadFromFile(const char* file)
{
	ifstream fin(file);
	if (!fin.is_open()) {
		cout << "Error opening file for reading!" << endl;
		return;
	}
	fin >> size;
	fin.ignore();
	delete[] contacts;
	contacts = new Phone[size];
	for (int i = 0; i < size; i++) {
		contacts[i].load(fin);
	}
	fin.close();
}

Phone::~Phone()
{
	delete[] name;
	delete[] job;
	delete[] contacts;
}

