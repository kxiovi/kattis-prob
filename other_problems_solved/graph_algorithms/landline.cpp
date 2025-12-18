// resources: 
//   - Kruskals: https://cp-algorithms.com/graph/mst_kruskal.html 
//   - UnionFind: kactl - Lukas Polacek

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Edge {
  int u, v, weight;
  bool operator<(Edge const& other) {
    return weight < other.weight;
  }
};

struct UF {
  vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }

};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p;
    cin >> n >> m >> p;

    set<int> insecure;

    {int a;
    for (int i = 0; i < p; ++i) {
      cin >> a;
      insecure.insert(a);
    }}

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
      cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // corner case n == 2
    if (n == 2) {
      int minimo = edges[0].weight;
      cout << minimo; 
      return 0;
    }
    

    // otherwise
    // Kruskal's
    sort(edges.begin(), edges.end());

    UF uf(n+1); 
    ll cost = 0;
    int edges_used = 0;
    vi degree(n+1, 0);
    
    for (Edge& e : edges) {
      if (insecure.contains(e.u) && insecure.contains(e.v)) continue;
      if ((insecure.contains(e.u) && degree[e.u] >= 1) || 
          (insecure.contains(e.v) && degree[e.v] >= 1)) continue;
      
      if (uf.join(e.u, e.v)) {
        cost += e.weight;
        edges_used++;
        degree[e.u]++;
        degree[e.v]++;
      }

      if (edges_used == n-1) break;
    }

    // cout << edges_used << endl;

    if (edges_used != n-1) {
      cout << "impossible";
      return 0;
    }

    // for (int a : insecure) {
    //   if (degree[a] > 1) {
    //     cout << "impossible";
    //     return 0;
    //   }
    // }

    cout << cost;
}
