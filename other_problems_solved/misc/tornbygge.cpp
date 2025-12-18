#include <bits/stdc++.h>

using namespace std;

// const int MAX = 50;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        // cout << v[i];
    }

    int towers = 1;
    for (int i = 1; i < n; ++i) {
        if (v[i-1] < v[i]) {
            towers++;
        }
    }

    cout << towers;
    
}