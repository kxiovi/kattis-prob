#include <bits/stdc++.h>

using namespace std;

// const int MAX = 50;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
            // cout << v[i][j];
        }
    }

    int wr = 0;
    int br = 0;

    for (int i = 0; i < n-2; ++i) {
        for (int j = 0; j < n; ++j) {
            // cout << "HERE";
            if (v[i+1][j] == v[i][j] && v[i+1][j] == v[i+2][j]) {
                cout << 0;
                return 0;
            }
        }
    }

    for (int i = 0; i < n-2; ++i) {
        for (int j = 0; j < n; ++j) {
            // cout << "HERE";
            if (v[j][i+1] == v[j][i] && v[j][i+1] == v[j][i+2]) {
                cout << 0;
                return 0;
            }
        }
    }

    bool row = false;
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (v[i][j] == 'W') {
                wr++;
            } 
            else {br++;}
        }
        // cout << wr << " " << br << endl;
        if (wr == br) {
            row = true;
        }
        else { 
            cout << 0;
            return 0;
        }
        wr = 0;
        br = 0;
    }
    

    int w = 0;
    int b = 0;
    if (row) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (v[j][i] == 'W') {
                    w++;
                } else {
                    b++;
                }
            }
            if (w != b) {
                cout << 0;
                return 0;
            } 
            w = 0;
            b = 0;
        }
    } 

    cout << 1;
    
    
}
