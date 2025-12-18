// references
//   BWT Algorithm: https://github.com/toiletpapar/BWT/tree/master
//   duplicate string: https://stackoverflow.com/questions/34639854/using-suffix-array-algorithm-for-burrows-wheeler-transform

// use suffix array that gives the staring index of each suffix in sorted order
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    while (getline(std::cin, line)) {
        int len = line.length();
        string s = line + line;
        vector<int> suffix_arr(len);
        iota(suffix_arr.begin(), suffix_arr.end(), 0);
        vector<int> ranks(len*2);  // for ranks
        for (int i = 0; i < len*2; ++i) { ranks[i] = s[i]; }
        vector<int> tmp(len*2);  // for ranks in each iteration

        for (int m = 1; m < len; m <<= 1) {
            auto rank = [&](int x, int y) {
                if (ranks[x] != ranks[y]) return ranks[x] < ranks[y];
                else return ranks[(x + m)% len] < ranks[(y + m) % len];
            };
            sort(suffix_arr.begin(), suffix_arr.end(), rank);
            tmp[suffix_arr[0]] = 0; 
            
            for (int i = 1; i < len; ++i) {
                int p = suffix_arr[i-1];
                int n = suffix_arr[i];
                tmp[n] = tmp[p] + rank(p, n);
            }

            for (int i = 0; i < len; ++i) {
                int n = suffix_arr[i];
                ranks[n] = tmp[n];
            }


            // what if all ranks are unique
            if (ranks[suffix_arr[len-1]] == len-1) break;
        }

        string ans;
        ans.reserve(len);
        for (int i : suffix_arr) {
            ans.push_back(s[len + i - 1]);
        }
        cout << ans << '\n';

    }
}
