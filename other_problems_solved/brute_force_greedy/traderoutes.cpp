// resource: small to large merging: https://codeforces.com/blog/entry/103064

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

// const double EPS = 1e-8;
// const double PI = 3.14159265359;
// using point = complex<double>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(7);

    // greedy
    int n;
    cin >> n;  // num cities; rome is 1

    vector<int> p(n-1);
    for (int i = 0; i < n-1; ++i) {
      int v;
      cin >> v;
      v -= 1;
      p[i] = v;
    }
    
    vector<int> max_routes(n);
    for (int i = 0; i < n; ++i) {
      int v;
      cin >> v;
      max_routes[i] = v;
    }

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
      int v;
      cin >> v;
      values[i] = v;
    }

    // uses min heap to eliminate the smallest value routes (greedy)
    vector<priority_queue<pii, vector<pii>, greater<pii>>> pq(n); // {city, value} // default is max heap

    for (int i = n-1; i >= 0; --i) {
      pq[i].push({values[i], i});

      // cannot have more than cap cities (constraint)
      while(pq[i].size() > max_routes[i]) {
        pq[i].pop();
      }

      if (i > 0) {  // rome doesn't count
        int pi = p[i-1];  // reachable city
        
        if (pq[i].size() <= pq[pi].size()) {
          // push paths from i to i-1
          // this is the bottleneck i think
          while (!pq[i].empty()) {
            pq[pi].push(pq[i].top());
            pq[i].pop();
          }
        } else 
        if (pq[i].size() > pq[pi].size()) {
          swap(pq[i], pq[pi]);
          while (!pq[i].empty()) {
            pq[pi].push(pq[i].top());
            pq[i].pop();
          }
          
        }

      }
    }

    ll ans = 0;
    vector<int> cities;
    while (!pq[0].empty()) {
      auto [v, c] = pq[0].top();
      ans += v;
      cities.push_back(c+1);
      pq[0].pop();
    }

    sort(all(cities));

    cout << ans << "\n";
    cout << cities.size() << " ";
    for (auto c : cities) {
      cout << c << " ";
    }

}