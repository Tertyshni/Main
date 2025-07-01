#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <cstdio>
//#include <stdio.h>

using namespace std;

void initArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 1 + rand() % 50;
	}
}

bool printArrayToFile(FILE* descriptor, int arr[], int size) {
	if (descriptor == nullptr) {
		return false;
	}

	for (int i = 0; i < size; i++) {
		fprintf(descriptor, "%i Hello %i", arr[i], i);
		fprintf(descriptor, "\n");
	}
	return true;
}

int main() {
	srand(time(NULL));
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << h << endl;
	/*
	���� - �� ��������� ������� (��������� �����), �� ����������� �� ���������� ���
	����������(�������� ����)
	����������:
	��'� ����� - �� �������� ��'�, ��� �� ����� ��������� ���������� �� �����.

	������� ����� - ������� ����. ���� ���� ���� ��������� ����� ������� �����.

	"myFile.txt" "myFile.png" - �� ����� ���.
	*/

	/*
	���� - �� ����������� �����, ��� �� �������� �� ����������� ��������. � �����������
	����� ���������� �������(����, ���������, ���������� ���'���).

	��������� ���� - �� ����������� �������, ��� ���� ���������� � ������ ��� ��������
	�����. ���� �������, ��� ����� �� ����� ������ �� ������������ ��� ���� ������� � ����
	(���������: ������ ������ ����� \n)

	�������� ���� - �� ����������� �����, �� ���������� ���������� ��� ������ ����������
	��� ���������� �� ���������� ���.

	����� �������� ����� - �� ����������� ���� ��� ����� �� ����� ������ �� �����.
	r - �������� ���������� ����� ��� �������. ���� ����� �� ����, ���������� ������� -
	������ ������ � ������� �����
	w - ³������� ���������� ����� ����� � ����� ������. ���� ������ ����� �� ����, ��
	�� ���� ���������. ������ ���� ���� ���� �������� � ���� ��������������. - ������
	� ������� �����
	a - ³������� ���������� ����� ��� ���������. ���� ������ ����� �� ���� �� �� ����
	���������. ������ ����� ��������� � ���� �����. - � ���� �����
	r+ - ³������� ���������� ����� � ����� ������� ���� �����. ���� ����� �� ���� ���� �������
	w+ - ³������� ���������� ����� � ����� ������� ���� �����. ���� ����� �� ���� �� ���� ���������. ������ ��������� ����.
	a+ - ³������� ���������� ����� � ����� �������� ���� �����. ���� ����� �� ����, �� ���� ���������. ������ ��� ���� ������ ���������� � ����� �����.
	*/

	/*
	�-style - �������� � ���������� FILE �� ���������
	Cpp-style - ����� � ��������� �������� fstream -> ifstream -> ofstream
	*/

	/*
	* ����'����� 䳿 ��� ����� � �������:
	1) ³������� �����
	... ���� 䳿
	2) �������� �����
	*/
	// ���������� �������
	//FILE* fileDescriptor = fopen("myFile.txt", "r");
	FILE* fileDescriptor = nullptr;


	// �������� �����
	//int openResult = fopen_s(&fileDescriptor, "myFile.txt", "a");

	//if (openResult == ENOENT) {
	//	cout << "File is not exist. Please create file";
	//	return 0;
	//}

	//if (openResult == 0) {
	//	cout << "File open success" << endl;
	//	// ��������� ����
	//	fclose(fileDescriptor);
	//	//cout << "Result: " << openResult << endl;
	//}

	/*FILE
	- ���������� �����
	- �������� �� ����� �����-������ � ������� ���� � �����
	- �������� �����
	- ����� �������� � ���� �������� ����
	*/

	if ((fileDescriptor = fopen("C:\\Users\\Ukraine\\Desktop\\p-48.txt", "w")) == NULL) {
		cout << "File wasn't successfuly created";
	}
	else {
		cout << "File created!!!" << endl;
		int arr[10];
		initArray(arr, 10);
		bool result = printArrayToFile(fileDescriptor, arr, 10);
		result ? cout << "File write status: \033[42mOK\033[0m\n" : cout << "File write status: \033[41m!OK\033[0m\n";
		fclose(fileDescriptor);
	}

	const char* path = "C:\\Users\\Ukraine\\Desktop\\p-48.txt";



	int openResult = fopen_s(&fileDescriptor, path, "r");
	if (openResult == 0) {
		/*
		char buffer[255];
		while (!feof(fileDescriptor)) {
			fscanf_s(fileDescriptor, "%s", buffer, sizeof(buffer));
			cout << "String: " << buffer << endl;
		}*/
		char line[255];
		while (fgets(line, sizeof(line), fileDescriptor)) {
			cout << line;
		}
		fclose(fileDescriptor);
	}



}