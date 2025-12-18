// resources: kactl: euclid

#include <bits/stdc++.h>
using namespace std;

using ulll = __uint128_t;
// using ull = uint64_t;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// const double EPS = 1e-8;
// const double PI = 3.14159265359;
// using point = complex<double>;

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(1);

    int t;
    cin >> t;

    // extended euclidean

    // for every test case
    for (int i = 0; i < t; ++i) {
      int k, c;
      cin >> k >> c;

      // if (c%k == 0) { cout << "IMPOSSIBLE\n"; continue; }
      // if (k%c == 0) { cout << "IMPOSSIBLE\n"; continue; }
      
      if (k == 1 ) {
        if (c != 1) {
          cout << "1\n";
          continue;
        } else {
          cout << "2\n";
          continue;
        }
      }

      if (c == 1) {
        cout << (k+1) << "\n";
        continue;
      }

      ll x = 0; ll y = 0;
      ll euc = euclid(c, k , x, y);
      if (euc != 1) {
        cout << "IMPOSSIBLE\n"; 
        continue;
      }
      // only care about x
      x = (x % k + k) % k;  // x needs to be positive
      if (x == 0) {
        x = k;
      }
      if (x > 1e9) {
        cout << "IMPOSSIBLE\n";
      } else {
        cout << x << "\n";
      }


    }

}
