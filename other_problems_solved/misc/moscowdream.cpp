#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int e, m, h, t; 
    cin >> e >> m >> h >> t;
    
    if (e == 0 || m == 0 || h == 0 || t < 3) {
        cout << "NO";
        return 0;
    } else {
        
        e-=1;
        m-=1;
        h-=1;
        t-=3;
        
        while (t > 0 && (e > 0 || m > 0 || h > 0)) {
            if (e > 0) e-=1;
            else if (m > 0) m-=1;
            else if (h > 0) h-=1;
            t-=1;
        }
        
        if (t > 0) {
            cout << "NO";
        } else {
            cout << "YES";
        }
    }
}
