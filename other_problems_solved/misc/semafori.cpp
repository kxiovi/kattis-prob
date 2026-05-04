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

    int n, l;
	cin >> n >> l;
	int ans = 0;
	int prev_d = 0;
	while (n--) {
		int r, g, d;
		cin >> d >> r >> g;
		ans = ans + (d - prev_d);
		prev_d = d;

		vector<bool> v;
		int target = l*10;
		while (v.size() < target) {
			for (int i = 0; i < r && v.size() < target; ++i) {
				v.push_back(false);
			}

			for (int i = 0; i < g && v.size() < target; ++i) {
				v.push_back(true);
			}
		}

		// for (bool b : v) {
		// 	cout << b << " ";
		// }
		// cout << "\n";

		while (v[ans] == false) {
			ans++;
		}


	}

	ans = ans + (l - prev_d);

	cout << ans;
}
