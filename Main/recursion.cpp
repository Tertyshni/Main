#include <iostream>
using namespace std;

const int ROW = 3;
const int COL = 4;

void shiftOnce(int arr[ROW][COL]) {
	int temp = arr[0][0];
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (i == ROW - 1 && j == COL - 1) {
				arr[i][j] = temp;
			}
			else if (j == COL - 1) {
				arr[i][j] = arr[i + 1][0];
			}
			else {
				arr[i][j] = arr[i][j + 1];
			}
		}
	}
	
}


void recursiveShiftLeft(int arr[ROW][COL], int row, int col) {
	if (row == ROW) {
		return;
	}
	if (col == COL) {
		recursiveShiftLeft(arr, row + 1, 0);
		return;
	}
	int temp = arr[row][col];
	arr[row][col] = arr[row][col + 1];
	recursiveShiftLeft(arr, row, col + 1);
	arr[ROW - 1][COL - 1] = temp;
}
void recursiveShift(int arr[ROW][COL], int row, int col) {
	if (row == ROW) {
		return;
	}
	if (col == COL) {
		recursiveShift(arr, row + 1, 0);
		return;
	}
	int temp = arr[row][col];
	arr[row][col] = arr[row][col + 1];
	recursiveShift(arr, row, col + 1);
	arr[ROW - 1][COL - 1] = temp;
}
void recursiveShiftRight(int arr[ROW][COL], int row, int col) {
	if (row == ROW) {
		return;
	}
	if (col == 0) {
		recursiveShiftRight(arr, row + 1, COL - 1);
		return;
	}
	int temp = arr[row][col];
	arr[row][col] = arr[row][col - 1];
	recursiveShiftRight(arr, row, col - 1);
	arr[ROW - 1][0] = temp;
}



int binarySearch(int arr[], int left, int right, int x) {
	if (right >= left) {
		int mid = left + (right - left) / 2;
		
		if (arr[mid] == x)
			return mid;
		
		if (arr[mid] > x)
			return binarySearch(arr, left, mid - 1, x);
		return binarySearch(arr, mid + 1, right, x);
	}
	
	return -1;
}

int main()
{
	/*int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 10;
	int result = binarySearch(arr, 0, n - 1, x);
	if (result == -1)
		cout << "Element is not present in array";
	else
		cout << "Element is present at index " << result;*/

	/*int arr[ROW][COL] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
	shiftOnce(arr);
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	recursiveShift(arr, 0, 0);
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/

	int arr[ROW][COL] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
	recursiveShiftLeft(arr, 0, 0);
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	recursiveShiftRight(arr, 0, COL - 1);
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}