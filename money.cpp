#include "money.h"
#include <iostream>
#include <cmath>
using namespace std;
void money::convert()
{
	if ((get_money_in_penny()) >= 0) {
		while (penny >= 12) {
			++shilling;
			penny -= 12;
		}
		while (penny < 0) {
			--shilling;
			penny += 12;
		}
		while (shilling >= 20) {
			++pound;
			shilling -= 20;
		}
		while (shilling < 0) {
			--pound;
			shilling += 20;
		}
	}
	else {
		while (penny > 0) {
			++shilling;
			penny -= 12;
		}
		while (penny <= -12) {
			--shilling;
			penny += 12;
		}
		while (shilling > 0) {
			++pound;
			shilling -= 20;
		}
		while (shilling <= -20) {
			--pound;
			shilling += 20;
		}
	}
	if (pound < 0 || shilling < 0 || penny < 0) {
		pound = abs(pound);
		shilling = abs(shilling);
		penny = abs(penny);
		check = false;
	}
	else {
		check = true;
	} 
}

money::money()
{
	pound = 0;
	shilling = 0;
	penny = 0;
	check = true;
}

money::money(int a_pound, int a_shilling, double a_penny, bool a_check) {
	pound = a_pound;
	shilling = a_shilling;
	penny = a_penny;
	check = a_check;
}
money::money(int a_pound, int a_shilling, double a_penny) {
	pound = a_pound;
	shilling = a_shilling;
	penny = a_penny;
	const int pound_max = 1000000000;
	if (pound >= pound_max || pound < 0) {
		throw logic_error("wrong amount of pounds");
	}
	if (shilling >= 20 || shilling < 0) {
		throw logic_error("wrong amount of shillings");
	}
	if (penny >= 12 || penny < 0) {
		throw logic_error("wrong amount of pences");
	}
}

void money::set_pound(int a_pound) {
	pound = a_pound;
}
void money::set_shilling(int a_shilling) {
	shilling = a_shilling;
}
void money::set_penny(double a_penny) {
	penny = a_penny;
}
int money::get_pound() {
	return pound;
}
int money::get_shilling() {
	return shilling;
}
double money:: get_penny() {
	return penny;
}

double money::get_money_in_penny() {
	if (check) {
		return penny + shilling * 12 + pound * 12 * 20;
	}
	else {
		return (penny + shilling * 12 + pound * 12 * 20) * (-1);
	}
}

void money::print() {
	if (check == false) {
		cout << "-";
	}
	if (pound != 0) {
		cout << pound << " pd. ";
	}
	if (shilling != 0) {
		cout << shilling << " sh. ";
	}
	if (penny != 0) {
		cout << penny << " p. ";
	}
	if (pound == 0 && shilling == 0 && penny == 0) {
		cout << "0 p.";
	}
}
money money::operator + ( money& amount_of_money_2) const {
	double pound_1 = pound + amount_of_money_2.get_pound();
	double shilling_1 = shilling + amount_of_money_2.get_shilling();
	double penny_1 = penny + amount_of_money_2.get_penny();
	money m (pound_1, shilling_1, penny_1);
	m.convert();
	return m;
}
money money::operator - (money& amount_of_money_2) const {
	double pound_2 = pound - amount_of_money_2.get_pound();
	double shilling_2 = shilling - amount_of_money_2.get_shilling();
	double penny_2 = penny - amount_of_money_2.get_penny();
	money m(pound_2, shilling_2, penny_2);
	m.convert();
	return m;
}

money money::operator += (money& amount_of_money_2) {
	*this = *this + amount_of_money_2;
	return *this;
}
money money::operator -= (money& amount_of_money_2) {
	*this = *this - amount_of_money_2;
	return *this;
}

bool money::operator > (money amount_of_money_2) {
	return this->get_money_in_penny() > amount_of_money_2.get_money_in_penny();
}
bool money::operator < (money amount_of_money_2) {
	return this->get_money_in_penny() < amount_of_money_2.get_money_in_penny();
}
bool money::operator >= (money amount_of_money_2) {
	return this->get_money_in_penny() >= amount_of_money_2.get_money_in_penny();
}
bool money::operator <= (money amount_of_money_2) {
	return this->get_money_in_penny() <= amount_of_money_2.get_money_in_penny();
}
bool money::operator == (money amount_of_money_2) {
	return this->get_money_in_penny() == amount_of_money_2.get_money_in_penny();
}
bool money::operator != (money amount_of_money_2) {
	return this->get_money_in_penny() != amount_of_money_2.get_money_in_penny();
}

istream& operator>>(istream& stream, money& mon)
{
	int pound;
	int shilling;
	double penny;

	stream >> pound >> shilling >> penny;
	mon.set_pound(pound);
	mon.set_shilling(shilling);
	mon.set_penny(penny);
	return stream;

}