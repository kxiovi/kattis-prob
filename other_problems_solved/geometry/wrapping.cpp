// resources: kactl: convex hull and Point and PolygonArea

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

// kactl convex hull code: 
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
typedef Point<double> P;  // EDITED VIDHI
vector<P> convexHull(vector<P> pts) {
    if (sz(pts) <= 1) return pts;
    sort(all(pts));
    vector<P> h(sz(pts)+1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (P p : pts) {
            while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}
template<class T>
T polygonArea2(vector<Point<T>>& v) {
    T a = v.back().cross(v[0]);
    rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
    return a;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(1);


    int N; 
    cin >> N;

    // Involves rotating
    // convex hull

    for (int i = 0; i < N; ++i) {
      int n; 
      cin >> n;
      vector<P> pts;
      double totalArea = 0;
      for (int j = 0; j < n; ++j) {
        double x, y, w, h, v;
        cin >> x >> y >> w >> h >> v;

        totalArea += w*h;
        double angle = -v * PI / 180.0;

        double wArm = w/2.0;
        double hArm = h/2.0;
        P centre(x, y);
        vector<P> p = {
          P(-wArm, -hArm), 
          P(wArm, -hArm), 
          P(-wArm, hArm), 
          P (wArm, hArm)
        };
        for (auto& z : p) {
          P rotated = z.rotate(angle);
          pts.push_back(centre + rotated);
        }
      }
      vector<P> hull = convexHull(pts);
      double area = abs(polygonArea2(hull)) / 2;  // can have negative area
      double ans = (totalArea / area) * 100.0;

      cout << ans << " %\n";
    }

}
