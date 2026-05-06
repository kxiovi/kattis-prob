#include <bits/stdc++.h>

using namespace std;

const double TORADIANS = M_PI / 180;

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
    cout << fixed << setprecision(0);

    int t; 
    cin >> t; 
    for (int i = 0; i < t; ++i) {
        int commands;
        cin >> commands;
        double x = 0; 
        double y = 0;
        double angle = 0;  // shuold be in rad
        double dist = 0;
        for (int j = 0; j < commands; ++j) {
            string a; 
            double b; 
            cin >> a >> b;
            
            if (a == "fd") {
                x += b * cos(angle);
                y += b * sin(angle);
            } else
            if (a == "bk") {
                x -= b * cos(angle);
                y -= b * sin(angle);
            } else 
            if (a == "lt") {
                angle += b * M_PI / 180;
                // angle += b;
            } else 
            if (a == "rt") {
                angle -= b * M_PI / 180;
                // angle -= b;
            }

        }
        cout << sqrt(x*x + y*y) << "\n";
    }
    
}
