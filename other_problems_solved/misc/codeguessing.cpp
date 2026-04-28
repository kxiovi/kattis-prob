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

    int A1, A2;
    cin >> A1 >> A2;

    string s;
    cin >> s;

    if (s == "AABB") {
        if (A2 == 7) {
            cout << "8 9";
        } else {
            cout << -1;
        }
    } else 
    if (s == "ABAB") {
        if (A2 == 8 && A1 == 6) {
            cout << "7 9";
        } else cout << -1;
    } else
    if (s == "ABBA") {
        if (A2-A1 == 3) {
            cout << A1+1 << " " << A1+2;
        } else cout << -1;
    } else 
    if (s == "BAAB") {
        if (A1 == 2 && A2 == 8) {
            cout << "1 9";
        } else cout << -1;
    } else 
    if (s == "BABA") {
        if (A1 == 2 && A2-A1 == 2) {
            cout << 1 << " " << A1+1;
        } else cout << -1;
    } else
    if (s == "BBAA") {
        if (A1 == 3) {
            cout << "1 2"; 
        } else cout << -1;

    }
    return 0;
}
