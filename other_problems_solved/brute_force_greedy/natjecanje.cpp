#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S, R;  // team, damaged teams, reserve teams
    cin >> N >> S >> R;

    int s = 0;
    int r = 0;
    int ans = 0;

    vector<char> v(N, 'g');

    for (int i = 0; i < S; ++i) {
        cin >> s;
        v[s-1] = 's';
    }

    for (int i = 0; i < R; ++i) {
        cin >> r;
        if (v[r-1] == 's') {
            v[r-1] = 'b';  // both damaged and reserve
        } else {
            v[r-1] = 'r';
        } 
    }

    for (int i = 0; i < N; ++i) {
        if (v[i] == 's') {
            if (i > 0 && v[i-1] == 'r') {
                v[i-1] = 'g';
            } else
            if (i < N && v[i+1] == 'r') {
                v[i+1] = 'g';
            } else {
                ans += 1;
            }
        }
    }


    cout << ans;

}
