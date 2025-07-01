#include <iostream>
using namespace std;

//�������� 1 <��������� � ����������� ��� �����, �������� �� � ���� � �� �, �������� ������ �������� � ��� ������.>
//г�����

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

//�������� 2 <��������� � ����������� �����, ��������� ������� ���� � �����.>
//г�����

void countDigits(int number) {
    int count = 0;
    while (number != 0) {
        count++;
        number /= 10;
    }

    cout << "ʳ������ ���� � ����: " << count << endl;
}
//�������� 3 <���������� ������� � ��������� ������� ��������, �� ������ �����, �� ������� ���������.���������, 
// ���� ������� ���������� ��������� �� �������� ������� ��������, � ����� ���� ������� ���������� ��������, 
// �� ������ �����.>
//г�����

void student(int x, int y) {
    int total = x + y;
    int percentPassed = (x * 100) / total;
    int percentDebtors = (y * 100) / total;
    cout << "³������ ��������, �� ������ �����: " << percentPassed << "%" << endl;
    cout << "³������ ��������: " << percentDebtors << "%" << endl;
}

//�������� 4 <������� ����� � 20 ��������, ����������� ����� ����������� ������� �� - 20 �� 20.>
// a. ��������� ������� �������� ��������.
// b. ��������� ������ �������� ����������.
// c. ������� ����������� �������� ����� ��������� �����.
//г�����

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 41 - 20;
    }
    cout << "�����: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}
int countZeros(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0)
            count++;
    }
    return count;
}

double averageNegative(int arr[], int size) {
    int sum = 0, count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            sum += arr[i];
            count++;
        }
    }
    if (count == 0)
        return 0;
    return static_cast<double>(sum) / count;
}


int maxPositive(int arr[], int size) {
    int max = -21; 

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0 && arr[i] > max) {
            max = arr[i];
        }
    }

    return (max == -21) ? 0 : max; 
}


//�������� 5 < ������� ���������� ��������� ����� ������� 5�5:>
//a.��������� � ����� ��������� ���� �������� � ������������
//b.�������� ������ 3 �� 4 �����
//c.������ ������ 5 �����
//г����� 

const int ROWS = 5;
const int COLS = 5;

int** createArray(int rows, int cols) {
    int** array = new int* [rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }
    return array;
}


void fillArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            array[i][j] = rand() % 10;
}


void printArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << array[i][j] << " ";
        cout << endl;
    }
}


int MaxColumn(int** array, int rows, int cols) {
    int maxSum = -1;
    int maxIndex = -1;
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++)
            sum += array[i][j];
        if (sum > maxSum) {
            maxSum = sum;
            maxIndex = j;
        }
    }
    return maxIndex;
}


void swapRows(int** array, int row1, int row2, int cols) {
    for (int j = 0; j < cols; j++) {
        int temp = array[row1][j];
        array[row1][j] = array[row2][j];
        array[row2][j] = temp;
    }
}


void reverseRow(int* row, int cols) {
    for (int i = 0; i < cols / 2; i++) {
        int temp = row[i];
        row[i] = row[cols - 1 - i];
        row[cols - 1 - i] = temp;
    }
}

void deleteArray(int** array, int rows) {
    for (int i = 0; i < rows; i++)
        delete[] array[i];
    delete[] array;
}

//�������� 6 <������� ��������� ����� �� ��������� ������� �������:>
//a.��������� ������ �������� � ���� - ��� �������
//b.��������� �������� � ���� - ��� �������
//c.��������� ����� �������� � ����� ������
//г�����

int main() {
    setlocale(LC_ALL, "UK_UA");
    /*int a, b;
    cout << "������ ����� ����� (a): ";
    cin >> a;
    cout << "������ ����� ����� (b): ";
    cin >> b;
    swap(a, b);
    cout << "ϳ��� �����:  " << a << " , " << b << endl*/

    /*int num;
    cout << "������ �����: ";
    cin >> num;
    countDigits(num);*/

    int x, y;
    cout << "������ ������� ��������, �� ������ �����: ";
    cin >> x;
    cout << "������ ������� ��������: ";
    cin >> y;
    student(x, y);

    /*const int SIZE = 20;
    int array[SIZE];
    srand(time(0));
    fillArray(array, SIZE);
    cout << "ʳ������ ����: " << countZeros(array, SIZE) << endl;
    cout << "������ �������� ����������: " << averageNegative(array, SIZE) << endl;
    cout << "����������� ����� ����������: " << maxPositive(array, SIZE) << endl;*/

    /*int** array = createArray(ROWS, COLS);
    fillArray(array, ROWS, COLS);
    cout << "������ �����:\n";
    printArray(array, ROWS, COLS);
    int maxCol = MaxColumn(array, ROWS, COLS);
    cout << "�������� � ������������ �����: " << maxCol << endl;
    swapRows(array, 2, 3, COLS);
    cout << "\nϳ��� ����� 3 �� 4 �����:\n";
    printArray(array, ROWS, COLS);
    reverseRow(array[4], COLS);
    cout << "\nϳ��� ������� 5 �����:\n";
    printArray(array, ROWS, COLS);
    deleteArray(array, ROWS);*/

    
    return 0;
    }




    