#include <iostream>
using namespace std;

int main() {
    const int SIZE = 20;
    int arr[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        arr[i] = (i + 1) * 2;
    }


    for (int index = 0; index < SIZE; index++) {
        printf("array[%i] = %i\n", index, arr[index]);
    }

    return 0;
}


using namespace std;

int main() {
    const int SIZE = 20;
    int arr[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        arr[i] = (i + 1) * -1;
    }


    for (int index = 0; index < SIZE; index++) {
        printf("array[%i] = %i\n", index, arr[index]);
    }

    return 0;
}



#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "UK_UA");
    const int SIZE = 20;
    int arr[SIZE];
    int sum = 0;

    srand(time(0));

    cout << "Масив: ";
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 41 - 20;
        cout << arr[i] << " ";
        sum += arr[i];
    }

    cout << "\nСума всіх елементів: " << sum << endl;

    return 0;
}



using namespace std;

int main() {
    setlocale(LC_ALL, "UK_UA");
    const int SIZE = 20;
    int arr[SIZE];
    int sum = 0;

    srand(time(0));

    cout << "Масив: ";
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 41 - 20;
        cout << arr[i] << " ";
        sum += arr[i] / 20;
    }

    cout << "\nСередне значення всіх елементів: " << sum << endl;

    return 0;
}


using namespace std;

int main() {
    setlocale(LC_ALL, "UK_UA");
    const int SIZE = 10;
    int arr[SIZE] = { 5, 8, 3, 12, 7, 1, 9, 4, 6, 10 };

    int number;
    cout << "Введіть число: ";
    cin >> number;

    bool found = false;

    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] == number) {
            cout << "Число знайдено на індексі: " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Числа не є частиною массива" << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "UK_UA");
    float num[10];
	for (int i = 0; i < 10; i++) {
		cout << "Введіть число: ";
		cin >> num[i];
	}
    float min = num[0];
	for (int i = 0; i < 10; i++) {
		if (num[i] < min) {
			min = num[i];
		}
     float max = num[9];
     for (int i = 0; i < 10; i++) {
         if (num[i] > max) {
            min = num[i];
        }
        cout << "Мінімальне число: " << max << endl;
		cout << "Максимальне число: " << min << endl;
	}
	 return 0;
}
    
#include <iostream>
    using namespace std;

    int main() {
        const int SIZE = 15;
        int arr[SIZE];

        
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i < SIZE; ++i) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }

        
        cout << "Масив чисел Фібоначчі: ";
        for (int i = 0; i < SIZE; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        
        int number;
        cout << "Введіть число: ";
        cin >> number;

        bool found = false;

        for (int i = 0; i < SIZE; ++i) {
            if (arr[i] == number) {
                cout << "Число знайдено на індексі: " << i << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Числа не є частиною массива" << endl;
        }

        return 0;
    }

#include <iostream>
    using namespace std;

    int main() {
        const int size = 5;
        int arr[size] = { 1, 2, 3, 4, 5 };

        cout << "Масив у зворотному порядку: ";
        for (int i = size - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
        return 0;
    }



