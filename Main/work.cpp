#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "uk-ua");
    int userNumber;


    do {
        cout << "Введіть число (не менше 1): ";
        cin >> userNumber;

        if (userNumber < 1) {
            cout << "Число повинно бути 1 або більше. Спробуйте ще раз.\n";
        }

    } while (userNumber < 1);


    int sum = 0;
    for (int i = 0; i <= userNumber; ++i) {
        sum += i;
    }

    cout << "Сума чисел від 0 до " << userNumber << " дорівнює: " << sum << endl;

    return 0;
}

#include<iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "uk-ua");
    int userNumber;
    do {
        cout << "Введіть число (не менше 1): ";
        cin >> userNumber;

        if (userNumber < 1) {
            cout << "Число повинно бути 1 або більше. Спробуйте ще раз.\n";
        }

    } while (userNumber < 1);
    unsigned long long factorial = 1;
    for (int i = 1; i <= userNumber; ++i) {
        factorial *= i;
    }
    cout << "Факторіал числа " << userNumber << " дорівнює: " << factorial << endl;

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "uk-ua");
    int userNumber;


    do {
        cout << "Введіть число для таблиці множення (не менше 1): ";
        cin >> userNumber;

        if (userNumber < 1) {
            cout << "Число повинно бути 1 або більше. Спробуйте ще раз.\n";
        }

    } while (userNumber < 1);


    cout << "Таблиця множення для " << userNumber << ":\n";
    for (int i = 1; i <= 10; ++i) {
        cout << userNumber << " * " << i << " = " << userNumber * i << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "uk-ua");
    int width;


    do {
        cout << "Введіть ширину лінії (не менше 1): ";
        cin >> width;

        if (width < 1) {
            cout << "Ширина повинна бути не менше 1. Спробуйте ще раз.\n";
        }

    } while (width < 1);


    string textColor = "\033[32m";
    string bgColor = "\033[40m";
    string reset = "\033[0m";

    cout << textColor << bgColor;
    for (int i = 0; i < width; ++i) {
        cout << "#";
    }
    cout << reset << endl;

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "uk-ua");
    int height;


    do {
        cout << "Введіть висоту лінії (не менше 1): ";
        cin >> height;

        if (height < 1) {
            cout << "Висота повинна бути не менше 1. Спробуйте ще раз.\n";
        }

    } while (height < 1);


    string textColor = "\033[32m";
    string bgColor = "\033[40m";
    string reset = "\033[0m";

    for (int i = 0; i < height; ++i) {
        cout << textColor << bgColor << "#\n" << reset;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            cout << i << " * " << j << " = " << i * j << endl;
        }
    }
    return 0;
}
#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }
    return 0;
}

