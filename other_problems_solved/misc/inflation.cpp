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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(0);

    int n; 
    cin >> n;
    vi helium;
    for (int i = 0; i < n; ++i) {
        // amount of helium in gas cannisters
        int a; cin >> a;
        helium.push_back(a);
    }

    sort(helium.begin(), helium.end());
  
    double minimo = 1;
    for (double i = 1; i <= n; ++i) {
        double a = helium[i-1]/i;
        if (a > 1) {
            cout << "impossible";
            return 0;
        } 
        if (a < minimo) {
            minimo = a;
        }
    }
    cout << minimo;
}
