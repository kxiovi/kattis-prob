#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    v[0] = 1;
    
    for (int i = 2; i <= N; ++i) {
        int k = 0;
        cin >> k;
        
        v[k+1] = i;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << v[i] << ' ';
    }
}
