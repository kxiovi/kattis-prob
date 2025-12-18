// Tries

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

struct TrieNode {
  TrieNode* ch[26];  // vs unordered map
  int count;
  // constructor
  TrieNode() : count(0) { memset(ch, 0, sizeof(ch)); }  
};


void addWord(const string& str, TrieNode* root) {
  TrieNode* node = root;
  for(char c : str) {
    int co = c - 'a';
    if (!node->ch[co]) {
      node->ch[co] = new TrieNode();
    }
    node = node->ch[co];
    node->count++;
  }
}

int solve(TrieNode* root, const string& str) {
  TrieNode* node = root;
  for (char c : str) {
    int co = c - 'a';
    if (!node->ch[co]) {
      return 0;
    } else {
      node = node->ch[co];
    }
  }
  return node->count;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(7);

    int n; 
    cin >> n;
    TrieNode* root = new TrieNode();
    for (int i = 0; i < n; ++i) {
      string word;
      cin >> word;
      cout << solve(root, word) << '\n';
      addWord(word, root);
    }
}