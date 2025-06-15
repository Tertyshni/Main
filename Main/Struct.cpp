#include <iostream>
#include <string>

using namespace std;

struct Point {
	int x,y;
	
};

void printPoint() {
	Point p = { 5, 10 };
	cout << "Point coordinates: (" << p.x << ", " << p.y << ")" << endl;
}

struct Student {
	string name;
	int age;
	float Grade;
};

void printStudent() {
	Student s;
	cout << "Enter student name: ";
	getline(cin, s.name);
	cout << "Enter student age: ";
	cin >> s.age;
	cout << "Enter student grade: ";
	cin >> s.Grade;
	cout << "Student Name: " << s.name << endl;
	cout << "Student Age: " << s.age << endl;
	cout << "Student Grade: " << s.Grade << endl;
}

struct Rectangle {
	int wight, hight;
};

void printRectangle(){
	Rectangle r = { 20, 30 };
	int area = r.wight * r.hight;
	cout << "Area: " << area << endl;
}

struct Time {
	int hour, minute, second;
};

void printTime() {
	Time t = { 12,45,32 };
	cout << "Time: ";
	printf("%02d:%02d:%02d\n", t.hour, t.minute, t.second);
}

struct Car {
	string brand;
	string model;
	int year;
	float price;
};

void printCar() {
	Car c = { "Toyota", "Corolla", 2020, 20000.0f };
	cout << "Car Brand: " << c.brand << endl;
	cout << "Car Model: " << c.model << endl;
	cout << "Car Year: " << c.year << endl;
	cout << "Car Price: $" << c.price << endl;
}

struct Date {
	int day, month, year;
};

void printDate() {
	Date d = { 15, 8, 2023 };
	cout << "Date: " << d.day << "." << d.month << "." << d.year << endl;
}

struct Person {
	string name;
	int age;
	double height;
};

int printPerson() {
	Person p;
	cout << "Enter name: ";
	getline(cin, p.name);
	cout << "Enter age: ";
	cin >> p.age;
	cout << "Enter height: ";
	cin >> p.height;
	cout << "Name: " << p.name << endl;
	cout << "Age: " << p.age << endl;
	cout << "Height: " << p.height << endl;
	return 0;
}

struct Book {
	string title;
	string author;
	int year;

};

void printBook() {
	Book b = { "War and peace", "Leo Tolstoy", 1869 };
	cout << "Book: \"" << b.title << "\" by " << b.author << " (" << b.year << ")" << endl;
}

struct Employee {
	string name;
	string position;
	int salary;
};

void printEmployee() {
	Employee e = { "John Doe", "Software Engineer", 75000 };
	cout << "Employee Name: " << e.name << endl;
	cout << "Position: " << e.position << endl;
	cout << "Salary: $" << e.salary << endl;
}

struct Tringle {
	int a, b, c;
};

void printTringle() {
	Tringle t = { 3, 4, 5 };
	int perimeter = t.a + t.b + t.c;
	cout << "Tringle Perimeter: " << perimeter << endl;
}

int main() {
	printPoint();
	printStudent();
	printRectangle();
	printTime();
	printCar();
	printDate();
	printPerson();
	printBook();
	printEmployee();
	printTringle();
	return 0;
}