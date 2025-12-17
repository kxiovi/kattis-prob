#include <bits/stdc++.h>
using namespace std;
struct Ant {
    int pos;
    char dir;
    int time;
};

int main() {
    int L, A;
    while (cin >> L >> A) {
        vector<Ant> ants(A);
        for (int i = 0; i < A; i++) {
            cin >> ants[i].pos >> ants[i].dir;
            ants[i].time = (ants[i].dir == 'L') ? ants[i].pos : (L - ants[i].pos);
        }

        sort(ants.begin(), ants.end(), [](const Ant &a, const Ant &b) {
            return a.pos < b.pos;
        });

        struct Collision { 
            int time; 
            char dir; 
            int idx; 
        };
        vector<Collision> c;
        for (int i = 0; i < A; i++) {
            c.push_back({ants.at(i).time, ants.at(i).dir, i});
        }

        sort(c.begin(), c.end(), [](const Collision &a, const Collision &b) {
            return a.time < b.time;
        });

        deque<int> labels;
        for (int i = 0; i < A; i++) labels.push_back(ants.at(i).pos);

        int maxT = c.back().time;
        vector<int> ans;

        for (int i = 0; i < c.size();) {
            int t = c.at(i).time;
            int j = i;
            vector<int> group;
            while (j < c.size() && c.at(j).time == t) j++;

            int cntL = 0, cntR = 0;
            for (int k = i; k < j; k++) {
                if (c.at(k).dir == 'L') cntL++;
                else cntR++;
            }
            for (int k = 0; k < cntL; k++) {
                group.push_back(labels.front());
                labels.pop_front();
            }
            for (int k = 0; k < cntR; k++) {
                group.push_back(labels.back());
                labels.pop_back();
            }

            if (t == maxT) {
                ans = group; // ants that fall last
            }

            i = j;
        }

        sort(ans.begin(), ans.end());
        cout << "The last ant will fall down in " << maxT << " seconds - started at";
        if (ans.size() == 1) {
            cout << " " << ans.at(0) << "." << endl;
        } else {
            for (int i = 0; i < ans.size() - 1; i++) {
                cout << " " << ans.at(i) << " and";
            }
            cout << " " << ans.at(ans.size()-1) << "." << endl;
        }
    }
}