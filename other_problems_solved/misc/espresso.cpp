#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;

const int MAX = 50;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int capacity;
    cin >> n >> capacity;

    int used = capacity;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string student;
        cin >> student;
        if (student.back() == 'L') {
            student.pop_back();
            // cout << student << endl;
            int s = stoi(student);
            if (used >= s+1) {
                used -= (s+1);
                // cout << s << " " << used << " " << ans << endl;
            } else {
                ans+=1;
                used = capacity;
                used -= (s+1);
                // cout << s << " " << used << " " << ans << endl;
            }
            // used += s + 1;
        } else {
            // cout << "else" << student << endl;
            int s = stoi(student);
            if (used >= s) {
                // cout<<"HERE s is "<<s<<endl;
                used -= s;
                // cout << s << " " << used << " " << ans << endl;
            } else {
                ans+=1;
                used = capacity;
                used -= s;
                // cout << s << " " << used << " " << ans << endl;
            }
        }
    }

    cout << ans;

}
