#pragma once
#include <string>

using namespace std;

class Player
{
public:
	Player();
	Player(int size_,string num_);
	Player(const Player& c);

	~Player();

	int Get_size();
	void Set_size(int size_);

	string Get_num();
	void Set_num(string num_);

	void createSize();				
	string createNum();				


private:
	int size;						
	string num;						
};
