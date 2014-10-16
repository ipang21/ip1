#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void myprint(unsigned int numOfFives, unsigned int numOfThrees) {
	for (int i = 0; i<numOfFives; i++) cout << 555;
	for (int i = 0; i<numOfThrees; i++) cout << 33333;
	cout << endl;
}

void printMaxVal(unsigned int x) {
	unsigned int mod, quinThrees, tripFives;
	unsigned int it = 0;
	if ( (x==1) || (x==2) || (x==4) || (x==7)) cout << -1 << endl;
	else {
		tripFives = x / 3;
		it = tripFives * 3;
		while ( (x-it) % 5 != 0) {
			tripFives--;
			it -= 3;
		}
		quinThrees = (x-it) / 5;
		myprint(tripFives, quinThrees);
	}
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int T;
	unsigned int N;
	cin >> T;
	for (int i = 0; i<T; i++) {
		cin >> N;
		printMaxVal(N);
	}
    return 0;
}
