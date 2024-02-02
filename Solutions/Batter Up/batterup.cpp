#include <iostream>

int main() {
    int n, true_count = 0;
    double total = 0.0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int bases;
        std::cin >> bases;
        if (bases == -1) continue;
        total += bases;
        true_count++;
    }
    printf("%f", (total / true_count));
    return 0;
}