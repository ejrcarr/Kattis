#include <iostream>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    for(int i = std::min(a, b) + 1; i < std::max(a, b) + 2; ++i) {
        printf("%d\n", i);
    }
    return 0;
}