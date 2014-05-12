#include <iostream>

class Date
{
private:
	int month;
	int day;
	int year;

public:
	void setDate(int m, int d, int y) {
		month = m;
		day = d;
		year = y;
	}
	void print() {
		using namespace std;
		cout << "Got: " << month << "/" << day << "/" << year << endl;
	}
};

int main()
{
	Date xmas;
	xmas.setDate(12, 25, 2014);
	xmas.print();
	return 0;
}

