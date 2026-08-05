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

    int P; 
    cin >> P;
    string alphabet = "0123456789ACDEFHJKLMNPRTVWX";
    unordered_map<char, char> not_used = {
        {'B','8'}, 
        {'G','C'}, 
        {'I','1'}, 
        {'O','0'}, 
        {'Q','0'}, 
        {'S','5'}, 
        {'U','V'}, 
        {'Y','V'}, 
        {'Z','2'}
    };
    vector<int> check = {2,4,5,7,8,10,11,13};
    while (P--) {
        int k; string s;
        cin >> k >> s;

        for (int i = 0; i < 8; ++i) {
            if (not_used.contains(s[i]))  {
                s[i] = not_used[s[i]];
            }
        }

        // string sub = s.substr(0, 8);
        //calculate check
        ull sum = 0;
        for (int i = 0;  i < check.size(); ++i) {
            int v = alphabet.find(s[i]);
            sum += check[i] * v;
        }
        sum = sum % 27;
        if (alphabet[sum] != s[8]) {
            // cout << sum << " " << "Invalid\n";
            cout << k << " " << "Invalid\n";
        } else {

            ull m = 1;
            ull ans = 0;
            for (int i = 7; i >= 0; --i) {
                // cout << "s:" << s[i] << endl;
                ans += alphabet.find(s[i]) * m;
                m *= 27;
            }
             
            cout << k << " " << ans << '\n';
        }

    }
}
