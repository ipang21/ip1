#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    int n, a, b;
	set<int> ans;
    cin >> T;
    for (int i = 0; i<T; i++) {
        cin >> n >> a >> b;
 		for (int j = 0; j<n; j++) ans.insert(j*a + (n-j-1)*b);
		for (set<int>::iterator x = ans.begin(); x!=ans.end(); x++) cout << *x <<endl;
		ans.clear();
    }
    return 0;
}
