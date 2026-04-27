/*
References: https://archive.algo.is/icpc/nwerc/ncpc/2016/ncpc2016slides.pdf 
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


int find(unordered_map<int, int>& g2, int x);
void join(unordered_map<int, int>& g2, int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(0);

    int n;
    cin >> n;
    // map to represent undirected graph
    unordered_map<int, vector<int>> g1;

    // map to represent what the parent of each node is. -1 == root
    unordered_map<int, int> g2;

    while(n--) {
        int s, t;
        cin >> s >> t;
        g1[s].push_back(t);
        g1[t].push_back(s);

        // assign -1 to every value of s, t initially
        if (g2.count(s) == 0) {
            g2[s] = -1;
        } 
        if (g2.count(t) == 0) {
            g2[t] = -1;
        }

        join(g2, s, t);
    }
    
    // root : connected components (i.e. the nodes that make up the cc)
    unordered_map<int, vector<int>> cc;
    for (auto& i : g2) {
        cc[find(g2, i.first)].push_back(i.first);
    } 

    long long total = 0;
    for (auto& [root, nodes] : cc) {
        int ncount = nodes.size();
        int ecount = 0;
        int maxnode = 0;

        for (auto z : nodes) {
            long deg = g1[z].size();
            total += (deg - 1) * z;
            ecount += deg;
            maxnode = max(maxnode, z);
        }

        ecount = ecount / 2;

        // a tree has edges = nodes - 1
        // thus if it's a tree, the largest side will be added to the vertical contribution
        // the node being entered, never exited is the vertical s
        // and the node being exited, never entered, is the horizontal t
        if (ecount < ncount) {
            total += maxnode;
        }

        // if ecount == ncount, then it's a cycle. 
    }
    cout << total << endl;
}


int find(unordered_map<int, int>& g2, int x) {
    if (g2[x] == -1) return x;
    else {
        g2[x] = find(g2, g2[x]);
        return g2[x];
    }
}

void join(unordered_map<int, int>& g2, int a, int b) {
    a = find(g2, a);
    b = find(g2, b);
    // if a and b have the same root, then they are already in the same component
    if (a == b) return;

    // else, make one root point to the other thereby merging 2 components
    else g2[a] = b;
}
