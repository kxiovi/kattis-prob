#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;

const int MAX = 50;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string wordToGuess; 
    string alphabet;
    cin >> wordToGuess >> alphabet;

    // cout << wordToGuess << '\n' << alphabet << '\n';

    int count=0;
    for (char c : alphabet) {
        if (find(wordToGuess.begin(), wordToGuess.end(), c) != wordToGuess.end()) {
            wordToGuess.erase(std::remove(wordToGuess.begin(), wordToGuess.end(), c), wordToGuess.end());
            // cout << wordToGuess << '\n';
            
        } else {
            count++;
        }

        if (count > 9) {
            cout << "LOSE";
            return 0;
        } else 
        if (wordToGuess.empty()) {
            cout << "WIN";
            return 0;
        }
    }

}
