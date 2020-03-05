#include <iostream>
#include <fstream>
#include <windows.h>
#include <clocale>
#include "Money.h"


void start(Money& m1)
{
	std::cout << "\nСколько у вас денег? (введите кол-во)\n";
	m1.input();
	m1.print();
}

void startMenu(Money& m1, Money& m2, Money& m3) {
	std::cout <<
		"Выберите действия с шекелями:\n" <<
		"1 - Скинуться на пиво (сложить)\n" <<
		"2 - Заплатить налог (вычесть)\n" <<
		"3 - У кого больше? (сравнить)\n" <<
		"4 - Поднять на ставках (умножить)\n" <<
		"5 - Выжить (разделить)\n"
		"Ввод: ";
	int menu = 0;
	std::cin >> menu;
	switch (menu)
	{
	case 1:
		system("cls");
		std::cout << "Сколько есть у вас: ";
		m1.print();
		std::cout << "Сколько скинет Дима?\n";
		m2.input();
		m3 = m1 + m2;
		m3.print();
		startMenu(m1, m2, m3);
		break;

	case 2:
		system("cls");
		std::cout << "Сколько есть у вас: ";
		m1.print();
		std::cout << "Какой налог?\n";
		m2.input();
		m3 = m1 - m2;
		m3.print();
		startMenu(m1, m2, m3);
		break;

	case 3:
		system("cls");
		std::cout << "Сколько есть у вас: ";
		m1.print();
		std::cout << "Сколько у Димы?\n";
		m2.input();
		if (m1 == m2) { std::cout << "У вас поровну шекелей\n"; }
		else { if (m1 != m2) { std::cout << "У вас неравное кол-во шекелей\n"; } }
		startMenu(m1, m2, m3);
		break;

	case 4:
		system("cls");
		int a;
		std::cout << "Сколько есть у вас: ";
		m1.print();
		std::cout << "Коэфицент\n";
		std::cin >> a;
		m3 = a * m1;
		std::cout << "У вас теперь:";
		m3.print();
		startMenu(m1, m2, m3);
		break;

	case 5:
		system("cls");
		int b;
		std::cout << "Сколько есть у вас: ";
		m1.print();
		std::cout << "Сколько дней живем?\n";
		std::cin >> b;
		m3 = b / m1;
		std::cout << "У вас теперь:";
		m3.print();
		startMenu(m1, m2, m3);
		break;

	default:
		std::cout << "Здесь нет других действий, жмякай от 1 до 3\n";
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
	

