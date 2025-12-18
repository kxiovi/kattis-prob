#include <bits/stdc++.h>
using namespace std;

using ulll = __uint128_t;
// using ull = uint64_t;

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
    // cout << fixed << setprecision(1);

    int n;
    cin >> n;

    // this is suspect
    // if (n < 7) {
    //   cout << "none";
    //   return 0;
    // }

    vector<string> song(n);
    for (int i = 0; i < n; ++i) {
      cin >> song[i];
    }

    vector<string> notes = {"A", "A#", 
    "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};

    vector<int> majorScale = {2, 4, 5, 7, 9, 11, 12};
    
    // for every note, get it's major scale
    map<string, set<string>> allscales;
    for (int i = 0; i < 12; ++i) {
      for (int j : majorScale) {
        allscales[notes[i]].insert(notes[(i+j) % 12]);
      }
    }


    // for (auto& a : allscales["A#"]) {
    //   cout << a << " ";
    // }
    // cout << "\n";

    bool atleastone = false;
    for (auto& note : notes) {
      bool flag = true;  // true until proven that note in song is not in scale
      for (auto& s : song) {
        if (!allscales[note].contains(s)) {
          flag = false;
          break;
        }
      }
      if (flag) {
        atleastone = true;
        cout << note << " ";
      }
    }

    if (!atleastone) {
      cout << "none";
    }



}