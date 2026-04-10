#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    if (N%4 == 0) {
        cout << "Even";
    } else
    if (N%2 == 0) {
        cout << "Odd";
    } else {
        cout << "Either";
    }
}
