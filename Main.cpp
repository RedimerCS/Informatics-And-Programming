#include "Game.h"
#include "Player.h"
#include "Computer.h"
#include <locale>
#include <iostream>

int main()
{
	setlocale(LC_ALL,"Russian");

	bool active = true;
	Game g1;
	g1.play();

	while (active) 
	{
		system("cls");
		std::cout << "Меню:\n" << "1 - Начать заново\n" << "0 - Выйти из игры\n> ";
		int vybor;
		std::cin >> vybor;
		if (vybor == 1) 
		{ 
			system("cls");
			g1.~Game();
			g1.play(); 
			vybor = 0;
		}
		else { break; }
	} 
	system("pause");
	return 0;
}