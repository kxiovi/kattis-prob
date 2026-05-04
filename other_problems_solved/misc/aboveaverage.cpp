#include <bits/stdc++.h>

using namespace std;

// const int MAX = 50;

bool isNumber(const string& str) {
    char *p;
    strtol(str.c_str(), &p, 10);
    return *p == '\0';
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2) - (y1-y2)*(y1-y2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(3);

    int c; 
    cin >> c;
    for (int j = 0; j < c; ++j) {
        int n;
        cin >> n;
        vector<int> v(n);
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            total += v[i];
        }
        double avg = total * 1.0 / n;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] > avg) {
                count++;
            }
        }
        double ans = count * 1.0 / n * 100.0;
        cout << ans << "%\n";
    }

    
    
}
