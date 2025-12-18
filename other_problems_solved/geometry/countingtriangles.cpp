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

struct Line {
  double x1, y1, x2, y2;
};

bool intersection(Line& line1, Line& line2) {
  double x11 = line1.x1;
  double y11 = line1.y1;
  double x12 = line1.x2;
  double y12 = line1.y2;
  double x21 = line2.x1;
  double y21 = line2.y1;
  double x22 = line2.x2;
  double y22 = line2.y2;

  // determinant = 0 means that pq are parallel
  double denominator = (x11 - x12) * (y21 - y22) - (y11 - y12) * (x21 - x22);
  if (denominator == 0) { return false; }

  double s = ((x11 - x21) * (y21 - y22) - (y11 - y21) * (x21 - x22)) / denominator;
  double t = -((x11 - x12) * (y11 - y21) - (y11 - y12) * (x11 - x21)) / denominator;
  if (s >= 1e-6 && s <= 1 + 1e-6 && t >= -1e-6 && t <= 1 + 1e-6) { return true; }

  return false;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    
    while (n != 0) {
      vector<Line> lines(n);
      for (int i = 0; i < n; ++i) {
        double q, w, e, r;
        cin >> q >> w >> e >> r;
        lines[i].x1 = q;
        lines[i].y1 = w;
        lines[i].x2 = e;
        lines[i].y2 = r;
      }

      int count = 0;
      for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
          if (!intersection(lines[i], lines[j])) continue;
          for (int c = j+1; c < n; c++) {
            if (intersection(lines[j], lines[c]) && intersection(lines[c], lines[i])) {
              count++;
            }
          }
        }
      }
      cout << count << '\n';
      // read next n
      cin >> n;
    }

    // read in the input
    

    // a must intersect b, b must intersect c, c must intersect a
    // check if they intersect
    // if yes, count++ else continue to permuation/test
    return 0;

}