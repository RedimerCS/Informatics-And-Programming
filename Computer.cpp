#include "Computer.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

Computer::Computer()
{
	num = "";
	size = 0;
}

Computer::Computer(int size_, string num_)
{
	size = size_;
	num = num_;
}

Computer::Computer(const Computer& c)
{
	size = c.size;
	num = c.num;
}

Computer::~Computer()
{
	num = "";
	size = 0;
}

int Computer::Get_size()
{
	return size;
}

void Computer::Set_size(int size_)
{
	size = size_;
}

string Computer::Get_num()
{
	return num;
}

void Computer::Set_num(string num_)
{
	num = num_;
}

string Computer::randNum(int size_)
{
	bool chisla[10] = { false };
	size = size_;
	srand(time(NULL));
	for (int i = 0; i < size; i++)	
	{
		int n;
		while (chisla[n = 0 + rand() % 9] == true);
		chisla[n] = true;
		num += char(n + 48);
	}

	std::cout << "Загаданное число: " << num << "\n";							// !!!(Dlya udobnoi proverki)!!! //

	return num;
}