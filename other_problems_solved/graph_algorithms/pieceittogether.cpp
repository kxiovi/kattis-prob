// references: 
//   - hopcroftKarp: kactl - Chen Xing

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a]) if (B[b] == L + 1) {
        B[b] = 0;
        if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
            return btoa[b] = a, 1;
    }
    return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
    int res = 0;
    vi A(g.size()), B(btoa.size()), cur, next;
    for (;;) {
        fill(all(A), 0);
        fill(all(B), 0);
        /// Find the starting nodes for BFS (i.e. layer 0).
        cur.clear();
        for (int a : btoa) if(a != -1) A[a] = -1;
        rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
        /// Find all layers using bfs.
        for (int lay = 1;; lay++) {
            bool islast = 0;
            next.clear();
            for (int a : cur) for (int b : g[a]) {
                if (btoa[b] == -1) {
                    B[b] = lay;
                    islast = 1;
                }
                else if (btoa[b] != a && !B[b]) {
                    B[b] = lay;
                    next.push_back(btoa[b]);
                }
            }
            if (islast) break;
            if (next.empty()) return res;
            for (int a : next) A[a] = lay;
            cur.swap(next);
        }
        /// Use DFS to scan for augmenting paths.
        rep(a,0,sz(g))
            res += dfs(a, 0, g, btoa, A, B);
    }
}

struct Tile {
    int br, bc;
    int w1r, w1c;
    int w2r, w2c;
    int var;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n);
    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        for (char c : line) {
            grid[i].push_back(c);
        }
    }

    vector<pii> blacks;
    map<pii,int> whiteMap;
    int whites = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'B') {
                blacks.push_back({i,j});
            } else 
            if (grid[i][j] == 'W') {
                whiteMap[{i,j}] = whites++;
            }
        }
    }

    int numB = blacks.size();
    if (whites != 2*numB) { 
        cout << "NO"; 
        return 0; 
    }

    int n_left = 2*numB;  // total nodes (i.e. amount of whites)
    vector<vi> graph(n_left);  
    vector<pii> hort = {{0, -1}, {0, 1}};
    vector<pii> vert = {{-1, 0}, {1, 0}};

    for (int i = 0; i < numB; ++i) {
        auto [r,c] = blacks[i];
        int h = 2 * i;
        int v = 2 * i + 1;

        for (auto [dr,dc] : hort) {
            int nr = r+dr;
            int nc = c+dc;
            if (0 <= nr && nr < n && 0 <= nc && nc < m && grid[nr][nc]=='W')
                graph[h].push_back(whiteMap[{nr,nc}]);
        }

        for (auto [dr,dc] : vert) {
            int nr = r+dr;
            int nc = c+dc;
            if (0 <= nr && nr < n && 0 <= nc && nc < m && grid[nr][nc]=='W')
                graph[v].push_back(whiteMap[{nr,nc}]);
        }
    }

    // all left handed has at least one right handed node
    for (auto &node : graph) {
        if (node.empty()) { 
        cout << "NO"; 
        return 0; 
        }
    }

    vi btoa(whites, -1);
    int matching = hopcroftKarp(graph, btoa);

    if (matching == n_left) cout << "YES";
    else cout << "NO";
}
