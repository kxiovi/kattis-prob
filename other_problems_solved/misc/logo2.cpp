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

constexpr double PI = 3.14159265358979323846; 


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<string, string>> pic;
        bool is_not_angle = false;
        for (int i = 0; i < n; ++i) {
            string dir; 
            string unit;
            cin >> dir >> unit;
            pic.push_back({dir, unit});
            if (unit == "?") {
                if (dir == "fd" || dir == "bk") {
                    is_not_angle = true;
                }
            }
        }
        if (is_not_angle) {
            double x = 0, y = 0;
            string j = "";
            double k = PI;
            double l = 0;
            
            for (const auto& p : pic) {
                string a = p.first;
                string b = p.second;
                if (b == "?") {
                    j = a;
                    l = k;
                } else
                if (a == "fd") {
                    x += stod(b) * cos(k);
                    y += stod(b) * sin(k);
                } else 
                if (a == "bk") {
                    x -= stod(b) * cos(k);
                    y -= stod(b) * sin(k);
                } else 
                if (a == "lt") {
                    k += stod(b) * PI / 180;
                } else 
                if (a == "rt") {
                    k -= stod(b) * PI / 180;
                }
            }
            ll ans = round(x / cos(l));
            cout << abs(ans) << '\n';
        } else {
            for (int i = 0; i < 360; ++i) {
                double k = PI;
                double x = 0, y = 0;
                for (const auto& p : pic) {
                    string a = p.first;
                    string b = p.second;
                    double bb;
                    if (b == "?") {
                        bb = i;
                    } else {
                        bb = stod(b);
                    }

                    if (a == "fd") {
                        x += bb * cos(k);
                        y += bb * sin(k);
                    } else 
                    if (a == "bk") {
                        x -= bb * cos(k);
                        y -= bb * sin(k);
                    } else 
                    if (a == "lt") {
                        k += bb * PI / 180;
                    } else {
                        k -= bb * PI / 180;
                    }
                }
                if (abs(x) < 1e-6 && abs(y) < 1e-6) {
                        cout << i << '\n';
                        break;
                    }

            }
        }
    }
}
