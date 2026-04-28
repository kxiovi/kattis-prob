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

vector<bool> parser(const string& t, int lim) {
    vector<bool> res(lim+1, false);
    if (t == "*") {
        fill(res.begin(), res.end(), true);
        return res;
    }
    stringstream ss(t);
    string part;
    while (getline(ss, part, ',')) {
        int dash = part.find('-');
        if (dash != string::npos) {
            int lo = stoi(part.substr(0, dash));
            int hi = stoi(part.substr(dash+1));
            for (int i = lo; i <= hi; ++i) {
                res[i] = true;
            }
        } else {
            res[stoi(part)] = true;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(0);

    int n;
    cin >> n;

    ull deuxieme = 0;
    vector<bool> p(86400, false); // to track unique starts at every second

    while(n--) {
        string h, m, s;
        cin >> h >> m >> s;
        
        vector<bool> hours = parser(h, 23);
        vector<bool> mins = parser(m, 59);
        vector<bool> secs = parser(s, 59);
    
        ull hc = 0, mc = 0, sc = 0;
        for (int i = 0; i <= 23; ++i) {
            if (hours[i]) {
                hc++;
            }
        }
        for (int i = 0; i <= 59; ++i) {
            if (mins[i]) {
                mc++;
            }
            if (secs[i]) sc++;
        }
    
        deuxieme += hc * mc * sc;
    
        for (int i = 0; i < 24; ++i) {
            if (hours[i]) {
                for (int j = 0; j < 60; ++j) {
                    if (mins[j]) {
                        for (int k = 0; k < 60; ++k) {
                            if (secs[k]) {
                                p[i*3600 + j*60 + k] = true;
                            }
                        }
                    }
                }
            }
        }
    }

    ull ans = 0;
    for (bool b : p) {
        if (b) ans++;
    }

    cout << ans << ' ' << deuxieme;
}
