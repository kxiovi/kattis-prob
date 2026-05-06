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

    string s;
    cin >> s;

    vector<int> alphabet(26);

    for (char c : s) {
        int g = c - 97;
        alphabet[g]++;
    }

    int count=0;
    int ans = 0;
    int save = 0;
    while (true) {
        for (int i = 0; i < 26; ++i) {
            if (alphabet[i] % 2 != 0) {
                count++;
                save = i;
            }
        }
        if (count > 1) {
                count = 0;
                ans++;
                alphabet[save]--;
            } else {
                cout << ans;
                return 0;
            } 
    }

    

    
}
