#include <bits/stdc++.h>

using namespace std;

// const int MAX = 50;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // solved with bit manipulation
    int dim;
    cin >> dim; 

    vector<int> arr(dim);
    for (int i = 0; i < dim; ++i) {
        int q = 0;
        for (int j = 0; j < dim; ++j) {
            int k;
            cin >> k;
            q = q | k;
        }
        arr[i] = q;
    }

    for (int q : arr) {
        cout << q << " ";
    }




}
