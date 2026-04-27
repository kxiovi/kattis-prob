#include <bits/stdc++.h>

using namespace std;

// const int MAX = 50;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v(9, 0);
    for (int i = 0; i < 9; ++i) {
        cin >> v[i];
    }

    // sort(v.begin(), v.end(), greater<int>());

    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        sum += v[i];
    }

    int leftover = sum - 100;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (j == i) continue;
            if (v[i] + v[j] == leftover) {
                int q = v[i];
                int w = v[j];
                for (int e : v) {
                    if (e == q || e == w) continue;
                    else {
                        cout << e << '\n';
                    }
                }
                return 0;
            }
        }
    }


}
