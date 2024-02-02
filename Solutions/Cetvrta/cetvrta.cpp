#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> first, second;
    int x, y, x1, y1, x2, y2;
    scanf("%d %d %d %d %d %d", &x, &y, &x1, &y1, &x2, &y2);

    // uses bitwise XOR, a ^ a = 0 so it will cancel out if it appears twice
    printf("%d %d", x ^ x1 ^ x2, y ^ y1 ^ y2);
    return 0;
}