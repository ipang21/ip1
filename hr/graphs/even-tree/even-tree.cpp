#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int M,N;
	int v1, v2;
	int ans = 0;
	int arr[101][101] = {0};
	cin >> M;
	cin >> N;
	while (N--) {
		cin >> v1;
		cin >> v2;
		arr[v1][v2] = 1;
		arr[v1][0]++;
		arr[v2][v1] = 1;
		arr[v2][0]++;
	}

	for (int i = 0; i<=100; i++) {
		
	}
	return 0;
}

