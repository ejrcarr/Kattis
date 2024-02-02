#include <iostream>

int main() {
    int a, b, c, d, t;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &t);

    int total_difference = abs(a - c) + abs(b - d);
    printf("%s", (total_difference <= t && (t - total_difference) % 2 == 0) ? "Y\n" : "N\n");

    return 0;
}
