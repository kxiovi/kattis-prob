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

    string s, t;
    getline(cin, s);
    getline(cin, t);
    
    unordered_map<char, int> count;
    unordered_map<char, int> co;
    set<char> sticky;

    for (char c : s) {
        if (count.contains(c)) {
            count[c]++;
        } else {
            count[c] = 1;
        }
    }

    for (char c : t) {
        if (co.contains(c)) {
            co[c]++;
        } else {
            co[c] = 1;
        }

        if (!sticky.contains(c) && co[c] > count[c]) {
            cout << c;
            sticky.insert(c);

        }
    }
    
}
