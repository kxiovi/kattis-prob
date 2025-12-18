#include <bits/stdc++.h>
using namespace std;

long binomial(int n, int k) {
    if (k > n || k < 0) return 0;
    if (k == 0 || k == n) return 1;
    if (k > (n-k)) {
        k = n - k;
    }

    long ans = 1;
    for (int i = 0; i < k; ++i) {
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N, V1, V2, W;
        cin >> N >> V1 >> V2 >> W;

        long left = N - V1 - V2;
        int toWin = (N/2 + 1);

        if (V1 >= toWin) {
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
            continue;
        }

        if (V1 + left < toWin) {
            cout << "RECOUNT!\n";
            continue;
        }

        int needed = toWin - V1;

        double prob = 0.0;
        for (int k = needed; k <= left; ++k) {
            double p = binomial(left, k) * pow(0.5, left);
            prob += p;
        }

        if (prob > W/100.0) {
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
        } else {
            cout << "PATIENCE, EVERYONE!\n";
        }
    }
    
}
