#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int candidates, total = 0;
        std::cin >> candidates;

        std::vector<int> votes(candidates);
        std::pair<int, int> potential_winner = {-1e9, 0}; // (max) votes, candidate
        for (int i = 0; i < candidates; ++i) {
            std::cin >> votes[i];
            total += votes[i];
            if(votes[i] > potential_winner.first) {
                potential_winner = {votes[i], i + 1};
            }
        }

        int winners = std::count(votes.begin(), votes.end(), potential_winner.first);

        if (winners > 1) {
            std::cout << "no winner\n";
        } else {
            if (potential_winner.first > total / 2) {
                std::cout << "majority winner " << potential_winner.second << "\n";
            } else {
                std::cout << "minority winner " << potential_winner.second << "\n";
            }
        }
    }
    return 0;
}
