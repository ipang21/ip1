#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map<int,int> a;
	int T, N, val;
	int ans = 0;
	cin >> T;
	while (T--) {
		cin >> N;
		while (N--) {
			cin >> val;
			if (a[val] > 0) ans += a[val];
			a[val]++;
		}
		cout << 2*ans << endl;
		a.clear();
		ans = 0;
	}    
    return 0;
}

