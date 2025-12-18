#include <bits/stdc++.h>
using namespace std;


// task idx, tool, drop number
int solve(vector<vector<vector<int>>> &memo, vector<int> &task_table, int n_size, int i, int t, int d) {
    if (i == n_size) return 0; 
    int &curr = memo[i][t][d];
    if (curr != -1) return curr;

    int ans = 0;

    ans = max(ans, solve(memo, task_table, n_size, i+1, t, d));
    if (task_table[i] == t) {
        ans = max(ans, 1+solve(memo, task_table, n_size, i+1, t, d));
    }

    for (int m = 0; m < 3; ++m) {
        // if the current tool does not match
        if (m != t && (d & 1<<m)) {
            // switch
            int d1 = d & ~(1<<t);  // drop curr tool
            ans = max(ans, solve(memo, task_table, n_size, i+1, m, d1) + (task_table[i] == m));
        
        }
    }

    curr = ans;
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;

    vector<int> task(n);

    for (int i = 0; i < n; ++i) {
        cin >> task[i];
    }

    vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(3, vector<int>(1<<3, -1)));
    // memset(memo, -1, sizeof(memo));

    int A = 0;
    int mask = (1<<3) - 1;  // 111
    for (int tool = 0; tool < 3; ++tool) {
        A = max(A, solve(memo, task, n, 0, tool, mask));
    }

    cout << A << '\n';

}