#pragma once
struct Student {
	char* name;
	char* surname;
	int group;
	int mark;
};

Student createNewStudent(const char* name, const char* surname, int group, int mark);
Student createNewStudent();
void printStudent(const Student& student);
void deleteStudent(Student& student);
void updateName(Student& student, const char* newName);
void updateSurname(Student& student, const char* newSurname);
void updateGroup(Student& student, int newGroup);
void updateMark(Student& student, int newMark);

