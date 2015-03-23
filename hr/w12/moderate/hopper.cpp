#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int in, num, energy = 0;
	vector<int> hops;
	cin >> N;
	while (N--) {
		cin >> in;
		hops.push_back(in);
	}
	for (vector<int>::reverse_iterator it = hops.rbegin(); it != hops.rend(); it++) {
		if (*it > energy) {
#if 0
			if ((energy - (*it - energy)) < energy ) {
				num = *it;
				if (num & 0x1) num = num/2 + 1;
				else num = num/2;
				energy = num;
				cout << "** it, num, en: " << *it << ", " <<  num << ", " << energy << endl;
			}
#endif
			num = *it + energy;
			if (num & 0x1) num = num/2 +1;
			else num = num/2;
			energy = num;
		}
		else {
			num = *it + energy;
			if (num & 0x1) num = num/2 +1;
			else num = num/2;
			energy = num;
		}
		cout << "got: " << *it << " en: " << energy << endl;
	}
	//cout << energy;
	return 0;
}
