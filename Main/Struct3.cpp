#include <iostream>
#include "Student.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "UK_UA");
    Student student;
    bool created = false;
    int choice;

    do {
        cout << "\n--- МЕНЮ ---\n";
        cout << "1. Створити студента\n";
        cout << "2. Показати інформацію про студента\n";
        cout << "3. Змінити ім'я\n";
        cout << "4. Змінити прізвище\n";
        cout << "5. Змінити групу\n";
        cout << "6. Змінити оцінку\n";
        cout << "7. Видалити студента\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            if (created) {
                deleteStudent(student);
            }
            char name[100], surname[100];
            int group, mark;

            cout << "Введіть ім'я: ";
            cin.getline(name, 100);
            cout << "Введіть прізвище: ";
            cin.getline(surname, 100);
            cout << "Введіть номер групи: ";
            cin >> group;
            cout << "Введіть оцінку: ";
            cin >> mark;
            cin.ignore();

            student = createNewStudent(name, surname, group, mark);
            created = true;
            break;
        }

        case 2:
            if (created) printStudent(student);
            else cout << "Студент ще не створений!\n";
            break;

        case 3:
            if (created) {
                char newName[100];
                cout << "Нове ім'я: ";
                cin.getline(newName, 100);
                updateName(student, newName);
            }
            else cout << "Студент ще не створений!\n";
            break;

        case 4:
            if (created) {
                char newSurname[100];
                cout << "Нове прізвище: ";
                cin.getline(newSurname, 100);
                updateSurname(student, newSurname);
            }
            else cout << "Студент ще не створений!\n";
            break;

        case 5:
            if (created) {
                int newGroup;
                cout << "Нова група: ";
                cin >> newGroup;
                cin.ignore();
                updateGroup(student, newGroup);
            }
            else cout << "Студент ще не створений!\n";
            break;

        case 6:
            if (created) {
                int newMark;
                cout << "Нова оцінка: ";
                cin >> newMark;
                cin.ignore();
                updateMark(student, newMark);
            }
            else cout << "Студент ще не створений!\n";
            break;

        case 7:
            if (created) {
                deleteStudent(student);
                created = false;
                cout << "Студент видалений.\n";
            }
            else cout << "Студент ще не створений!\n";
            break;

        case 0:
            if (created) deleteStudent(student);
            cout << "Вихід...\n";
            break;

        default:
            cout << "Невірний вибір!\n";
        }

    } while (choice != 0);

    return 0;
}
