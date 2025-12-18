#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
      int u, v;
      cin >> u >> v;
      graph[u-1].push_back(v-1);
      graph[v-1].push_back(u-1);
    }

    vector<int> army(N);
    for (int i = 0; i < N; i++) {
      cin >> army[i];
    }

   // treat n = 2 as a corner case
    if (N == 2) {
      if (army[0] > army[1]) {
        cout << army[0] + army[1];
      } else {
        cout << army[0];
      }
      return 0;
    }

   // for n >= 3 as
   long long ans = army[0];
   set<int> visited;
   visited.insert(0);

   priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
   for (int g : graph[0]) {
      pq.push({army[g], g});
   }

   while (!pq.empty()) {
    int next = pq.top().first;
    int island = pq.top().second;
    pq.pop();
    if (!visited.contains(island) && next < ans) {
      ans += next;
      visited.insert(island);
      for (int n : graph[island]) {
        if (!visited.contains(n)) {
          pq.push({army[n], n});
        }
      }
    }
   }

   cout << ans;
    
}
