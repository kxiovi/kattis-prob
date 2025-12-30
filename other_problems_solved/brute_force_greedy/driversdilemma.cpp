#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(0);

    // capacity, rate of feul leak, miles to gas station
   double c, x, m;
   cin >> c >> x >> m;

   vector<pair<int, double>> table (6);
   for (int i = 0; i < 6; ++i) {
    int a; 
    double b; 
    cin >> a >> b;
    table[i] = {a, b};
    // cout << table[i].first << " " << table[i].second << "\n";
   }

   for (int i = 5; i >= 0; --i) {
    double j = (double)m / table[i].first;  // distance/speed = time
    double w = (c / 2) - j * x; // only half tank left - feul leaked = remaining feul
    double n = m / table[i].second; // (miles) / (miles / gallons) = gallons needed
    // cout << j << " " << w << " " << n << "\n";
    if (w >= n) { 
      cout << "YES " << table[i].first;
      return 0;

    }   
  }
cout << "NO";
    
}
