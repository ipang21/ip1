#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

map<char,char> getCryptMap(string word) {
	map<char, char> ret;
	vector<char> columns;
	unsigned int tmp = 0;
	for (string::iterator it = word.begin(); it != word.end(); it++) {
		tmp |= (1 << (*it - 'A'));
		columns.push_back(*it);
	}
	for (int i=0; i<26; i++) {
		if (!(tmp & (1<<i))) columns.push_back('A' + i);
	}
	tmp = 0;
	sort(word.begin(), word.end());
	for (string::iterator it = word.begin(); it != word.end(); it++) {
		vector<char>::iterator col = find(columns.begin(), columns.end(), *it);
		while(col < columns.end() ) {
			ret.insert(pair<char,char>(*col,'A'+tmp));
			col += word.size();
			tmp++;
		}
	}
	ret.insert(pair<char,char>(' ', ' '));
	return ret;
}

int main() {
	int T;
	unsigned int tmp = 0;
	map<char, char> cryptMap;
	string keyword, line;
	cin >> T;
	getline(cin,keyword);
	while (T--) {
		//cin >> keyword;
		getline(cin, keyword);
		for (string::iterator it = keyword.begin(); it != keyword.end(); it++) {
			if (tmp & (1 << (*it - 'A'))) { keyword.erase(it); it--; }
			else tmp |= (1 << (*it - 'A'));
		}
		cryptMap = getCryptMap(keyword);
		tmp = 0;
		//for (map<char,char>::iterator it = cryptMap.begin(); it!=cryptMap.end(); it++) {
		//	cout<< "Got mapping: " << (*it).first << " " << (*it).second << endl;
		//}
		getline(cin, line);
		for (string::iterator it = line.begin(); it != line.end(); it++) {
			cout << cryptMap[*it];
		}
		printf("\n");
	}
	return 0;
}
