#include <iostream>
#include "money.h"
using namespace std;
int main() {
	
	//money amount_of_money_1(4, 9, 4), amount_of_money_2(2, 1, 1);
	money amount_of_money_1;
	cin >> amount_of_money_1;
	money amount_of_money_2;
	cin >> amount_of_money_2;

	money temp;
	cout << "first amount of money = ";
	amount_of_money_1.print();
	cout << endl;
	cout << "second amount of money = ";
	amount_of_money_2.print();
	cout << endl;

	temp = amount_of_money_1 + amount_of_money_2;
	cout << "a + b = ";
	temp.print();
	cout << endl;

	temp = amount_of_money_1 - amount_of_money_2;
	cout << "a - b = ";
	temp.print();
	cout << endl;

	temp = amount_of_money_1;
	temp += amount_of_money_2;
	cout << "a += b = a + b = ";
	temp.print();
	cout << endl;

	temp = amount_of_money_1;
	temp -= amount_of_money_2;
	cout << "a -= b = a - b = ";
	temp.print();
	cout << endl;

	cout << "a > b - " << (amount_of_money_1 > amount_of_money_2) << endl;
	cout << "a < b - " << (amount_of_money_1 < amount_of_money_2) << endl;
	cout << "a >= b - " << (amount_of_money_1 >= amount_of_money_2) << endl;
	cout << "a <= b - " << (amount_of_money_1 <= amount_of_money_2) << endl;
	cout << "a == b - " << (amount_of_money_1 == amount_of_money_2) << endl;
	cout << "a != b - " << (amount_of_money_1 != amount_of_money_2) << endl;

	return 0;
}
