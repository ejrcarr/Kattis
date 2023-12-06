#include <iostream>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    while (a + b + c + d != 0) {
        int first = std::max(a, b) * 10 + std::min(a, b);
        int second = std::max(c, d) * 10 + std::min(c, d);
        if (((first == 12 || first == 21) && (second == 12 || second == 21)) ||
            (first == second)) {
            printf("Tie.\n");
        }
        else if (first == 12 || first == 21) {
            printf("Player 1 wins.\n");
        }
        else if(second == 12 || second == 21) {
            printf("Player 2 wins.\n");
        }
        else if(a == b && c != d) {
            printf("Player 1 wins.\n");
        }
        else if(a != b && c == d) {
            printf("Player 2 wins.\n");
        }
        else {
            printf("Player %s wins.\n", ((first > second) ? "1" : "2"));
        }
        scanf("%d %d %d %d", &a, &b, &c, &d);
    }
    return 0;
}