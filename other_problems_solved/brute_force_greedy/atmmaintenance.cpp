/*
References: 

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int w;
        cin >> w;
        if (w <= k) {
            cout << 1;
            k -= w;
        } else {
            cout << 0;
        }
    }
    
}