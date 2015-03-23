#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	long long N, in;
	int count = 0;
	vector<long long> weight;
	cin >> N;
	while (N--) {
		cin >> in;
		weight.push_back(in);
	}
	sort(weight.begin(), weight.end());
	for (vector<long long>::iterator it=weight.begin(); it != weight.end(); it++) {
		in = *it;
		while ( (in+4) >= *it) {
			weight.erase(it);
			if (it == weight.end()) break;
		}
		it--;
		count++;
		//cout << ' ' << *it;
	}
	cout << count;
    return 0;
}
