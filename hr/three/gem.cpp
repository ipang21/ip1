#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    string in;
    unsigned long val = 0;
    unsigned long prev = 0xffffffff;
    unsigned int count = 0;
    cin >> N;
    for (int i = 0; i<N; i++){
        cin >> in;
        for (string::iterator x = in.begin(); x != in.end(); x++) {
            val = val | (1 << (*(x) - 'a'));
        }
        prev = prev & val;
        val = 0;
    }
    for (int i = 0; i<32; i++) {
        if (prev & (1<<i))  count++;
    }
    cout << count;
    return 0;
}

