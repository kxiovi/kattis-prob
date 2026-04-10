#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    int count = 0;
    vector<int> v(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    v.push_back(0);

    for (int i = 0; i < N+1; ++i) {
        if (v[i] + 1 == v[i+1]) {
            count += 1;
        } else {
            if (count > 1) {
                cout << v[i-count] << "-" << v[i] << " ";
                count = 0;
            } else {
                if (v[i] != 0) {
                    if (count != 0) {
                        cout << v[i-1] << " " << v[i] << " ";
                    } else {
                        cout << v[i] << " ";
                    }
                } 
                count = 0;
            }
        }
    }
} 
