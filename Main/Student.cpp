#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <iostream>
#include <cstring>

using namespace std;

Student createNewStudent(const char* name, const char* surname, int group, int mark)
{
	Student student;
	student.name = new char[strlen(name) + 1];
	strcpy_s(student.name, strlen(name) + 1, name);
	student.surname = new char[strlen(surname) + 1];
	strcpy_s(student.surname, strlen(surname) + 1, surname);
	student.group = group;
	student.mark = mark;
	return student;
}

Student createNewStudent()
{
	return Student();
}

void deleteStudent(Student& student) {
	delete[] student.name;
	delete[] student.surname;
	student.name = nullptr;
	student.surname = nullptr;
	student.group = 0;
	student.mark = 0;
}

void printStudent(const Student& student) {
	cout << "Name:" << student.name << endl;
	cout << "Surname:" << student.surname << endl;
	cout << "Group:" << student.group << endl;
	cout << "Mark:" << student.mark << endl;
}

void updateName(Student& student, const char* newName) {
	delete[] student.name;
	student.name = new char[strlen(newName) + 1];
	strcpy(student.name, newName);
}

void updateSurname(Student& student, const char* newSurname) {
	delete[] student.surname;
	student.surname = new char[strlen(newSurname) + 1];
	strcpy(student.surname, newSurname);
}

void updateGroup(Student& student, int newGroup) {
	student.group = newGroup;
}
void updateMark(Student& student, int newMark) {
	student.mark = newMark;
}