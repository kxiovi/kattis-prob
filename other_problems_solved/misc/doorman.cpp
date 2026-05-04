#include <bits/stdc++.h>

using namespace std;

// const int MAX = 50;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;

    string people;
    cin >> people;

    int w = 0;
    int m = 0;
    for (int i = 0; i < people.length(); ++i) {
        char p = people[i];
        if (p == 'W' && abs(w-m) <= n) {
            w++;
        } else 
        if (p == 'M' && abs(w-m) <= n) {
            m++;
        }
        // cout << abs(w-m) << endl;

        if (abs(w-m) > n) {
            // cout << "Here" << endl;
            // cout << people.length() << " " << i+1 << endl;
            if (people.length() > (i+1)) {
                // cout << "HERE poeple len" << endl;
                // cout << p << " " << people[i+1] << endl;
                if (p == people[i+1]) {
                    // cout << "HERE\n";
                    cout << i;
                    return 0;
                } else 
                if (people[i+1] == 'W') {
                    w++;
                    m--;
                    people[i+1] = p;
                } else 
                if (people[i+1] == 'M') {
                    w--;
                    m++;
                    people[i+1] = p;
                }
            }
        }
    }

    cout << people.length();
    return 0;
}
