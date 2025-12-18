// sources: efficient way of finding factors: https://www.rookieslab.com/posts/most-efficient-way-to-find-all-factors-of-a-number-python-cpp

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    long long N, M;
    cin >> N >> M;
    vector<long long> ans;

    long long i = 1;
    
    while (i*i <= M) {
        bool flag1 = false;
        bool flag2 = false;
        long long div = 0;
        if (M % i == 0) {
            flag1 = true;
            // cout << "i = " << i << endl;
            div = M/i;
            if (div != i) {
                flag2 = true;
                // cout << "M/i = " << div << endl;
            }
        }
        if (i <= N && div <= N) {
            if (flag1 && i <= N) {
                ans.push_back(i);
            } 
            if (flag2 && div <= N) {
                ans.push_back(div);
            }   
        }
        i++;
    } 

    // for (int j = 0; j < ans.size(); j++) {
    //  cout << ans[j] << ' ';
    // }
    // cout << endl;

    cout << ans.size();
    
}
