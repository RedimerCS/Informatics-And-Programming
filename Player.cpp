#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player()
{
	num = "";
	size = 0;
}

Player::Player(int size_,string num_)
{
	size = size_;
	num = num_;
}

Player::Player(const Player& c)
{
	size = c.size;
	num = c.num;
}

Player::~Player()
{
	num = "";
	size = 0;
}

int Player::Get_size()
{
	return this->size;
}

void Player::Set_size(int size_)
{
	size = size_;
}

string Player::Get_num()
{
	return this->num;
}

void Player::Set_num(string num_)
{
	num = num_;
}

void Player::createSize()
{
	std::cout << "¬ведите размер загадываемого числа\n";
	do 
	{
		std::cout << "¬вод: ";
		std::cin >> size;
	} while (size < 0 || size > 8);													
}																					

string Player::createNum()
{
	bool chisla[10] = { false };
	int count = 0;
	std::cout << "¬ведите отгадываемое число\n";
	std::cin >> num;
	while (true)																	
	{
		while (num.length() > size || num.length() < size)								
		{
			std::cout << "¬ведите число заново: ";
			std::cin >> num;
		}

		for (int i = 0; i < num.length(); i++)										
		{																			
			int n = num[i] - 48;													
			chisla[n] = true;
		}

		for (int i = 0; i < 10; i++)
		{
			if (chisla[i] == true) { count++; }
		}

		if (count != num.length())													
		{
			std::cout << "\n¬ числе есть повтор€ющиес€ цифры!\n¬вод: ";
			std::cin >> num;
		}
		else { break; }																

		for (int i = 0; i < 10; i++)
		{
			chisla[i] = false;														
		}
		count = 0;
	}
	return num;																		
}