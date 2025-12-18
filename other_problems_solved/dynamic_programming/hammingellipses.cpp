#include <bits/stdc++.h>
using namespace std;


// task idx, tool, drop number
long long solve(vector<vector<long long>> &memo, int q, int n, int d, string& s1, string& s2, int i) {
    // if all char placed OR if distance < 0 (too much distance from focal points to p) we are done
    if (i == n) return d == 0 ? 1 : 0;
    if (d < 0) return 0;
    if (memo[i][d] != -1) {
        return memo[i][d];
    }

    long long total = 0;

    if (s1[i] == s2[i]) {
        total += solve(memo, q, n, d, s1, s2, i+1);
        total += (q - 1) * solve(memo, q, n, d-2, s1, s2, i+1);
    } else {
        total += 2 * solve(memo, q, n, d-1, s1, s2, i+1);
        if (q > 2) {
            total += (q - 2) * solve(memo, q, n, d-2, s1, s2, i+1);
        }
    }

    memo[i][d] = total;
    return total;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q, n, d; 
    cin >> q >> n >> d;

    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<long long>> memo(n+1, vector<long long>(d+1, -1));

    long long ans = solve(memo, q, n, d, s1, s2, 0);
    cout << ans << "\n";

}