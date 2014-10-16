#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, T, in, b, e;
	vector<int> width;
	vector<int>::iterator iWidth;
	cin >> N >> T;
//	cout << "N is " << N << ", T is " << T << endl;
	for (int i = 0; i < N; i++) {
		cin >> in;
		width.push_back(in);
	}
	for (int i = 0; i < T; i++) {
		cin >> b >> e;
		cout << *min_element(width.begin()+b, width.begin()+e) << endl;
	}
	//for (iWidth = width.begin(); iWidth != width.end(); iWidth++) {
	//	cout << *iWidth << " ";
	//}
	cout << endl;
	return 0;
}
