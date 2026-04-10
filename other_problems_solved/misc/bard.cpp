#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, E;
    cin >> N >> E;
    
    vector<set<int>> knows(N+1); // the songs known by each villager
    int song = 0;

    for (int e = 0; e < E; ++e) {
        int K; 
        cin >> K;
        vector<int> villagers(K);
        for (int k = 0; k < K; ++k) {
            cin >> villagers[k];
        }

        bool bard_present = find(villagers.begin(), villagers.end(), 1) != villagers.end();

        if (bard_present) {
            song++;
            for (int v : villagers) {
                knows[v].insert(song);
            } 
        } else {
                // if bard is not present
                set<int> union_songs;
                for (int v : villagers) {
                    union_songs.insert(knows[v].begin(), knows[v].end());
                }

                for (int v : villagers) {
                    knows[v] = union_songs;
                }
            }
        }

    for (int v = 1; v <= N; ++v) {
        if (knows[v].size() == song) {
            cout << v << "\n";
        }
    }
}
