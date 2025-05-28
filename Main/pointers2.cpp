#include <iostream>

using namespace std;


void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}


void insertElement(int*& arr, int& size, int value, int index) {
    if (index < 0 || index > size) {
        cout << "Неправильний індекс вставки!" << endl;
        return;
    }

    int* newArr = new int[size + 1];

    for (int i = 0; i < index; ++i)
        newArr[i] = arr[i];

    newArr[index] = value;

    for (int i = index; i < size; ++i)
        newArr[i + 1] = arr[i];

    delete[] arr;
    arr = newArr;
    ++size;
}


void removeElement(int*& arr, int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Неправильний індекс видалення!" << endl;
        return;
    }

    int* newArr = new int[size - 1];

    for (int i = 0; i < index; ++i)
        newArr[i] = arr[i];

    for (int i = index + 1; i < size; ++i)
        newArr[i - 1] = arr[i];

    delete[] arr;
    arr = newArr;
    --size;
}

int main() {
    int* arr = nullptr;
    int size = 0;

    insertElement(arr, size, 10, 0); 
    insertElement(arr, size, 20, 1); 
    insertElement(arr, size, 30, 1); 
    printArray(arr, size);

    removeElement(arr, size, 1);   
    printArray(arr, size);

    insertElement(arr, size, 40, 0); 
    printArray(arr, size);

    delete[] arr; 
    return 0;
}


