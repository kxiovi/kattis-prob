#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
const ull MODULO = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // double s; 
    int s;
    cin >> s;
    cout << s << ":" << "\n";

    set<pair<int, int>> pattern;
    // for (int i = 1; i <= s; ++i) {
    //   for (int j : {i, i-1}) {
    //     if (j <= 0) continue;
    //     for (int x = 1; x <= ceil(s/2); ++x) {
    //       for (int y = 1; y <= ceil(s/2); ++y) {
    //         if (x+y < 3) continue;
    //         if (x * i + y * j == s && x>=y && (x==y || y == x-1)) {
    //           pattern.insert({x, y});
    //         }
    //       }
    //     }
    //   }
    // }

    for (int i = 2; i <= s/2+1; ++i) {
      for (int j : {i, i-1}) {
        if (j<= 0) continue;
        if (s % (i + j) == 0 || (s - i) % (i + j) == 0) {
          pattern.insert({i, j});
        }
      }
    }

    for (auto c : pattern) {
      cout << c.first << "," << c.second << "\n";
    }
    
}
