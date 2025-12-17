#include <bits/stdc++.h>

int main(int argc, char **argv) {
    int H_hours;
    int N_guests;
    long C_capacity;
    long totalEffort = 0;
    
    std::cin >> N_guests >> H_hours >> C_capacity;

    int totalCandles = N_guests * H_hours;
    std::vector<std::vector<int>> candles(N_guests);

    for (int i = 0; i < N_guests; i++) {
        candles.at(i).resize(H_hours);
        for (int j = 0; j < H_hours; j++) {    
            int effort;
            std::cin >> effort; 
            candles.at(i).at(j) = effort;
            totalEffort += effort;
        };

        std::sort(candles.at(i).begin(), candles.at(i).end(), std::greater<int>()); // decending order
    }
    
    long mustRemainEffort = totalEffort - C_capacity;
    long effortNotExerted = 0;
    std::vector<int> numCandlesRemainingPerGuest(N_guests, 0);
    int x = 0; // num candles selected to remain per row for each round

    while (effortNotExerted < mustRemainEffort) {
        // sort rows by 1 elem in each row
        std::vector<std::pair<int, int>> order; // stores most effort candles from each guest that hasn't already been chosen
        for (int i = 0; i < N_guests; i++) {
            int alreadyChosen = numCandlesRemainingPerGuest.at(i);
            if (alreadyChosen < H_hours) {
                order.push_back({candles.at(i).at(alreadyChosen), i});
            }
        }
        sort(order.begin(), order.end(), std::greater<>());

        bool picked = false;
        for (auto [e, row] : order) {  // e for effort
            if (numCandlesRemainingPerGuest[row] < x + 1) {
                effortNotExerted += e;
                candles[row][numCandlesRemainingPerGuest[row]] = 0;
                numCandlesRemainingPerGuest[row]++;
                picked = true;
                break;
            }
        }
        if (!picked) {
            x++;
        }
    }
   
    std::cout << totalCandles - accumulate(numCandlesRemainingPerGuest.begin(), numCandlesRemainingPerGuest.end(), 0) << std::endl;
    // print candles
    // for (int i = 0; i < N_guests; i++) {
    //     for (int j = 0; j < H_hours; j++) {
    //         auto [effort, blown] = candles.at(i).at(j);
    //         std::cout << effort << " " << blown << std::endl;
    //     }
    //     std::cout << std::endl;
    // }
    
}