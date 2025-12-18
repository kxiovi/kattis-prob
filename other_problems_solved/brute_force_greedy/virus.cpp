#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // match from front until one is not the same
    // then start matching from the back

    char c;
    string before;
    string after;
    int count=0;
    int stopped=0;

    cin >> before >> after;


    while (before[stopped] == after[stopped] && stopped < before.size() && stopped < after.size()) {
        stopped += 1;
    }

    int b = before.size() - 1;
    int a = after.size() - 1;
    while (before[b] == after[a] && b >= stopped && a >= stopped) {
        b--;
        a--;
    }

    count = (a + 1 - stopped);
    if (count < 0) count = 0;

    cout << count << endl;

}
