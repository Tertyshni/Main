#include <iostream>
#include "Student.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "UK_UA");
    Student student;
    bool created = false;
    int choice;

    do {
        cout << "\n--- ���� ---\n";
        cout << "1. �������� ��������\n";
        cout << "2. �������� ���������� ��� ��������\n";
        cout << "3. ������ ��'�\n";
        cout << "4. ������ �������\n";
        cout << "5. ������ �����\n";
        cout << "6. ������ ������\n";
        cout << "7. �������� ��������\n";
        cout << "0. �����\n";
        cout << "��� ����: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            if (created) {
                deleteStudent(student);
            }
            char name[100], surname[100];
            int group, mark;

            cout << "������ ��'�: ";
            cin.getline(name, 100);
            cout << "������ �������: ";
            cin.getline(surname, 100);
            cout << "������ ����� �����: ";
            cin >> group;
            cout << "������ ������: ";
            cin >> mark;
            cin.ignore();

            student = createNewStudent(name, surname, group, mark);
            created = true;
            break;
        }

        case 2:
            if (created) printStudent(student);
            else cout << "������� �� �� ���������!\n";
            break;

        case 3:
            if (created) {
                char newName[100];
                cout << "���� ��'�: ";
                cin.getline(newName, 100);
                updateName(student, newName);
            }
            else cout << "������� �� �� ���������!\n";
            break;

        case 4:
            if (created) {
                char newSurname[100];
                cout << "���� �������: ";
                cin.getline(newSurname, 100);
                updateSurname(student, newSurname);
            }
            else cout << "������� �� �� ���������!\n";
            break;

        case 5:
            if (created) {
                int newGroup;
                cout << "���� �����: ";
                cin >> newGroup;
                cin.ignore();
                updateGroup(student, newGroup);
            }
            else cout << "������� �� �� ���������!\n";
            break;

        case 6:
            if (created) {
                int newMark;
                cout << "���� ������: ";
                cin >> newMark;
                cin.ignore();
                updateMark(student, newMark);
            }
            else cout << "������� �� �� ���������!\n";
            break;

        case 7:
            if (created) {
                deleteStudent(student);
                created = false;
                cout << "������� ���������.\n";
            }
            else cout << "������� �� �� ���������!\n";
            break;

        case 0:
            if (created) deleteStudent(student);
            cout << "�����...\n";
            break;

        default:
            cout << "������� ����!\n";
        }

    } while (choice != 0);

    return 0;
}
