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

struct room {
    int index;
    int exams;
};

bool cmp(room& r, room& t) {
    return r.exams > t.exams;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(0);

    int n; 
    cin >> n;
    
    vector<room> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].exams;
        v[i].index = i+1;
    }
    sort(all(v), cmp);

    int sum = 0;
    for (int i = 1; i < n; ++i) {
        sum += v[i].exams;
    }

    if (v[0].exams > sum) {
        cout << "impossible";
        return 0;
    } 

    for (auto a : v) {
        cout << a.index << " ";
    }
    
}
