/*
References: 

*/

#include <bits/stdc++.h>
using namespace std;

long MODULO = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; 
    cin >> s;

    long ans = 0;
    long ones = 0;
    long k = 1;
    for (char c : s) {
        if (c == '0') {
            ans += ones;
            ans %= MODULO;
        } else 
        if (c == '1') {
            ones += k;
            ones %= MODULO;
        } else {
            ans = ones + (ans << 1);
            ans %= MODULO;
            ones = k + (ones << 1);
            ones %= MODULO;
            k = k << 1;
            k %= MODULO;
        }
    }

    cout << ans;
    
}