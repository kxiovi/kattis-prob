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

    int n, e, d;
    cin >> n >> e >> d;
    set<int> explodingKittenCards;
    int card;
    for (int i = 0; i < e; ++i) {
      cin >> card;
      explodingKittenCards.insert(card);
    }
    set<int> defuseCards;
    for (int i = 0; i < d; ++i) {
      cin >> card; 
      defuseCards.insert(card);
    }
    vector<pii> special;  // {pos, cat or defuse}
    for (int pos : explodingKittenCards) {
      special.push_back({pos, 1});
    }
    for (int pos : defuseCards) {
      special.push_back({pos, 2});
    }
    sort(all(special));

    vector<int> playersInGame(n);
    iota(all(playersInGame), 0);

    vector<int> playerdefuses(n, 0); 
    vector<int> playerHand(n, 0);
    int curr_card = 0;
    int curr_player = 0;
    int kittens = 0;

    for (auto& [pos, card] : special) {
      if (playersInGame.size() <= 1 || e <= kittens) break;
      int cards_to_advance = pos - curr_card;
      curr_player = (curr_player + cards_to_advance) % playersInGame.size();
      int player = playersInGame[curr_player];
      curr_card = pos+1;

      if (card == 1) {
        kittens++;
        if (playerdefuses[player] > 0) {
          playerdefuses[player]--;
          curr_player = (curr_player + 1) % playersInGame.size();
        } else {
          playersInGame.erase(playersInGame.begin() + curr_player);
          if (playersInGame.size() == 0) {
            cout << -1;
            return 0;
          }
          if (curr_player >= playersInGame.size()) curr_player = 0;
        }
      } else {
        if (playerdefuses[player] < 5) {
          playerdefuses[player]++;
        } 
        curr_player = (curr_player + 1) % playersInGame.size();
      }
    }

    if (playersInGame.size() == 1) {
      cout << playersInGame[0]; 
    } else {
      cout << -1;
    }
}
