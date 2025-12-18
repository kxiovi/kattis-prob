
#include <bits/stdc++.h>
using namespace std;

using ulll = __uint128_t;
using ull = uint64_t;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// const double EPS = 1e-8;
// const double PI = 3.14159265359;
// using point = complex<double>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(1);

    ll a , b, m, sigma;
    cin >> a >> b >> m >> sigma;

    // y <= m - x and y >= sigma - 2x
    // so sigma - 2x <= m - x
    // therefore sigma - m <= x
    // sigma - 2x <= y <= m - x
    // thus y can be min 1 and min (sigma - 2x)
    // thus min of y --> 1 = sigma - 2x
    // thus x = 0.5(sigma - 1)
    ll xmin = max(1LL, sigma - m);

    // x + y <= m
    // x <= m - y
    // y >= 1
    // thus the max x can be is m - 1
    ll xmax = m - 1;

    vector<ll> points;
    auto valid = [&](ll x) {
      if (x < xmin || x > xmax) return;
      else points.push_back(x);
    };

    valid(xmin);
    valid(xmax);

    // this is a piecewise function
    ll piecewise = (sigma - 1) / 2;
    valid(piecewise);
    valid(piecewise+1);


    ll ans = -1;
    for (auto& x : points) {
      ll ymin = max(1LL, sigma - 2*x);
      ll ymax = m - x;
      if (ymin > ymax) continue;
      ll y;
      if (b >= 0) y = ymax;
      else y = ymin;

      ll tmp = a*x + b*y;
      if (tmp > ans) ans = tmp;
    }

    cout << ans;


}