// resources: kactl - string hashing by Simon Lindholm

#include <bits/stdc++.h>
using namespace std;

using ulll = __uint128_t;
using ull = uint64_t;

const ulll X = 8675309; 
const ulll INV_X = 8261199684264045559;
const ull P = 9223372036854775783;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

//  Arithmetic mod 2^64-1. 2x slower than mod 2^64 and more
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

struct HashInterval {
    vector<H> ha, pw;
    HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
        pw[0] = 1;
        rep(i,0,sz(str))
            ha[i+1] = ha[i] * C + str[i],
            pw[i+1] = pw[i] * C;
    }
    H hashInterval(int a, int b) { // hash [a, b)
        return ha[b] - ha[a] * pw[b - a];
    }
};

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

H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> dict(n);
    for (int i = 0; i < n; ++i) {
      cin >> dict[i];
    }

    // typo is any word in dict s.t. deleting a char from that word produces
    // another dictionary word

    //window hashing

    unordered_set<ull> um;
    vector<H> hashes(n);
    for (int i = 0; i < n; ++i) {
      hashes[i] = hashString(dict[i]);
      um.insert(hashes[i].get());
    }

    vector<string> typos;
    for (int i = 0; i < n; ++i) {
      string s = dict[i];
      HashInterval h(s);
      bool is_typo = false;
      for (int j = 0; j < s.size() && !is_typo; ++j) {
        H left = h.hashInterval(0, j);
        H right = h.hashInterval(j+1, s.size());
        left = left * h.pw[s.size()-j-1];
        H combo = left + right;
        if (um.count(combo.get())) {
          is_typo = true;
        }
      }
      if (is_typo) {
          typos.push_back(s);
        }

    }
    
    if (typos.empty()) cout << "NO TYPOS";
    else {
      for (auto &t : typos) {
        cout << t << '\n';
      }
    }
    

}
