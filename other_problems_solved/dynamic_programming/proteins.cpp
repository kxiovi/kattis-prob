#include <bits/stdc++.h>
using namespace std;


int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    string dna;
    cin >> n >> dna;

    const string M = "ATG";
    const int INF = 1e9;
    int len = dna.size();
    int y = min(n, len);

    // [nucleotide][n]
    vector<vector<int>> dp(len+1, vector<int>(y+1, INF));
    dp[0][0] = 0;
    
    for (int nucleotide = 0; nucleotide <= len; ++nucleotide) {
        for (int k = 0; k <= y; ++k) {
            if (dp[nucleotide][k] < INF) {
                int curr_in = dp[nucleotide][k];

                // if the next codon is M
                if (k < y) {
                    int in = curr_in; // insertions 
                    int pos = nucleotide;

                    for (char c : M) {
                        if (pos < len && dna[pos] == c) {
                            pos += 1;
                        } else {
                            in += 1;
                        }
                    }
                    dp[pos][k+1] = min(dp[pos][k+1], in);
                }

                // if the next codon is not M
                // use j letters from dna to make a M
                // therefore goal is the num of insertions required
                for (int j = 1; j < min(4, len - nucleotide + 1); ++j) {
                    int goal = 3 - j;
                    dp[nucleotide+j][k] = min(dp[nucleotide+j][k], curr_in + goal);
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= len; ++i) {
        for (int k = 0; k <= y; ++k) {
            if (dp[i][k] < INF) {
                ans = min(dp[i][k] + (n-k)*3, ans);
            }
        }
    }
    cout << ans << endl;
}