/*
  Resources: kactl: Hashing.h
*/


#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Arithmetic mod 2^64-1. 2x slower than mod 2^64 and more
// code, but works on evil test data (e.g. Thue-Morse, where
// ABBA... and BAAB... of length 2^10 hash the same mod 2^64).
// "typedef ull H;" instead if you think test data is random,
// or work mod 10^9+7 if the Birthday paradox is not a problem.
typedef uint64_t ull;
struct H {
    ull x; H(ull x=0) : x(x) {}
    H operator+(H o) { return x + o.x + (x + o.x < x); }
    H operator-(H o) { return *this + ~o.x; }
    H operator*(H o) { auto m = (__uint128_t)x * o.x;
        return H((ull)m) + (ull)(m >> 64); }
    ull get() const { return x + !~x; }
    bool operator==(H o) const { return get() == o.get(); }
    bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)


vector<H> getHashes(string& str, int length) {
    if (sz(str) < length) return {};
    H h = 0, pw = 1;
    rep(i,0,length)
        h = h * C + str[i], pw = pw * C;
    vector<H> ret = {h};
    rep(i,length,sz(str)) {
        ret.push_back(h = h * C + str[i] - pw * str[i-length]);
    }
    return ret;
}

// rolling hash to more efficiently, O(l) rater than O(l^2), store substrings
bool unique(string s, int l) {
  auto hashes = getHashes(s, l);
  unordered_set<ull> visited;
  visited.reserve(hashes.size() * 2);
  for (auto& hash : hashes) {
    if (!visited.insert(hash.get()).second) {
      return false;
    }
  }
  return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // read input
    string S;
    cin >> S;

    int Slen = size(S)/2;
    int numsub = Slen+1;

    sort(S.begin(), S.end());

    auto f = S.substr(0, Slen);
    auto s = S.substr(Slen);
    
    if (f == s) {
        cout << "-1";
        return 0;
    }


    string ans;
    ans.reserve(S.length());
    for (int i = 0; i < Slen; ++i) {
      ans += f[i];
      ans += s[i];
    }
    if (unique(ans, Slen)) cout << ans;
    else if (unique(s+f, Slen)) cout << s+f;
    else cout << "-1";

    
}
