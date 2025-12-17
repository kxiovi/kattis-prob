// Resources: binary addition using strings: https://www.youtube.com/watch?v=qjYPzyzrxsc

#include <bits/stdc++.h>
using namespace std;

int main() {
    string runes;
    unsigned long long days;
    cin >> runes >> days;

    for (int i = 0; i < runes.size(); ++i) {
        if (runes.at(i) == 'A') {
            runes.at(i) = '0';
        } else 
        if (runes.at(i) == 'B') {
            runes.at(i) = '1';
        }
    }

    reverse(runes.begin(), runes.end());
    // int intRunes = stoi(runes);

    string b = "";
    int m  = 1;
    for (int i = 0; i < 31; i++) { 
        if ((m & days) >= 1) b = "1" + b;
        else b = "0" + b;
        m <<= 1;
    }

    // cout << b << endl;
    b.erase(0, b.find_first_not_of('0'));    
    if (b.length() < runes.length()) {
        int diff = runes.length() - b.length();
        for (int i = 0; i < diff; ++i) {
            b = '0' + b;
        }
    }
    // cout << b << endl;
    // int intMask = stoi(mask);
    string sum = "";
    int r = 0;
    for (int i = runes.length() - 1; i >= 0; i--) {
        int d1 = runes.at(i) - '0';
        int d2 = b.at(i) - '0';
        int d = 0;
        if (d1 == 0 && d2 == 0) {
            if (r == 0) {
                d = 0; r = 0;
            } else {
                d = 1; r = 0;
            }

        } else if (d1 == 1 && d2 == 0) {
            if (r == 0) {
                d = 1; r = 0; 
            } else {
                d = 0; r = 1;
            }

        } else if (d1 == 0 && d2 == 1) {
            if (r == 0) {
                d = 1; r = 0;
            } else {
                d = 0; r = 1;
            }

        } else if (d1 == 1 && d2 == 1) {
            if (r == 0) {
                d = 0; r = 1;
            } else {
                d = 1; r = 1;
            }

        }
        sum = to_string(d) + sum;
    }

    reverse(sum.begin(), sum.end());

    for (int i = 0; i < sum.size(); ++i) {
        if (sum.at(i) == '0') {
            sum.at(i) = 'A';
        } else 
        if (sum.at(i) == '1') {
            sum.at(i) = 'B';
        }
    }
    cout << sum << endl;
}