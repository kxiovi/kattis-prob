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

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
char grid[4][4];
bool visited[4][4];
// map colour to the positions it occupies initially in input
map<char, vector<pair<int, int>>> dict;
vector<char> colours;
// int getIndex(int r, int c) (return r * 4 + c);
// pair<int, int> getRC(int index) {return {index/4, index % 4}};

bool solve(int node);

bool getPath(int node, char colour, pair<int, int> start, pair<int, int> end, vector<pair<int, int>>& path) {
  int r = path.back().first;
  int c = path.back().second;

  if (r == end.first && c == end.second) {
    if (solve(node+1)) {
      return true;
    }
    return false;
  }

  // o/w try neighbours
  for (int i = 0; i < 4; ++i) {
    int nr = dr[i] + r;
    int nc = dc[i] + c;

    if (0 <= nr && nr < 4 && 0 <= nc && nc < 4) {
      if (!visited[nr][nc] || (nr == end.first && nc == end.second)) {
        if (grid[nr][nc] == 'W' || grid[nr][nc] == colour) {
          visited[nr][nc] = true;
          path.push_back({nr, nc});

          if (getPath(node, colour, start, end, path)) {
            return true;
          } else {
            path.pop_back();
            if (!(nr == start.first && nc == start.second) && 
                !(nr == end.first && nc == end.second)) {
                  visited[nr][nc] = false;
                }
          }
        }
      }
    }
  }
  return false;
}

bool solve(int node) {
  if (node == colours.size()) {
    for (int r = 0; r < 4; ++r) {
      for (int c = 0; c < 4; ++c) {
        if (!visited[r][c]) { return false; }  // make sure all nodes are visited
      }
    }
    return true;
  }

  char colour = colours[node];
  pair<int, int> start = dict[colour][0];
  pair<int, int> end = dict[colour][1];

  visited[start.first][start.second] = true;
  visited[end.first][end.second] = true;

  vector<pair<int, int>> path;
  path.push_back(start);
  bool ans = getPath(node, colour, start, end, path);
  // if (!ans) {
  //   visited[start.first][start.second] = false;
  //   visited[end.first][end.second] = false;
  // }
  return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(1);

    // brute force since grid is only 4 x 4
    // vector<vector<char>> grid(4);
    for (int i = 0; i < 4; ++i) {
      string line;
      cin >> line;
      for (int j = 0; j < 4; ++j) {
        grid[i][j] = line[j];
        visited[i][j] = false;
        if (grid[i][j] != 'W') {
          dict[grid[i][j]].push_back({i, j});
        }
      }
    }

    for (auto& c : dict) {
      colours.push_back(c.first);
    }

    if (solve(0)) {
      cout << "solvable";
    } else {
      cout << "not solvable";
    }

}