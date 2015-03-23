#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, N, in, max = 0, prev = 0;
    cin >> T;
    while (T--) {
        cin >> N;
        cin >> prev;
        N--;
        while (N--) {
            cin >> in;
			cout << "in, prev, abs: " << in << " " << prev << " " << (unsigned int) abs(in - prev) << endl;
            max += abs( in - prev);
            prev = in;
			cout << "max: " << max << endl;
        }
        cout << max << endl;
    }
    return 0;
}
