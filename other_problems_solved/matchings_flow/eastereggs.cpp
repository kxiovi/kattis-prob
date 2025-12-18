// sources: kactl - hopcroftKarp

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
eastereggs: If I told you there is a solution with largest minimum distance >= D, could you 
at least verify that using an algorithm from this week's topic?
topics: bipartite, matchings, Hopcroft-Karp, Network Flow, 
*/

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

bool solve(long double a, int n, int b, int r, vector<vector<double>> distances) {
    vector<vi> g(b);
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < r; ++j) {   
            if (distances[i][j] < a) {
                g[i].push_back(j);
            }
        }
    }
    // matched is the number of blue-red pairs with distance < a
    // we must place n eggs with at least matched of each colour
    // thus, verify that we have at least n pairs with distance >= a
    vector<int> btoa(r, -1);
    int m = hopcroftKarp(g, btoa);
    return b + r - m >= n;
}

double distance(double ax, double ay, double bx, double by) {
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(6);

    int n, b, r;
    cin >> n >> b >> r;

    /*
    maximize the minimum dist b/w any blue red pair
    so we try diff min dist from 0 to pow(10, 10) [maybe higher]
      - binary search
      - solve algo will be bipartite
    */
    vector<pair<double, double>> blue(b);
    vector<pair<double, double>> red(r);
    for (int i = 0; i < b; ++i ) {
        cin >> blue[i].first >> blue[i].second;
    }
    for (int i = 0; i < r; ++i) {
        cin >> red[i].first >> red[i].second;
    }

    vector<vector<double>> distances(b);
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < r; ++j) {
            double d = distance(blue[i].first, blue[i].second, red[j].first, red[j].second);
            distances[i].push_back(d);
        }
    }

    vector<double> distances_flat;
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < r; ++j) {
            distances_flat.push_back(distances[i][j]);
        }
    }

    // bin search on the distances
    sort(all(distances_flat));

    int low = 0; 
    int high = distances_flat.size() - 1;
    double ans = 0.0;
    while (low <= high) {
        int mid = (low+high) / 2;
        double dist = distances_flat[mid];
        if (solve(dist, n, b, r, distances)) {
            ans = dist;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans;

}
