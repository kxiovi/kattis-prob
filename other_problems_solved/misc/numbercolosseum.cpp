#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> v;
    v.reserve(N);

    bool done = false;
    bool pos = false;
    bool neg = false;

    for (int i = 0; i < N; ++i) {
        int c;
        cin >> c;

        done = false;
        while (!v.empty()) {
            int back = v.back();
            if ((back > 0 && c < 0) || (back < 0 && c > 0)) {
                if (abs(back) == abs(c)) {
                    v.pop_back();
                    done = true;
                    break;
                } else 
                if (abs(back) > abs(c)) {
                    v.back() = back + c;
                    done = true;
                    break;
                } else 
                if (abs(back) < abs(c)) {
                    c = back + c;
                    v.pop_back();
                }
            } else {
                break;
            }
            
        }

        if (!done) {
            v.push_back(c);
        }
    }

    if (v.empty()) {
        cout << "Tie!";
        return 0;
    }
    for (int c : v) {
        if (c > 0) pos = true;
        else neg = true;
    }

    if (pos && !neg) cout << "Positives win!\n";
    else cout << "Negatives win!\n";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
}
