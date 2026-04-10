/*
References: https://zibada.guru/gcj/2008r4c/problems/#analysis-C
We find that a is the parent of b. a has degree D. For each of the children of b: 
- child 1: we have k - D choices since we cannot have a colour that any of a's edges has
- child 2: k - D - 1 choices
- child 3: k - D - 2 choices
Therefore, for every subtree from a parent (starting with root), we have k - D - (num of children of b) + 1 choices. 

for the sample: 
1)  the tree looks like this and has 10 possible colours: 

3
|
|
1 -------- 2
|
|
|
4

There are 3 nodes all connected to the root: 10 * 9 * 8 = 720 since 1-2 has 10 choices, 
then 1-3 has 9 choices, and 1-4 has 8 choices. 

2)   the tree looks like this and has 3 possible colours: 

1 ---- 2 ---- 3 ---- 4 ---- 5

For 1-2: 3 choices, 2-3, 2 choices, 3-4, 1 choice, and then 5 can be only one color, 
Thus: 3 * 2 * 1 * 1 = 6 rainbow colourings possible.
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

const ull MOD = 1000000009;
vector<vector<int>> adjacencies;
vector<bool> visited;

ull dfs(int node, int parent, int k) {
    ull ans = 1;
    
    int parent_degree = 0;
    if (parent != -1) parent_degree = adjacencies[parent].size();

    int free_colours = k - parent_degree;
    int used = 0;
    for (int a : adjacencies[node]) {
        if (a == parent) continue;
        ans = ans * (free_colours - used) % MOD;
        used++;
        ans = ans * dfs(a, node, k) % MOD; // dfs
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(0);

    int c;
    cin >> c;
    for (int i = 1; i <= c; ++i) {
        int n, k;
        cin >> n >> k;
        adjacencies.assign(n+1, {});
        for (int j = 0; j < n-1; ++j ) {
            int u, v;
            cin >> u >> v;
            adjacencies[u].push_back(v);
            adjacencies[v].push_back(u);
        }
        visited.assign(n+1, false);
        ull ans = dfs(1, -1, k);  // start at root, root has no parent therefore parent of root == -1
        cout << "Case #" << i << ": " << ans << "\n";
    }
    
}
