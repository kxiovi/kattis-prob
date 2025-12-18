// resources: kactl - LCA, RMQ

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
boxes: Consider the tree-like structure of nested boxes. Consider using least-common ancestor 
queries to help solve the problem. Do some small examples by hand to get a sense for how to 
approach this one.
*/

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

/* 
Description: Data structure for computing lowest common ancestors in a tree
 * (with 0 as root). C should be an adjacency list of the tree, either directed
 * or undirected.
*/
struct LCA {
    int T = 0;
    vi time, path, ret, depth;
    RMQ<int> rmq;

    LCA(vector<vi>& C) : time(sz(C)), depth(sz(C)), rmq((dfs(C,0,-1), ret)) {}
    void dfs(vector<vi>& C, int v, int par) {
        time[v] = T++;
        for (int y : C[v]) if (y != par) {
            depth[y] = depth[v] + 1;
            path.push_back(v), ret.push_back(time[v]);
            dfs(C, y, v);
        }
    }

    int lca(int a, int b) {
        if (a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
    
    // check if a is an ancestor of b
    bool is_ancestor(int a, int b) {
        if (a == b) return true;
        return lca(a, b) == a && depth[b] > depth[a];
    }
};

vector<vi> children;
vector<int> depth;

void mydfs(int node) { // dfs to get depth from root
    depth[node] = 1;
    for (auto child : children[node]) {
        mydfs(child);
        depth[node] += depth[child];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(7);
    
    int n;
    cin >> n;
    
    // all 0 indexed
    children.resize(n+1);
    depth.resize(n+1);
    // vi parent(n);
    vi roots;
    
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        if (p == 0) {
            // parent[i] = -1;
            roots.push_back(i);
            children[0].push_back(i);
        } else {
            // parent[i] = p - 1;
            children[p].push_back(i);
        }
    }

    
    LCA lca_(children);
    for (int r : roots) {
        mydfs(r);
    }
    
    int q;
    cin >> q;
    
    for (int s = 0; s < q; ++s) {
        int k;
        cin >> k;
        
        vector<int> visited;
        for (int i = 0; i < k; ++i) {
            int box;
            cin >> box;
            visited.push_back(box);
        }
        
        vector<int> final;
        for (int box : visited) {
            bool is_descendant = false;
            for (int b : visited) {
                if (b != box && lca_.is_ancestor(b, box)) {
                    is_descendant = true;
                    break;
                }
            }
            
            if (!is_descendant) {
                final.push_back(box);
            }
        }
        
        int ans = 0;
        for (int b : final) {
            ans += depth[b];
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
