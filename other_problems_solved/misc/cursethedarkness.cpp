#include <bits/stdc++.h>

using namespace std;

// const int MAX = 50;

bool isNumber(const string& str) {
    char *p;
    strtol(str.c_str(), &p, 10);
    return *p == '\0';
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

bool solve(double dist) {
    if (dist < 8) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(3);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        double bx, by;
        cin >> bx >> by;
        int n;
        cin >> n;
        bool flag = false;
        for (int j = 0; j < n; ++j) {
            double cx, cy;
            cin >> cx >> cy;
            double dist = distance(bx, by, cx, cy);
            if (!flag && solve(dist)) {
                cout << "light a candle\n";
                flag = true;
            }
        }
        if (!flag) cout << "curse the darkness\n";
    }

    
    
}
