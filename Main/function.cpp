#include <iostream>
using namespace std;

int square(int x) {
    return x * x;
}

int isEven(int a) {
	return a % 2 == 0;
}
int maxOfTwo(int a, int b) {
	return (a > b) ? a : b;
}
int sumToN(int n) {
	int sum = 0;
	for (int i = 1;i <= n;++i) {
		sum += i;
	}
	return sum;
}

int factorial(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}
int isPrime(int n) {
	if (n <= 1) return 0;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return 0;
	}
	return 1;
}
int sumOfDigits(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int reverseNumber(int n) {
	int reversed = 0;
	int sign = n < 0 ? -1 : 1;
	n = abs(n);

	while (n > 0) {
		int digit = n % 10;           
		reversed = reversed * 10 + digit;  
		n /= 10;                      
	}
	return reversed * sign;
}
int toBinary(int n) {
	int binary = 0;
	int base = 1;
	while (n > 0) {
		int lastDigit = n % 2;
		n /= 2;
		binary += lastDigit * base;
		base *= 10;
	}
	return binary;
}
int power(int base, int exp) {
	int result = 1;
	for (int i = 0; i < exp; ++i) {
		result *= base;
	}
	return result;
}

int fibonacci(int n) {
	if (n <= 1) return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int arraySum(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}
int main() {
	setlocale(LC_ALL, "UK_UA");	
	/*int num;
	cout << "¬вед≥ть число: ";
	cin >> num*/;
	/* cout << " вадрат числа: " << square(num) << endl; */
	
	/*if (isEven(num)) {
		cout << num << " - парне число" << endl;
	}
	else {
		cout << num << " - непарне число" << endl;
	}*/
	/*int a, b;
	cout << "¬вед≥ть два числа: ";
	cin >> a >> b;
	cout << "Ѕ≥льше з двох: " << maxOfTwo(a, b) << endl;*/

	/*int n;
	cout << "¬вед≥ть число:";
	cin >> n;
	cout << "—ума чисел до " <<  << sumToN(n) << endl;*/

	/*int n;
	cout << "¬вед≥ть число:";
	cin >> n;
	cout << "‘актор≥ал:" << factorial(n) << endl;*/

	/*int n;
	cout << "¬вед≥ть число:";
	cin >> n;
	if (isPrime(n)) {
		cout << n << " - просте число" << endl;
	}
	else {
		cout << n << " - не просте число" << endl;
	}*/

	/*int n;
	cout << "¬вед≥ть числа";
	cin >> n;
	cout << "—умма цифр:" << sumOfDigits(n) << endl;*/

	/*int n;
	cout << "¬вед≥ть числа";
	cin >> n;
	cout << "Revers:" << reverseNumber(n) << endl;*/

	/*int n;
	cout << "¬вед≥ть число:";
	cin >> n;
	cout << "ƒв≥йкове представленн€: " << toBinary(n) << endl;*/

	/*int n;
	cout << "¬вед≥ть число:";
	cin >> n;
	cout << "‘≥бонач≥:" << fibonacci(n) << endl;*/

	int arr[] = { 1, 2, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "—ума масиву: " << arraySum(arr, size) << endl;

	return 0;
}
	
