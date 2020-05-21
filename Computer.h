#pragma once
#include <string>

using namespace std;

class Computer
{
public:
	Computer();
	Computer(int size_, string num_);
	Computer(const Computer& c);

	~Computer();

	int Get_size();
	void Set_size(int size_);

	string Get_num();
	void Set_num(string num_);

	string randNum(int size_);			
	
private:
	int size;							
	string num;							
};