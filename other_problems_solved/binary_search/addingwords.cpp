#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // try unordered_map or bimap
    unordered_map<string, int> dict;  // store definitions -> foo : 2
    unordered_map<int, string> reverseDict;  // 2 : foo

    string cmd;
    while (cin >> cmd) {
        if (cmd == "def") {
            string x;
            int y;
            cin >> x >> y;
            if (dict.count(x)) { reverseDict.erase(dict[x]); }
            if (reverseDict.count(y)) { dict.erase(reverseDict[y]); }
            dict[x] = y;
            reverseDict[y] = x;
        } else 

        if (cmd == "calc") {
            string a;
            queue<string> q;
            int sum = 0;
            while (cin >> a && a != "=") {
                q.push(a);
            }
            string b = q.front(); 
            q.pop();
            cout << b;
            bool unknown = false;
            if (!dict.count(b)) {
                unknown = true;
            } else {
                sum = dict[b];
            }
            while (!q.empty()) {
                string op = q.front(); 
                q.pop();
                string b2 = q.front(); 
                q.pop();
                cout << " " << op << " " << b2;
                if (!dict.count(b2)) unknown = true; else {
                    if (op == "+") {
                        sum += dict[b2];
                    } else {
                        sum -= dict[b2];
                    }
                }
                
            }
            cout << " = ";
            if (!reverseDict.count(sum) || unknown) {
                cout << "unknown" << "\n";
            } else {
                cout << reverseDict[sum] << "\n";
            }
            
        } else 

        if (cmd == "clear") {
            dict.clear();
            reverseDict.clear();
        }
    }
    return 0;
}