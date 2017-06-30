#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        int yes = 0;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }
        for (int i = 0; i<R; i++) {
            string tmp = G[i];
            int pos = 0;
            if (i+r > R) break;
            do {
                pos = tmp.find(P[0], pos);
                if (pos != string::npos) {
                    int j;
                    for (j = 1; j<r; j++) {
                        string tmp2 = G[i+j];
                        int pos2 = tmp2.find(P[j], pos);
                        if (pos2 != pos) break;
                    }
                    if (j == r) {
                        yes = 1;
                        break;
                    }
                    pos++;
                }
            } while (pos != string::npos);
        }
        if (yes == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
