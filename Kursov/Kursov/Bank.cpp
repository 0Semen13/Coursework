//Bank.cpp

#include "Bank.h"
#include <iostream>
#include <iomanip>

using namespace std;

Banks::Banks() { //����������� ��� ����������
	name = "No";
	status = "No";
	contribution = "No";
	interest = "No";
	address = "No";
}

void Banks::input() {  //���� ������ � ���������� string
	cout << "������� ������������ ������������� �����: ";
	cin.ignore();
	getline(cin, name, '\n');

	cout << "������� ������ (����� �������������) ������������� ����� ";
	cout << "\n��������: ���������������, �������������, �������, �����������, ���������: ";
	getline(cin, status, '\n');

	cout << "������� ���� ������� ������������� ����� (<= 5) ����� �������: ";
	getline(cin, contribution, '\n');

	cout << "������� ������� �������� ��� ������ ������� (����� ������, ��� ����� %): ";
	getline(cin, interest, '\n');

	cout << "������� ������ ������������� �����: ";
	getline(cin, address, '\n');

	cout << "\n";
}

void Banks::inputMini(string NameTemp, string AddressTemp) {  //���� ������ � ���� �������
	name = NameTemp;
	address = AddressTemp;
}

void Banks::inputAddress(string addr) {  //���� ������ ������ (4)
	address = addr;
}

void Banks::output() {  //����� ������
	cout << "������������: " << name;
	cout << "\n������ (����� �������������): " << status;
	cout << "\n���� �������: " << contribution;
	cout << "\n������� �������� ��� ������ �������: " << interest;
	cout << "\n�����: " << address;
	cout << endl;
}

void Banks::outputName() {  //����� ������������ �����
	cout << name;
}

void Banks::outputMini() {  //����� ���� �������
	cout << "������������: " << name;
	cout << "\n�����: " << address;
	cout << endl;
}

void Banks::diskOut(ofstream& fout) { //���� � ����
	fout << name << endl;
	fout << status << endl;
	fout << contribution << endl;
	fout << interest << endl;
	fout << address << endl;
}

void Banks::diskOut4(ofstream& fout) { //������ � ���� ��� ������
	fout << name << endl;
	fout << status << endl;
	fout << contribution << endl;
	fout << interest << endl;
}

void Banks::diskOutAddress(ofstream& fout) { //������ ������ � ����
	fout << address << endl;
}

void Banks::diskOutMini(ofstream& fout) { //������ ���� ������� � ����
	fout << name << endl;
	fout << address << endl;
}

void Banks::diskIn(ifstream& fin) { //������ �� �����
	getline(fin, name);
	getline(fin, status);
	getline(fin, contribution);
	getline(fin, interest);
	getline(fin, address);
}

void Banks::diskIn4(ifstream& fin) { //������ �� ����� ��� ������
	getline(fin, name);
	getline(fin, status);
	getline(fin, contribution);
	getline(fin, interest);
}

void Banks::diskInMini(ifstream& fin) { //������ ���� ������� �� �����
	getline(fin, name);
	getline(fin, address);
}