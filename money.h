#pragma once
using namespace std;
class money
{
private:
	int pound;
	int shilling;
	double penny;
	bool check;
	void convert();
	money(int, int, double, bool);
public:
	money();
	money(int, int, double);
	
	void set_pound(int);
	void set_shilling(int);
	void set_penny(double);

	int get_pound();
	int get_shilling();
	double get_penny();
	
	double get_money_in_penny();

	void print();

	money operator + (money&) const;
	money operator - (money&) const;
	money operator += (money&);
	money operator -= (money&);
	
	bool operator > (money);
	bool operator < (money);
	bool operator >= (money);
	bool operator <= (money);
	bool operator == (money);
	bool operator != (money);

	friend istream& operator>>(istream& stream, money& mon);
};

