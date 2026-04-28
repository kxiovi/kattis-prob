#include <bits/stdc++.h>

using namespace std;

// const int MAX = 50;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int h1, h2, m1, m2;
    h1 = s[0] - '0';
    h2 = s[1] - '0';
    m1 = s[2] - '0';
    m2 = s[3] - '0';

    // cout << h1 << h2 << m1 << m2;
    vector<vector<int>> ans(4, vector<int>(4));
    vector<int> v(4);
    for (int i = 3; i >= 0; --i) {
        v[i] = (h1 >> i) & 1;
        // cout << v[i] << endl;
    }

    for (int i = 3; i >= 0; --i) {
        ans[i][0] = v[i];
    }

    vector<int> q(4);
    for (int i = 3; i >= 0; --i) {
        q[i] = (h2 >> i) & 1;
        // cout << q[i] << endl;
    }
    for (int i = 3; i >= 0; --i) {
        ans[i][1] = q[i];
    }

    vector<int> w(4);
    for (int i = 3; i >= 0; --i) {
        w[i] = (m1 >> i) & 1;
        // cout << q[i] << endl;
    }
    for (int i = 3; i >= 0; --i) {
        ans[i][2] = w[i];
    }

    vector<int> r(4);
    for (int i = 3; i >= 0; --i) {
        r[i] = (m2 >> i) & 1;
        // cout << q[i] << endl;
    }
    for (int i = 3; i >= 0; --i) {
        ans[i][3] = r[i];
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (ans[3-i][j] == 0) {
                cout << '.';
            } else {
                cout << '*';
            }
            if (j == 1) cout << "  ";
            if (j != 3) cout << " ";
            // if (j == 3) cout << '|';
        }
        cout << '\n';
    }
}
