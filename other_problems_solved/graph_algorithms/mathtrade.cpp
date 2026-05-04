/*
References: 

goal: find the length of the largest cycle possible. 
in the graph, the nodes are the people, and the edges are the items. 
the incoming are the items wanted, and the outcoming are the has items. 
basically though, in the code, the only items that matter are the wants, because in a cycle, 
they are the same as the has items. 

i.e. the graph for sample 1 looks like this: 

|Maria|       |Sally| --->[clock] |Carlos|
				   ^               |
|                  |               | 
		    [doll]  \              / [painting]
				     \ |Steve| <--	

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

    int n;
	cin >> n;

	unordered_map<string, string> has;  // item -> person
	unordered_map<string, string> wants;  // person -> item

	while(n--) {
		string n, h, w;
		cin >> n >> h >> w;
		wants[n] = w;
		has[h] = n;
	}

	unordered_map<string, string> g;

	for (auto& [na, w] : wants) {
		auto it = has.find(w);
		if (it != has.end()) {
			// cout << it->second << "\n";
			g[na] = it->second;
		}
	}

	// now find the largest cycle in graph
	int ans = 0;
	unordered_map<string, bool> v; // visited

	for (auto& [na, _] : wants) {
		if (v[na]) continue;  // already checked the length of this cycle
		// all cycles must be disjoint by definition

		unordered_map<string, int> path;
		string node = na;
		int count = 0;
		while (!v[node] && !path.contains(node)) {
			if (!g.contains(node)) break;
			path[node] = count++;
			node = g[node];
		}
		if (path.contains(node)) {
			int c = count - path[node];
			if (c > ans) ans = c;
		}

		for (auto& [n, _] : path) v[n] = true;
	}

	if (ans >= 2) cout << ans;
	else cout << "No trades possible";
	
}
