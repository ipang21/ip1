#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getPoli(string::iterator b, string::iterator e) {
	int sum = 0;
	e--;
	while ( (b<e) && (b!=e) ) sum += abs(*b++ - *e--);
	return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
	string in;
    for (int i = 0; i < T; i++) {
        cin >> in;
		cout << getPoli(in.begin(), in.end()) << endl;
    }
    return 0;
}

