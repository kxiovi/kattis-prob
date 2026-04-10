#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> towers(6);
    for (int i = 0; i < 6; ++i) {
        cin >> towers[i];
    }

    int t1, t2;
    cin >> t1 >> t2;

    for (int i = 0; i < 6; ++i) {
        for (int j = 1; j < 6; ++j) {
            for (int k = 2; k < 6; ++k) {
                int sum = towers[i] + towers[j] + towers[k];
                if (sum == t1 || sum == t2) {
                    vector<int> arr = {towers[i], towers[j], towers[k]};
                    vector<int> leftover(3);
                    sort(arr.begin(), arr.end(), greater<int>());

                    for (int m = 0; m < 6; ++m) {
                        if (towers[m] != arr[0] && towers[m] != arr[1] && towers[m] != arr[2]) {
                            leftover.push_back(towers[m]);
                        }
                    }

                    sort(leftover.begin(), leftover.end(), greater<int>());

                    if (sum == t1) {
                        cout << arr[0] << " " << arr[1] << " " << arr[2] << " ";
                        cout << leftover[0] << " " << leftover[1] << " " << leftover[2];
                    } else 
                    if (sum == t2) {
                        cout << leftover[0] << " " << leftover[1] << " " << leftover[2] << " ";
                        cout << arr[0] << " " << arr[1] << " " << arr[2] << " ";
                    }
                    return 0;
                }
            }
        }
    }

    
    
    
}
