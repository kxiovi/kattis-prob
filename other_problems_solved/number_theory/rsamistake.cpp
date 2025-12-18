// resources: 
// kactl: Factor, ModMulLL, MillerRabin
//   is_square: https://stackoverflow.com/questions/25532306/optimized-way-to-find-if-a-number-is-a-perfect-square

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

bool is_square(ull n) {
  ull root = sqrt(n);
  return root * root == n;
}

vector<ull> getAllFactors(ull n) {
    // from prev assignment
    vector<ull> f = factor(n);
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
    // allFactors.erase(allFactors.begin());
    return allFactors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(7);

    // check for full credit
    // else check if number is not a perfect square, partial cred
    // else no cred

    ull a, b;
    cin >> a >> b;
    if (a == b) {cout << "no credit"; return 0; }
    if (isPrime(a) && isPrime(b)) {cout << "full credit"; return 0;}
    vector<ull> c = factor(a);
    vector<ull> d = factor(b);
    // c.erase(unique(all(c)), c.end());
    // d.erase(unique(all(d)), d.end());
    // if ((c.size() + d.size()) % 2 != 0) { cout << "no credit"; return 0;}
    // vector<ull> f = factor(n);
    sort(all(d));
    sort(all(c));
    for (int i = 1; i < c.size(); i++) {
      if (c[i] == c[i-1]) {
          cout << "no credit";
          return 0;
      }
    }


    for (int i = 1; i < d.size(); i++) {
      if (d[i] == d[i-1]) {
          cout << "no credit";
          return 0;
      }
    }
    if (gcd(a, b) == 1) {
      cout << "partial credit";
      return 0;
    }
    cout << "no credit";

}
