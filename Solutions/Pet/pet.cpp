#include <iostream>

int main() {
    std::pair<int, int> winner(0, 0);
    for (int i = 1; i < 6; ++i) {
        int one, two, three, four;
        scanf("%d %d %d %d", &one, &two, &three, &four);
        if ((one + two + three + four) > winner.second) {
            winner = std::make_pair(i, one + two + three + four);
        }
    }
    printf("%d %d", winner.first, winner.second);
}