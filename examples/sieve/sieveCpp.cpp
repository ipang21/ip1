#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#define MAX_NUM 1000000
using namespace std;

vector<unsigned long long> getPrimes(unsigned long long max) {
	bool chk[max];
	vector<unsigned long long> ret;
	cout << "BOOL ARRAY: Size of chk used: " << sizeof(chk) << endl;
	for (unsigned long long i=0; i<max; i++) chk[i] = 0;
	for (unsigned long long i=2; i<max; i++) {
		if (chk[i] != 1) {
			ret.push_back(i);
			for (unsigned long long j = i; j<max; j+=i) chk[j] = 1;
		}
	}
	return ret;
}

vector<unsigned long long> getPrimes2(unsigned long long max) {
	vector<bool> chk(max);
	vector<bool>::iterator chk_it = chk.begin();
	vector<unsigned long long> ret;
	cout << "VECTOR: Size of chk used: " << chk.size() << endl;
	for (vector<bool>::iterator it = chk.begin(); it!=chk.end(); it++) *it = 0;
	for (unsigned long long i=2; i<max; i++) {
		if (*(chk_it+i) != 1) {
			ret.push_back(i);
			for (unsigned long long j = i; j<max; j+=i) *(chk_it+j) = 1;
		}
	}
	return ret;
}

vector<unsigned long long> getPrimes3(unsigned long long max) {
	set<unsigned long long> chk;
	vector<unsigned long long> ret;
	chk.insert(2);
	for (unsigned long long i=3; i<max; i+=2) chk.insert(i);
	cout << "SET: Size of chk used: " << chk.size() << endl;
	int p = *chk.begin();
	ret.push_back(2);
	chk.erase(p);
	int rt = sqrt(*(chk.rbegin()));
	while (chk.size() > 0) {
		if (p>rt) {
			while(chk.size()>0) {
				p = *chk.begin();
				ret.push_back(p);
				chk.erase(p);
			}
			break;
		}
		int i = p*p;
		int temp = *(chk.rbegin());
		while (i<=temp) {
			chk.erase(i);
			i+=p;
			i+=p;
		}
		p=*chk.begin();
		ret.push_back(p);
		chk.erase(p);
	}
	return ret;
}

int main() {
	vector<unsigned long long> primeNumbers;
	primeNumbers = getPrimes(MAX_NUM);
	cout << "BOOL ARRAY: last prime is: " << *primeNumbers.rbegin();
	cout << "\n";
	primeNumbers = getPrimes2(MAX_NUM);
	cout << "VECTOR: last prime is: " << *primeNumbers.rbegin();
	cout << "\n";
	primeNumbers = getPrimes3(MAX_NUM);
	cout << "SET: last prime is: " << *primeNumbers.rbegin();
	cout << "\n";
	return 0;
}
