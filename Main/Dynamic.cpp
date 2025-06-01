#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "UK_UA");
	int size = 5;
	int* arr = new int[size];
	/*for (int i = 0; i < size; i++) {
		arr[i] = (i + 1)* 10;
	}
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += *(arr + i); 
	}
	double average = static_cast<double>(sum) / size;
	cout << "Середнє значення: " << average << endl;*/
	/*cout << "Елементи масиву:";
	for (int i = 0; i < size; i++) {
		*(arr + i) = (i + 1) * 10;
		cout << *(arr + i) << " ";
	}
	cout << "\nМасив у зворотному порядку:";
	for (int i = size - 1; i >= 0; i--) {
		cout << *(arr + i) << " ";
	}*/

	cout << "Початковий масив:";
	for (int i = 0; i < size; i++) {
		*(arr + i) = (i + 1) * 10;
		cout << *(arr + i) << " ";
	}

	/*int index1, index2;
	cout << "\nВведіть індекси для обміну (0-" << size - 1 << "): ";
	cin >> index1 >> index2;
	if (index1 >= 0 && index1 < size && index2 >= 0 && index2 < size) {
		int temp = *(arr + index1);
		*(arr + index1) = *(arr + index2);
		*(arr + index2) = temp;
		cout << "Масив після обміну елементів на індексах " << index1 << " і " << index2 << ": ";
		for (int i = 0; i < size; i++) {
			cout << *(arr + i) << " ";
		}
	}
	else {
		cout << "Неправильні індекси!" << endl;
	}*/

	/*for (int i = 0; i < size / 2; ++i) {
		int temp = *(arr + i);
		*(arr + i) = *(arr + (size - 1 - i));
		*(arr + (size - 1 - i)) = temp;
	}*/

	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1 - i; ++j) {
			if (*(arr + j) > *(arr + j + 1)) {
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
	/*cout << "\nМасив після реверсу:";*/
	cout << "\nВідсортований масив: ";
	for (int i = 0; i < size; i++) {
		cout << *(arr + i) << " ";
	}
	delete[] arr;
	return 0;
}