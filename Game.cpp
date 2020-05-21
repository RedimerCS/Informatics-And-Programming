#include "Game.h";
#include <iostream>;
#include <string>;

using namespace std;

Game::Game()
{
	size = 0;
	step = 0;
}

Game::Game(int size_, int step_, Player user_, Computer comp_)
{
	size = size_;
	step = step_;
	user = user_;
	comp = comp_;
}

Game::Game(const Game& c)
{
	size = c.size;
	step = c.step;
	user = c.user;
	comp = c.comp;
}

Game::~Game()
{
	size = 0;
	step = 0;
	user.Set_num("");
	user.Set_size(0);
	comp.Set_num("");
	comp.Set_size(0);
}

bool Game::check()
{
	string rand, num;
	int byk = 0, korov = 0;
	rand = comp.Get_num();													
	num = user.Get_num();													

	if (rand == num)														
	{
		std::cout << "Вы выиграли!\n" << "Сделаных шагов: " << step << "\n";
		(void)getchar(); (void)getchar();
		system("cls");
		return false;														
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (rand[i] == num[j])											
			{
				if (i == j) 
				{
					byk++;
				}
				else { korov++; };
			}
		}
	}

	cout << "Быков: " << byk << "\n" << "Коров: " << korov << "\n";			
	step++;																	

	return true;															
}

void Game::play()
{
	step = 1;
	user.createSize();
	size = user.Get_size();
	comp.randNum(size);
	user.createNum();
	while (check()) { user.createNum(); };									
}