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

    cout << "Меню:" << endl;
    cout << "1. Видалити останній рядок з файлу" << endl;
    cout << "2. Довжина найдовшого рядка" << endl;
    cout << "3. Порахувати слово у файлі" << endl;
    cout << "4. Знайти і замінити слово" << endl;
    cout << "5. Порівняти два файли" << endl;
    cout << "6. Шифр Цезаря" << endl;
    cout << "Ваш вибір: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case 1:
        cout << "Введіть ім'я вхідного файлу: ";
        getline(cin, file1);
        cout << "Введіть ім'я вихідного файлу: ";
        getline(cin, file2);
        removeLastLine(file1, file2);
        break;
    case 2:
        cout << "Введіть ім'я файлу: ";
        getline(cin, file1);
        cout << "Максимальна довжина рядка: " << longestLineLength(file1) << endl;
        break;
    case 3:
        cout << "Введіть ім'я файлу: ";
        getline(cin, file1);
        cout << "Введіть слово для пошуку: ";
        getline(cin, word);
        cout << "Кількість входжень: " << countWord(file1, word) << endl;
        break;
    case 4:
        cout << "Введіть ім'я вхідного файлу: ";
        getline(cin, file1);
        cout << "Введіть ім'я вихідного файлу: ";
        getline(cin, file2);
        cout << "Що знайти: ";
        getline(cin, search);
        cout << "На що замінити: ";
        getline(cin, replace);
        replaceWord(file1, file2, search, replace);
        break;
    case 5:
        cout << "Введіть ім'я першого файлу: ";
        getline(cin, file1);
        cout << "Введіть ім'я другого файлу: ";
        getline(cin, file2);
        cout << "Введіть ім'я файлу для результату: ";
        getline(cin, file3);
        compareFiles(file1, file2, file3);
        break;
    case 6:
        cout << "Введіть ім'я вхідного файлу: ";
        getline(cin, file1);
        cout << "Введіть ім'я вихідного файлу: ";
        getline(cin, file2);
        cout << "Введіть ключ (число для шифру): ";
        cin >> key;
        caesarEncrypt(file1, file2, key);
        break;
    default:
        cout << "Невірний вибір!" << endl;
    }

    return 0;
}
