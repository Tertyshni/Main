#include<iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "uk-ua");
    cout << boolalpha;
    int a, b, X;

    cout << "Введите a: ";
    cin >> a;

    cout << "Введите b: ";
    cin >> b;

    if (a > b) {
        X = b - 5 * a;
    }
    else if (a == b) {
        if (a != 0) {
            X = (5 - b) / a;
        }
        else {
            cout << "Помилка: ділення на нуль!" << endl;
            return 1;
        }
    }
    else {
        if (b != 0) {
            X = (a - 5) / b;
        }
        else {
            cout << "Помилка: ділення на нуль!" << endl;
            return 1;
        }
    }

    cout << "Результат X = " << X << endl;

    return 0;
}

#include<iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "uk-ua");
    cout << boolalpha;
    int commodity, cost, discount = 0;

    cout << "Введите кількість товару: ";
    cin >> commodity;

    cout << "Введите вартість: ";
    cin >> cost;

    int all_cost = commodity * cost;

    if (all_cost >= 300) {
        discount = 0.07;
    }
    else if (all_cost >= 200) {
        discount = 0.05;
    }
    else if (all_cost >= 100) {
        discount = 0.03;
    }



    cout << "Загальна вартість: " << all_cost << " грн" << endl;
    cout << "Знижка: " << discount * 100 << "% = " << all_cost << " грн" << endl;
    return 0;
}

#include <iostream>
#include <cmath> 

int main() {
    double number;
    std::cout << "Введіть дробове число: ";
    std::cin >> number;

    if (fabs(number - static_cast<int>(number)) < 1e-9) {
        std::cout << "Десяткова частина дорівнює нулю." << std::endl;
    }
    else {
        std::cout << "Є ненульова десяткова частина." << std::endl;
    }

    return 0;
}

#include <iostream>

int main() {
    int day;
    std::cout << "Введіть номер дня тижня (1-7): ";
    std::cin >> day;

    switch (day) {
    case 1:
        std::cout << "Понеділок" << std::endl;
        break;
    case 2:
        std::cout << "Вівторок" << std::endl;
        break;
    case 3:
        std::cout << "Середа" << std::endl;
        break;
    case 4:
        std::cout << "Четвер" << std::endl;
        break;
    case 5:
        std::cout << "П'ятниця" << std::endl;
        break;
    case 6:
        std::cout << "Субота" << std::endl;
        break;
    case 7:
        std::cout << "Неділя" << std::endl;
        break;
    default:
        std::cout << "Невірний номер дня! Введіть число від 1 до 7." << std::endl;
        break;
    }

    return 0;
}

#include <iostream>

int main() {
    double x, y;
    std::cout << "Введіть координати точки (x y): ";
    std::cin >> x >> y;

    if (x == 0 && y == 0) {
        std::cout << "Точка знаходиться у початку координат." << std::endl;
    }
    else if (x == 0) {
        std::cout << "Точка знаходиться на осі Y." << std::endl;
    }
    else if (y == 0) {
        std::cout << "Точка знаходиться на осі X." << std::endl;
    }
    else if (x > 0 && y > 0) {
        std::cout << "Точка знаходиться у І чверті." << std::endl;
    }
    else if (x < 0 && y > 0) {
        std::cout << "Точка знаходиться у ІІ чверті." << std::endl;
    }
    else if (x < 0 && y < 0) {
        std::cout << "Точка знаходиться у ІІІ чверті." << std::endl;
    }
    else if (x > 0 && y < 0) {
        std::cout << "Точка знаходиться у ІV чверті." << std::endl;
    }

    return 0;
}

#include <iostream>

int main() {
    double uah, result;
    int choice;
    const double EUR_RATE = 41.5; 
    const double USD_RATE = 38.2; 
    const double RUB_RATE = 0.42; 

    std::cout << "Введіть суму в гривнях: ";
    std::cin >> uah;

    if (uah < 0) {
        std::cout << "Сума не може бути від'ємною!" << std::endl;
    }
    else {
        std::cout << "Оберіть валюту для конвертації:" << std::endl;
        std::cout << "1 - Євро" << std::endl;
        std::cout << "2 - Долари США" << std::endl;
        std::cout << "3 - Російські рублі" << std::endl;
        std::cout << "Ваш вибір: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            result = uah / EUR_RATE;
            std::cout << "Сума у євро: " << result << " EUR" << std::endl;
            break;
        case 2:
            result = uah / USD_RATE;
            std::cout << "Сума у доларах США: " << result << " USD" << std::endl;
            break;
        case 3:
            result = uah / RUB_RATE;
            std::cout << "Сума у російських рублях: " << result << " RUB" << std::endl;
            break;
        default:
            std::cout << "Невірний вибір валюти!" << std::endl;
            break;
        }
    }

    return 0;
}
#include <iostream>

