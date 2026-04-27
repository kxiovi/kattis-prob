#include <bits/stdc++.h>

using namespace std;

// const int MAX = 50;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a1, c1, a2, c2;
    int p, m, g;
    cin >> a1 >> c1 >> a2 >> c2;
    cin >> p >> m >> g;

    int dog1 = a1 + c1;
    int dog2 = a2 + c2;

    int ans = 0;

    int posp1 = p % dog1;
    int posp2 = p % dog2;
    if (posp1 == 0) posp1 = dog1;
    if (posp2 == 0) posp2 = dog2;

    if (posp1 <= a1) ans++;
    if (posp2 <= a2) ans++;

    if (ans == 0) cout << "none\n";
    else if (ans == 1) cout << "one\n";
    else if (ans == 2) cout << "both\n";

    // could've been a for loop :(((((())))))

    ans = 0;
    int posm1 = m % dog1;
    int posm2 = m % dog2;
    if (posm1 == 0) posm1 = dog1;
    if (posm2 == 0) posm2 = dog2;

    if (posm1 <= a1) ans++;
    if (posm2 <= a2) ans++;

    if (ans == 0) cout << "none\n";
    else if (ans == 1) cout << "one\n";
    else if (ans == 2) cout << "both\n";

    // feiojiwjjewijijewiwjfiewfji
    ans = 0;
    int posg1 = g % dog1;
    int posg2 = g % dog2;
    if (posg1 == 0) posg1 = dog1;
    if (posg2 == 0) posg2 = dog2;

    if (posg1 <= a1) ans++;
    if (posg2 <= a2) ans++;

    if (ans == 0) cout << "none\n";
    else if (ans == 1) cout << "one\n";
    else if (ans == 2) cout << "both\n";



}
