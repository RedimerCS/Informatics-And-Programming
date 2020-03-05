#include "Money.h"
#include <iostream>

Money::Money() : rub(0), cop(0) {}

Money::Money(const Money &c) : rub(c.rub), cop(c.cop) {}

Money::Money(int _rub, int _cop) : rub(_rub), cop(_cop) {}

Money::~Money() {
	rub = 0;
	cop = 0;
}

int Money::rubx() { return this->rub; }
int Money::copx() { return this->cop; }


void Money::Set_R(int rr) {
	rub = rr;
}

void Money::Set_C(int cc) {
	if (cc > 100) {
		cop = cc % 100;
		rub += cc / 100;
	}
	else {
		cop = cc;
	}
}

void Money::print() {
	std::cout << rubx() << "." << copx() << std::endl;
}

void Money::input() {
	int r, c;
	std::cout << "Введите рубли - ";
	std::cin >> r;
	std::cout << "Введите копейки - ";
	std::cin >> c;

	Set_R(r);
	Set_C(c);

}

Money& Money::operator=(const Money& c) {
	rub = c.rub;
	cop = c.cop;
	return *this;
}

bool Money::operator==(const Money& c) {
	if (c.rub == rub && c.cop == cop) return true;
	else return false;
}

bool Money::operator!=(const Money& c) {
	if (c.rub != rub || c.cop != cop) return true;
	else return false;
}

Money Money::operator+(const Money& c) {
	Money res;
	res.rub = rub + c.rub;
	res.cop = cop + c.cop;
	int a = res.cop;
	res.Set_C(a);
	return res;
}

Money Money::operator-(const Money& c) {
	Money res;
	res.rub = rub - c.rub;
	res.cop = cop - c.cop;
	int a = res.cop;
	res.Set_C(a);
	return res;
}

Money operator+(int d, const Money& c) {
	Money res;
	res.rub = d + c.rub;
	res.cop = c.cop;
	int a = res.cop;
	res.Set_C(a);
	return res;
}

Money operator-(int d, const Money& c) {
	Money res;
	res.rub = d - c.rub;
	res.cop = -c.cop;
	int a = res.cop;
	res.Set_C(a);
	return res;
}

Money operator*(int d, const Money& c) {
	Money res;
	res.rub = d * c.rub;
	res.cop = d * c.cop;
	int a = res.cop;
	res.Set_C(a);
	return res;
}

Money operator/(int d, const Money& c) {
	Money res;
	if (c.rub == 0 && c.cop == 0) {
		std::cout << "Ошибка, деление на 0" << std::endl;
		res.rub = -1;
	}
	else {
		res.rub = c.rub / d;
		res.cop = c.cop / d;
	}
	int a = res.cop;
	res.Set_C(a);
	return res;
}

std::ostream& operator<<(std::ostream& stream, const Money& c) {
	stream << c.rub << ".";
	stream << c.cop;
	return stream;
}

std::istream& operator>>(std::istream& stream, Money& c) {
	stream >> c.rub >> c.cop;
	return stream;
}
