// resources: kactl: Factor.h, ModMulLL, MillerRabin

#include <bits/stdc++.h>
using namespace std;

using ulll = __uint128_t;
// using ull = uint64_t;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// const double EPS = 1e-8;
// const double PI = 3.14159265359;
// using point = complex<double>;

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}

bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n-1), d = n >> s;
    for (ull a : A) {   // ^ count trailing zeroes
        ull p = modpow(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}

ull pollard(ull n) {
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    auto f = [&](ull x) { return modmul(x, x, n) + i; };
    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) x = ++i, y = f(x);
        if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}
vector<ull> factor(ull n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), all(r));
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(1);

    ull n; 
    cin >> n;

    while (n != 0) {

      if (n == 3) { cout << 4 << "\n"; }
      else if (n < 3) { cout << "No such base\n"; } 
      // find smallest base b s.t. n % b = 3
      // n and 3 must have the same remainder when divided by b
      // i.e. (n-3) = bx, where x is a natural number
      // thus b = (n-3) / x
      // to find the smallest b, which must be a whole number, get the divisors of (n-3)
      // which we can substitute into x to find the smallest b
      // else cout << No such base
      else { 
        ull ans = 2147483648;  // not guaranteed to be the smallest base

        // from evening out 2, to get all factors
        vector<ull> f = factor(n-3);
        sort(f.begin(), f.end());
        vector<pair<ull, int>> primes; // {prime, num times it divides a}
        for (auto& i : f) {
          if (primes.empty() || primes.back().first != i) {
            primes.push_back({i, 1});
          } else {
            primes.back().second++;
          }
        }

        vector<ull> allFactors = {1};
        for (auto& [prime, num] : primes) {
          vector<ull> next;
          ull e = 1;
          for (int i = 0; i <= num; ++i) {
            for (auto& fac : allFactors) {
              next.push_back(fac * e);
            }
            e *= prime;
          }
          allFactors.swap(next);
        }
        sort(all(allFactors));

        ull maximo = n - 3;
        for (auto& f : allFactors) {
          ull tmp = maximo / f;
          if (tmp > 3) {
            ans = min(ans, tmp);
          }
        }

        if (ans == 2147483648) {
          cout << "No such base\n";
        } else {
          cout << ans << "\n";
        }
      }

      cin >> n;
    }



}