#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int l = 0;
    int h = 0;
    int k = 0;
    cin >> l >> h >> k;

    int sl = 0;
    int sh = 0;
    int a = 0;
    int b = 0;
    vector<vector<char>> v(h, vector<char> (l, '_'));
    for (int i = 0; i < k; ++i) {
        cin >> sl >> sh >> a >> b;
        char ch = 'a' + i;
        for (int j = b; j < b+sh; ++j) {
            if (j < 0 || j >= h) continue;
            for (int m = a; m < a+sl; ++m) {
                if (m < 0 || m >= l) continue;
                v[j][m] = ch;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++) {
            cout << v[i][j];
        }
        cout << endl;
    }

}
