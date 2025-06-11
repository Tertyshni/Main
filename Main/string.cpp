#include <iostream>
#include <cstring>
using namespace std;

void removeChar(char *str, char index){
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		str[i] = str[i + 1];
	}
}

void removeAll(char* str, char target) {
	int readIndex = 0;
	int writeIndex = 0;
	while (str[readIndex] != '\0') {
		if (str[readIndex] != target) {
			str[writeIndex++] = str[readIndex];
		}
		readIndex++;
	}
}
void insert(char* str, char symbol, int index) {
	int len = strlen(str);
	for (int i = len; i >= index; i--) {
		str[i + 1] = str[i];
	}
	str[index] = symbol;
}
void replace(char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '.') {
			str[i] = '!';
		}

	}
}

void countChar(const char* str, char symbol) {
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == symbol) {
			count++;
		}
	}
}
void countLetter(const char* str, int& letters, int& digits, int& others) {
	letters = 0;
	digits = 0;
	others = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (isalpha(str[i])) {
			letters++;
		}
		else if (isdigit(str[i])) {
			digits++;
		}
		else {
			others++;
		}
	}
}

int main() {
	setlocale(LC_ALL, "UK_UA");
	/*char str[100];
	cout << "������ �����: ";
	cin.getline(str, 100);
	char index;
	cout << "������ ������ ��� ���������: ";
	cin >> index;
	removeChar(str, index);
	cout << "����� ���� ��������� �������: " << str << endl;
	char target;
	cout << "������ ������ ��� ��������� ��� ��������: ";
	cin >> target;
	removeAll(str, target);
	cout << "����� ���� ��������� ��� �������� �������: " << str << endl;
	char symbol;
	int position;
	cout << "������ ������ ��� �������: ";
	cin >> symbol;
	cout << "������ ������� ��� �������: ";
	cin >> position;
	insert(str, symbol, position);
	cout << "����� ���� ������� �������: " << str << endl;
	replace(str);
	cout << "����� ���� ����� ������ �� ����� ������: " << str << endl;
	char countSymbol;
	cout << "������ ������ ��� ��������� ��������: ";
	cin >> countSymbol;
	countChar(str, countSymbol);*/

	const int SIZE = 256;
	char str[SIZE];
	int letters, digits, others;

	char symbol;

	cout << "������ �����: ";
	cin.getline(str, SIZE);
	countLetter(str, letters, digits, others);
	cout << "ʳ������ ����: " << letters << endl;
	cout << "ʳ������ ����: " << digits << endl;
	cout << "ʳ������ ����� �������: " << others << endl;

	/*cout << "������ ������ ��� ������: ";
	cin >> symbol;

	countChar(str, symbol);
	int result = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == symbol) {
			result++;
		}
	}

	cout << "������ '" << symbol << "' ����������� " << result << " ���(�) � �����." << endl;*/

	return 0;
}
