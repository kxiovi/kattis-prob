#include <iostream>
#include <list>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string input; 
    std::cin >> input;

    std::list<char> output;
    auto idx = output.begin();
    for (char c : input) {
        if (c == 'L') {
            if (idx != output.begin()) --idx;
        } else
        if (c == 'R') {
            if (idx != output.end()) ++idx;
        } else
        if (c == 'B') {
            if (idx != output.begin()) {
                idx = output.erase(--idx);
            }
        } else {
            idx = output.insert(idx, c);
            ++idx;
        }
    }
    for (char c : output) std::cout << c;
    std::cout << std::endl;
}