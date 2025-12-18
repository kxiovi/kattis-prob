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

ll solve(ll m, ll n) {
  ll gcf = gcd(m, n);
  if (gcf == 1) {
    return (m & 1) * (n & 1);  // will rule out even coordinates
  } else {
    return solve(m / gcf, n / gcf) * gcf;
  }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(1);

    ll m, n;
    cin >> m >> n;

    if (m == n) {
      cout << m;
      return 0;
    }

    // ans is just the gcf ? 
    ll ans = solve(m, n);
    cout << ans;


}
