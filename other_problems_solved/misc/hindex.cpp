#include <bits/stdc++.h>
using namespace std;

int main() {
    int totalPapers = 0;
    cin >> totalPapers;

    std::vector<long> allPapers(totalPapers);
    for (int i = 0; i < totalPapers; i++) {
        cin >> allPapers[i];
    }

    sort(allPapers.begin(), allPapers.end(), greater<int>());

    int k = 0;
    while (k < totalPapers && allPapers[k] > k) {
        k++;
    }

    cout << k << endl;
}
