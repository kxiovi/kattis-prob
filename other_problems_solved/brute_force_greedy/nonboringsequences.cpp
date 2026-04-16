/*
References: https://cerc.tcs.uj.edu.pl/2012/data/cerc 2012 solutions.pdf 

The question is: is each subarray unique? 
Thus, find a unique element in the array (if not, boring). 
Then, scan in parallel, each subarray, to find a unique element in the subarray
If not ==> boring, else, non-boring

Basically, recurse on each subarray to find if there is at least 1 unique
element in each subarray. To find a unique element in O(1) time, find the positions 
of the closest identical elements for each element in the sequence. 
*/

#include <bits/stdc++.h>
using namespace std;

using ulll = __uint128_t;
using ull = uint64_t;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


vector<int> s; 
vi vleft;
vi vright;

bool solve(int l, int r) {
    if (l >= r) {
        return true;
    }
    for (int i = 0; i <= (r-l)/2; ++i) {
        if (vright[l+i] > r && vleft[l+i] < l) {
            return solve(l, l+i-1) && solve(l+i+1, r);
        }
        if (vright[r-i] > r && vleft[r-i] < l) {
            return solve(l, r-i-1) && solve(r-i+1, r);
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        s.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }

        vleft.resize(n);  // occurence to the left
        vright.resize(n);  // occurence to the right
        unordered_map<int, int> prev;  // penultimate appearance of current element
        for(int i = 0; i < n; ++i) {
            if (prev.contains(s[i])) {
                vleft[i] = prev[s[i]];
            } else {
                vleft[i] = -1;
            }
            prev[s[i]] = i;
        }

        prev.clear();
        for (int i = n-1; i >= 0; --i) {
            if (prev.contains(s[i])) {
                vright[i] = prev[s[i]];
            } else {
                vright[i] = n;
            }
            prev[s[i]] = i;
        }

        // -1 means no appearance to the left, n means no appearance to the right
        bool ans = solve(0, n-1);
        if (ans) {
            cout << "non-boring\n";
        } else {
            cout << "boring\n";
        }
        
    }
    
}
