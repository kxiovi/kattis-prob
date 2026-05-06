/*
References: 
https://icpcarchive.github.io/North%20America%20Contests/North%20Central%20Regional%20Contest/2019%20North%20Central%20Regional%20Contest/solution.pdf
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
    
    int n, k;
    cin >> n >> k;
    
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<int> freq(k+1, 0);
    vector<int> s;
    s.reserve(k);
    vector<bool> inStack(k+1, false);

    for (int a : v) {
        freq[a]++;
    }

    for (int a : v) {
        freq[a]--;
        if (!inStack[a]) {
            while (!s.empty() && s.back() > a && freq[s.back()] > 0) {
                inStack[s.back()] = false;
                s.pop_back();
            }
            s.push_back(a);
            inStack[a] = true;
        } 

    }

    for (int i = 0; i < s.size(); ++i) {
        cout << s[i] << " "; 
    }
    
}
