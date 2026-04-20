#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
const ull MODULO = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; 
    cin >> N;

    for (int i = 0; i < N; ++i) {
      int pass;
      cin >> pass; 

      int first3 = pass/1000;
      vector<int> candidates;
      for (int i : {first3-1, first3, first3+1}) {
        if (i >= 100 && i <= 999) {
          string s = to_string(i);
          string r = s;
          reverse(r.begin(), r.end());
          candidates.push_back(stoi(s+r)); 
        }
      }

      int ans = candidates[0];
      for (int c : candidates) {
        int diff1 = abs(c - pass);
        int diff2 = abs(ans - pass);
        if (diff1 < diff2 || (diff1 == diff2 && c < ans)) {
          ans = c;
        }
      }
      cout << ans << '\n';
    }
    
    
}
