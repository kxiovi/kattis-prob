#include <bits/stdc++.h>

using namespace std;

// const int MAX = 50;

bool isNumber(const string& str) {
    char *p;
    strtol(str.c_str(), &p, 10);
    return *p == '\0';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        string str; 
        cin >> str;
        count++;
        if (isNumber(str)) {
            if (count != stoi(str)) {
                cout << "something is fishy";
                return 0;
            }
        } 
    }
    cout << "makes sense";
    
    
}
