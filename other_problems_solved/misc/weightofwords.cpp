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

    int l, w;
    cin >> l >> w;

    if (w < l || w > l * 26) {
        cout << "impossible";
        return 0;
    }

    // greedy sol
    string s(l, 'a');
    int remaining = w - l;
    for (int i = l - 1; i >= 0 && remaining > 0; --i) {
        int add = min(25, remaining);
        s[i] += add;
        remaining -= add;
    }

    cout << s;

	
}


