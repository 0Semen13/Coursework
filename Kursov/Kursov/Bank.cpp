//Bank.cpp

#include "Bank.h"
#include <iostream>
#include <iomanip>

using namespace std;

Banks::Banks() { //Конструктор без параметров
	name = "No";
	status = "No";
	contribution = "No";
	interest = "No";
	address = "No";
}

void Banks::input() {  //Ввод данных в переменные string
	cout << "Введите наименование коммерческого банка: ";
	cin.ignore();
	getline(cin, name, '\n');

	cout << "Введите статус (форму собственности) коммерческого банка ";
	cout << "\nНапример: Государственный, Муниципальный, Частный, Акционерный, Смешанный: ";
	getline(cin, status, '\n');

	cout << "Введите виды вкладов коммерческого банка (<= 5) через запятую: ";
	getline(cin, contribution, '\n');

	cout << "Введите годовые проценты для разных вкладов (через пробел, без знака %): ";
	getline(cin, interest, '\n');

	cout << "Введите адресс коммерческого банка: ";
	getline(cin, address, '\n');

	cout << "\n";
}

void Banks::inputMini(string NameTemp, string AddressTemp) {  //Ввод данных в мини таблицу
	name = NameTemp;
	address = AddressTemp;
}

void Banks::inputAddress(string addr) {  //Ввод нового адреса (4)
	address = addr;
}

void Banks::output() {  //Вывод данных
	cout << "Наименование: " << name;
	cout << "\nСтатус (форма собственности): " << status;
	cout << "\nВиды вкладов: " << contribution;
	cout << "\nГодовые проценты для разных вкладов: " << interest;
	cout << "\nАдрес: " << address;
	cout << endl;
}

void Banks::outputName() {  //Вывод наименивания банка
	cout << name;
}

void Banks::outputMini() {  //Вывод мини таблицы
	cout << "Наименование: " << name;
	cout << "\nАдрес: " << address;
	cout << endl;
}

void Banks::diskOut(ofstream& fout) { //Ввод в файл
	fout << name << endl;
	fout << status << endl;
	fout << contribution << endl;
	fout << interest << endl;
	fout << address << endl;
}

void Banks::diskOut4(ofstream& fout) { //Запись в файл без адреса
	fout << name << endl;
	fout << status << endl;
	fout << contribution << endl;
	fout << interest << endl;
}

void Banks::diskOutAddress(ofstream& fout) { //Запись адреса в файл
	fout << address << endl;
}

void Banks::diskOutMini(ofstream& fout) { //Запись мини таблицы в файл
	fout << name << endl;
	fout << address << endl;
}

void Banks::diskIn(ifstream& fin) { //Чтение из файла
	getline(fin, name);
	getline(fin, status);
	getline(fin, contribution);
	getline(fin, interest);
	getline(fin, address);
}

void Banks::diskIn4(ifstream& fin) { //Чтение из файла без адреса
	getline(fin, name);
	getline(fin, status);
	getline(fin, contribution);
	getline(fin, interest);
}

void Banks::diskInMini(ifstream& fin) { //Чтение мини таблицы из файла
	getline(fin, name);
	getline(fin, address);
}