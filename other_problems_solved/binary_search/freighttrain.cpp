// References
// Binary Search: https://www.geeksforgeeks.org/dsa/binary-search/
// struct to pass variables: https://stackoverflow.com/questions/6687088/performance-implications-of-global-variables-in-c 


#include <bits/stdc++.h>
using namespace std;

struct Variables {
    int N, W, L;
    vector<int> arr;
};

bool query(int maxWagons, const Variables& v) {
    // asking: does the train split into <= L locomotives if each train is at most x long? 
    // where x = maxWagons
    int trainsUsed = 0; 
    int wagonIdx = 1; 
    int freightIdx = 0;  // arr idx
    while (freightIdx < v.W) {
        if (v.arr[freightIdx] - wagonIdx < maxWagons) {
            trainsUsed++; 
            wagonIdx += maxWagons;
            while (freightIdx < v.W && v.arr[freightIdx] < wagonIdx) freightIdx++;
        } else {
            trainsUsed++;  // can attach arbitrary wagons to trains going to N 
            wagonIdx = v.arr[freightIdx];
        }
        if (trainsUsed > v.L) return false;
    }
    if (wagonIdx <= v.N) trainsUsed++;
    return trainsUsed <= v.L;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // binary search to find the min wagons that can be attached to a locomotive
  // if some M can be at most hi, then search left. if not, then search high. 
  
  int T = 0;
  cin >> T;

  for (int i = 0; i < T; ++i) {
    Variables v;
    cin >> v.N >> v.W >> v.L;

    v.arr.assign(v.W, 0);
    for (int i = 0; i < v.W; ++i) {
        cin >> v.arr[i];
    }
    
    int lo = 1; 
    int hi = v.N;
    int mid = 0;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (query(mid, v)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << "\n";
  }
}