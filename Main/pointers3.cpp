#include <iostream>
using namespace std;

void increment(int* ptr) {
	*ptr += 1; 
}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
//int Even(int* arr, int size) {
//	int count = 0;
//	int* end = arr + size;
//
//	while (arr < end) {
//		if (*arr % 2 == 0)
//			++count;
//		++arr; 
//	}
//
//	return count;
//}
//
//int Max(int* arr, int size) {
//	int max = *arr;
//	for (int i = 0; i < size; i++) {
//		if (*(arr + i) > max) {
//			max = *(arr + i);
//		}
//	}
//}

void reverse(int* arr, int size) {
	int* start = arr;
	int* end = arr + size - 1;
	while (start < end) {
		int temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

void print(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

void countElements(int* arr, int size, int* positive, int* negative, int* zero){
	*positive = 0;
	*negative = 0;
	*zero = 0;
	for (int i = 0; i < size; i++) {
		if (*(arr + i) > 0) {
			(*positive)++;
		}
		else if (*(arr + i) < 0) {
			(*negative)++;
		}
		else {
			(*zero)++;

		}
	}

	
}
void replace(int* arr, int size) {
	int* ptr = arr;
	for (int i = 0; i < size; i++) {
		if (*ptr % 2 != 0) {
			*ptr = 0;
		}
		ptr++;
	}
}

void copy(int* source, int* destination, int size) {
	int* scrPtr = source;
	int* destPtr = destination;
	for (int i = 0; i < size; i++) {
		if (*scrPtr % 2 == 0) {
			*destPtr = *scrPtr;
		}
		else {
			*destPtr = 0;
		}
		scrPtr++;
		destPtr++;
	}
}
void bubble(int* arr, int size) {
	for (int* i = arr; i < arr + size - 1; i++) {
		for (int* j = i + 1; j < arr + size; j++) {
			if (*i > *j) {
				int temp = *i;
				*i = *j;
				*j = temp;
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "UK_UA");
	/*int x = 5;
	int* p = &x;
	cout << "значення :" << x << endl;*/

	/*int arr[] = { 1, 2, 3, 4, 5 };
	int* p = arr; 
	for (int i = 0;i < 5;i++) {
		cout <<  *(p + i) << endl;
	}*/
	/*int num;
	cout << "Введіть число: ";
	cin >> num;
	increment(&num);
	cout << "Збільшене число: " << num << endl;*/

	/*int a, b;
	cout << "Введіть два числа: ";
	cin >> a >> b;
	swap(&a, &b);
	cout << "Обмін:" << a << "і" << b << endl;*/

	/*int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* ptr = a;
	int sum = 0;
	for (int i = 0;i < 10; i++) {
		sum += *(ptr + i);
	}
	cout << "Сума:" << sum << endl;*/

	/*int a[] = { 1, 4, 6, 7, 9, 12, 14, 3, 2, 8 };
	int Count = Even(a, 10);
	cout << "Кількість парних елементів: " << Count << endl;*/
	
	/*int arr[] = { 1, 4, 6, 7, 9, 12, 14, 3, 2, 8 };
	int num = Max(arr, 10);
	cout << "Максимальне число: " << num << endl;*/

	/*int arr[] = { 1, 4, 6, 7, 9, 12, 14, 3, 2, 8 };
	cout << "До інверсії: ";
	print(arr, 10);
	reverse(arr, 10);
	
	cout << "Після інверсії: ";
	print(arr, 10);*/

	/*int arr[] = { 1, -2, 3, 0, -5, 6, 0, -8, 9, 10 };
	int pos, neg, zer;
	countElements(arr, 10, &pos, &neg, &zer);
	cout << "Кількість додатних елементів: " << pos << endl;
	cout << "Кількість від'ємних елементів: " << neg << endl;
	cout << "Кількість нульових елементів: " << zer << endl;*/

	/*int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	replace(arr, size);
	cout << "Масив після заміни непарних елементів на нуль: ";
	print(arr, size);
	return 0;*/

	/*int source[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int destination[10];
	int size = sizeof(source) / sizeof(source[0]);
	copy(source, destination, size);
	cout << "Скопійований масив з парними елементами: ";
	print(destination, size);*/

	int arr[] = { 5, 2, 9, 1, 5, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, size);
	cout << "Відсортований масив: ";
	print(arr, size);
	return 0;
}
