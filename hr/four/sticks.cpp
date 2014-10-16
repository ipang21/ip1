#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N;
    vector<int> arr;
    unsigned int in, min;
	cin >> N;
    for (int i = 0; i<N; i++) {
        cin >> in;
        arr.push_back(in);
    }
    while (arr.size() > 0) {
		min = *min_element(arr.begin(), arr.end());
        cout << arr.size() << endl;
		for (vector<int>::iterator x = arr.begin(); x != arr.end();) {
			*x -= min;
			if (*x <= 0) arr.erase(x);
			else x++;
		}
    }
    return 0;
}

