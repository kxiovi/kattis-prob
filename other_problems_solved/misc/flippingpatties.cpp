/*
References: 

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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(0);

    int n;
	cin >> n;

    // represents how many simultaneous tasks must be accomplished by 1 hand at a time
    vi v(43200);

    while (n--) {
        int a, b;
        cin >> a >> b;
        v[b]++; // remove
        v[b-a]++; // flip
        v[b-2*a]++;  // place on grill
    }

    double max = *max_element(all(v));

    cout  << ceil(max/2);
}