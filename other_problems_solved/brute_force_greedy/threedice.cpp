#include <bits/stdc++.h>
using namespace std;

bool solve(int index, vector<string> &words, vector<set<char>> &dice,
            map<char, int> &letter_to_die, vector<array<int, 3>> &perm) {

    // compare that each vector has unique letters across each vector
    // if not, remove the offending letter in one set, and replace with a letter 
    // from another set at the same index
    if (index == (int)words.size()) return true;  // every word assigned :)

    string& w = words[index];

    // need to track the current word before its letters are assigned to a die
    // otherwise not all  permutations can be checked properly if an earlier one fails
    vector<pair<char, int>> tmp (3);

    bool ok = true;
    for (auto &p : perm) {
        ok = true;
        tmp.clear();

        for (int i = 0; i < 3; ++i) {
            char c = w[i];
            int die = p[i];

            if (letter_to_die.contains(c)) {
                if (letter_to_die[c] != die) {
                    // c must stay on a specific die, otherwise there will be problems
                    ok = false;
                    break;
                }
            } else {
                if (dice[die].size() >= 6) {
                    // no more space
                    ok = false;
                    break;
                }
                tmp.push_back(pair<char, int> (c, die));
            }
        }

        // if a perm is valid, it is added for the time being
        if (ok) {
            for (auto [c, die] : tmp) {
                dice[die].insert(c);
                letter_to_die[c] = die;
            }

            // now, try adding next word
            if (solve(index+1, words, dice, letter_to_die, perm)) return true;

            // if the tmp assignments don't work, erase them
            for (auto [c, die] : tmp) {
                dice[die].erase(c);
                letter_to_die.erase(c);
            }
        }
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // NOTE: Must have 18 distinct letters across the 3 6-sided dice

    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    
    // accounting for words like dad (same letter twice)
    for (const auto& w : words) {
        if (w[0] == w[1] || w[0] == w[2] || w[1] == w[2]) {
            cout << "0";
            return 0;
        }
    }

    // separate each of the 2 letter of every word into 3 different vectors
    set<char> input;
    for (const auto& w : words) {
        for (const char& ch : w) {
            input.insert(ch);
        }
    }

    
    vector<set<char>> dice(3);
    map<char, int> letter_to_die;
    vector<array<int, 3>> perm = {
        {0, 1, 2}, 
        {0, 2, 1}, 
        {1, 0, 2}, 
        {1, 2, 0}, 
        {2, 0, 1}, 
        {2, 1, 0}
    };
    
    if (!solve(0, words, dice, letter_to_die, perm)) {
        cout << 0;
        return 0;
    }

    vector<char> leftover;
    for (char c = 'a'; c <= 'z'; c++) {
        if (!input.contains(c)) {
            leftover.push_back(c);
        }
    }
    for (int i = 0; i < 3; i++) {
        while (dice[i].size() < 6 && !leftover.empty()) {
            dice[i].insert(leftover.back());
            leftover.pop_back();
        }
        if (dice[i].size() != 6) {
            cout << 0; 
            return 0;
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (char ch : dice[i]) {
            cout << ch;
        }
        cout << " "; 
    }
    

}