#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


void removeLastLine(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile);
    vector<string> lines;
    string line;
    while (getline(in, line)) {
        lines.push_back(line);
    }
    in.close();

    if (!lines.empty()) lines.pop_back();

    ofstream out(outputFile);
    for (const auto& l : lines) {
        out << l << endl;
    }
    out.close();
}


int longestLineLength(const string& filename) {
    ifstream in(filename);
    string line;
    int maxLength = 0;
    while (getline(in, line)) {
        if (line.length() > maxLength)
            maxLength = line.length();
    }
    in.close();
    return maxLength;
}


int countWord(const string& filename, const string& word) {
    ifstream in(filename);
    string str;
    int count = 0;
    while (in >> str) {
        if (str == word)
            count++;
    }
    in.close();
    return count;
}


void replaceWord(const string& inputFile, const string& outputFile, const string& search, const string& replace) {
    ifstream in(inputFile);
    ofstream out(outputFile);
    string line;
    while (getline(in, line)) {
        size_t pos = 0;
        while ((pos = line.find(search, pos)) != string::npos) {
            line.replace(pos, search.length(), replace);
            pos += replace.length();
        }
        out << line << endl;
    }
    in.close();
    out.close();
}


void compareFiles(const string& file1, const string& file2, const string& resultFile) {
    ifstream f1(file1), f2(file2);
    ofstream fout(resultFile);

    string line1, line2;
    while (getline(f1, line1) && getline(f2, line2)) {
        if (line1 != line2) {
            fout << "File1: " << line1 << endl;
            fout << "File2: " << line2 << endl;
        }
    }
    while (getline(f1, line1)) fout << "File1 (extra): " << line1 << endl;
    while (getline(f2, line2)) fout << "File2 (extra): " << line2 << endl;

    f1.close();
    f2.close();
    fout.close();
}


char caesarChar(char c, int key) {
    if ((unsigned char)c < 128 && isalpha(c)) {
        char base = islower(c) ? 'a' : 'A';
        return (char)((c - base + key + 26) % 26 + base); 
    }
    return c;
}

void caesarEncrypt(const string& inputFile, const string& outputFile, int key) {
    ifstream in(inputFile);
    ofstream out(outputFile);
    string line;
    while (getline(in, line)) {
        for (char& c : line) {
            c = caesarChar(c, key);
        }
        out << line << endl;
    }
    in.close();
    out.close();
}


int main() {
	setlocale(LC_ALL, "UK_UA");
    int choice;
    string file1, file2, file3, word, search, replace;
    int key;

    cout << "����:" << endl;
    cout << "1. �������� ������� ����� � �����" << endl;
    cout << "2. ������� ���������� �����" << endl;
    cout << "3. ���������� ����� � ����" << endl;
    cout << "4. ������ � ������� �����" << endl;
    cout << "5. �������� ��� �����" << endl;
    cout << "6. ���� ������" << endl;
    cout << "��� ����: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case 1:
        cout << "������ ��'� �������� �����: ";
        getline(cin, file1);
        cout << "������ ��'� ��������� �����: ";
        getline(cin, file2);
        removeLastLine(file1, file2);
        break;
    case 2:
        cout << "������ ��'� �����: ";
        getline(cin, file1);
        cout << "����������� ������� �����: " << longestLineLength(file1) << endl;
        break;
    case 3:
        cout << "������ ��'� �����: ";
        getline(cin, file1);
        cout << "������ ����� ��� ������: ";
        getline(cin, word);
        cout << "ʳ������ ��������: " << countWord(file1, word) << endl;
        break;
    case 4:
        cout << "������ ��'� �������� �����: ";
        getline(cin, file1);
        cout << "������ ��'� ��������� �����: ";
        getline(cin, file2);
        cout << "�� ������: ";
        getline(cin, search);
        cout << "�� �� �������: ";
        getline(cin, replace);
        replaceWord(file1, file2, search, replace);
        break;
    case 5:
        cout << "������ ��'� ������� �����: ";
        getline(cin, file1);
        cout << "������ ��'� ������� �����: ";
        getline(cin, file2);
        cout << "������ ��'� ����� ��� ����������: ";
        getline(cin, file3);
        compareFiles(file1, file2, file3);
        break;
    case 6:
        cout << "������ ��'� �������� �����: ";
        getline(cin, file1);
        cout << "������ ��'� ��������� �����: ";
        getline(cin, file2);
        cout << "������ ���� (����� ��� �����): ";
        cin >> key;
        caesarEncrypt(file1, file2, key);
        break;
    default:
        cout << "������� ����!" << endl;
    }

    return 0;
}
