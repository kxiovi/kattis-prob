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


/*
piano: First just see if you can solve it if workers can work 7 days per week. Think of how 
we modelled some decisions that involve multiple components as a flow problem. Adapt that to 
this problem
*/

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
    cout << fixed << setprecision(6);

    int n, m, p;
    cin >> n;

    // everything is 0 indexed except days
    for (int nt = 0; nt < n; ++nt) {
        cin >> m >> p;  
        // if (p < 2) {
        //  cout << "serious trouble\n";
        //  continue;
        // }
        vector<pii> pianos(m);  // get times b and e
        int max_day = 100;
        for (int i = 0; i < m; ++i) {
            cin >> pianos[i].first >> pianos[i].second;
        }

        // indicesssssssssssss
        int source = 0;
        int mi = 1;
        int dayi = m + 1;
        int sink = max_day + dayi + 1;
        Dinic dinic(sink + 1);
        for (int i = 0; i < m; ++i) {
            dinic.addEdge(source, mi + i, 1);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = pianos[i].first; j <= pianos[i].second; ++j) {
                dinic.addEdge(mi + i, dayi + j - 1, 1);
            }
        }
        for (int i = 1; i <= max_day; ++i) {
            dinic.addEdge(dayi + i - 1, sink, p / 2);
        }
        ll flow = dinic.calc(source, sink);
        if (flow < m) {
            cout << "serious trouble\n";
        } else {
            // another flow with just weekdays
            Dinic justWeekdays(sink + 1);
            for (int i = 0; i < m; ++i) {
                justWeekdays.addEdge(source, mi + i, 1);
            }
            for (int i = 0; i < m; ++i) {
                for (int j = pianos[i].first; j <= pianos[i].second; ++j) {
                    int mo = j % 7; // 0 or 6 == weekend
                    if (mo != 0 && mo != 6) {
                        justWeekdays.addEdge(mi + i, dayi + j - 1, 1);
                    }
                }
            }
            for (int i = 1; i <= max_day; ++i) {
                justWeekdays.addEdge(dayi + i - 1, sink, p / 2);
            }

            ll weekflow = justWeekdays.calc(source, sink);

            if (weekflow < m) {
                cout << "weekend work\n";
            } else {
                cout << "fine\n";
            }
        }
    }
}
