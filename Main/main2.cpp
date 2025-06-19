#include <iostream>
#include "Film.h"
using namespace std;

int main() {
    Film* films = nullptr;
    int filmCount = 0;
    int choice;

    do {
        cout << "\n--- Меню ---\n";
        cout << "1. Додати новий фільм\n";
        cout << "2. Показ усіх фільмів\n";
        cout << "3. Показ фільму за індексом\n";
        cout << "4. Видалення усіх фільмів\n";
        cout << "5. Видалення фільму за індексом\n";
        cout << "6. Пошук фільмів (режисер або жанр)\n";
        cout << "7. Вихід\n";
        cout << "Ваш вибір: ";
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
            cout << "Введіть індекс (від 0): ";
            cin >> idx;
            printFilmByIndex(films, filmCount, idx);
            break;
        }
        case 4:
            deleteAllFilms(films, filmCount);
            break;
        case 5: {
            int idx;
            cout << "Введіть індекс для видалення: ";
            cin >> idx;
            deleteFilmByIndex(films, filmCount, idx);
            break;
        }
        case 6: {
            char dir[256], genre[256];
            cout << "Введіть режисера для пошуку: ";
            cin.ignore();
            cin.getline(dir, 256);
            cout << "Введіть жанр для пошуку: ";
            cin.getline(genre, 256);
            findFilms(films, filmCount, dir, genre);
            break;
        }
        case 7:
            deleteAllFilms(films, filmCount);
            cout << "Вихід...\n";
            break;
        default:
            cout << "Невірний вибір.\n";
        }
    } while (choice != 7);

    return 0;
}