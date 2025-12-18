// resources: kactl: phiFunction

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


// phi(6) = 2 b/c only 1, 5 (out of 1, 2, 3, 4, 5, 6) have no common factor with 6. 
// phi(12) = 4 b/c 1, 5, 7, 11
const int LIM = 10001;
int phi[LIM];

void calculatePhi() {
    rep(i,0,LIM) phi[i] = i&1 ? i : i/2;
    for (int i = 3; i < LIM; i += 2) if(phi[i] == i)
        for (int j = i; j < LIM; j += i) phi[j] -= phi[j] / i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(1);

    int p;
    cin >> p;

    calculatePhi();

    vector<ll> fareylen(LIM);
    fareylen[0] = 0;
    for (int i = 1; i < LIM; ++i) {
      fareylen[i] = fareylen[i-1] + phi[i];
    }

    for (int i = 0; i < p; ++i) {
      int k, n;
      cin >> k >> n;

      // get length of farey sequence of order n
      // for example, farey length of 6: 
      /*
      phi(1) = 1 --> 1 --> 0/1
      phi(2) = 1 --> 1 --> 1/2
      phi(3) = 2 --> 1, 2 --> 1/3, 2/3
      phi(4) = 2 --> 1, 3 --> 1/4, 3/4
      phi(5) = 4 --> 1, 2, 3, 4 --> 1/5, 2/5, 3/5, 4/5
      phi(6) = 2 --> 1, 5 --> 1/6, 5/6
      -------------------
      ======== 12

      Do 12 + 1 to account for 1/1. 
      therefore ans = 13
      */


      cout << k << " " << fareylen[n] + 1 << "\n";
    }



}