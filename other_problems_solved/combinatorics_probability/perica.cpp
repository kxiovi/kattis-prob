// references: 
//   Fermat's: https://www.geeksforgeeks.org/dsa/compute-ncrp-using-fermat-little-theorem/

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
const ull MOD = 1000000007;

ull fermat(ull a, ull b) {
    ull result = 1;
    a %= MOD;
    while (b > 0) {
      if (b & 1) {
        result = result * a % MOD;
        
      }
      a = a * a % MOD;
      b >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<ull> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<ull> factorial(n+1);
    vector<ull> inv(n+1);
    factorial[0] = 1;

    for (int i = 1; i <= n; ++i) {
      factorial[i] = factorial[i-1] * i % MOD;
    }

    inv[n] = fermat(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i) {
      inv[i] = inv[i+1] * (i + 1) % MOD;
    }

    ull ans = 0;
    for (int i = 0; i < n; ++i) {
      if (i >= k-1) {
        ull binomial = factorial[i] * inv[k-1] % MOD * inv[i - k + 1] % MOD;
        ull t = a[i] * binomial % MOD;
        ans = (ans + t) % MOD;
      }
    }

    cout << ans;
    
}