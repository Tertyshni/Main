#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <cstdio>
//#include <stdio.h>

using namespace std;

void initArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 1 + rand() % 50;
	}
}

bool printArrayToFile(FILE* descriptor, int arr[], int size) {
	if (descriptor == nullptr) {
		return false;
	}

	for (int i = 0; i < size; i++) {
		fprintf(descriptor, "%i Hello %i", arr[i], i);
		fprintf(descriptor, "\n");
	}
	return true;
}

int main() {
	srand(time(NULL));
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << h << endl;
	/*
	Файл - це іменована область (сукупність даних), що розташована на зовнішньому носії
	інформації(жорсткий диск)
	Властивості:
	ім'я файлу - це унікальне ім'я, яке дає змогу програмам звертатися до файлів.

	довжина файлу - кількість байт. Вона може бути обмеженою тільки обсягом диску.

	"myFile.txt" "myFile.png" - ці файли різні.
	*/

	/*
	Потік - це послідовність байтів, яка не залежить від конкретного пристрою. З послідовністю
	байтів виконується взаємодія(файл, клавіатура, оперативна пам'ять).

	Текстовий потік - це послідовність символів, яка може складатися з одного або декількох
	рядків. Деякі символи, при виводі на екран можуть не відображатися але вони присутні в файлі
	(наприклад: символ нового рядка \n)

	Бінарний потік - це послідовність байтів, які однозначно відповідають тим байтам інформації
	яка зберігається на зовнішноьму носії.

	Режим відкриття файлу - це спеціальная мітка яка вказує на права доступ до файлу.
	r - відкриття текстового файла для читання. Якщо файлу не існує, виводиться помилка -
	Починає читати з початку файлу
	w - Відкриття текстового файлу тільки у режимі запису. Якщо такого файлу не існує, то
	він буде створений. Інакше його вміст буде видалено і файл перезапишеться. - Починає
	з початку файлу
	a - Відкриття текстового файлу для додавання. Якщо такого файлу не існує то він буде
	створений. Інакше запис почнеться з кінця файлу. - З кінця файлу
	r+ - Відкриття текстового файлу у режимі читання плюс запис. Якщо файлу не існує буде помилка
	w+ - Відкриття текстового файлу у режимі читання плюс запис. Якщо файлу не існує він буде створений. Інакше перезапис файл.
	a+ - Відкриття текстового файлу у режимі читайння плюс запис. Якщо файлу не існує, він буде створений. Інакше нові данні будуть додаватися у кінець файлу.
	*/

	/*
	С-style - працюємо зі структурою FILE та функціями
	Cpp-style - класи з наступних бібліоткек fstream -> ifstream -> ofstream
	*/

	/*
	* Обов'язкові дії при роботі з файлами:
	1) Відкриття файлу
	... Ваші дії
	2) Закриття файлу
	*/
	// небезпечна функція
	//FILE* fileDescriptor = fopen("myFile.txt", "r");
	FILE* fileDescriptor = nullptr;


	// відкриття файлу
	//int openResult = fopen_s(&fileDescriptor, "myFile.txt", "a");

	//if (openResult == ENOENT) {
	//	cout << "File is not exist. Please create file";
	//	return 0;
	//}

	//if (openResult == 0) {
	//	cout << "File open success" << endl;
	//	// закриваємо файл
	//	fclose(fileDescriptor);
	//	//cout << "Result: " << openResult << endl;
	//}

	/*FILE
	- дескриптор файлу
	- покажчик на буфер вводу-виводу і поточне місце в ньому
	- лічильник байтів
	- режим відкриття і його поточний стан
	*/

	if ((fileDescriptor = fopen("C:\\Users\\Ukraine\\Desktop\\p-48.txt", "w")) == NULL) {
		cout << "File wasn't successfuly created";
	}
	else {
		cout << "File created!!!" << endl;
		int arr[10];
		initArray(arr, 10);
		bool result = printArrayToFile(fileDescriptor, arr, 10);
		result ? cout << "File write status: \033[42mOK\033[0m\n" : cout << "File write status: \033[41m!OK\033[0m\n";
		fclose(fileDescriptor);
	}

	const char* path = "C:\\Users\\Ukraine\\Desktop\\p-48.txt";



	int openResult = fopen_s(&fileDescriptor, path, "r");
	if (openResult == 0) {
		/*
		char buffer[255];
		while (!feof(fileDescriptor)) {
			fscanf_s(fileDescriptor, "%s", buffer, sizeof(buffer));
			cout << "String: " << buffer << endl;
		}*/
		char line[255];
		while (fgets(line, sizeof(line), fileDescriptor)) {
			cout << line;
		}
		fclose(fileDescriptor);
	}



}