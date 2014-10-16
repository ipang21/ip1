#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long getMax(vector<unsigned long long> *x) {
	unsigned long long max = 0;
	vector<unsigned long long>::iterator peak;
	while (x->size() > 0) {
		peak = max_element(x->begin(), x->end());
		for (vector<unsigned long long>::iterator it = x->begin(); it != peak; it++) {
			max += (*peak - *it);
		}
		x->erase(x->begin(), peak+1);
	}
	return max;
}

int main() {
    /* Enter your code here. Read input from STDIN. Prunsigned long long output to STDOUT */   
	unsigned long long T, N, in;
	vector<unsigned long long> prices;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i<N; i++) {
			cin >> in;
			prices.push_back(in);
		}
		cout << getMax(&prices)<<endl;
		prices.clear();
	}
    return 0;
}

