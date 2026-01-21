/*
References: 

*/

#include <bits/stdc++.h>
using namespace std;

using ulll = __uint128_t;
using ull = uint64_t;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void show(vector<vi> grid) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<vi> dir0(vector<vi> grid) {
    vector<vi> init(4);

    // push all integers to the left
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] != 0) {
                init[i].push_back(grid[i][j]);
            }
        }

        for (int j = 1; j < 4; ++j) {
            if (init[i][j-1] == init[i][j]) {
                init[i][j-1] <<= 1;
                init[i][j] = 0;
                j++;
            }
        }

        vector<int> remove;
        for (int a : init[i]) {
            if (a != 0) {
                remove.push_back(a);
            }
        }

        while (remove.size() < 4) {
            remove.push_back(0);
        }

        init[i] = remove;
    }

    return init;
}

vector<vi> dir2(vector<vi> grid) {
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(0);

    vector<vi> init(4, vi(4));

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> init[i][j];
        }
    }

    int dir;
    cin >> dir;

    vector<vi> ans;
    if (dir == 0) {
        ans = dir0(init);
    } else 
    if (dir == 2) {
        ans = dir2(g);
    }

    show(ans);
    
}