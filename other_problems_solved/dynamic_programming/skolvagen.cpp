#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int n = s.size();
    int INF = n*4;
    vector<vector<int>> dp (n+1, vector<int>(2, INF));
    dp[0][0] = 0;  // starting at north therefore
    dp[0][1] = INF;  // cannot start at south

    /**
    THE TABLE: 

        |  N  |  S  |
      0 |  0  | inf |
    S 1 |  0  |  1  |
    N 2 |  1  |  1  |
    B 3 |  2  |  2  |
    N 4 |  3  |  2  |
    N 5 |  3  |  2  |
    S 6 |  3  |  3  |
    B 7 |  4  |  4  |
    */

    for (int i = 1; i <= n; ++i) {
        // build table
        char c = s[i-1];
        int north = dp[i-1][0];
        int south = dp[i-1][1];

        if (c == 'N') {
            north += 1;
        } else 
        if (c == 'S') {
            south += 1;
        }
        // if (c == 'B') {
        //     north += 1;
        //     south += 1;
        // }
        

        // int findmin1 = dp[i][1] < INF ? dp[i][1] + 1 : INF;
        dp[i][0] = min(north, dp[i-1][1] + 1);
        dp[i][1] = min(south, dp[i-1][0] + 1);

        if (c == 'B') {
            dp[i][0] += 1;
            dp[i][1] += 1;
        }
    }

    cout << dp[n][0]; // must end north
}
