#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool qualifies_for_bonus(const int& rank, const int& streak) {
    return (rank >= 6 && rank <= 25) && (streak >= 3);
}

int main() {
    string results;
    cin >> results;

    vector<int> caps = {0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2};
    vector<int> rank_values(26, 0);

    int streak = 0, rank = 25;

    for(char result : results) {
        if(rank == 0) break;
        if(result == 'W') {
            ++streak;
            int increase = 1 + qualifies_for_bonus(rank, streak);
            if(increase == 2 && (rank_values[rank] + 1 == caps[rank])) {
                rank_values[rank] = caps[rank];
                --rank;
                increase = 1;
            }
            else if(rank_values[rank] >= caps[rank]) {
                --rank;
            }

            rank_values[rank] += increase;
        }
        else {
            streak = 0;
            if(rank == 0 || rank > 20) {
                continue;
            }
            if(rank <= 20 && rank_values[rank] > 0) {
                --rank_values[rank];
            }
            else if(rank < 20 && rank_values[rank] == 0) {
                ++rank;
                rank_values[rank] = caps[rank] - 1;
            }
        }
    }

    if(rank == 0) cout << "Legend";
    else cout << rank;
    return 0;
}