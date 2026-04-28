#include <bits/stdc++.h>

using namespace std;

// const int MAX = 50;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int wc, hc, ws, hs;
    cin >> wc >> hc >> ws >> hs;

    if (wc > ws+1 && hc > hs+1) {
        cout << 1;
    } else {
        cout << 0;
    }

    
}
