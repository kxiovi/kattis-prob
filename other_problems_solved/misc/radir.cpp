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


bool check_win(set<pii>& cards) {
	for (auto [suit, val] : cards) {
		if (cards.count({suit, val+1}) && cards.count({suit, val+2})) {
			return true;
		}
	}
	return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(0);

	int n, p; 
    cin >> n >> p;
	int p2 = p;

	set<pii> init;
	vector<pii> drew;
	while(p--) {
		int a, b;
		cin >> a >> b;
		init.insert({a, b});
	}
	int dec = n-p2;
	while (dec--) {
		int a, b;
		cin >> a >> b;
		drew.push_back({a, b});
	}

	if (check_win(init)) {
		cout << 1;
		return 0;
	}
	
	int count = 0;
	for (auto [a, b] : drew) {
		init.insert({a, b});
		count++;
		if (check_win(init)) {
			cout << count;
			return 0;
		}
	}

	cout << "Neibb";
}
