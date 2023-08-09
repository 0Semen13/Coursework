//Bank.h

#pragma once

#ifndef BANK_H
#define BANK_H

#include <string>
#include <fstream>

using namespace std;

class Banks {

private:
	string name; //������������ �����
	string status; //������ (����� �������������)
	string contribution; //���� �������
	string interest; //������� �������� ��� ������� ���� ������
	string address; //�����

public:
	Banks(); //����������� ��� ����������
	void input(); //���� ������ � ���������� string
	void inputAddress(string addr); //���� ������ ������ (4)
	void inputMini(string NameTemp, string AddressTemp); //���� ������ � ���� �������
	void output(); //����� ������
	void outputName(); //����� ������������ �����
	void outputMini(); //����� ���� �������
	void diskOut(ofstream& fout); //������ � ����
	void diskOut4(ofstream& fout); //������ � ���� ��� ������
	void diskOutAddress(ofstream& fout); //������ ������ � ����
	void diskOutMini(ofstream& fout); //������ ���� ������� � ����
	void diskIn(ifstream& fin); //������ �� �����
	void diskIn4(ifstream& fin); //������ �� ����� ��� ������
	void diskInMini(ifstream& fin); //������ ���� ������� �� �����

	string getInterest() { //�������� �������� �����
		return interest;
	}

	string getName() { //�������� ������������ �����
		return name;
	}

	string getAddress() { //�������� ����� �����
		return address;
	}
};

#endif // FIGURE_H