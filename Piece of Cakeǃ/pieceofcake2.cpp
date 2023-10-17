#include <iostream>

int main() {
    int n, h, v;
    scanf("%d %d %d", &n, &h, &v);
    printf("%d", 4 * std::max(h, n - h) * std::max(v, n - v));
    return 0;
}