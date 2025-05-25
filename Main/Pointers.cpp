#include <iostream>
using namespace std;

bool contains(int* arr, int size, int value) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			return true;
		}
	}
	return false;
}

void swapEvenOddIndices(int* arr, int size) {
	
	for (int i = 0; i < size - 1; i += 2) {
		int temp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = temp;
	}
}
void meregeArrays(int* A, int n, int* B, int m, int* C) {
	int* pA = A;
	int* pB = B;
	int* pC = C;
	
	while (pA < A + n && pB < B + m) {
		if (*pA < *pB) {
			*pC++ = *pA++;
		}
		else {
			*pC++ = *pB++;
		}
	}

	while (pA < A + n) {
		*pC++ = *pA++;
	}
	while (pB < B + m) {
		*pC++ = *pB++;
	}
}


int main() {
	setlocale(LC_ALL, "UK_UA");
	/*int arr[] = { 1, 2, 3, 4, 5, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Original array: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	swapEvenOddIndices(arr, size);
	cout << "Array after swapping even and odd indices: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;*/

	/*int A[] = { 1, 3, 5, 7 };
	int B[] = { 2, 4, 6, 8 };
	int n = sizeof(A) / sizeof(A[0]);
	int m = sizeof(B) / sizeof(B[0]);
	int C[n + m];
	meregeArrays(A, n, B, m, C);
	cout << "Merged array: ";
	for (int i = 0; i < n + m; i++) {
		cout << C[i] << " ";
	}
	cout << endl;
	return 0;*/

	int A[] = { 1, 2, 3, 4, 5 };
	int B[] = { 4, 5, 6, 7, 8 };
	int n = sizeof(A) / sizeof(A[0]);
	int m = sizeof(B) / sizeof(B[0]);

	int AB[100], common[100], onlyA[100], onlyB[100], unique[100];
	int abCount = 0, commonCount = 0, onlyACount = 0, onlyBCount = 0, uniqueCount = 0;

	
	for (int* p = A; p < A + n; ++p) {
		AB[abCount++] = *p;
	}
	for (int* p = B; p < B + m; ++p) {
		AB[abCount++] = *p;
	}

	
	for (int* p = A; p < A + n; ++p) {
		if (contains(B, m, *p) && !contains(common, commonCount, *p)) {
			common[commonCount++] = *p;
		}
	}

	
	for (int* p = A; p < A + n; ++p) {
		if (!contains(B, m, *p)) {
			onlyA[onlyACount++] = *p;
		}
	}

	for (int* p = B; p < B + m; ++p) {
		if (!contains(A, n, *p)) {
			onlyB[onlyBCount++] = *p;
		}
	}


	for (int i = 0; i < onlyACount; ++i) {
		unique[uniqueCount++] = onlyA[i];
	}
	for (int i = 0; i < onlyBCount; ++i) {
		unique[uniqueCount++] = onlyB[i];
	}

	
	auto printArray = [](const char* title, int* arr, int size) {
		cout << title;
		for (int* p = arr; p < arr + size; ++p) {
			cout << *p << " ";
		}
		cout << endl;
		};

	printArray("1. Об'єднання A і B: ", AB, abCount);
	printArray("2. Загальні елементи: ", common, commonCount);
	printArray("3. Елементи A, яких немає в B: ", onlyA, onlyACount);
	printArray("4. Елементи B, яких немає в A: ", onlyB, onlyBCount);
	printArray("5. Унікальні елементи (тільки в A або тільки в B): ", unique, uniqueCount);
}