#include <iostream>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;
    std::unordered_map<int, int> probability = {{2, 1}, {3, 2}, {4, 3}, {5, 4}, {6, 5}, {7, 6}, {8, 5}, {9, 4}, {10, 3}, {11, 2}, {12, 1}};
    double total = 0.0;
    for (int i = 0; i < n; ++i) {
        int space;
        std::cin >> space;
        total += probability.at(space);
    }
    std::cout << total/36;
    return 0;
}