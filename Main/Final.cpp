#include <iostream>
using namespace std;

//Завдання 1 <Запитайте у користувача два числа, запишіть їх у змінні а та б, поміняйте місцями значення у цих змінних.>
//Рішення

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

//Завдання 2 <Запитайте у користувача число, порахуйте кількість цифр в ньому.>
//Рішення

void countDigits(int number) {
    int count = 0;
    while (number != 0) {
        count++;
        number /= 10;
    }

    cout << "Кількість цифр у числі: " << count << endl;
}
//Завдання 3 <Користувач вводить з клавіатури кількість студентів, які склали іспит, та кількість «боржників».Обчислити, 
// який відсоток становлять «боржники» від загальної кількості студентів, а також який відсоток становлять студенти, 
// які склали іспит.>
//Рішення

void student(int x, int y) {
    int total = x + y;
    int percentPassed = (x * 100) / total;
    int percentDebtors = (y * 100) / total;
    cout << "Відсоток студентів, які склали іспит: " << percentPassed << "%" << endl;
    cout << "Відсоток боржників: " << percentDebtors << "%" << endl;
}

//Завдання 4 <Створіть масив з 20 елементів, ініціалізуйте масив випадковими числами від - 20 до 20.>
// a. Порахуйте кількість нульових елементів.
// b. Порахуйте середнє значення негативних.
// c. Знайдіть максимальне значення серед позитвних чисел.
//Рішення

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 41 - 20;
    }
    cout << "Масив: ";
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


//Завдання 5 < Створіть двовимірний динамічний масив розміром 5х5:>
//a.Визначіть в якому стовпчику сума елементів є максимальною
//b.Поміняйте місцями 3 та 4 рядок
//c.Зробіть реверс 5 рядку
//Рішення 

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

//Завдання 6 <Створіть динамічний масив та реалізуйте наступні функції:>
//a.Додавання нового елементу з будь - якої позиції
//b.Видалення елементу з будь - якої позиції
//c.Додавання блоку елементів у кінець масиву
//Рішення

int main() {
    setlocale(LC_ALL, "UK_UA");
    /*int a, b;
    cout << "Введіть перше число (a): ";
    cin >> a;
    cout << "Введіть друге число (b): ";
    cin >> b;
    swap(a, b);
    cout << "Після обміну:  " << a << " , " << b << endl*/

    /*int num;
    cout << "Введіть число: ";
    cin >> num;
    countDigits(num);*/

    int x, y;
    cout << "Введіть кількість студентів, які склали іспит: ";
    cin >> x;
    cout << "Введіть кількість боржників: ";
    cin >> y;
    student(x, y);

    /*const int SIZE = 20;
    int array[SIZE];
    srand(time(0));
    fillArray(array, SIZE);
    cout << "Кількість нулів: " << countZeros(array, SIZE) << endl;
    cout << "Середнє значення негативних: " << averageNegative(array, SIZE) << endl;
    cout << "Максимальне серед позитивних: " << maxPositive(array, SIZE) << endl;*/

    /*int** array = createArray(ROWS, COLS);
    fillArray(array, ROWS, COLS);
    cout << "Перший масив:\n";
    printArray(array, ROWS, COLS);
    int maxCol = MaxColumn(array, ROWS, COLS);
    cout << "Стовпчик з максимальною сумою: " << maxCol << endl;
    swapRows(array, 2, 3, COLS);
    cout << "\nПісля обміну 3 та 4 рядка:\n";
    printArray(array, ROWS, COLS);
    reverseRow(array[4], COLS);
    cout << "\nПісля реверсу 5 рядка:\n";
    printArray(array, ROWS, COLS);
    deleteArray(array, ROWS);*/

    
    return 0;
    }




    