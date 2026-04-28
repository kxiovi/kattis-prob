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

    // basically, sort in windows of size 3
    string s;
    cin >> s;

    int n = s.length();
    ll ans = 0;

    while(true) {
        int prev = ans;
        for (int i = 0; i < n-2; ++i) {
            if (s[i] == 'P' && s[i+2] == 'C') {
                swap(s[i], s[i+2]);
                ans++;
                break;
            }
        }

        // check to make sure that C is before P
        // will correct patterns like: PCP or CPC
        if (ans == prev) {
            for (int i = 0; i < n-2; ++i) {
                if (!(s[i] <= s[i+1] && s[i+1] <= s[i+2])) {
                    sort(s.begin() + i, s.begin() + i + 3); 
                    ans++;
                    break;
                }
            }
        }

        if (ans == prev) break;
    }

    cout << ans;
}
