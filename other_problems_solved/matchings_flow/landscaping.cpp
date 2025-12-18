// resources: kactl - Dinic

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
    // cout << fixed << setprecision(6);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<char>> grid(n, vector<char>(m, ' '));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int source = 0;
    // 1 to n*m == grid cells
    int sink = n * m + 1;
    Dinic dinic(sink+1);
    // bidirectional edges
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int node = i * m + j + 1;  // node index
            // low on source, high on sink side
            if (grid[i][j] == '.') {
                dinic.addEdge(source, node, b);
            } else {
                dinic.addEdge(node, sink, b);
            }

            // get neighbours directly to the right and underneath
            int dx[] = {0, 1};
            int dy[] = {1, 0};
            for (int c = 0; c < 2; ++c) {
                int ci = i + dx[c];
                int cj = j + dy[c];
                if (ci < n && cj < m) {
                    int neighbour = ci * m + cj + 1;
                    dinic.addEdge(node, neighbour, a, a);  // reverse cap (bidirectional)
                }
            }
        }
    }
    // if source to node edge is cut, that node is on sink side. 
    // if node to sink edge is cut, the node is on source side. 
    // if node is not cut, its elevation is unchanged
    ll minimo = dinic.calc(source, sink);
    cout << minimo;
}

