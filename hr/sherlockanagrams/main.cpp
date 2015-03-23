#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int a[26];

void create_anagram_table(string x) {
	int i;
	for (i=0; i<26; i++) a[i] = 0;
	for (string::iterator it = x.begin(); it != x.end(); it++) {
		a[*it - 'a']++;
	}
}

int anagram(string x) {
	int cpy[26];
	int i;
	for (i = 0; i<26; i++) cpy[i] = a[i];
	for (string::iterator it = x.begin(); it != x.end(); it++) {
		cpy[*it - 'a']--;
	}
	for (i=0; i<26; i++) {
		if (cpy[i] > 0) return 0;
	}
	return 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    string s, tmp, cmp;
	int ans = 0;
    cin >> T;
    while (T--) {
        cin >> s;
        for (int i = 1; i<s.length(); i++) {
            for (int j = 0; j<s.length(); j++) {
				tmp = s.substr(j,i);
				create_anagram_table(tmp);
				for (int k = j+1; k<s.length(); k++) {
					cmp = s.substr(k,i);
					if (anagram(cmp)) {
						cout << "anagram: " << tmp << " and " << cmp <<endl;
						ans++;
					}
				}
			}
        }
		cout << ans << endl;
		ans = 0;
    }
    return 0;
}

