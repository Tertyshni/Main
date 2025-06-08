#include <iostream>
using namespace std;

void Block(int*& arr, int& size, const int* block, int blockSize) {
	int* newArr = new int[size + blockSize];
	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}

	for (int i = 0; i < blockSize; i++) {
		newArr[size + i] = block[i];
	}

	delete[] arr;
	arr = newArr;
	size += blockSize;
}

void insertBlock(int* arr, int size,int index,int* block, int blockSize,int* newArr){
	
	for (int i = 0; i < index; ++i) {
		newArr[i] = arr[i];
	}

	
	for (int i = 0; i < blockSize; ++i) {
		newArr[index + i] = block[i];
	}

	
	for (int i = index; i < size; ++i) {
		newArr[blockSize + i] = arr[i];
	}
}
void deleteBlock(int* arr, int size, int index, int blockSize, int* newArr) {
	for (int i = 0; i < index; ++i) {
		newArr[i] = arr[i];
	}
	for (int i = index + blockSize; i < size; ++i) {
		newArr[i - blockSize] = arr[i];
	}
}

int main() {
	setlocale(LC_ALL, "UK_UA");
	/*int n;
	cout << "Введіть розмір масиву: ";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Введіть елемент" << i + 1 << ":";
		cin >> *(arr + i);
	}
	int index;
	cout << "Індекс який потрібно видалити:";
	cin >> index;
	

	int* newArr = new int[n - 1];
	for (int i = 0, j = 0; i < n; i++) {
		if (i!= index) {
			newArr[j++] = arr[i];
		}
	}

	int negative = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			negative++;
		}
	}

	int* negativeArr = new int[negative];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			negativeArr[j++] = arr[i];
		}
	}

	cout << "Новий масив:";
	for (int i = 0; i < n - 1; i++) {
		cout << *(newArr + i) << " ";
	}

	cout << "\nМасив від'ємних елементів:";
	for (int i = 0; i < negative; i++) {
		cout << *(negativeArr + i) << " ";
	}*/

	/*int size;
	cout << "Введіть розмір масиву: ";
	cin >> size;

	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "Введіть елемент " << i + 1 << ": ";
		cin >> arr[i];
	}

	int blockSize;
	cout << "Введіть кількість елементів у блоці: ";
	cin >> blockSize;

	int* block = new int[blockSize];
	for (int i = 0; i < blockSize; i++) {
		cout << "Введіть елемент блоку " << i + 1 << ": ";
		cin >> block[i];
	}

	Block(arr, size, block, blockSize);
	cout << "Новий масив : ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}*/

	/*int arr[] = { 1, 2, 3, 7, 8 };
	int block[] = { 4, 5, 6 };
	int size = 5;
	int blockSize = 3;
	int insertIndex = 3;
	int newSize = size + blockSize;

	int* newArr = new int[newSize];

	insertBlock(arr, size, insertIndex, block, blockSize, newArr);
	for (int i = 0; i < newSize; ++i) {
		cout << newArr[i] << " ";
	}*/

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int size = 8;
	int index = 2; 
	int blockSize = 3; 
	int* newArr = new int[size - blockSize];
	deleteBlock(arr, size, index, blockSize, newArr);
	cout << "Новий масив після видалення блоку: ";
	for (int i = 0; i < size - blockSize; ++i) {
		cout << newArr[i] << " ";
	}

	



	




	delete[] arr;
	/*delete[] block;*/
	delete[] newArr;
	/*delete[] negativeArr;*/
	return 0;
}