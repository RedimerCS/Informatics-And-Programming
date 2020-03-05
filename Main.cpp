#include <iostream>
#include <fstream>
#include <windows.h>
#include <clocale>
#include "Money.h"


void start(Money& m1)
{
	std::cout << "\n������� � ��� �����? (������� ���-��)\n";
	m1.input();
	m1.print();
}

void startMenu(Money& m1, Money& m2, Money& m3) {
	std::cout <<
		"�������� �������� � ��������:\n" <<
		"1 - ��������� �� ���� (�������)\n" <<
		"2 - ��������� ����� (�������)\n" <<
		"3 - � ���� ������? (��������)\n" <<
		"4 - ������� �� ������� (��������)\n" <<
		"5 - ������ (���������)\n"
		"����: ";
	int menu = 0;
	std::cin >> menu;
	switch (menu)
	{
	case 1:
		system("cls");
		std::cout << "������� ���� � ���: ";
		m1.print();
		std::cout << "������� ������ ����?\n";
		m2.input();
		m3 = m1 + m2;
		m3.print();
		startMenu(m1, m2, m3);
		break;

	case 2:
		system("cls");
		std::cout << "������� ���� � ���: ";
		m1.print();
		std::cout << "����� �����?\n";
		m2.input();
		m3 = m1 - m2;
		m3.print();
		startMenu(m1, m2, m3);
		break;

	case 3:
		system("cls");
		std::cout << "������� ���� � ���: ";
		m1.print();
		std::cout << "������� � ����?\n";
		m2.input();
		if (m1 == m2) { std::cout << "� ��� ������� �������\n"; }
		else { if (m1 != m2) { std::cout << "� ��� �������� ���-�� �������\n"; } }
		startMenu(m1, m2, m3);
		break;

	case 4:
		system("cls");
		int a;
		std::cout << "������� ���� � ���: ";
		m1.print();
		std::cout << "���������\n";
		std::cin >> a;
		m3 = a * m1;
		std::cout << "� ��� ������:";
		m3.print();
		startMenu(m1, m2, m3);
		break;

	case 5:
		system("cls");
		int b;
		std::cout << "������� ���� � ���: ";
		m1.print();
		std::cout << "������� ���� �����?\n";
		std::cin >> b;
		m3 = b / m1;
		std::cout << "� ��� ������:";
		m3.print();
		startMenu(m1, m2, m3);
		break;

	default:
		std::cout << "����� ��� ������ ��������, ������ �� 1 �� 3\n";
		Sleep(1000);
		startMenu(m1, m2, m3);
		break;
	}
}

int main(){
	setlocale(LC_CTYPE, "Russian");

	Money m1, m2, m3;
	start(m1);
	startMenu(m1, m2, m3);

	system("pause");
}
	

