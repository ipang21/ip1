#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T, tmp;
    cin >> T;
    while (T--) {
        int N, M, S;
        int n1, n2;
        int level = 1;
        cin >> N >> M;
        int answer[N+1];
        for (int i = 0; i<N+1; i++) answer[i] = -1;
        vector< vector<int> > edges(N+1);
        while (M--) {
            cin >> n1 >> n2;
            edges[n1].push_back(n2);
            edges[n2].push_back(n1);
            //if (n1 < n2) edges[n1].push_back(n2);
            //else edges[n2].push_back(n1);
        }
        cin >> S;
        queue<int> work;
        queue<int> work2;
        work.push(S);
        while(!work.empty() || !work2.empty()) {
            if (level%2 == 1) {
                while(!work.empty()) {
                    int num = work.front();
                    work.pop();
                    for (vector<int>::iterator it = edges[num].begin(); it != edges[num].end(); ++it) {
                        int edge = *it;
                        if (edge != 0) {
                            if (answer[edge] == -1) {
                                answer[edge] = level * 6;
                                int idx = find(edges[edge].begin(), edges[edge].end(), num) - edges[edge].begin();
                                edges[edge][idx] = 0;
                                work2.push(edge);
                            }
                        }
                    }
                }
                level++;
            }
            else {
                while(!work2.empty()) {
                    int num = work2.front();
                    work2.pop();
                    for (vector<int>::iterator it = edges[num].begin(); it != edges[num].end(); ++it) {
                        int edge = *it;
                        if (edge != 0) {
                            if (answer[edge] == -1) {
                                answer[edge] = level * 6;
                                int idx = find(edges[edge].begin(), edges[edge].end(), num) - edges[edge].begin();
                                edges[edge][idx] = 0;
                                work.push(edge);
                            }
                        }
                    }
                }
                level++;
            }
        }
        for (int i = 1; i<N+1; i++) {
            if (i != S) cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