int main() {
    int day, month, year;
    int hour, minute, second;
    bool isValid = true;

    std::cout << "Введіть рік: ";
    std::cin >> year;
    std::cout << "Введіть місяць (1-12): ";
    std::cin >> month;
    std::cout << "Введіть день: ";
    std::cin >> day;
    std::cout << "Введіть години (0-23): ";
    std::cin >> hour;
    std::cout << "Введіть хвилини (0-59): ";
    std::cin >> minute;
    std::cout << "Введіть секунди (0-59): ";
    std::cin >> second;

    if (year < 0) {
        isValid = false;
    }

    if (month < 1 || month > 12) {
        isValid = false;
    }

    int maxDays = 31;
    switch (month) {
    case 4: case 6: case 9: case 11:
        maxDays = 30;
        break;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            maxDays = 29;
        else
            maxDays = 28;
        break;
    }

    if (day < 1 || day > maxDays) {
        isValid = false;
    }

  
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
        isValid = false;
    }

   
    if (isValid) {
        std::cout << "Дата і час введені коректно!" << std::endl;
    }
    else {
        std::cout << "Помилка! Невірно введені дані." << std::endl;
    }

    return 0;
}

#include <iostream>

int main() {
    int ticket;
    std::cout << "Введіть номер квитка (6 цифр): ";
    std::cin >> ticket;

    if (ticket < 0 || ticket > 999999) {
        std::cout << "Невірний номер квитка! Він має бути шестизначним." << std::endl;
    }
    else {
        int d1 = (ticket / 100000) % 10;
        int d2 = (ticket / 10000) % 10;
        int d3 = (ticket / 1000) % 10;
        int d4 = (ticket / 100) % 10;
        int d5 = (ticket / 10) % 10;
        int d6 = ticket % 10;

        int sumFirstHalf = d1 + d2 + d3;
        int sumSecondHalf = d4 + d5 + d6;

        if (sumFirstHalf == sumSecondHalf) {
            std::cout << "Квиток щасливий!" << std::endl;
        }
        else {
            std::cout << "Квиток нещасливий." << std::endl;
        }
    }

    return 0;
}

#include <iostream>

int main() {
    int age;
    std::cout << "Введіть ваш вік: ";
    std::cin >> age;

    if (age < 0) {
        std::cout << "Вік не може бути від'ємним!" << std::endl;
    }
    else if (age >= 60) {
        std::cout << "Вам пора на пенсію." << std::endl;
    }
    else {
        std::cout << "Ще зарано на пенсію." << std::endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Введіть порядковий номер карти (від 0 до 35): ";
    cin >> number;

    if (number < 0 || number > 35) {
        cout << "Помилка: номер має бути в межах від 0 до 35!" << endl;
        return 1;
    }

    string suits[] = { "Піки", "Трефи", "Бубни", "Черви" };
    string ranks[] = { "6", "7", "8", "9", "10", "Валет", "Дама", "Король", "Туз" };

    int suit = number / 9;  
    int rank = number % 9;  

    cout << "Ваша карта: " << ranks[rank] << " " << suits[suit] << endl;

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int hours, minutes;

    cout << "Введіть години (0-23): ";
    cin >> hours;
    cout << "Введіть хвилини (0-59): ";
    cin >> minutes;


    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
        cout << "Помилка: невірно введений час!" << endl;
        return 1;
    }

    if (hours >= 5 && hours < 12) {
        cout << "Добрий ранок!" << endl;
    }
    else if (hours >= 12 && hours < 18) {
        cout << "Добрий день!" << endl;
    }
    else if (hours >= 18 && hours < 23) {
        cout << "Добрий вечір!" << endl;
    }
    else {
        cout << "Доброї ночі!" << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int height, weight, idealWeight, difference;

    cout << "Введіть ваш ріст (в сантиметрах): ";
    cin >> height;
    cout << "Введіть вашу вагу (в кілограмах): ";
    cin >> weight;

    idealWeight = height - 110;
    difference = weight - idealWeight;

    cout << "Ідеальна вага для вас: " << idealWeight << " кг." << endl;

    if (difference > 0) {
        cout << "Вам потрібно скинути " << difference << " кг." << endl;
    }
    else if (difference < 0) {
        cout << "Вам потрібно набрати " << -difference << " кг." << endl;
    }
    else {
        cout << "Ваша вага ідеальна!" << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

// Функція перевірки високосного року
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int day, month, year;

    cout << "Введіть день: ";
    cin >> day;
    cout << "Введіть місяць: ";
    cin >> month;
    cout << "Введіть рік: ";
    cin >> year;

  
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31 };


    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    day++;

    if (day > daysInMonth[month - 1]) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    cout << "Наступна дата: " << day << "." << month << "." << year << endl;

    return 0;
}

#include <iostream>
using namespace std;


bool isPrimeDigit(int digit) {
    return (digit == 2 || digit == 3 || digit == 5 || digit == 7);
}

int main() {
    int number;
    cout << "Введіть п'ятизначне число: ";
    cin >> number;

  
    if (number < 10000 || number > 99999) {
        cout << "Помилка: потрібно ввести п'ятизначне число!" << endl;
        return 1;
    }

    bool allPrime = true;

    int temp = number;
    while (temp > 0) {
        int digit = temp % 10;
        if (!isPrimeDigit(digit)) {
            allPrime = false;
            break;
        }
        temp /= 10; 
    }

    if (allPrime) {
        cout << "Усі цифри є простими числами!" << endl;
    }
    else {
        cout << "Не всі цифри є простими числами." << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int year;
    cout << "Введіть рік: ";
    cin >> year;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " рік є високосним." << endl;
    }
    else {
        cout << year << " рік не є високосним." << endl;
    }

    return 0;
}






