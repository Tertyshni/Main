#pragma once
struct Film {
    char* title;      
    char* director;   
    char* genre;     
    int year;        
    int duration;     
};


Film createNewFilm(const char* title, const char* director, const char* genre, int year, int duration);
Film createNewFilm();
void printFilm(const Film& film);
void deleteFilm(Film& film);
void printAllFilms(Film* films, int count);
void deleteAllFilms(Film*& films, int& count);
void addFilm(Film*& films, int& count, const Film& newFilm);
void deleteFilmByIndex(Film*& films, int& count, int index);
void findFilms(Film* films, int count, const char* keyDirector, const char* keyGenre);
void printFilmByIndex(Film* films, int count, int index);

