#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int C, P, X, L;
    cin >> C >> P >> X >> L;

    if (X == L) {
      cout << "leave";
      return 0;
    }

    // queue for BFS
    queue<int> q;
    q.push(L); // push first to leave

    // init
    vector<vector<int>> partners(C+1); // all countries
    vector<int> numPartners(C+1, 0);
    vector<bool> brexit(C+1, false);
    vector<int> remaining(C+1);

    brexit[L] = true;

    for (int i = 0; i < P; ++i) {
        int x, y;
        cin >> x >> y;

        partners[x].push_back(y); 
        partners[y].push_back(x);
        numPartners[x]++;
        numPartners[y]++;
    }

    for (int i = 1; i <= C; ++i) {
      remaining[i] = numPartners[i];
    }

    while (!q.empty()) {
      int explore = q.front();
      q.pop();

      for (int p : partners[explore]) {
        if (!brexit[p]) {
          remaining[p]--;
          if (remaining[p] * 2 <= numPartners[p]) {
              brexit[p] = true;
              if (p == X) {
                cout << "leave";
                return 0;
              }
              q.push(p);
          }
        }
      }
    }

    // if (brexit[X]) cout << "leave";
    // else cout << "stay";
    if (!brexit[X]) cout << "stay";
    
}
