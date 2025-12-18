// resources: kactl: Point, OnSegment, SegmentDistance, SegmentIntersection, UnionFind

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

const double EPS = 1e-8;
const double PI = 3.14159265359;
// using point = complex<double>;

// double dot(point a, point b) { return real(a*conj(b)); }
// double cross(point a, point b) { return imag(a*conj(b)); }

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P> bool onSegment(P s, P e, P p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

typedef Point<double> P;
double segDist(P& s, P& e, P& p) {
    if (s==e) return (p-s).dist();
    auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
    return ((p-s)*d-(e-s)*t).dist()/d;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b),
         oc = a.cross(b, c), od = a.cross(b, d);
    // Checks if intersection is single non-endpoint point.
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return {(a * ob - b * oa) / (ob - oa)};
    set<P> s;
    if (onSegment(c, d, a)) s.insert(a);
    if (onSegment(c, d, b)) s.insert(b);
    if (onSegment(a, b, c)) s.insert(c);
    if (onSegment(a, b, d)) s.insert(d);
    return {all(s)};
}

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(1);


    int N, M; 
    cin >> N >> M;
    vector<P> graph(N);
    for (int i = 0; i < N; ++i) {
      int x, y;
      cin >> x >> y; 
      graph[i] = P(x, y);
    }

    // read in the edges
    vector<pii> edges(M);
    // vector<vector<int>> neighbours(N);
    for (int i = 0; i < M; ++i) {
      int j, k;
      cin >> j >> k;
      edges[i] = {j, k};
      // neighbours[j].push_back(k);
      // neighbours[k].push_back(j);
    }

    // Involves planar graphs and Euler's formula
    
    // all nodes must be connected: 
    // use UF; if all nodes don't have the same root, not connected
    UF uf(N);
    for (auto [u, v]: edges) {
      uf.join(u, v);
    }

    int root = uf.find(0);
    for (int i = 0; i < N; ++i) {
      if (uf.find(i) != root) {
        cout << -1;
        return 0;
      }
    }

    for (int i = 0; i < M; ++i) {
      for (int j = i+1; j < M; ++j) {
        P a = graph[edges[i].first];
        P b = graph[edges[i].second];
        P c = graph[edges[j].first];
        P d = graph[edges[j].second];
        vector<P> sinter = segInter(a, b, c, d);
        if (!sinter.empty()) {
          // intersection can only be at one common endpoint
          if (sinter.size() != 1) {
            cout << -1;
            return 0;
          }
          P p = sinter[0];
          bool flag = ((p == a || p == b) && (p == c || p == d));
          if (!flag) {
            cout <<  -1;
            return 0;
          }
        }
      }
    }

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        P p = graph[i];
        P s = graph[edges[j].first];
        P e = graph[edges[j].second];
        if (p != s && p != e) {
          if (onSegment(s, e, p)) {
            cout << -1;
            return 0;
          }
          
        }
      }
    }

    int eulers = M - N + 2; 
    cout << eulers;
    return 0;

}