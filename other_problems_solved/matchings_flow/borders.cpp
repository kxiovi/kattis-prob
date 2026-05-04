/*
References: 
kactl - Dinic

This is a bipartite graph problem because adjacent regions always have opposite values. 
A 'region' is either a cluster of adjacent 1's or 0's. 
A region can contribute only once regardless of how many neighbours it has. 

A node: each region with the same value of pixels. 
2 nodes are connected if their regions share a border segment. 
Thus edge connects adjacent regions of opposing value. 

if a region is already touching a boundary, they can be excluded from the flow

source --> layer for nodes representing 0 value regions --> layer for nodes representing 1 value regions --> sink
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
    // cout << fixed << setprecision(0);

    int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (auto& r : grid) {
		cin >> r;
	}

	vector<vi> label(n, vi(m, -1));
	int numRegions = 0;
	vi val;
	vector<bool> touchesBoundary;

	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (label[r][c] != -1) continue;
			int v = grid[r][c] - '0';
			int id = numRegions++;
			val.push_back(v);
			touchesBoundary.push_back(false);
			queue<pii> bfsq;
			bfsq.push({r, c});
			label[r][c] = id;
			while (!bfsq.empty()) {
				auto [x, y] = bfsq.front();
				bfsq.pop();

				// check if the cell is on the boundary or not
				if (x==0 || x==n-1 || y==0 || y==m-1) {
					touchesBoundary[id] = true;
				}
				for (int k = 0; k < 4; ++k) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && label[nx][ny] == -1) {
						if (grid[nx][ny] - '0' == v) {
							label[nx][ny] = id; 
							bfsq.push({nx, ny});
						}
					} 
				}
			}
		}
	}

	// regions that must be selected i.e. those touching the boundary
	// the outside can't be 'selected'
	vector<bool> mustSelect(numRegions, false);
	for (int i = 0; i < numRegions; ++i) {
		if (touchesBoundary[i]) {
			mustSelect[i] = true;
		}
	} 

	// find adjacency eges between interior (non-boundary) regions
	// the remaining uncovered edges are b/w 2 non-boundary regions
	set<pii> edges;
	int dd[] = {0, 2};
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			for (int d : dd) {  // only right and down to avoid duplicates
				int nr = r + dx[d];
				int nc = c + dy[d];
				if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
				int u = label[r][c];
				int v = label[nr][nc];
				if (u == v) continue;
				if (mustSelect[u] || mustSelect[v]) continue;

				// both are interior, neither are forced-selected
				int u0 = (val[u] == 0) ? u : v;
				int u1 = (val[u] == 1) ? u : v;
				edges.insert({u0, u1});
			}
		} 
	}

	int s = numRegions; 
	int t = numRegions + 1;
	Dinic d(numRegions+2); 
	for (int i = 0; i < numRegions; ++i) {
		if (mustSelect[i]) continue;
		if (val[i] == 0) {
			d.addEdge(s, i, 1);
		} else {
			d.addEdge(i, t, 1);
		}
	}
	for (auto [u0, u1] : edges) {
		d.addEdge(u0, u1, 1);
	}

	int forced = count(mustSelect.begin(), mustSelect.end(), true);
	cout << forced + d.calc(s, t);
}
