//Bank.h

#pragma once

#ifndef BANK_H
#define BANK_H

#include <string>
#include <fstream>

using namespace std;

class Banks {

private:
	string name; //Наименование банка
	string status; //Статус (форма собственности)
	string contribution; //Виды вкладов
	string interest; //Годовые проценты для каждого вида вклада
	string address; //Адрес

public:
	Banks(); //Конструктор без параметров
	void input(); //Ввод данных в переменные string
	void inputAddress(string addr); //Ввод нового адреса (4)
	void inputMini(string NameTemp, string AddressTemp); //Ввод данных в мини таблицу
	void output(); //Вывод данных
	void outputName(); //Вывод наименования банка
	void outputMini(); //Вывод мини таблицы
	void diskOut(ofstream& fout); //Запись в файл
	void diskOut4(ofstream& fout); //Запись в файл без адреса
	void diskOutAddress(ofstream& fout); //Запись адреса в файл
	void diskOutMini(ofstream& fout); //Запись мини таблицы в файл
	void diskIn(ifstream& fin); //Чтение из файла
	void diskIn4(ifstream& fin); //Чтение из файла без адреса
	void diskInMini(ifstream& fin); //Чтение мини таблицы из файла

	string getInterest() { //Получить проценты банка
		return interest;
	}

	string getName() { //Получить наименование банка
		return name;
	}

	string getAddress() { //Получить адрес банка
		return address;
	}
};

#endif // FIGURE_H