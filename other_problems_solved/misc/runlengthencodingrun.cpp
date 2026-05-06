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

    char coding;
    cin >> coding;

    string str;
    cin >> str;
    if (coding == 'E') {
        int count = 1;
        for (int i = 1; i < str.length()+1; ++i) {
            if (str[i-1] == str[i]) {
                count++;
            } else {
                cout << str[i-1] << count;
                count = 1;
            }
        }
    }
    else if (coding == 'D') {
        for (int i = 1; i < str.length(); i+=2) {
            char c = str[i-1];
            int count = str[i]-48;
            for (int j = 0; j < count; ++j) {
                cout << c;
            }
        }
    }
    
}
