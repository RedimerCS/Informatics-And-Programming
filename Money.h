#pragma once
#include <iostream>
#include <fstream>

class Money {
public:
	Money();
	Money(const Money &c);
	Money(int _rub, int _cop);

	~Money();

	int rubx(), copx();
	void Set_R(int rr);
	void Set_C(int cc);

	void print();
	void input();

	Money& operator=(const Money& c);

	bool operator==(const Money& c);
	bool operator!=(const Money& c);

	Money operator+(const Money& c);
	Money operator-(const Money& c);

	friend Money operator+(int d, const Money& c);
	friend Money operator-(int d, const Money& c);
	friend Money operator*(int d, const Money& c);
	friend Money operator/(int d, const Money& c);

	friend std::ostream& operator<<(std::ostream& stream, const Money& c);
	friend std::istream& operator>>(std::istream& stream, Money& c);

private:
	int rub;
	int cop;
};
