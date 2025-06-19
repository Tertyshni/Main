#include <iostream>
#include "Film.h"
using namespace std;

int main() {
    Film* films = nullptr;
    int filmCount = 0;
    int choice;

    do {
        cout << "\n--- ���� ---\n";
        cout << "1. ������ ����� �����\n";
        cout << "2. ����� ��� ������\n";
        cout << "3. ����� ������ �� ��������\n";
        cout << "4. ��������� ��� ������\n";
        cout << "5. ��������� ������ �� ��������\n";
        cout << "6. ����� ������ (������� ��� ����)\n";
        cout << "7. �����\n";
        cout << "��� ����: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Film f = createNewFilm();
            addFilm(films, filmCount, f);
            break;
        }
        case 2:
            printAllFilms(films, filmCount);
            break;
        case 3: {
            int idx;
            cout << "������ ������ (�� 0): ";
            cin >> idx;
            printFilmByIndex(films, filmCount, idx);
            break;
        }
        case 4:
            deleteAllFilms(films, filmCount);
            break;
        case 5: {
            int idx;
            cout << "������ ������ ��� ���������: ";
            cin >> idx;
            deleteFilmByIndex(films, filmCount, idx);
            break;
        }
        case 6: {
            char dir[256], genre[256];
            cout << "������ �������� ��� ������: ";
            cin.ignore();
            cin.getline(dir, 256);
            cout << "������ ���� ��� ������: ";
            cin.getline(genre, 256);
            findFilms(films, filmCount, dir, genre);
            break;
        }
        case 7:
            deleteAllFilms(films, filmCount);
            cout << "�����...\n";
            break;
        default:
            cout << "������� ����.\n";
        }
    } while (choice != 7);

    return 0;
}