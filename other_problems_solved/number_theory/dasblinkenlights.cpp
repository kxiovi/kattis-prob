/*
References: 

*/

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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(0);
    
    int p, q, s;
    cin >> p >> q >> s;
    
    ll lcm = p*q/gcd(p,q);
    if (lcm <= s) {
        cout << "yes";
    } else {
        cout << "no";
    }
}
