
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

const double PMAX = 100;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(7);

    int dl, dw; double g, l; 
    cin >> dl >> dw >> g >> l;

    g = g / 100;
    l = l / 100;
    int P = 0;  // adding int to int gives int
    double numMatches = 0;

    // init all states s.t. P < 101
    // index represents P, from 0 to 100 (use 100 - index to get P)
    // stores expected number of matches
    vector<double> v(PMAX+1, 0); 
    // l will never be 1 :)
    v[PMAX] = 1/(1-l);  // if P == 100, your expected num matches is this
    // go backwards from 100% chance
    for (double i = PMAX-1; i >= 0; --i) {
      double p = i/100;
      // if you win and get a prize, then v[i] will be 0 since no more matches needed (or expected)
      // add 1 for the current match
      v[i] = l * v[min(PMAX, (i + dl))] + (1 - l) * v[min(PMAX, (i + dw))] * (1 - p) + 1;
    }

    // expected val of num time to open any prize
    // need to get expected num of matches until gorilla /t divide by g
    double expected = v[0]/g;

    cout << expected;

    // cout << numMatches;


}