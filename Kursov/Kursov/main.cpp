//main.cpp

#include "Bank.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <clocale>
#include <Windows.h>
#include <fcntl.h>
#include <io.h> 
#include <cctype>
#pragma warning(disable : 4996)
#pragma warning(suppress : 4996)

using namespace std;

int Quantity(ifstream& fin, int numb) { //Сколько строк находится в файле (numb)
	char* str = new char[1024];
	while (!fin.eof()) {
		fin.getline(str, 1024, '\n');
		numb++;
	}
	fin.close();
	delete[] str;
	return numb;
}

int main() {
	setlocale(LC_ALL, "RUS");
	setlocale(0, " ");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string filePath = string(getenv("USERPROFILE")) + "\\Desktop" + "\\Справочник коммерческих банков.txt";
	string miniFilePath = string(getenv("USERPROFILE")) + "\\Desktop" + "\\Мини-Справочник коммерческих банков.txt";
	vector<int> percForCompar;
	int mode = 0;
	int N;
	int flag, flag2, flag3 = 0;
	int percent;
	int numb;

	try {
		do {
			cout << "________________________________________________________________________________________________________";
			cout << "\n\n\tВыберете и введите число: ";
			cout << "\n1-Ввести новый коммерческий банк";
			cout << "\n2-Выдать на экран содержимое файла «Справочник коммерческих банков»";
			cout << "\n3-Выдать на экран все наименования коммерческих банков, у которых % годовых не менее заданной величины";
			cout << "\n4-Корректировать адрес коммерческого банка";
			cout << "\n5-Очистить список банков";
			cout << "\n6-Сформировать файл с минимальными данными банков (название, адрес) и вывести его";
			cout << "\n7-Удаление данных банков из списка, у которых % менее заданного";
			cout << "\n8-Выход из программы";
			do {
				flag = 0;
				cout << "\n> ";
				cin >> mode;
				cout << endl;

				if (mode == NULL) {
					throw "\nОшибка формата! Ввод не числа!";
				}
				
				if (mode > 8 || mode < 1) {
					cout << "\aНеобходимо ввести число от 1 до 8!";
				}
			} while (mode > 8 || mode < 1);

			if (mode == 1) {
				Banks* bank = new Banks;

				cout << "Введите данные банка:\n\n";
				bank->input();

				ofstream fout(filePath, ios_base::app);
				bank->diskOut(fout);
				fout.close();

				cout << "Новый коммерческий банк введен и записан в файл «Справочник коммерческих банков»\n";
			}

			if (mode == 2) {
				ifstream fin(filePath);

				if (!fin) {
					throw "\nОшибка: Файл не найден!";
				}
				else if (fin.peek() == EOF) {
					throw "\nОшибка в файле: Файл пустой!";
				}
				else {
					numb = 0;
					N = Quantity(fin, numb) / 5;

					ifstream fin(filePath); //Чтение из файла
					Banks* bank = new Banks[N];
					for (int i = 0; i < N; i++) {
						bank[i].diskIn(fin);
					}
					fin.close();

					cout << "Содержимое файла «Справочник коммерческих банков»: \n\n"; //Вывод данных
					for (int i = 0; i < N; i++) {
						cout << i + 1 << "-й банк: \n";
						bank[i].output();
						cout << endl;
					}
				}
			}

			if (mode == 3) {
				ifstream fin(filePath);

				if (!fin) {
					throw "\nОшибка: Файл не найден!";
				}
				if (fin.peek() == EOF) {
					throw "\nОшибка в файле: Файл пустой!";
				}
				else {
					cout << "Введите процент годовых % для сравнения: ";
					cin >> percent;
					if (percent == NULL) {
						throw "\nОшибка формата!";
					}

					numb = 0;
					N = Quantity(fin, numb) / 5;

					ifstream fin(filePath); //Чтение из файла
					Banks* bank = new Banks[N];
					for (int i = 0; i < N; i++) {
						bank[i].diskIn(fin);
					}
					fin.close();

					flag2 = 0;
					for (int i = 0; i < N; i++) { //Сравнивание процентов банков с заданным
						flag = 0;
						string tp = bank[i].getInterest();
						istringstream is(tp);
						copy(istream_iterator<int>(is), istream_iterator<int>(), back_inserter(percForCompar));
						for (int j = 0; j < percForCompar.size(); j++) {
							if (percForCompar[j] > percent) {
								flag++;
								flag2++;
								break;
							}
						}

						if (flag != 0) { //Вывод наименования банков
							cout << "- ";
							bank[i].outputName();
							cout << endl;
						}
						percForCompar.clear();
					}

					if (flag2 == 0) {
						cout << "\nБанков с годовыми процентами не менее " << percent << " в файле нет!\n";
					}
				}
			}

			if (mode == 4) {
				ifstream fin(filePath);
				if (!fin) {
					throw "\nОшибка: Файл не найден!";
				}
				if (fin.peek() == EOF) {
					throw "\nОшибка в файле: Файл пустой!";
				}
				else {
					numb = 0;
					N = Quantity(fin, numb) / 5;

					ifstream fin(filePath); //Чтение из файла
					Banks* bank = new Banks[N];
					for (int i = 0; i < N; i++) {
						bank[i].diskIn(fin);
					}
					fin.close();

					flag = 0;
					cin.ignore();
					do {
						numb = 0;
						string NameTP;
						NameTP = " ";
						cout << "Введите наименование банка: ";
						getline(cin, NameTP, '\n');

						for (int i = 0; i < N; i++) {
							if (NameTP == bank[i].getName()) { //Удаляем данные из файла
								ifstream fin(filePath);
								ofstream fout;
								fout.open(filePath, ofstream::out | ofstream::trunc);
								fout.close();
								fin.close();
								break;
							}
							else {
								numb++;
								if (numb == N) {
									cout << "\aБанка под таким наименованием не существует!\n\n";
								}
							}
						}

						for (int i = 0; i < N; i++) {
							if (NameTP == bank[i].getName()) { //Вставка нового адреса
								flag = 1;
								string addr;
								cout << "Введите новый адрес банка: ";
								getline(cin, addr, '\n');

								ofstream foutt(filePath, ios_base::app);
								bank[i].diskOut4(foutt);
								bank[i].inputAddress(addr);
								bank[i].diskOutAddress(foutt);
								foutt.close();

								cout << endl;
								cout << "Адрес успешно изменен..." << endl;
							}
							else {
								ofstream fout(filePath, ios_base::app);
								bank[i].diskOut(fout);
								fout.close();
							}
						}
					} while (flag == 0);
				}
			}

			if (mode == 5) {
				ifstream fin(filePath); //Очистка файла
				if (!fin) {
					throw "\nОшибка: Файл не найден!";
				}
				else {
					ofstream fout;
					fout.open(filePath, ofstream::out | ofstream::trunc);
					fout.close();
					cout << "Файл очищен...\n" << endl;
				}
				fin.close();
			}

			if (mode == 6) {
				ifstream fin(filePath);
				if (!fin) {
					throw "\nОшибка: Файл не найден!";
				}
				if (fin.peek() == EOF) {
					throw "\nОшибка в файле: Файл пустой!";
				}
				else {
					ifstream fink(miniFilePath);
					ofstream fout;
					fout.open(miniFilePath, ofstream::out | ofstream::trunc); //ОТкрываем для записи, предварительно очищая его
					fout.close();
					fink.close();

					numb = 0;
					N = Quantity(fin, numb) / 5;

					ifstream finf(filePath);
					Banks* bank = new Banks[N];
					for (int i = 0; i < N; i++) { //Создание и заполняем мини-справочника
						bank[i].diskIn(finf);
						string NameTemp = bank[i].getName();
						string AddressTemp = bank[i].getAddress();
						bank->inputMini(NameTemp, AddressTemp);
						ofstream fout(miniFilePath, ios_base::app);
						bank->diskOutMini(fout);
						fout.close();
					}
					finf.close();

					ifstream fin(miniFilePath);
					if (!fin) {
						throw "\nОшибка: Файл не найден!";
					}
					if (fin.peek() == EOF) {
						throw "\nОшибка в файле: Файл пустой!";
					}
					else {
						cout << "Получившийся файл:";
						numb = 0;
						N = Quantity(fin, numb) / 2;

						ifstream fin(miniFilePath); //Чтение из файла
						Banks* bank = new Banks[N];
						for (int i = 0; i < N; i++) {
							bank[i].diskInMini(fin);
						}
						fin.close();

						cout << "\n\nДанные банков:\n"; //Вывод данных из мини-справочника
						for (int i = 0; i < N; i++) {
							cout << i + 1 << "-й банк: \n";
							bank[i].outputMini();
							cout << endl;
						}

						cout << "\nПечать файла....\n";
						ShellExecuteA(NULL, "print", "Мини-Справочник коммерческих банков.txt", NULL, "C:\\Users\\Semen\\Desktop", SW_HIDE);
					}
				}
			}

			if (mode == 7) {
				ifstream fin(filePath);
				if (!fin) {
					throw "\nОшибка: Файл не найден!";
				}
				else if (fin.peek() == EOF) {
					throw "\nОшибка в файле: Файл пустой!";
				}
				else {
					cout << "Введите процент годовых % для сравнения: ";
					cin >> percent;

					numb = 0;
					N = Quantity(fin, numb) / 5;

					ifstream fin(filePath); //Чтение из файла
					Banks* bank = new Banks[N];
					for (int i = 0; i < N; i++) {
						bank[i].diskIn(fin);
					}

					ofstream fout; //Очищаем файл
					fout.open(filePath, ofstream::out | ofstream::trunc);
					fout.close();
					fin.close();

					flag2 = 0;
					vector<string> lines; //Вектор для процентов банков
					for (int i = 0; i < N; i++) {
						flag = 0;
						string tp = bank[i].getInterest();
						istringstream is(tp);
						copy(istream_iterator<int>(is), istream_iterator<int>(), back_inserter(percForCompar));
						for (int j = 0; j < percForCompar.size(); j++) {
							if (percForCompar[j] < percent) {
								flag++;
								flag2++;
								break;
							}
						}

						if (flag == 0) { //Записываем в файл, если процент банка больше заданного
							ofstream fout(filePath, ios_base::app);
							bank[i].diskOut(fout);
							fout.close();
						}
						percForCompar.clear();
					}

					if (flag2 == 0) {
						cout << "Банка с процентом менее " << percent << " нет!\n";
					}
					else {
						cout << "Банки с процентом менее " << percent << " удалены!\n";
					}
				}
			}
		} while (mode != 8);
	}
	catch (const char* str) {
		cout << str << endl;
	}
}