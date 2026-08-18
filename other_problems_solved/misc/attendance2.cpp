/*
References: 
https://archive.algo.is/icpc/nwerc/2017/nwerc2017slides.pdf 
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

int inf = 1 << 30;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(0);

    int n;
	cin >> n;

	bool flag = true;
	queue<string> q;
	for (int i = 0; i < n; ++i) {
		string name;
		cin >> name;
		q.push(name);
		if (q.size() > 1 && q.back() == "Present!") {
			q.pop();
			q.pop();
		} else {
			if (q.size() > 1) {
				cout << q.front() << "\n";
				q.pop();
				flag = false;
			}
		}
	}
	if (!q.empty()) {
		cout << q.front();
		flag = false;
	}
	if (flag) cout << "No Absences";
    
    
}
