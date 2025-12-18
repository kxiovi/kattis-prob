// resources: kactl - segment tree

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


/*

justforsidekicks: Building a single segment tree storing the values of the gems is not good 
enough since updating a value takes too much time. Consider how multiple segment trees can help.
*/

struct Tree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a+b; } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(7);

    int n, q;
    cin >> n >> q;

    vector<ull> values(6);
    for (int i = 0; i < 6; ++i) {
        cin >> values[i];
    }

    // gems can be type 1,2,3,4,5,6
    // index gem_types to find type of a gem
    string gem_types;
    cin >> gem_types;


    // have multiple segment trees by type of gem?
    vector<Tree> trees(6, Tree(n));
    for (int i = 0; i < n; ++i) {
        int g = gem_types[i] - '1';  // 0 indexed
        trees[g].update(i, 1);
    }

    // convert input to 0 indexed
    for (int i = 0; i < q; ++i) {
        int query_type;
        cin >> query_type;
        if (query_type == 1) {
            int k, p;
            cin >> k >> p;
            int init = gem_types[k-1] - '1';  // get type of gem being modified
            gem_types[k-1] = p + '0';
            trees[init].update(k-1, 0);
            trees[p-1].update(k-1, 1);

        } else 
        if (query_type == 2) {
            int p, v;
            cin >> p >> v;
            values[p-1] = v;  // can store values in segment tree !!!!!!!!!!!!!!1
        } else 
        if (query_type == 3) {
            int l, r;
            cin >> l >> r;
            ull ans = 0;
            for (int j = 0; j < 6; ++j) {
                int count = trees[j].query(l-1, r);
                ans += values[j] * count;
            }
            cout << ans << '\n';
        }
    }
    
}

