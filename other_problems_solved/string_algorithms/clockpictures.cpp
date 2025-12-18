// resources:   kactl - KMP

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int circle = 360000;

vi pi(const string& s) {
    vi p(sz(s));
    rep(i,1,sz(s)) {
        int g = p[i-1];
        while (g && s[i] != s[g]) g = p[g-1];
        p[i] = g + (s[i] == s[g]);
    }
    return p;
}

vi match(const string& s, const string& pat) {
    vi p = pi(pat + '\0' + s), res;
    rep(i,sz(p)-sz(s),sz(p))
        if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int hands;
    cin >> hands;

    vector<int> a(hands);
    vector<int> b(hands);
    for (int i = 0; i < hands; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < hands; ++i) {
        cin >> b[i];
    }

    // sort angles clockwise
    sort(all(a));
    sort(all(b));

    // get the gaps between the hands on each of the images
    vector<int> da;
    vi db;
    for (int i = 0; i < hands-1; ++i) {
        da.push_back(a[i+1]-a[i]);
    }
    da.push_back(circle - a.back() + a.front());

    for (int i = 0; i < hands-1; ++i) {
        db.push_back(b[i+1] - b[i]);
    }
    db.push_back(circle - b.back() + b.front());

    // for KMP, it should be in str
    string as;
    string bs;
    for (int i : da) {
        as += to_string(i) + ",";
    }
    for (int i : db) {
        bs += to_string(i) + ",";
    }

    string longer = as + as;
    if (!match(longer, bs).empty()) {
        cout << "possible";
    } else {
        cout << "impossible";
    }

}
