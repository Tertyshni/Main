#include <iostream>
#include <cstring>
#include "Film.h"
#include <fstream>

using namespace std;


Film createFilm() {
    Film f;
    char buffer[256];

    cout << "Введіть назву фільму: ";
    cin.ignore();
    cin.getline(buffer, 256);
    copyString(f.title, buffer);

    cout << "Введіть режисера: ";
    cin.getline(buffer, 256);
    copyString(f.director, buffer);

    cout << "Введіть жанр: ";
    cin.getline(buffer, 256);
    copyString(f.genre, buffer);

    cout << "Введіть рік: ";
    cin >> f.year;

    cout << "Введіть тривалість (хв): ";
    cin >> f.duration;

    return f;
}

void copyString(char*& dest, const char* src)
{
}

Film createNewFilm(const char* title, const char* director, const char* genre, int year, int duration)
{
    return Film();
}

Film createNewFilm()
{
    return Film();
}

void printFilm(const Film& f) {
    cout << "Назва: " << f.title << "\n";
    cout << "Режисер: " << f.director << "\n";
    cout << "Жанр: " << f.genre << "\n";
    cout << "Рік: " << f.year << "\n";
    cout << "Тривалість: " << f.duration << " хв\n\n";
}

void deleteFilm(Film& f) {
    delete[] f.title;
    delete[] f.director;
    delete[] f.genre;
}

void printAllFilms(Film* films, int count) {
    if (count == 0) {
        cout << "Бібліотека порожня.\n";
        return;
    }
    for (int i = 0; i < count; ++i) {
        cout << "Фільм #" << i + 1 << ":\n";
        printFilm(films[i]);
    }
}

void deleteAllFilms(Film*& films, int& count) {
    for (int i = 0; i < count; ++i)
        deleteFilm(films[i]);

    delete[] films;
    films = nullptr;
    count = 0;
    cout << "Усі фільми видалено.\n";
}

void addFilm(Film*& films, int& count, const Film& newFilm) {
    Film* temp = new Film[count + 1];
    for (int i = 0; i < count; ++i)
        temp[i] = films[i];

    temp[count] = newFilm;
    delete[] films;
    films = temp;
    count++;
}

void deleteFilmByIndex(Film*& films, int& count, int index) {
    if (index < 0 || index >= count) {
        cout << "Невірний індекс!\n";
        return;
    }

    deleteFilm(films[index]);

    for (int i = index; i < count - 1; ++i)
        films[i] = films[i + 1];

    count--;
    Film* temp = new Film[count];
    for (int i = 0; i < count; ++i)
        temp[i] = films[i];

    delete[] films;
    films = temp;

    cout << "Фільм видалено.\n";
}

void findFilms(Film* films, int count, const char* keyDirector, const char* keyGenre) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if ((strcmp(films[i].director, keyDirector) == 0) ||
            (strcmp(films[i].genre, keyGenre) == 0)) {
            printFilm(films[i]);
            found = true;
        }
    }
    if (!found) cout << "Фільми не знайдено.\n";
}

void printFilmByIndex(Film* films, int count, int index) {
    if (index < 0 || index >= count) {
        cout << "Невірний індекс!\n";
        return;
    }
    printFilm(films[index]);
}

void saveFilmsToFile(Film* films, int count, const char* filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Не вдалося відкрити файл для запису.\n";
        return;
    }

    for (int i = 0; i < count; ++i) {
        file << "------ FILM " << i + 1 << " ------\n";
        file << "Name: " << films[i].title << '\n';
        file << "Date: " << films[i].year << '\n';
        file << "--------------------\n\n";
    }

    file.close();
    cout << "Фільми збережено у файл \"" << filename << "\"\n";
}