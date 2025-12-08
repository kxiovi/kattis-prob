/*
  BEGIN-HEADER
  
  Name: Vidhi Patel
  
  Student-ID: 1702707

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  <List Resources Here>
  kactl - Dinic
  To decide which data structure to use to store input: https://ngoduyhoa.blogspot.com/2015/06/summary-of-different-containers.html
  reading in string: https://favtutor.com/blogs/split-string-cpp

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  <List Classmates Here>

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 303/403.

  END-HEADER
*/

#include <bits/stdc++.h>
using namespace std;

using ull = uint64_t;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	// not using ull for g may lead to overflow in some test cases
    ull r, e, g;
	cin >> r >> e >> g;

	// using unordered map like this: reindeer_id : [hour: [elves preferred]]
	// read everything in and store as 0 indexed for indexing in the network flow
	unordered_map <int, map<int, vi>> dict;
	for (int i = 0; i < r; ++i) {
		int reindeer_id;
		cin >> reindeer_id;
		while (true) {
			int hour;
			cin >> hour;
			if (hour == 0) break;  // termination symbol is 0

			string row;
			getline(cin, row); 
			stringstream ss(row);
			int elf;
			while (ss >> elf) {
				elf -= 1;
				dict[reindeer_id][hour].push_back(elf);
			}
		}
	}

	/*
	Network flow indices
	0: source
	1 to r*24: each note represents combination of reindeer and hour. Should be max 9*24.
	rhcombo + 1 to rhcombo + e*24: combination of elf and hour. 
	rhcombo + ehcombo + 1: sink
	*/

	int source = 0;
	int rhcombo = r * 24;
	int ehcombo = e * 24;
	int sink = rhcombo + ehcombo + 1;
	Dinic dinic(sink+1);

	const int r24 = r * 24;

	// for every reindeer, for each hour it can work, there is a cap of 1
	// since a reindeer can work for 1 elf per hour
	for (auto& [reindeer, hours] : dict) {
		for (auto& [hour, elves] : hours) {
			int rh = reindeer * 24 + hour + 1;
			dinic.addEdge(source, rh, 1);
			for (int elf : elves) {
				int eh = r24 + elf * 24 + hour + 1;
				dinic.addEdge(rh, eh, 1);
			}
		}
	}

	// each elf can work with only 1 reindeer per hour
	for (int elf = 0; elf < e; ++elf) {
		for (int hour = 0; hour < 24; ++hour) {
			dinic.addEdge(r24 + elf * 24 + hour + 1, sink, 1);
		}
	}

	ll ans = dinic.calc(source, sink);
	ll gift = ans * 25;
	if (gift >= g) {
		cout << "possible";
	} else {
		cout << "impossible";
	}
}